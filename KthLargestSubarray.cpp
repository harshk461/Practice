#include <bits/stdc++.h>
using namespace std;

// approach 1 TC-O(n^2) SC-O(n^2)
// int getKthLargest(vector<int> &arr, int k)
// {
//     vector<int> ans;
//     int n = arr.size();
//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             sum += arr[j];
//             ans.push_back(sum);
//         }
//     }
//     sort(ans.begin(), ans.end());
//     return ans[ans.size() - k];
// }

// approach 2 using heaps TC-O(n^2) SC-O(k)
void getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> mini;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (mini.size() < k)
            {
                mini.push(sum);
            }
            else
            {
                if (sum > mini.top())
                {
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
}

int main()
{

    return 0;
}