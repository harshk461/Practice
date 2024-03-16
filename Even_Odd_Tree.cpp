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
    bool checkOddOrEven(vector<int> &arr, bool dirn)
    {
        // dirn->true->even check
        // dirn->false->odd check

        for (auto it : arr)
        {
            if (it % 2 != 0 && dirn)
                return false;
            if (it % 2 == 0 && !dirn)
                return false;
        }

        return true;
    }

public:
    bool isEvenOddTree(TreeNode *root)
    {
        vector<vector<int>> levelOrder;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> curr;
            for (int i = q.size(); i > 0; --i)
            {
                TreeNode *top = q.front();
                q.pop();

                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);

                curr.push_back(top->val);
            }
            levelOrder.push_back(curr);
        }

        for (auto it : levelOrder)
        {
            for (auto i : it)
                cout << i << " ";
            cout << endl;
        }

        for (int i = 0; i < levelOrder.size(); i++)
        {
            if (i % 2 == 0)
            {
                if (!checkOddOrEven(levelOrder[i], false))
                    return false;
                else
                {
                    // check for strictly increasing
                    int j = 0;
                    while (j < levelOrder[i].size() - 1)
                    {
                        if (levelOrder[i][j + 1] <= levelOrder[i][j])
                            return false;
                        j++;
                    }
                }
            }

            if (i % 2 != 0)
            {
                if (!checkOddOrEven(levelOrder[i], true))
                    return false;
                else
                {
                    // check for strictly decreasing
                    int j = 0;
                    while (j < levelOrder[i].size() - 1)
                    {
                        if (levelOrder[i][j + 1] >= levelOrder[i][j])
                            return false;
                        j++;
                    }
                }
            }
        }

        return true;
    }
};

int main()
{

    return 0;
}