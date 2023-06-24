#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int key;
    int value;
    Node *next;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};
class MyHashMap
{
public:
    Node *root;
    MyHashMap()
    {
        root = NULL;
    }

    void put(int key, int value)
    {
        Node *temp = root;
        if (temp == NULL)
        {
            temp = new Node(key, value);
            temp->next = root;
            root = temp;
            return;
        }
        bool isPresent = false;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                temp->value = value;
                isPresent = true;
            }
            temp = temp->next;
        }

        if (!isPresent)
        {
            Node *temp2 = new Node(key, value);
            temp2->next = root;
            root = temp;
        }
    }

    int get(int key)
    {
        Node *temp = root;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return temp->value;
            }
        }
        return -1;
    }

    void remove(int key)
    {
        Node *temp = root;
        while (temp != NULL)
        {
            if (temp->next->key == key)
            {
                Node *req = temp->next;
                temp->next = temp->next->next;
                req->next = NULL;
                break;
            }
        }
    }
};

int main()
{

    return 0;
}