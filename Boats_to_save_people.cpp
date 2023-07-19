#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int ans = 0;
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        for (int i = 0, j = people.size() - 1; i <= j; ++ans)
        {
            int rm = limit - people[j--];
            if (people[i] <= rm)
                i++;
        }
        return ans;
    }
};

int main()
{
    vector<int> ar = {1, 2};
    Solution s;
    cout << s.numRescueBoats(ar, 3);
    return 0;
}