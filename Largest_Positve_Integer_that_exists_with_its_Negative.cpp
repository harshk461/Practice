#include <iostream>
using namespace std;

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        vector<int> positive;
        set<int> negative;
        for (auto it : nums)
            if (it > 0)
                positive.push_back(it);
            else
                negative.insert(it);

        sort(positive.begin(), positive.end());

        int ans = -1;
        for (auto it : positive)
        {
            cout << it << " ";
            if (negative.find(it) != negative.end())
                ans = max(ans, it);
        }

        return ans;
    }
};

int main()
{

    return 0;
}