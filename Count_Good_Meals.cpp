#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int MOD = 1e9 + 7;
    bool isPower2(int a, int b)
    {
        int sum = (a + b) % MOD;
        for (int i = 0; i < 21; i++)
        {
            if (sum == pow(2, i))
                return true;
        }
        return false;
    }
    int solve(vector<int> &arr)
    {
        unordered_map<int, int> map;
        vector<int> v;
        int num = 1, ans = 0, n = arr.size();
        v.push_back(1);

        for (int i = 0; i <= 21; i++)
        {
            num <<= 1;
            v.push_back(num);
        }

        for (int i = 0; i < arr.size(); i++)
            map[arr[i]]++;

        for (int i = 0; i < n; i++)
        {
            map[arr[i]]--;
            if (map[arr[i]] == 0)
                map.erase(arr[i]);

            for (int j = 0; j < v.size(); j++)
            {
                if (map.find(v[j] - arr[i]) != map.end())
                    ans = (ans + map[v[j] - arr[i]]) % MOD;
            }
        }
        return ans;
    }

public:
    int countPairs(vector<int> &deliciousness)
    {
        int n = deliciousness.size();
        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j)
                    if (isPower2(deliciousness[i], deliciousness[j]))
                        count++;
        return count;
    }
};

int main()
{

    return 0;
}