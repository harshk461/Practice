#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> arr, int start, int end)
{
    int max = arr[end];
    for (int i = start; i < end; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
// O(N*N)
vector<int> replaceElements(vector<int> &arr)
{
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
        {
            ans.push_back(-1);
            break;
        }
        int max = findMax(arr, i + 1, arr.size() - 1);
        cout << max << " ";
        ans.push_back(max);
    }
    // reverse(ans.begin(), ans.end());
    return ans;
}

// O(N)

vector<int> replaceElements(vector<int> &arr)
{
    vector<int> ans;
    int maxR = -1;
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = maxR;
        if (arr[i] > maxR)
        {
            maxR = arr[i];
        }
        ans.push_back(temp);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr = {17, 18, 5, 4, 6, 1};
    vector<int> ans = replaceElements(arr);
    // for (auto i : ans)
    // {
    //     cout << i << " ";
    // }
    return 0;
}