#include <bits/stdc++.h>
using namespace std;

// TLE
int arrayProduct(vector<int> arr)
{
    int ans = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        ans *= arr[i];
    }
    return ans;
}
// vector<int> productExceptSelf(vector<int> &nums)
// {
//     vector<int> ans;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         vector<int> left;
//         vector<int> right;
//         for (int j = 0; j < i; j++)
//             left.push_back(nums[j]);
//         for (int k = i + 1; k < nums.size(); k++)
//             right.push_back(nums[k]);
//         long long prod1 = arrayProduct(left) * arrayProduct(right);
//         ans.push_back(prod1);
//         left.clear();
//         right.clear();
//     }
//     return ans;
// }

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    vector<int> left(n, 1);
    vector<int> right(n, 1);

    for (int i = 1; i < n; ++i)
    {
        left[i] = left[i - 1] * nums[i - 1];
    }
    for (int i = n - 2; i >= 0; --i)
    {
        right[i] = right[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < n; ++i)
    {
        ans[i] = left[i] * right[i];
    }
    return ans;
}
int main()
{
    vector<int> arr = {-1, 1, 0, -3, 3, 3};
    vector<int> ans = productExceptSelf(arr);
    // for (auto i : ans)
    //     cout << i << " ";
    set<int> s(arr.begin(), arr.end());
    for (auto i : s)
        cout << i << " ";
    return 0;
}