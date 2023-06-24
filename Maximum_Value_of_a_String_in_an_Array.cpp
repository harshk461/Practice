#include <bits/stdc++.h>
using namespace std;

int maximumValue(vector<string> &strs)
{
    int ans = 0;
    for (auto s : strs)
    {
        ans = max(ans, any_of(begin(s), end(s), [](char c)
                              { return isalpha(c); })
                           ? static_cast<int>(s.length())
                           : stoi(s));
    }
    return ans;
}

int main()
{
    vector<string> arr = {"1", "01", "001", "00001"};
    maximumValue(arr);
    return 0;
}