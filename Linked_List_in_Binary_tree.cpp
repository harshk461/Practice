#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
                                                                                                                                                                                                  *
};

bool isContinousSubPath(TreeNode *root, ListNode *head)
{
    if (head == NULL)
    {
        return true;
    }
    if (root == NULL)
    {
        return false;
    }

    return head->val == root->val &&
           (isContinousSubPath(root->right, head->next) ||
            isContinousSubPath(root->left, head->next));
}

bool isSubPath(ListNode *head, TreeNode *root)
{
    if (root == NULL)
    {
        return false;
    }

    return isContinousSubPath(root, head) ||
           isSubPath(head, root->left) || isSubPath(head, root->right);
}

int main()
{

    return 0;
}