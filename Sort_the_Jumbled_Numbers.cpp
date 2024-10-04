#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int newNum(int num, map<int, int> &mapping)
    {
        string s = to_string(num);
        for (int i = 0; i < s.length(); i++)
            s[i] = mapping[s[i] - '0'] + '0';

        return stoi(s);
    }

public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        map<int, int> mp;
        for (int i = 0; i < 10; i++)
            mp[i] = mapping[i];

        // vector()-> <new_val,old_val,index>
        vector<vector<int>> new_to_old;
        for (int i = 0; i < nums.size(); i++)
        {
            int new_num = newNum(nums[i], mp);
            new_to_old.push_back({new_num, nums[i], i});
        }

        sort(new_to_old.begin(), new_to_old.end(), [&](const vector<int> &a, const vector<int> &b)
             {
            if(a[0]<b[0])return true; 
            else if(a[0]==b[0])return a[2]<b[2];
            else return false; });

        vector<int> ans;
        for (auto it : new_to_old)
            ans.push_back(it[1]);
        return ans;
    }
};

int main()
{

    return 0;
}