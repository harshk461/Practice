#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    cout << magazine.find(ransomNote) << " ";
    if (magazine.find(ransomNote) <= magazine.length())
    {
        return true;
    }
    return false;
}

int main()
{
    cout << canConstruct("bg", "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj");
    return 0;
}