#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// brute force
// class Solution
// {
// private:
//     void getLevelSum(TreeNode *root, vector<long long> &sum, int level)
//     {
//         if (root == NULL)
//             return;

//         sum[level] += root->val;
//         getLevelSum(root->left, sum, level + 1);
//         getLevelSum(root->right, sum, level + 1);
//     }

//     int getHeight(TreeNode *root)
//     {
//         if (root->left == NULL && root->right == NULL)
//             return 1;

//         int left = 0;
//         if (root->left != NULL)
//             left = getHeight(root->left);

//         int right = 0;
//         if (root->right != NULL)
//             right = getHeight(root->right);

//         return (max(left, right) + 1);
//     }

// public:
//     long long kthLargestLevelSum(TreeNode *root, int k)
//     {
//         int height = getHeight(root);
//         vector<long long> sumArray(height + 1);
//         getLevelSum(root, sumArray, 0);
//         sort(sumArray.begin(), sumArray.end());
//         reverse(sumArray.begin(), sumArray.end());
//         cout << height << " ";
//         if (k > height)
//             return -1;
//         return sumArray[k - 1];
//     }
// };

// optimised

class Solution
{
private:
    void dfs(TreeNode *root, int level, vector<long long> &LevelSum)
    {
        if (root == NULL)
            return NULL;

        if (LevelSum.size() == level)
        {
            LevelSum.push_back(0);
        }
        LevelSum[level] += root->val;
        dfs(root->left, level + 1, LevelSum);
        dfs(root->right, level + 1, LevelSum);
    }

public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        vector<long long> LevelSum;
        dfs(root, 0, LevelSum);
        if (k > LevelSum.size())
            return -1;

        nth_element(LevelSum.begin(), LevelSum + k - 1, LevelSum.end(), greater<>());
        return LevelSum[k - 1];
    }
};

int main()
{

    return 0;
}