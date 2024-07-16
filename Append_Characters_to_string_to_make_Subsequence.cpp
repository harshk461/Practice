#include <iostream>
using namespace std;

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int i = 0, j = 0; // 2 pointer for s and t string
        int n = s.length(), m = t.length();
        while (i < n && j < m)
        {
            if (s[i] == t[j])
                i++, j++;
            else
                i++;
        }

        return m - j;
    }
};

int main()
{
    Solution s;
    cout << s.appendCharacters("abcd", "sf");
    return 0;
}