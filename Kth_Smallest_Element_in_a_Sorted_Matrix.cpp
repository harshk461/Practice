#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int brute(vector<vector<int>> &matrix, int k)
    {
        vector<int> arr;
        for (auto it : matrix)
            for (auto i : it)
                arr.push_back(i);

        sort(arr.begin(), arr.end());
        return arr[k - 1];
    }

    int solve(vector<vector<int>> &matrix, int k) {}

public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
    }
};

int main()
{

    return 0;
}