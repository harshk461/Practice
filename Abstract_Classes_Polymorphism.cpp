#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int value;
    int key;
    Node(Node *p, Node *n, int k, int val) : prev(p), next(n), key(k), value(val) {};
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache
{

protected:
    map<int, Node *> mp;            // map the key to the node in the linked list
    int cp;                         // capacity
    Node *tail;                     // double linked list tail pointer
    Node *head;                     // double linked list head pointer
    virtual void set(int, int) = 0; // set function
    virtual int get(int) = 0;       // get function
};
#include <bits/stdc++.h>

class LRUCache : protected Cache
{
public:
    int size;

    LRUCache(int size)
    {
        this->cp = size;
        this->size = 0;
        this->tail = new Node(-1, -1);
        this->head = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node *node)
    {
        Node *next = node->next;
        Node *prev = node->prev;

        prev->next = next;
        next->prev = prev;
    }

    void addNode(Node *node)
    {
        Node *next = head->next;

        node->next = next;
        node->prev = head;
    }

    void set(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            deleteNode(node);

            Node *temp = new Node(key, value);
            addNode(temp);
            mp[key] = temp;
        }
        else
        {
            Node *temp = new Node(key, value);
            addNode(temp);
            mp[key] = temp;
            size++;
            if (size > cp)
            {
                deleteNode(tail->prev);
                mp.erase(tail->prev->key);
            }
        }
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        else
            return mp[key]->value;
    }
};

int main()
{
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "get")
        {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set")
        {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}
