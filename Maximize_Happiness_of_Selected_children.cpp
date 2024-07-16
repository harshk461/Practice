#include <iostream>
using namespace std;

class Solution
{
private:
    long long solve(vector<int> &happiness, int k)
    {
        sort(happiness.begin(), happiness.end());
        reverse(happiness.begin(), happiness.end());
        long long ans = 0;
        for (int i = 0; i < k; i++)
        {
            if (happiness[i] - i <= 0)
                ans += 0;
            else
                ans += happiness[i] - i;
        }

        return ans;
    }

public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        // priority_queue<int> pq;
        // for (auto it : happiness)
        //     pq.push(it);

        // long long ans = 0;
        // ans += pq.top();
        // pq.pop();
        // k--;
        // int turn = 1;
        // while (k > 0)
        // {
        //     int top = pq.top();
        //     pq.pop();

        //     if (top - turn <= 0)
        //         ans += 0;
        //     else
        //         ans += (top - turn);
        //     turn++;
        //     k--;
        // }
        return solve(happiness, k);
    }
};

int main()
{

    return 0;
}