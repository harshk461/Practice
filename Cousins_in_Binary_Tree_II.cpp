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

class Solution
{
private:
    TreeNode *brute(TreeNode *root)
    {
        if (!root)
            return root;

        // depth->{parent,curr}
        unordered_map<int, vector<pair<TreeNode *, TreeNode *>>> map;

        queue<pair<pair<TreeNode *, TreeNode *>, int>> q;
        q.push({{root, root}, 0});

        while (!q.empty())
        {
            auto top = q.front();
            q.pop();

            TreeNode *parent = top.first.first;
            TreeNode *curr = top.first.second;
            int depth = top.second;

            map[depth].push_back({parent, curr});
            if (curr->left)
                q.push({{curr, curr->left}, depth + 1});
            if (curr->right)
                q.push({{curr, curr->right}, depth + 1});
        }

        for (auto it : map)
        {
            vector<int> sum_of_cousins(it.second.size(), 0);
            for (int i = 0; i < it.second.size(); i++)
            {
                for (int j = 0; j < it.second.size(); j++)
                {
                    if (i != j)
                    {
                        if (it.second[i].first != it.second[j].first)
                        {
                            sum_of_cousins[i] += it.second[j].second->val;
                        }
                    }
                }
            }

            // Modify the current node values with the cousin sum
            for (int i = 0; i < it.second.size(); i++)
            {
                it.second[i].second->val = sum_of_cousins[i];
            }
        }

        return root;
    }

    TreeNode *solve(TreeNode *root)
    {
        if (!root)
            return root;

        queue<TreeNode *> q;
        q.push(root);
        vector<int> level_sum;

        while (!q.empty())
        {
            int curr_level = 0;
            for (int i = q.size(); i > 0; i--)
            {
                TreeNode *curr = q.front();
                q.pop();
                curr_level += curr->val;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            level_sum.push_back(curr_level);
        }
        // for(auto it:level_sum)cout<<it<<" ";
        // cout<<endl;
        // updating values
        // always
        root->val = 0;
        queue<TreeNode *> q1;
        q1.push(root);
        // because we've already changed the level 0 (root level)
        int level = 1;

        while (!q1.empty())
        {
            int n = q1.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = q1.front();
                q1.pop();

                int sibling_sum = 0;
                if (curr->left)
                    sibling_sum += curr->left->val;
                if (curr->right)
                    sibling_sum += curr->right->val;

                if (curr->left)
                {
                    q1.push(curr->left);
                    curr->left->val = level_sum[level] - sibling_sum;
                }
                if (curr->right)
                {
                    q1.push(curr->right);
                    curr->right->val = level_sum[level] - sibling_sum;
                }
            }
            level++;
        }

        return root;
    }

public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        return solve(root);
    }
};

int main()
{

    return 0;
}