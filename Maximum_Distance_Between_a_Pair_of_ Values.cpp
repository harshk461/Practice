#include <bits/stdc++.h>
using namespace std;

// O(N^2)
int maxDistance(vector<int> &nums1, vector<int> &nums2)
{
    int maxNum = 0;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = i; j < nums2.size(); j++)
        {
            if (nums1[i] <= nums2[j])
            {
                int dist = j - i;
                if (dist > maxNum)
                {
                    maxNum = dist;
                }
            }
        }
    }
    return maxNum;
}

// O(N)
int maxDistance(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1[nums1.size() - 1] > nums2[0])
    {
        return 0;
    }
    int i = 0, j = 0, max_dist = 0;
    while (i < nums1.size())
    {
        if (j < nums2.size() && nums1[i] <= nums2[j])
        {
            max_dist = max(max_dist, j - i);
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    return max_dist;
}

int main()
{

    return 0;
}