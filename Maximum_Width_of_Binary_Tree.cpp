#include <bits/stdc++.h>
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

typedef long long ll;
class Solution
{
public:
    // we have to use BFS to get each level max width
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int ans = 0;
        // Node->{val}
        queue<pair<TreeNode *, int>> q;
        ll ans = 1;
        q.push({root, 0});
        while (!q.empty())
        {
            ll size = q.size();
            ll left = q.front().second;
            ll right = q.back().second;

            ans = max(ans, right - left + 1);
            for (int i = 0; i < size; i++)
            {
                int idx = q.front().second - right;
                TreeNode *node = q.front().first;
                q.pop();

                if (node->left)
                    q.push({node->left, 2 * idx + 1});
                if (node->right)
                    q.push({node->right, 2 * idx + 2});
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}