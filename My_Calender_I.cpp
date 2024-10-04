#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class MyCalendar
{
public:
    vector<pair<int, int>> vec;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        for (auto it : vec)
        {
            if ((it.first <= start && start < it.second) || (end >= it.first && end < it.second))
                return false;
        }
        vec.push_back({start, end});
        return true;
    }
};
int main()
{

    return 0;
}