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
    void dfs(TreeNode *root, int depth, vector<int> &ans)
    {
        if (root == NULL)
            return;
        if (depth == ans.size())
            ans.push_back(root->val);
        dfs(root->right, depth + 1, ans);
        dfs(root->left, depth + 1, ans);
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        // If the tree is empty, return an empty vector.
        if (root == NULL)
            return {};

        // We use a queue to perform level-order traversal (Breadth First Search - BFS).
        queue<TreeNode *> q;
        q.push(root); // Start by adding the root to the queue.
        q.push(NULL); // Add a NULL marker to signify the end of the first level.

        vector<int> ans; // This will store the rightmost nodes of each level.

        // Continue the loop as long as there are elements in the queue.
        while (!q.empty())
        {
            // Extract the front element of the queue.
            auto top = q.front();
            q.pop();

            // If we encounter NULL, it means we have reached the end of a level.
            if (top == NULL)
            {
                // If there are still nodes left in the queue, add another NULL to mark the end of the next level.
                if (!q.empty())
                    q.push(NULL);
            }
            else
            {
                // We check if the next element in the queue is NULL.
                // If it is, this means 'top' is the rightmost node at this level.
                if (!q.empty() && q.front() == NULL)
                    ans.push_back(top->val);

                // Add the left child of the current node to the queue, if it exists.
                if (top->left)
                    q.push(top->left);

                // Add the right child of the current node to the queue, if it exists.
                if (top->right)
                    q.push(top->right);
            }
        }

        // Return the final list of right-side view nodes.
        return ans;
    }
};

int main()
{

    return 0;
}