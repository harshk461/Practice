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
    vector<TreeNode *> solve(int n, unordered_map<int, list<TreeNode *>> map)
    {
        vector<TreeNode *> arr = map[n];
        if (!arr.empty())
            return arr;

        arr.clear();

        if (n == 1)
            arr.push_back(new TreeNode(0));

        n -= 1; // root
        for (int i = 1; i <= n; i += 2)
        {
            vector<TreeNode *> left = allPossibleFBT(i);
            vector<TreeNode *> right = allPossibleFBT(n - i);
            for (auto i : left)
            {
                for (auto j : right)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = i;
                    root->right = j;
                    arr.push_back(root);
                }
            }
        }
        map[n + 1] = arr;
        return arr;
    }

public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        unordered_map<int, list<int>> map;
        return solve(n, map;)
    }
};

int main()
{

    return 0;
}