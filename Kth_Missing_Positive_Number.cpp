#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        unordered_map<int, int> map;
        for (auto it : arr)
            map[it]++;

        int count = 1;
        int i = 1;
        while (true)
        {
            if (map.find(i) == map.end() && count != k)
                count++;
            else if (map.find(i) == map.end() && count == k)
                return i;
            i++;
        }

        return -1;
    }
};

int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    Solution s;
    cout << s.findKthPositive(arr, 5);
    return 0;
}