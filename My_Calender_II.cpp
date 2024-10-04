#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class MyCalendarTwo
{
public:
    vector<pair<int, int>> vec;
    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        for (auto it : vec)
        {
            if (start < it.second && end > it.first)
            {
                int new_x = max(it.first, start);
                int new_y = min(end, it.second);

                if (check(new_x, new_y))
                    return false;
            }
        }

        vec.push_back({x, y});
        return true;
    }

    bool check(int a, int b)
    {
        int count = 0; // overlap count
        for (auto it : vec)
        {
            if (a < it.second && b > it.first)
            {
                count++;
                // already double booking is present
                if (count == 2)
                    return true;
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}