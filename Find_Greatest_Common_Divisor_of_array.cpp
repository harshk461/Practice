#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findGCD(vector<int> &nums)
    {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        return __gcd(maxi,mini);
    }
};

int main()
{

    return 0;
}