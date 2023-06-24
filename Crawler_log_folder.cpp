#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<string> &logs)
{
    stack<string> ans;
    for (auto i : logs)
    {
        if (i == "../" && !ans.empty())
        {
            ans.pop();
        }
        else if (i != "../" && i != "./")
        {
            ans.push(i);
        }
    }
    cout << ans.size();
    return ans.size();
}

int main()
{
    vector<string> arr = {"d1/", "../", "../", "../"};
    minOperations(arr);
    return 0;
}