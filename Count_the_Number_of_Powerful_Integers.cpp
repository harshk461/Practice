#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    set<string> vis;
    int getLen(long long num)
    {
        int len = 0;
        while (num)
        {
            len++;
            num /= 10;
        }

        return len;
    }

    void solve(int empty, string s, int limit, int start, int end)
    {
        if (empty <= 0)
            return;

        for (int i = 0; i <= limit; i++)
        {
            string temp = to_string(i) + s;
            // if (stoll(temp) >= start && stoll(temp) <= end)
            // {
            // cout<<temp<<" ";
            vis.insert(temp);
            solve(empty - 1, temp, limit, start, end);
            // }
        }
    }

    long long brute(long long start, long long finish, int limit, string s)
    {
        int suffix_length = s.length();

        int start_length = getLen(start);
        int end_length = getLen(finish);

        if (suffix_length > end_length)
            return 0;

        if (stoll(s) > finish)
            return 0;

        int rem_length = end_length - suffix_length;
        solve(rem_length, s, limit, start, finish);
        int count = 0;

        set<long long> st;
        for (auto it : vis)
        {
            // cout<<stoll(it)<<" ";
            // if(stoll(it)>=start && stoll(it)<=finish)count++;
            st.insert(stoll(it));
        }

        for (auto it : st)
        {
            if (it >= start && it <= finish)
                count++;
        }
        return count;
    }

    long long recursiveUtil(int index, string &high, int tight, int limit,
                            string &s, vector<vector<long long>> &dp)
    {
        if (index + s.length() >= high.length())
        {
            if (index + s.length() > high.length())
                return 0;

            // number we added in our current possible number is out of limit
            if (!tight)
                return 1;

            string str = high.substr(index);
            if (s > str)
                return 0;

            return 1;
        }

        if (dp[index][tight] != -1)
            return dp[index][tight];

        int new_limit = tight ? high[index] - '0' : 9;

        long long ans = 0;
        for (int i = 0; i <= min(new_limit, limit); i++)
            ans += recursiveUtil(index + 1, high, tight & (i == new_limit), limit, s, dp);

        return dp[index][tight] = ans;
    }

    long long recursive(long long start, long long finish, int limit, string s)
    {
        string low = to_string(start - 1);
        string high = to_string(finish);

        vector<vector<long long>> dp1(16, vector<long long>(2, -1));
        vector<vector<long long>> dp2(16, vector<long long>(2, -1));

        long long ans1 = recursiveUtil(0, high, 1, limit, s, dp1);
        long long ans2 = recursiveUtil(0, low, 1, limit, s, dp2);

        return ans1 - ans2;
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s)
    {

        return recursive(start, finish, limit, s);
    }
};

int main()
{

    return 0;
}