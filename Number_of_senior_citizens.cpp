#include <bits/stdc++.h>
using namespace std;

int countSeniors(vector<string> &details)
{
    int ans = 0;
    for (auto i : details)
    {
        int age = stoi(i.substr(11, 2));
        if (age > 60)
            ans++;
    }

    return ans;
}

int main()
{
    vector<string> arr = {"1313579440F2036", "2921522980M5644"};
    cout << countSeniors(arr);
    return 0;
}