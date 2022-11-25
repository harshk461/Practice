#include <bits/stdc++.h>
using namespace std;

void reverseString(string &s, int i)
{
    // base case
    if (i > s.size() - i - 1)
    {
        return;
    }

    swap(s[i], s[s.size() - i - 1]);
    i++;
    reverseString(s, i);
}

int main()
{
    string s = "harsh";
    reverseString(s, 0);
    cout << s << endl;
    return 0;
}