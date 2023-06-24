#include<bits/stdc++.h>
using namespace std;

int maxCount(vector<int> &banned,int maxSum){
    int ans=0;
    int sum=0;
    unordered_set<int> set(banned.begin(),banned.end());

    for(int i=1;i<=n;i++){
        if(!set.count(i) && sum+i<=maxSum){
            ans++;
            sum+=i;
        }
    }
    return ans;
}

int main()
{

    return 0;
}