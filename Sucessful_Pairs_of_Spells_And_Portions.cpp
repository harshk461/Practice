#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int countSucess(vector<int> arr, int num, int target)
    {
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] * num >= target)
                count++;
        return count;
    }

public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        int n = spells.size();
        int m = potions.size();

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int temp = countSucess(potions, spells[i], success);
            ans.push_back(temp);
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        for (int i = 0; i < spells.size(); i++)
        {
            int lowestPotionSpellNeed = success / spells[i];
            // if we get the lowest potion in sorted list then all potions after that index are effective
            int temp = lower_bound(potions.begin(), potions.end(), lowestPotionSpellNeed);
            if (temp >= spells.size())
                ans.push_back(0);
            else
                ans.push_back(temp);
        }

        return ans;
    }
};

int main()
{

    return 0;
}