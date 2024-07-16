#include <iostream>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<int, int> map;
        for (auto it : s)
            map[it]++;

        int odd_length = 0;
        int one_odd_flag = false;
        int ans = 0;
        // for (auto it : map)
        //     cout << (char)(it.first) << "->" << it.second << endl;
        // We don't have to use every element's frequency
        for (auto it : map)
        {
            if (it.second % 2 == 0)
                ans += it.second;
            else if (it.second % 2 != 0)
            {
                odd_length += it.second - 1;
                one_odd_flag = true;
            }
        }
        if (one_odd_flag)
            ans++;
        return ans + odd_length;
    }
};

int main()
{

    return 0;
}