#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int countVowels(string s)
    {
        int count = 0;
        for (auto it : s)
            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u' ||
                it == 'A' || it == 'E' || it == 'I' || it == 'O' || it == 'U')
                count++;
        return count;
    }

public:
    bool halvesAreAlike(string s)
    {
        int mid = s.length() / 2;
        string a = s.substr(0, mid);
        string b = s.substr(mid);
        return countVowels(a) == countVowels(b);
    }
};

int main()
{

    return 0;
}