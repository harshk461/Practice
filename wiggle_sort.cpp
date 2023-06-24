#include <bits/stdc++.h>
using namespace std;

void wiggleSort(vector<int> &nums)
{
    // sort(nums.begin(), nums.end());
    // int mid = nums.size() / 2;
    // vector<int> n1;
    // vector<int> n2;
    // for (int i = 0; i < mid + 1; i++)
    // {
    //     n1.push_back(nums[i]);
    // }
    // for (int i = mid + 1; i < nums.size(); i++)
    // {
    //     n2.push_back(nums[i]);
    // }

    // for(int i=0;i<nums.size();i++){

    // }
    int n = nums.size();
    auto mid_it = nums.begin() + n / 2;
    nth_element(nums.begin(), mid_it, nums.end());
    int middle = *mid_it;

#define A(i) nums[(1 + (i)*2) % (n | 1)]
    int i = 0, j = 0, k = n - 1;
    while (j <= k)
    {
        if (A(j) > middle)
            swap(A(i++), A(j++));
        else if (A(j) < middle)
            swap(A(j), A(k--));
        else
            ++j;
    }
}

int main()
{
    vector<int> arr = {5, 5, 5, 4, 4, 4, 4};
    wiggleSort(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}