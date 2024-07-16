#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        unordered_map<int, int> map;
        for (auto i : arr)
            map[i]++;
        int count = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k =j + 1; k < n; k++)
                {
                    if (arr[i] + arr[j] + arr[k] == target)
                    {
                        map[arr[i]]--;
                        map[arr[j]]--;
                        map[arr[k]]--;
                        count += (map[arr[i]] + 1) * (map[arr[j]] + 1) * (map[arr[k]] + 1)
                    }
                }
            }
            map[arr[i]]++;
            map[arr[j]]++;
            map[arr[k]]++;
        }
        return count;
    }
};

int main()
{

    return 0;
}