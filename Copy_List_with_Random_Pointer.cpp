#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
private:
    unordered_map<Node *, Node *> map;

public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
        {
            return head;
        }

        if (const auto it = map.find(head); it != map.cend())
        {
            return it->second;
        }

        Node *newNode = new Node(head->val);
        map[head] = newNode;
        newNode->next = copyRandomList(head->next);
        newNode->next = copyRandomList(head->random);

        return newNode;
    }
};
int main()
{

    return 0;
}