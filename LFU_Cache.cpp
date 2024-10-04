#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    int value;
    int freq;
    Node *next;
    Node *prev;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->freq = 1;
        this->next = NULL;
        this->prev = NULL;
    }
};

// DLL of same frequency key-value pairs
// in this List we apply logic of LRU nodes near head are new
// and nodes near tail are old ones
class List
{
public:
    int size;
    Node *head;
    Node *tail;

    List()
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addNode(Node *node)
    {
        Node *next = head->next;

        node->next = next;
        node->prev = head;
        head->next = node;
        next->prev = node;
        size++;
    }

    void deleteNode(Node *node)
    {
        Node *prev = node->prev;
        Node *next = node->next;

        prev->next = next;
        next->prev = prev;
        size--;
    }
};

class LFUCache
{
public:
    map<int, Node *> key_to_node;
    // freq->DLL of same frequency keys
    map<int, List *> freq;

    // minimum frequency till now
    int min_freq;

    // current size of cache
    int curr_size;

    // maximum size of cache
    int size;
    LFUCache(int capacity)
    {
        size = capacity;
        min_freq = 0;
        curr_size = 0;
    }

    void UpdateFrequencyListMap(Node *node)
    {
        key_to_node.erase(node->key);
        freq[node->freq]->deleteNode(node);

        // for example we get the key 1 which is the only one node in the list of that frequency
        // which mean we have increase our minimum frequency
        if (node->freq == min_freq && freq[node->freq]->size == 0)
            min_freq++;

        List *nextHigherFrequencyList = new List();

        // we are if freq of curr node+1 exists in the map or not
        if (freq.find(node->freq + 1) != freq.end())
            nextHigherFrequencyList = freq[node->freq + 1];

        node->freq += 1;
        // increase its frequency and push it in the list of higher frequency
        nextHigherFrequencyList->addNode(node);
        // update the frequency list
        freq[node->freq] = nextHigherFrequencyList;
        key_to_node[node->key] = node;
    }

    int get(int key)
    {
        if (key_to_node.find(key) != key_to_node.end())
        {
            Node *node = key_to_node[key];
            int value = node->value;
            UpdateFrequencyListMap(node);
            return value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (size == 0)
            return;

        // if key already exist update its value and update its frequency
        if (key_to_node.find(key) != key_to_node.end())
        {
            Node *node = key_to_node[key];
            node->value = value;
            UpdateFrequencyListMap(node);
        }
        // key doesn't exists
        else
        {
            // size if full
            if (curr_size == size)
            {
                // remove element from the least frequent list
                List *list = freq[min_freq];
                // when we have to remove any key from the min freq list we have to remove the last used node
                // to do this we will use the logic of LRU cache
                key_to_node.erase(list->tail->prev->key);
                freq[min_freq]->deleteNode(list->tail->prev);
                curr_size--;
            }
            // if cache is not full
            curr_size++;
            // if new element is added which means it have frequency 1 and minimum frequency becomes 1
            min_freq = 1;
            List *list_freq = new List();
            // check if list of frequency 1 exists or not
            if (freq.find(min_freq) != freq.end())
                list_freq = freq[min_freq];

            Node *node = new Node(key, value);
            list_freq->addNode(node);
            key_to_node[key] = node;
            freq[min_freq] = list_freq;
        }
    }
};

int main()
{

    return 0;
}