#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class MyCircularDeque
{
public:
    vector<int> arr;
    int k;
    MyCircularDeque(int k)
    {
        this->k = k;
    }

    bool insertFront(int value)
    {
        if (arr.size() == k)
            return false;
        reverse(arr.begin(), arr.end());
        arr.push_back(value);
        reverse(arr.begin(), arr.end());

        return true;
    }

    bool insertLast(int value)
    {
        if (arr.size() == k)
            return false;
        arr.push_back(value);
        return true;
    }

    bool deleteFront()
    {
        if (arr.size() == 0)
            return false;
        reverse(arr.begin(), arr.end());
        arr.pop_back();
        reverse(arr.begin(), arr.end());
        return true;
    }

    bool deleteLast()
    {
        if (arr.size() == 0)
            return false;
        arr.pop_back();
        return true;
    }

    int getFront()
    {
        return !arr.empty() ? arr[0] : -1;
    }

    int getRear()
    {
        return !arr.empty() ? arr[arr.size() - 1] : -1;
    }

    bool isEmpty()
    {
        return arr.size() == 0;
    }

    bool isFull()
    {
        return arr.size() == k;
    }
};

class Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Linked List Approach
class MyCircularDeque
{
public:
    int length;
    int k;
    Node *head;
    Node *tail;
    MyCircularDeque(int k)
    {
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;

        this->length = 0;
        this->k = k;
    }

    bool insertFront(int value)
    {
        if (length == k)
            return false;

        Node *node = new Node(value);
        Node *next = head->next;

        head->next = node;
        node->next = next;
        node->prev = head;
        length++;
        return true;
    }

    bool insertLast(int value)
    {
        if (length == k)
            return false;

        Node *prev = tail->prev;
        Node *node = new Node(value);

        node->prev = prev;
        node->next = tail;
        tail->prev = node;
        length++;

        return true;
    }

    bool deleteFront()
    {
        if (length == 0)
            return false;

        Node *next = head->next;
        Node *node = next->next;
        head->next = node;
        node->prev = head;
        length--;

        return true;
    }

    bool deleteLast()
    {
        if (length == 0)
            return false;

        Node *prev = tail->prev;
        Node *node = prev->prev;

        tail->prev = node;
        node->next = tail;
        length--;

        return true;
    }

    int getFront()
    {
        if (length == 0)
            return -1;

        Node *node = head->next;
        return node->data;
    }

    int getRear()
    {
        if (length == 0)
            return -1;

        Node *node = tail->prev;
        return node->data;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    bool isFull()
    {
        return length == k;
    }
};

int main()
{

    return 0;
}