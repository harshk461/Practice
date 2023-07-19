#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if array has 2 elements
    // whose sum is equal to the given value
    bool hasArrayTwoCandidates(int arr[], int n, int x)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
            map[arr[i]]++;

        for (int i = 0; i < n; i++)
        {
            map[arr[i]]--;
            if (map[x - arr[i]] >= 1)
                return true;
            map[arr[i]]++;
        }
        return false;
    }
};

int main()
{

    return 0;
}