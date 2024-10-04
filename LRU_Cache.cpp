#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    int value;
    Node *prev;
    Node *next;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache
{
public:
    map<int, Node *> mp;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int size;
    LRUCache(int capacity)
    {
        this->size = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *node)
    {
        Node *next = head->next;
        node->next = next;
        node->prev = head;

        head->next = node;
        next->prev = node;
    }

    void deleteNode(Node *node)
    {
        Node *prev = node->prev;
        Node *next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    int get(int key)
    {
        // means key exists
        if (mp.find(key) != mp.end())
        {
            Node *ans = mp[key];
            mp.erase(key);

            deleteNode(ans);
            addNode(ans);

            mp[key] = head->next;

            return ans->value;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *ans = mp[key];
            mp.erase(key);

            deleteNode(ans);
        }

        if (mp.size() == size)
        {

            // delete the node prev to tail because that is the least recently used
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

int main()
{

    return 0;
}