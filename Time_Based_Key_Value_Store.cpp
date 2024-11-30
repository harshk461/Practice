#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class TimeMap
{
public:
    unordered_map<string, vector<pair<int, string>>> map;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        map[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        vector<pair<int, string>> arr = map[key];
        sort(arr.begin(), arr.end(), [&](const pair<int, string> &a, const pair<int, string> &b)
             { return a.first < b.first; });

        int low = 0;
        int high = arr.size() - 1;
        string ans = "";
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (arr[mid].first <= timestamp)
            {
                ans = arr[mid].second;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        return ans;
    }
};

int main()
{

    return 0;
}