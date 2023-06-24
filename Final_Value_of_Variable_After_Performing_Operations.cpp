#include <bits/stdc++.h>
using namespace std;

int finalValueAfterOperations(vector<string> &operations)
{
    int ans = 0;
    for (int i = 0; i < operations.size(); i++)
    {
        string word = operations[i];
        if (word == "--X" || word == "X--")
        {
            ans--;
        }
        else if (word == "++X" || word == "X++")
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    vector<string> arr;
    arr.push_back("X++");
    arr.push_back("X--");
    arr.push_back("++X");
    cout << finalValueAfterOperations(arr);
    return 0;
}