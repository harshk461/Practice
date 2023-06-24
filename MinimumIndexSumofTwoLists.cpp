#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        int minsum = INT_MAX;
        unordered_map<string, int> map;
        for (int i = 0; i < list1.size(); i++)
        {
            map[list1[i]] = i;
        }
        vector<string> ans;
        for (int j = 0; j < list2.size(); j++)
        {

            if (map.count(list2[j]))
            {
                int sum = j + map[list2[j]];
                if (sum < minsum)
                {
                    minsum = sum;
                    ans.clear();
                    ans.push_back(list2[j]);
                }

                else if (sum == minsum)
                {
                    ans.push_back(list2[j]);
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}