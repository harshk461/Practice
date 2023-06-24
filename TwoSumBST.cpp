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

void inorder(BinaryTreeNode<int> *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

bool twoSumInBST(BinaryTreeNode<int> *root, int target)
{
    // Write your code here
    vector<int> arr;
    inorder(root, arr);
    int i = 0;
    int j = arr.size() - 1;
    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum == target)
        {
            return true;
        }

        else if (sum > target)
            j--;
        else
            i++;
    }
    return false;
}

int main()
{

    return 0;
}