#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    unordered_map<int, int> numToNextGreater;
    stack<int> stack;

    for (auto num : nums2)
    {
        while (!stack.empty() && stack.top() < num)
        {
            numToNextGreater[stack.top()] = num;
            stack.pop();
        }
        stack.push(num);
    }

    for (const int num : nums1)
        if (const auto it = numToNextGreater.find(num);
            it != numToNextGreater.cend())
            ans.push_back(it->second);
        else
            ans.push_back(-1);

    return ans;
}

int main()
{

    return 0;
}