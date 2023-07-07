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

Node *connect(Node *root)
{
    Node *node = root;

    while (node)
    {
        Node dummy(0);

        // needle children
        for (Node *needle = &dummy; node; node = node->next)
        {
            if (node->left)
            {
                needle->next = node->left;
                needle = needle->next;
            }

            if (node->right)
            {
                needle->next = node->right;
                needle = needle->next;
            }
        }
        node = dummy.next;
    }
    return root;
}

int main()
{

    return 0;
}