#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    int value;
    int freq;
    list<int> it;
};

class LFUCache
{

public:
    LFUCache(int capacity)
    {
        size = capacity;
    }

    int get(int key)
    {
        if (!map[key])
        {
            return -1;
        }

        int freq_val = freq[key];
        freq[key] = freq_val + 1;
        return map[key];
    }

    void put(int key, int value)
    {
        if (!map[key])
        {
            map[key] = value;
            freq[key] = 1;
        }
        else
        {
            map[key] = value;
            freq[key]++;
        }
    }

private:
    
};

int main()
{
    unordered_map<int, int> map;
    map.insert(make_pair(1, 1));
    map.insert(make_pair(2, 2));
    cout << map[3];
    return 0;
}