#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
    vector<int>pref(n);
    pref[0]=nums[0];
    for(int i=1;i<nums.size();i++){
        pref[i]=nums[i]^pref[i-1];
    }   

    // for(auto it:pref)cout<<it<<" ";
    int k=pow(2,maximumBit)-1;
    for(int i=0;i<n;i++)
        pref[i]^=k;
    reverse(pref.begin(),pref.end());
    return pref;
    }
};


int main()
{

    return 0;
}
