#include <iostream>
using namespace std;

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
private:
    int dfs(TreeNode *root, int &moves)
    {
        if (root == NULL)
            return 0;

        int left = dfs(root->left, moves);
        int right = dfs(root->right, moves);

        moves += abs(left) + abs(right);

        return (root->val - 1) + left + right;
    }

public:
    int distributeCoins(TreeNode *root)
    {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }
};

int main()
{

    return 0;
}