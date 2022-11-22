// #include <bits/stdc++.h>
// using namespace std;

// bool checkPalindrome(string s, int i, int j)
// {
//     if (i > j)
//     {
//         return true;
//     }

//     if (s[i] != s[j])
//         return false;
//     else
//         return checkPalindrome(s, i + 1, j - 1);
// }
// int main()
// {
//     string s = "aabbaa";
//     bool isPalindrome = checkPalindrome(s, 0, s.length() - 1);
//     if (isPalindrome)
//         cout << "Palindrome" << endl;
//     else
//         cout << "Not Palindrome" << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s, int i)
{
    if (i > s.length() - i - 1)
    {
        return true;
    }

    if (s[i] != s[s.length() - i - 1])
        return false;
    else
        return checkPalindrome(s, i + 1);
}
int main()
{
    string s = "aabbaaa";
    bool isPalindrome = checkPalindrome(s, 0);
    if (isPalindrome)
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}