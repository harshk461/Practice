#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
private:
    unordered_map<Node *, Node *> map;

public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;

        if (auto it = map.find(node); it != map.cend())
            return it->second;

        Node *newNode = new Node(node->val);
        map[node] = newNode;

        for (Node *neighbour : node->neighbors)
            newNode->neighbors.push_back(cloneGraph(neighbour));

        return newNode;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;

        unordered_map<Node *, Node *> map;
        Node *root = new Node(node->val, {});

        map[node] = root;
        queue<Node *> q;
        q.push(node);

        while (!q.empty())
        {
            auto top = q.front();
            q.pop();

            for (auto nbr : top->neighbors)
            {
                if (map[nbr] == NULL)
                {
                    map[nbr] = new Node(nbr->val, {});
                    q.push(nbr);
                }

                // at first map[top]=={node}->root
                // root-> it is the pointer of our new graph
                // we are pushing map[nbr] because we currently changed its value
                // after next neighbour comes its value changes
                map[top]->neighbors.push_back(map[nbr]);
            }
        }

        return root;
    }
};

int main()
{

    return 0;
}