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
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        vector<int> left = {0, 0};
        vector<int> right = {0, 0};

        int leftAns = 0, rightAns = 0;

        // left tree
        if (root->left != NULL)
        {
            TreeNode *leftNode = root->left;
            left[0]++;
            while (leftNode != NULL)
            {
                if (leftNode->left != NULL)
                    left[0]++;
                if (leftNode->right != NULL)
                    left[1]++;
            }
        }

        // right tree
        if (root->right)
        {
            TreeNode *rightNode = root->right;
            right[1]++;
            while (rightNode != NULL)
            {
                if (rightNode->right)
                    right[1]++;
                if (rightNode->left)
                    right[0]++;
            }
        }

        cout << left[0] << " " << left[1] << endl;
        cout << right[0] << " " << right[1] << endl;

        return 1;
    }
};

int main()
{

    return 0;
}