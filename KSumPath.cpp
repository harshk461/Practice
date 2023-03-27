#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(Node *root, int &count, vector<int> path, int k)
    {
        if (root == NULL)
        {
            return;
        }

        path.push_back(root->data);

        // left path
        solve(root->left, count, path, k);

        // right path
        solve(root->right, count, path, k);

        // check for k sum;
        int size = path.size();
        int sum = 0;
        for (int i = size - 1; i >= 0; i--)
        {
            sum += path[i];
            if (sum == k)
            {
                count++;
            }
        }
        path.pop_back();
    }

    int sumK(Node *root, int k)
    {
        vector<int> path;
        int count = 0;
        solve(root, count, path, k);
        return count;
    }
};

int main()
{

    return 0;
}