#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    string s;
    cin >> s;

    set<char> st;
    for (auto i : s)
    {
        if (i >= 'A' && i <= 'Z')
            st.insert(i + 'a' - 'A');
    }

    if (st.size() == 26)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}