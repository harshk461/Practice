#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void createMapping(int in[], map<int, int> &nodeToIndex, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nodeToIndex[in[i]] = i;
        }
    }
    Node *solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex)
    {
        // base case
        if (index >= n || inOrderStart > inOrderEnd)
        {
            return NULL;
        }

        int element = pre[index];
        index++;
        Node *root = new Node(element);

        int posn = nodeToIndex[element];

        // recursive calls
        root->left = solve(in, pre, index, inOrderStart, posn - 1, n, nodeToIndex);
        root->right = solve(in, pre, index, posn + 1, inOrderEnd, n, nodeToIndex);

        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        int preOrderIndex = 0;
        map<int, int> nodeToIndex;
        // create node to index mapping
        createMapping(in, nodeToIndex, n);
        Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);
        return ans;
    }
};

int main()
{

    return 0;
}
