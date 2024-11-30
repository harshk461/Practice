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
public:
    string longestDiverseString(int a, int b, int c)
    {
        // freq,char
        priority_queue<pair<int, char>> pq;

        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});

        string ans = "";
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int freq = top.first;
            char ch = top.second;

            int len = ans.size();

            // if previous 2 elements are equal to current character we can't add ch
            // because 3 char can't be same
            if (len >= 2 && s[len - 1] == ch && s[len - 2] == ch)
            {
                // if we don't have any other character to add break the loop
                if (pq.empty())
                    break;

                // find second highest character
                auto second = pq.top();
                pq.pop();

                ans += second.second;
                // frequency of first character
                if (second.first > 1)
                {
                    int new_freq = second.first - 1;
                    pq.push({new_freq, second.second});
                }

                // push first character into pq because we've not used it
                pq.push({freq, ch});
            }
            // else we can add the current character
            else
            {
                ans += ch;
                int new_freq = freq - 1;
                if (new_freq > 0)
                    pq.push({new_freq, ch});
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}