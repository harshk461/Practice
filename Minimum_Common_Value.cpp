#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int brute(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> st;
        for (auto it : nums1)
            st.insert(it);

        for (auto it : nums2)
            if (st.find(it) != st.end())
                return it;

        return -1;
    }

    int solve(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size())
        {

            if (nums1[i] == nums2[j])
                return nums1[i];

            if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }

        return -1;
    }

public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        return solve(nums1, nums2);
    }
};

int main()
{

    return 0;
}