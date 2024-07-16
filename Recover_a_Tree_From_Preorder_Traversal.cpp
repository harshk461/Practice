#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *recoverFromPreorder(string traversal)
    {
        int n = traversal.length();
        stack<pair<TreeNode *, int>> st;
        TreeNode *root = NULL;
        int num_of_dash = 0;
        for (int i = 0; i < n; i++)
        {
            // getting node value and storing it with its level
            if (traversal[i] != '-')
            {
                int num = 0;
                for (; i <= n; i++)
                {
                    if (i == n || traversal[i] == '-')
                        break;
                    else
                        num = num * 10 + (traversal[i] - '0');
                }
                // if we encounter any '-' so we have to decrement the pointer
                i--;

                // getting current level nodes
                while (!st.empty() && num_of_dash != st.top().second + 1)
                    st.pop();

                // if it is empty means its root node
                if (st.empty())
                {
                    root = new TreeNode(num);
                    st.push({root, num_of_dash});
                }
                else
                {
                    // we get the top node in the stack and check if its left is already acquired means we have to fill the right part
                    TreeNode *node = st.top().first;
                    if (node->left == NULL)
                    {
                        node->left = new TreeNode(num);
                        st.push({node->left, num_of_dash});
                    }
                    else
                    {
                        node->right = new TreeNode(num);
                        st.push({node->right, num_of_dash});
                    }

                    // reset the level count
                    num_of_dash = 0;
                }
            }
            else
            {
                // increment level
                num_of_dash++;
            }
        }

        return root;
    }
};

int main()
{

    return 0;
}