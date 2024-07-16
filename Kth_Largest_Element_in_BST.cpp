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
    void solve(Node *root, int &ans, int &rank, int k)
    {
        if (root == NULL)
            return;

        solve(root->right, ans, rank, k);
        if (++rank == k)
        {
            ans = root->data;
        }
        solve(root->left, ans, rank, k);
    }

public:
    int kthLargest(Node *root, int K)
    {
        int ans = -1;
        int rank = 0;

        solve(root, ans, rank, k);

        return ans;
    }
};

int main()
{

    return 0;
}