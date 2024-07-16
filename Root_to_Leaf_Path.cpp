#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
private:
    void dfs(Node *root, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (root->left == NULL && root->right == NULL)
        {
            temp.push_back(root->data);
            ans.push_back(temp);

            return;
        }

        if (root->left)
        {
            temp.push_back(root->data);
            dfs(root->left, temp, ans);
            temp.pop_back();
        }

        if (root->right)
        {
            temp.push_back(root->data);
            dfs(root->right, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> Paths(Node *root)
    {
        vector<int> temp;
        vector<vector<int>> ans;
        dfs(root, temp, ans);

        return ans;
    }
};

int main()
{

    return 0;
}