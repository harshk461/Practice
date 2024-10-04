#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
private:
    pair<int, int> split(string s)
    {
        int hour = stoi(s.substr(0, 2));
        int minute = stoi(s.substr(3));

        return {hour, minute};
    }

public:
    int findMinDifference(vector<string> &timePoints)
    {
        vector<pair<int, int>> vec;
        for (auto it : timePoints)
        {
            vec.push_back(split(it));
        }

        // for (auto it : vec)
        //     cout << it.first << " " << it.second << endl;

        vector<int> minutes(timePoints.size());

        for (int i = 0; i < timePoints.size(); i++)
            minutes[i] = vec[i].first * 60 + vec[i].second;

        sort(minutes.begin(), minutes.end());

        int ans = INT_MAX;

        for (int i = 0; i < minutes.size() - 1; i++)
            ans = min(ans, minutes[i + 1] - minutes[i]);

        // first and last elememt
        ans = min(ans, 24 * 60 - minutes[minutes.size() - 1] + minutes[0]);

        return ans;
    }
};

int main()
{

    return 0;
}