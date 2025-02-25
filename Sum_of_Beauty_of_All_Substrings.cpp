#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
private:
    vector<string> generate(string s)
    {
        vector<string> res;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                string t(s.begin() + i, s.begin() + j + 1);
                if (t.length() >= 1)
                    res.push_back(t);
            }
        }

        return res;
    }

    int brute(string s)
    {
        vector<string> subs = generate(s);
        // for (auto it : subs)
        //     cout << it << " ";
        int ans = 0;

        for (auto word : subs)
        {
            vector<int> freq(26, 0);
            for (auto it : word)
                freq[it - 'a']++;

            int maxi = INT_MIN;
            int mini = INT_MAX;

            for (auto it : freq)
            {
                if (it > 0)
                {
                    maxi = max(maxi, it);
                    mini = min(mini, it);
                }
            }
            // cout<<word<<" "<<maxi<<" "<<mini<<endl;
            ans += (maxi - mini);
        }

        return ans;
    }


    int solve(string s){
        
    }
public:
    int beautySum(string s)
    {
        int ans = brute(s);
        return ans;
    }
};

int main()
{

    return 0;
}