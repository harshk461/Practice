#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int brute(vector<vector<int>> &arrays)
    {
        int m = arrays.size();

        vector<int> maxi;
        vector<int> mini;

        for (auto it : arrays)
        {
            int _max = INT_MIN;
            int _min = INT_MAX;
            for (int i = 0; i < it.size(); i++)
            {
                _max = max(_max, it[i]);
                _min = min(_min, it[i]);
            }

            maxi.push_back(max);
            mini.push_back(min);
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i != j)
                    ans = max(ans, abs(maxi[i] - mini[j]));
            }
        }

        return ans;
    }

    int solve(vector<vector<int>> &arr)
    {
        int m = arr.size();
        // val->array index
        pair<int, int> maxi;
        pair<int, int> mini;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                if (arr[i][j] > maxi.first && i != mini.second)
                    maxi.first = arr[i][j];

                if (arr[i][j] < mini.first && i != maxi.second)
                    mini.first = arr[i][j];
            }
        }

        cout << maxi.first << "->" << maxi.second << endl;
        cout << mini.first << "->" << mini.second << endl;

        return abs(maxi.first - mini.first);
    }

public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        return solve(arrays);
    }
};

int main()
{

    return 0;
}