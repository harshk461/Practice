#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    int minSwaps(vector<int> arr)
    {
        int n = arr.size();
        vector<pair<int, int>> map(n);
        for (int i = 0; i < n; i++)
        {
            map[i].first = arr[i];
            map[i].second = i;
        }

        sort(map.begin(), map.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (map[i].second == i)
                continue;

            while (map[i].second != i)
            {
                ans++;
                swap(map[i], map[map[i].second]);
            }
        }
        return ans;
    }

public:
    int minimumOperations(TreeNode *root)
    {
        int ans = 0;
        if (!root)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int t = q.size();
            vector<int> v;
            while (t--)
            {
                TreeNode *top = q.front();
                q.pop();

                if (top->left)
                {
                    q.push(top->left);
                    v.push_back(top->left->val);
                }
                if (top->right)
                {
                    q.push(top->right);
                    v.push_back(top->right->val);
                }
            }
            ans += minSwaps(v);
        }
        return ans;
    }
};

int main()
{

    return 0;
}