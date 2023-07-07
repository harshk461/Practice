#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// recursive
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return NULL;
        connectTwoNodes(root->left, root->right);
        return root;
    }

private:
    void connectTwoNodes(Node *p, Node *q)
    {
        if (p == nullptr)
            return;
        p->next = q;
        connectTwoNodes(p->left, p->right);
        connectTwoNodes(q->left, q->right);
        connectTwoNodes(p->right, q->left);
    }
};

// iterative
Node *connect(Node *root)
{
    Node *node = root;
    while (node && node->left)
    {
        Node dummy(0);
        for (Node *needle = &dummy; node; node = node->next)
        {
            needle->next = node->left;
            needle = needle->next;
            needle->next = node->right;
            needle = needle->next;
        }
        node = dummy.next;
    }
    return root;
}
int main()
{

    return 0;
}