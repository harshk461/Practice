#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
public:
    unordered_set<int> arr;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (arr.find(val) != arr.end())
            return false;
        arr.push_back(val);
        return true;
    }

    bool remove(int val)
    {
        if (arr.find(val) == arr.end())
            return false;
        arr.erase(val);
        return true;
    }

    int getRandom()
    {
        int n = arr.size();
        int index = rand() % n;
        return *next(arr.begin(),index);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    RandomizedSet r;
    r.insert(2);
    return 0;
}