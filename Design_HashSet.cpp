#include <bits/stdc++.h>
using namespace std;

class MyHashSet
{
private:
    vector<bool> set;

public:
    MyHashSet() : set(1000001) {}

    void add(int key)
    {
        set[key] = true;
    }

    void remove(int key)
    {
        set[key] = false;
    }

    bool contains(int key)
    {
        return set[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    vector<int>::iterator new_end;
    new_end = remove(arr.begin(), arr.end(), 2x);
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    return 0;
}