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

int main()
{

    return 0;
}