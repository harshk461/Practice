#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<Node *, pair<int, int>>> q;
        vector<int> ans;

        if (root == NULL)
        {
            return ans;
        }

        // at starting the horizontal distance hd is 0 and level is also 0
        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty())
        {
            pair<Node *, pair<int, int>> temp = q.front();

            Node *frontNode = temp.first;
            q.pop();
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(frontNode->data);

            if (frontNode->left)
            {
                q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
            }

            if (frontNode->right)
            {
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
            }
        }

        for (auto i : nodes)
        {
            for (auto j : i.second)
            {
                for (auto k : j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}