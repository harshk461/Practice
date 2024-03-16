#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++)
            for (int j = 0; j < nums1.size(); j++)
                ans ^= (nums1[i] ^ nums2[i]);

        return ans;
    }
};

int main()
{

    return 0;
}