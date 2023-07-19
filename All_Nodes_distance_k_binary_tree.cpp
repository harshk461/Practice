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
    void makeParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track, TreeNode *target)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->left)
            {
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent_track;
        makeParents(root, parent_track, target);

        unordered_map<TreeNode *, bool> vis;
        queue<TreeNode *> queue;
        queue.push(target);
        vis[target] = true;
        int curr_level = 0;
        while (!queue.empty())
        {
            int size = queue.size();
            if (curr_level++ == k)
                break;
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = queue.front();
                queue.pop();
                if (curr->left && !vis[curr->left])
                {
                    queue.push(curr->left);
                    vis[curr->left] = true;
                }
                if (curr->right && !vis[curr->right])
                {
                    queue.push(curr->right);
                    vis[curr->right] = true;
                }
                if (parent_track[curr] && !vis[parent_track[curr]])
                {
                    queue.push(parent_track[curr]);
                    vis[parent_track[curr]] = true;
                }
            }
        }

        vector<int> result;
        while (!queue.empty())
        {
            TreeNode *curr = queue.front();
            queue.pop();
            result.push_back(curr->val);
        }
        return result;
    }
};

int main()
{

    return 0;
}