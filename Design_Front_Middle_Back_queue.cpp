#include <bits/stdc++.h>
using namespace std;

class Node
{
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
}

class FrontMiddleBackQueue
{
private:
    int getLen(Node *head)
    {
        int n = 0;
        while (head)
        {
            n++;
            head = head->next;
        }
        return n;
    }

public:
    Node *root;
    FrontMiddleBackQueue()
    {
        root = NULL;
    }

    void pushFront(int val)
    {
        Node *node = new Node(val);
        node->next = root;
        root = node;
    }

    void pushMiddle(int val)
    {
        int mid = getLen(root) / 2;
        Node *mid_node = root;
        while (mid > 1)
        {
            mid_node = mid_node->next;
            mid--;
        }
        Node *next = mid_node->next;
        mid_node->next = new Node(val);
        mid_node->next->next = next;
    }

    void pushBack(int val)
    {
        Node *back = root;
        while (back->next)
        {
            back = back->next;
        }
        back->next = new Node(val);
    }

    int popFront()
    {
        int val = root->data;
        root = root->next;
        return val;
    }

    int popMiddle()
    {
        mid = getLen(root) / 2;
        Node *mid_pop = root;
        while (mid > 1)
        {
            mid_pop = mid_pop->next;
            mid--;
        }
        int ans = mid_pop->next->data;
        mid_pop->next = mid_pop->next->next;
        return ans;
    }

    int popBack()
    {
        Node *pop_back = root;
        while (root->next)
        {
            root = root->next;
        }
        return root->data;
    }
};
int main()
{

    return 0;
}