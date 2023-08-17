#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        // unordered_map<int, int> map;
        // for (auto c : t)
        //     map[c]++;

        // int count = t.length();
        // int i = 0, j = 0, d = INT_MAX;
        // int head = 0;

        // while (j < s.length())
        // {
        //     if (map[s[j++]]-- > 0)
        //         count--;
        //     while (count == 0)
        //     {
        //         if (j - i < d)
        //             d = j - (head = i);
        //         if (map[s[i++]]++ == 0)
        //             count++;
        //     }
        // }
        // return d == INT_MAX ? "" : s.substr(head, d);
    }
};

int main()
{

    return 0;
}