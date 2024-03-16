#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        map<int, int> mp;
        for (auto it : nums)
            mp[it]++;

        vector<pair<int, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [&](const pair<int, int> &a, const pair<int, int> &b)
             {
            if(a.second==b.second){
                return a.first>b.first;
            } 
            else{
                return a.second<b.second;
            } });
        vector<int> ans;

        for (auto it : v)
        {
            int t = it.second;
            while (t > 0)
            {
                ans.push_back(it.first);
                t--;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}