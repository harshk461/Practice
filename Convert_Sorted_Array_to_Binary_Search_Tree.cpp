#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    TreeNode* BuildTree(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return NULL;

        int m = l + (r - l) / 2;
        return new TreeNode(nums[m], BuildTree(nums, l, m - 1), BuildTree(nums, m + 1, r));
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return BuildTree(nums, 0, nums.size() - 1);
    }
};

int main()
{

    return 0;
}