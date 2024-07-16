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
    void inorder(Node *root, vector<Node *> &arr)
    {
        if (root == NULL)
            return;

        inorder(root->left, arr);
        arr.push_back(root);
        inorder(root->right, arr);
    }

public:
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        vector<Node *> arr;
        inorder(root, arr);

        for (auto it : arr)
            cout << it->key << " ";

        Node *pred = NULL;
        Node *succ = NULL;

        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            if (arr[i]->key == key)
            {
                if (i > 0)
                    pre = arr[i - 1];
                if (i < n - 1)
                    suc = arr[i + 1];
            }
            else if (arr[i]->key < key)
                pre = arr[i];
            else
            {
                suc = arr[i];
                break;
            }
        }
    }
};

int main()
{

    return 0;
}