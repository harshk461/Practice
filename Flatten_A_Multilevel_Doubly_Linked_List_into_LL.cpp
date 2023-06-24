#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

// recursive
Node *flatten(Node *head, Node *rest = NULL)
{
    if (head == NULL)
    {
        return rest;
    }

    head->next = flatten(head->child, flatten(head->next, rest));
    if (head->next)
    {
        head->next->prev = head;
    }
    head->child = NULL;
    return head;
}

// iterative
Node *flatten(Node *head)
{
    for (Node *curr = head; curr; curr = curr->next)
    {
        if (curr->child)
        {
            Node *child_node = curr->next;
            curr->next = curr->child;
            curr->child->prev = curr;
            curr->child = NULL;
            Node *tail = curr->next;
            while (tail->next)
            {
                tail = tail->next;
            }
            tail->next = child_node;
            if (child_node != NULL)
            {
                child_node->prev = tail;
            }
        }
    }
    return head;
}

Node *flatten(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        if (curr->child)
        {
            Node *next_part = curr->next;
            curr->next = curr->child;
            curr->child->prev = curr;
            curr->child = NULL;
            Node *tail = curr->next;
            while (tail->next)
            {
                tail = tail->next;
            }
            tail->next = next_part;
            if (next_part != NULL)
            {
                next_part->prev = tail;
            }
        }
        curr = curr->next;
    }

    return head;
}

int main()
{

    return 0;
}