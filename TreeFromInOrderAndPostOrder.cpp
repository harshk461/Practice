#include <bits/stdc++.h>
using namespace std;

void createMapping(int in[], map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

Node *solve(int in[], int post[], int &index, int inStart, int inOut, int n, map<int, int> &nodeToIndex)
{
    // base case
    if (index < 0 || inStart > inOut)
    {
        return NULL;
    }

    int element = post[index--];
    Node *root = new Node(element);

    int posn = nodeToIndex[element];

    root->right = solve(in, post, index, posn + 1, inOut, n, nodeToIndex);
    root->left = solve(in, post, index, inStart, posn - 1, n, nodeToIndex);

    return root;
}

Node *buildTree(int in[], int post[], int n)
{
    int postOrderIndex = n - 1;

    map<int, int> nodeToIndex;
    createMapping(in, nodeToIndex, n);

    Node *ans = solve(in, post, postOrderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}

int main()
{

    return 0;
}