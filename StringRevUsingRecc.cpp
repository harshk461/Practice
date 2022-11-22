// #include <bits/stdc++.h>
// using namespace std;

// void reverse(string &s, int i, int j)
// {
//     if (i > j)
//     {
//         return;
//     }

//     swap(s[i], s[j]);
//     i++;
//     j--;
//     reverse(s, i, j);
// }

// int main()
// {
//     string s = "harsh";
//     reverse(s, 0, s.length() - 1);
//     cout << s << endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

void reverse(string &s, int i)
{
    if (i > s.length() - i - 1)
    {
        return;
    }

    swap(s[i], s[(s.length() - i - 1)]);
    i++;
    reverse(s, i);
}

int main()
{
    string s = "harsh";
    reverse(s, 0);
    cout << s << endl;
    return 0;
}