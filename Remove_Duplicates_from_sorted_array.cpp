#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    for (int num : nums)
    {
        if (i < 1 || num > nums[i - 1])
        {
            nums[i++] = num;
        }
    }
    return i;
}

int main()
{

    return 0;
}