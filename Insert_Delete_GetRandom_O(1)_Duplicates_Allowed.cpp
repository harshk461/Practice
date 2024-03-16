#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection
{
public:
    unordered_map<int, int> count;
    RandomizedCollection()
    {
    }

    bool insert(int val)
    {
        if (count.find(val) != count.end())
        {
            count[val] = 1;
            return false;
        }
        count[val]++;
        return true;
    }

    bool remove(int val)
    {
        if (count.find(val) == count.end())
            return false;

        count[val]--;
        if (count[val] == 0)
            count.erase(val);
        return true;
    }

    int getRandom()
    {
        vector<int> arr;
        for (auto it : count)
            arr.push_back(it.first);
        return 0;
    }
};

int main()
{

    return 0;
}