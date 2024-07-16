#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        // horizontal distance
        // if we go to right side of tree increment the hd valeu and
        // decrement on going left side
        map<int, int> mp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            Node *temp = top.first;
            int hd = top.second; // horizontal distance

            mp[hd] = temp->data;
            if (temp->left)
                q.push({root->left, hd - 1});
            if (temp->right)
                q.push({root->right, hd + 1});
        }

        vector<int> ans;
        for (auto it : mp)
            ans.push_back(it.second);

        return ans;
    }
};

int main()
{

    return 0;
}