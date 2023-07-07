#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                                   'A', 'E', 'I', 'O', 'U'};
        int l = 0;
        int r = s.length() - 1;
        while (l < r)
        {
            while (l < r && !vowels.count(s[l]))
                l++;
            while (l < r && !vowels.count(s[r]))
                r--;
            swap(s[l++], s[r--]);
        }
        return s;
    }
};

int main()
{

    return 0;
}