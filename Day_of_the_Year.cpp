#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool checkYear(int year)
    {
        if (year % 400 == 0)
            return true;
        else if (year % 100 == 0)
            return false;
        else if (year % 4 == 0)
            return true;
        else
            return false;
    }

public:
    int dayOfYear(string date)
    {
        int day = stoi(date.substr(date.length() - 2, date.length() - 1));
        int month = stoi(date.substr(date.length() - 5, date.length() - 4));
        int year = stoi(date.substr(0, 4));

        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int ans = 0;
        bool alt = true;
        days[1] = checkYear(year) ? 29 : 28;
        for (int i = 0; i < month; i++)
        {
            ans += days[i];
        }

        ans += day;

        cout << ans;
        return ans;
    }
};

int main()
{
    Solution s;
    s.dayOfYear("2019-01-09");
    return 0;
}