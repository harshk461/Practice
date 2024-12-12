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
    vector<int> brute(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> ans(n, 0);

        if (k == 0)
            return ans;

        if (k > 0)
        {
            for (int i = 0; i < n; i++)
            {
                int sum = 0;
                for (int j = 1; j <= k; j++)
                {
                    cout << (i + j) % n << " ";
                    sum += arr[(i + j) % n];
                }
                cout << endl;
                ans[i] = sum;
            }
        }
        else if (k < 0)
        {
            reverse(arr.begin(), arr.end());
            for (int i = 0; i < n; i++)
            {
                int sum = 0;
                for (int j = 1; j <= abs(k); j++)
                {
                    cout << (i + j) % n << " ";
                    sum += arr[(i + j) % n];
                }
                cout << endl;
                ans[i] = sum;
            }

            reverse(ans.begin(), ans.end());
        }

        return ans;
    }

    vector<int> solve(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> ans(n, 0);

        if (k == 0)
            return ans;

        int l = 0;
        int r = k;
        int sum = 0;

        if (k < 0)
        {
            l = arr.size() - abs(k);
            r = arr.size() - 1;
        }

        for (int i = l; i <= r; i++)
            sum += arr[i];

        for (int i = 0; i < n; i++)
        {
            ans[i] += sum;
            sum -= arr[l % n];
            sum += arr[(r + 1) % n];
            l++;
            r--;
        }

        return ans;
    }

public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        // int n = code.size();
        // vector<int> ans(n, 0);

        // if (k == 0)
        //     return ans;

        // vector<int> prefix(n, 0);
        // prefix[0] = code[0];

        // for (int i = 1; i < n; i++)
        //     prefix[i] = prefix[i - 1] + code[i];

        // if (k > 0)
        // {

        // }
        // else
        // {
        // }

        return brute(code, k);
    }
};

int main()
{
    return 0;
}