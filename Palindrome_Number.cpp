#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    int palindrome = 0;
    int temp = x;
    while (x > 0)
    {
        palindrome = (palindrome * 10) + (x % 10);
        cout << palindrome << endl;
        x = x / 10;
    }
    return palindrome == temp;
}

int main()
{
    cout << isPalindrome(121);
    return 0;
}