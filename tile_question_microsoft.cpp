#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<string> &arr)
    {
        unordered_map<string, int> map;
        for (auto it : arr)
            map[it]++;
        }
};
int main()
{
    vector<string> arr = {"RR", "GR", "RG", "GR", "GR", "RR"};
    Solution s;
    s.solve(arr);
    return 0;
}