#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int oneFourth = arr.size() / 4;
        unordered_map<int, int> map;
        for (auto it : arr)
            map[it]++;

        for (auto it : map)
            if (it.second > oneFourth)
                return it.first;
        return -1;
    }
};

int main()
{

    return 0;
}