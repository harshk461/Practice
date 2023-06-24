#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

// TC-O(n*klogk)
// SC-O(k)
Node<int> *mergeKLists(vector<Node<int> *> &listArray)
{
    priority_queue<Node<int> *, vector<Node<int> *>, compare> minHeap;

    int k = listArray.size();
    if (k == 0)
    {
        return NULL;
    }

    // insert elements to min heap
    for (int i = 0; i < k; i++)
    {
        if (listArray[i] != NULL)
        {
            minHeap.push(listArray[i]);
        }
    }

    Node<int> *head = NULL;
    Node<int> *tail = NULL;

    while (minHeap.size() > 0)
    {
        Node<int> *top = minHeap.top();
        minHeap.pop();

        if (top->next != NULL)
        {
            minHeap.push(top->next);
        }

        if (head == NULL)
        {
            // answer node is empty
            head = top;
            tail = top;
        }
        else
        {
            // insert in LL
            tail->next = top;
            tail = top;
        }
    }

    return head;
}

int main()
{

    return 0;
}