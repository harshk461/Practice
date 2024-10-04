#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        unordered_map<int, int> map;
        for (auto it : arr)
            map[it]++;

        for (auto it : target)
            map[it]--;

        for (auto it : map)
            if (it.second != 0)
                return false;
        return true;
    }
};

int main()
{

    return 0;
}