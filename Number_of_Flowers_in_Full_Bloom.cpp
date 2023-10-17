#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool check(vector<int> &arr, int val)
    {
        if (val >= arr[0] && val <= arr[1])
            return true;
        return false;
    }

    // TLE
    int brute(vector<vector<int>> &flowers, vector<int> &people)
    {
        int n = people.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < flowers.size(); j++)
            {
                cout << flowers[j][0] << " " << flowers[j][1] << " " << people[i] << endl;
                if (check(flowers[j], people[i]))
                    ans[i]++;
            }
        }
        return ans;
    }

    int opti(vector<vector<int>> &flowers, vector<int> &people)
    {
        vector<int> start;
        vector<int> end;

        for (auto it : flowers)
        {
            start.push_back(it[0]);
            end.push_back(it[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        vector<int> ans;

        for (int person : people)
        {
            int i = upper_bound(start.begin(), start.end(), person) - start.begin();
            int j = upper_bound(end.begin(), end.end(), person) - end.begin();
            ans.push_back(i - j);
        }
        return ans;
    }

public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        return opti(flowers, people);
    }
};

int main()
{

    return 0;
}