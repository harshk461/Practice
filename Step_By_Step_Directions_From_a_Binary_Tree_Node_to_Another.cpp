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
    void rootToNode(TreeNode *root, int start, int end, string &temp, string &s, string &d)
    {
        if (root == NULL)
            return;

        if (root->val == start)
            s = temp;
        if (root->val == end)
            d = temp;

        temp.push_back('L');
        rootToNode(root->left, start, end, temp, s, d);
        temp.pop_back();

        temp.push_back('R');
        rootToNode(root->right, start, end, temp, s, d);
        temp.pop_back();
    }

public:
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        string s, d, temp;
        rootToNode(root, startValue, destValue, temp, s, d);

        int index = 0;
        for (int i = 0; i < s.size() && i < d.size(); i++)
        {
            if (s[i] == d[i])
                index = i + 1;
            else
                break;
        }

        string ans = "";
        // from root to start node we to travel back to the root then we can travel normally from root to destination
        for (int i = index; i < s.length(); i++)
            ans.push_back('U');
        for (int index; i < d.length(); i++)
            ans.push_back(d[i]);

        return ans;
    }
};

int main()
{

    return 0;
}