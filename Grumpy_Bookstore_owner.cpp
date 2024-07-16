#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = customers.size();

        int inital_satisified_customer = 0;
        int current_window_satisfied_customer = 0;

        for (int i = 0; i < n; i++)
        {
            if (!grumpy[i])
                inital_satisified_customer += customers[i];
            // elements in our current window(0->minutes)
            else if (i < minutes)
                current_window_satisfied_customer += customers[i];
        }

        int max_satisfied_customer_in_window = current_window_satisfied_customer;

        for (int i = minutes; i < n; i++)
        {
            // increasing window from end
            current_window_satisfied_customer += customers[i] * grumpy[i];
            // decreasing window from start
            current_window_satisfied_customer -= customers[i - minutes] * grumpy[i - minutes];

            max_satisfied_customer_in_window = max(max_satisfied_customer_in_window, current_window_satisfied_customer);
        }

        return inital_satisified_customer + max_satisfied_customer_in_window;
    }
};

int main()
{

    return 0;
}