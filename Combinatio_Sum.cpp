#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        for(int i=0;i<candidates.size();i++){
            if(target%candidates[i]==0){
                int temp=target;
                while(temp>0){
                    ans.push_back(candidates[i]);
                    temp=temp-candidates[i];
                }
            }
        }
    }
};

int main()
{

    return 0;
}