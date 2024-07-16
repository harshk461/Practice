#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
private:
    int solve(Node *root)
    {
        int left = 0;
        int right = 0;

        if (root == NULL || (root->left == NULL && root->right == NULL))
            return 1;

        else
        {
            if (root->left)
                left = root->left->data;
            if (root->right)
                right = root->right->data;

            if (root->data == left + right && solve(root->left) && solve(root->right))
                return 1;

            return 0;
        }
    }

public:
    int isSumProperty(Node *root)
    {
        return solve(root);
    }
};

int main()
{

    return 0;
}