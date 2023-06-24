#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    unordered_map<int,int> map;
    for(auto i:nums){
        map[i]++;
    }
    int ans=-1;
    for(auto i:map){
        if(i.second==1){
            ans=i.first;
        }
    }
    return ans;
}

int main()
{

    return 0;
}