#include <bits/stdc++.h>
using namespace std;

string restoreString(string s, vector<int> &indices)
{
    string ans = s;
    for (int i = 0; i < indices.size(); ++i)
    {
        ans[indices[i]] = s[i];
    }
    cout << ans;
    return ans;
}

int main()
{
    string s = "codeleet";
    vector<int> arr = {4, 5, 6, 7, 0, 2, 1, 3};
    restoreString(s, arr);
    return 0;
}