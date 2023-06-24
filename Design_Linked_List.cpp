#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

class MyLinkedList
{
private:
    int len = 0;
    Node dummy = Node(0);

public:
    int get(int index)
    {
        if (index < 0 || index >= len)
        {
            return -1;
        }
        Node *curr = dummy.next;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        return curr->data;
    }

    void addAtHead(int val)
    {
        Node *head = dummy.next;
        Node *node = new Node(val);
        node->next = head;
        dummy.next = node;
        ++len;
    }

    void addAtTail(int val)
    {
        Node *curr = &dummy;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = new Node(val);
        ++len;
    }

    void addAtIndex(int index, int val)
    {
        if (index > len)
        {
            return;
        }

        Node *curr = &dummy;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }

        Node *temp = curr->next;
        Node *node = new Node(val);
        node->next = temp;
        curr->next = node;
        ++len;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 | index >= len)
        {
            return;
        }

        Node *curr = dummy;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }

        Node *next = curr->next;
        curr->next = next->next;
        --len;
        delete next;
    }
};

int main()
{

    return 0;
}