#include <bits/stdc++.h>
using namespace std;
class TreeNode<int>
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
/*
Approach 1 is to store inorder of both trees and then merge those inorder array
 and then create an bst from that array
TC-O(n+m) SC-O(n+m)

void inorder(TreeNode<int> *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

vector<int> mergeArray(vector<int> a, vector<int> b)
{
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0;
    int k = 0;
    while (i < a.size() && j < b.size())
    {

        if (a[i] < b[j])
        {
            ans[k++] = a[i];
            i++;
        }
        else
        {
            ans[k++] = b[j];
            j++;
        }
    }

    while (i < a.size())
    {
        ans[k++] = a[i];
        i++;
    }

    while (j < b.size())
    {
        ans[k++] = b[j];
        j++;
    }

    return ans;
}

TreeNode<int> *inorderToBST(int s, int e, vector<int> arr)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = s + (e - s) / 2;
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);
    root->left = inorderToBST(s, mid - 1, arr);
    root->right = inorderToBST(mid + 1, e, arr);

    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // step 1 is to store the inorder of both trees
    vector<int> tree1;
    vector<int> tree2;

    inorder(root1, tree1);
    inorder(root2, tree2);

    // step2 is to merge two sorted array
    vector<int> mergedArray = mergeArray(tree1, tree2);

    // create bst from inorder
    TreeNode<int> *root = inorderToBST(0, mergedArray.size() - 1, mergedArray);

    return root;
}

Approach 2 is to flatten the bst into linked list and then create bst from that
LL
TC-O(n+m) but SC-O(h1+h2) h1/2=height of tree 1/2
steps are
1. Convert BST into Linked List
2. Merge Two sorted Linked List
3.Sorted Linked List to BST
*/

/*
step 1 convert BST to doubly Linked list TC-O(n) and SC-O(H)
algo-
1.convert right side to LL using recursion (head of LL)
2.root->right=head and head->left=root
3. head=root

4. convert left subtree into LL
*/
/*
step 2 merge 2 LL in a sorted way

step3 is to create bst from 2 sorted LL
*/
int main()
{

    return 0;
}