#include <bits/stdc++.h>
using namespace std;

class node
{
    int data;
    node *left;
    node *right;
    
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void morrisTraversal(node *root)
{
    node *current;
    if (root == NULL)
    {
        return;
    }
    current = root;
    node *pre;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
            {
                pre = pre->right;
            }

            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(2);
    root->left->right = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(5);

    morrisTraversal(root);
    return 0;
}