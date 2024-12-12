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
    /**
     * Adds spaces to the given string `s` at the specified indices in `spaces`.
     * @param s - The input string.
     * @param spaces - A vector of indices where spaces need to be added.
     * @return The resulting string with spaces added.
     */
    string addSpaces(string s, vector<int> &spaces)
    {
        int n = s.length();
        int m = spaces.size();

        string ans = ""; // Resultant string
        int i = 0;       // Pointer for the input string
        int j = 0;       // Pointer for the spaces vector

        // Traverse the string and insert spaces at specified positions
        while (i < n)
        {
            // If the current index matches a space position, add a space
            if (j < m && i == spaces[j])
            {
                ans += ' ';
                j++; // Move to the next space index
            }
            // Add the current character from the string
            ans += s[i];
            i++;
        }

        return ans;
    }
};

int main()
{

    return 0;
}