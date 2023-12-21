#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int i = 0;
        int size = 0; // size of final array

        while (i < chars.size())
        {
            int grp = 1; // initally size of grp is 1
            if (i + grp < chars.size() && chars[i + grp] == chars[i])
                // increase size if staring ans starting+grpLength are equal
                grp++;

            // increase array size
            chars[size++] = chars[i];
            if (grp > 1)
                for (auto c : to_string(grp))
                    // breaking bigger number into grps
                    chars[size++] = c;
            i += grp;
        }
        return size;
    }
};

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int i = 0, res = 0;
        while (i < chars.size())
        {
            int groupLength = 1;
            while (i + groupLength < chars.size() && chars[i + groupLength] == chars[i])
            {
                groupLength++;
            }
            chars[res++] = chars[i];
            if (groupLength > 1)
            {
                for (char c : to_string(groupLength))
                {
                    chars[res++] = c;
                }
            }
            i += groupLength;
        }
        return res;
    }
};

int main()
{
    vector<char> arr = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    Solution s;
    s.compress(arr);
    return 0;
}