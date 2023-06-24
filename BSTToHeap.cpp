#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(Node *root, vector<int> &arr)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

void fillPreorder(Node *root, vector<int> inorder, int *index)
{
    if (root == NULL)
    {
        return;
    }
    root->data = inorder[++*index];

    fillPreorder(root->left, inorder, index);
    fillPreorder(root->right, inorder, index);
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        { // purana level complete ho gya h
            cout << endl;
            if (!q.empty()) // queue still have some child node
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void convertBSTToHeap(Node *root)
{

    vector<int> arr;
    int i = -1;

    inorder(root, arr);
    fillPreorder(root, arr, &i);
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    convertBSTToHeap(root);
    preorder(root);
    return 0;
}