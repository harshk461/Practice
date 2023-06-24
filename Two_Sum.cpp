#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = nums[i];
        for (int j = i + 1; j < nums.size(); j++)
        {
            sum += nums[j];
            cout << sum << endl;
            if (sum == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
            else
            {
                sum -= nums[j];
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr = {3, 3};
    vector<int> ans = twoSum(arr, 6);
    for (auto i : ans)
        cout << i << ' ';
    return 0;
}
