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
    void checkPalindrome(vector<int> &freq, int &ans)
    {
        int odd = 0;
        for (auto it : freq)
            if (it % 2 != 0)
                odd++;
        if (odd <= 1)
            ans++;
    }
    void preorder(TreeNode *root, vector<int> &freq, int &ans)
    {
        if (root->left == NULL && root->right == NULL)
        {
            freq[root->val]++;
            checkPalindrome(freq, ans);
            freq[root->val]--;
            return;
        }

        freq[root->val]++;
        if (root->left)
            preorder(root->left, freq, ans);
        if (root->right)
            preorder(root->right, freq, ans);

        freq[root->val]--;
    }

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        vector<int> freq(10, 0);
        int ans = 0;

        preorder(root, freq, ans);

        return ans;
    }
};

int main()
{

    return 0;
}