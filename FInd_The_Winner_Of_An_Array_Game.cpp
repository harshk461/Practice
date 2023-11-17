#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &arr, int k)
    {
        int maxi = arr[0];
        for (int i = 1; i < arr.size(); i++)
            maxi = max(maxi, arr[i]);

        int curr = arr[0];
        int wins = 0;

        for (int i = 1; i < arr.size(); i++)
        {
            int op = arr[i];

            if (curr > op)
                wins++;
            else
            {
                curr = op;
                wins = 1;
            }

            if (wins == k || curr == maxi)
                return curr;
        }
        return -1;
    }

public:
    int getWinner(vector<int> &arr, int k)
    {
        if (k >= arr.size())
            return max_element(arr.begin(), arr.end());

        deque<int> dq;
        unordered_map<int, int> map;
        for (auto it : arr)
            dq.push_back(it);

        while (true)
        {
            int a = dq.front();
            dq.pop_front();

            int b = dq.front();
            dq.pop_front();

            if (a > b)
            {
                dq.push_front(a);
                dq.push_back(b);
                map[a]++;
                if (map[a] == k)
                    return a;
            }
            else
            {
                dq.push_front(b);
                dq.push_back(a);
                map[b]++;
                if (map[b] == k)
                    return b;
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}