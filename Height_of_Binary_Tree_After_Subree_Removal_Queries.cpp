#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int findHeight(TreeNode *root, int level, vector<int> &levelEach, vector<int> &height, vector<int> &maxHeight, vector<int> &secondMaxHeight)
    {

        if (root == nullptr)
            return 0;
        levelEach[root->val] = level;
        height[root->val] = 1 + max(findHeight(root->left, level + 1, levelEach, height, maxHeight, secondMaxHeight),
                                    findHeight(root->right, level + 1, levelEach, height, maxHeight, secondMaxHeight));
        if (maxHeight[level] < height[root->val])
        {
            secondMaxHeight[level] = maxHeight[level];
            maxHeight[level] = height[root->val];
        }
        else if (secondMaxHeight[level] < height[root->val])
        {
            secondMaxHeight[level] = height[root->val];
        }

        return height[root->val];
    }

    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {

        vector<int> level(100001, 0);
        vector<int> height(100001, 0);
        vector<int> maxHeight(100001, 0);
        vector<int> secondMaxHeight(100001, 0);

        findHeight(root, 0, level, height, maxHeight, secondMaxHeight);

        vector<int> res;
        for (int &i : queries)
        {

            int atLevel = level[i];
            if (height[i] == maxHeight[atLevel])
            {
                res.push_back(atLevel + (secondMaxHeight[atLevel] - 1));
            }
            else
            {
                res.push_back(atLevel + (maxHeight[atLevel] - 1));
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}