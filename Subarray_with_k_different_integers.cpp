#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	int solve(vector<int>&nums,int k){
		int n=nums.size();
		unordered_map<int,int> map;

		int i=0,j=0;
		int count=0;

		while(j<n){
			map[nums[j]]++;

			while(i<=j &&  map.size()>k){
				if(--map[nums[i]]==0)
					map.erase(nums[i]);

				i++;
			}

			count+=(j-i+1);
			j++;
		}

		return count;
	}
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};

int main(){
	return 0;
}