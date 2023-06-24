#include <bits/stdc++.h>
using namespace std;

// two pointer approach
vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> ans;
    int i = 0, j = numbers.size() - 1;
    while (numbers[i] + numbers[j] != target)
    {
        if (numbers[i] + numbers[j] < target)
            ++i;
        else
            --j;
    }

    return {i + 1, j + 1};
}

int main()
{
    vector<int> arr = {2, 25, 75};
    vector<int> ans = twoSum(arr, 100);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}