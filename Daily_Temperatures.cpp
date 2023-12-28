#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> solve(vector<int> &temperatures)
    {
        vector<int> ans(temperatures.size(), 0);
        stack<int> s;
        for (int i = 0; i < temperatures.size(); i++)
        {

            while (!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                int j = s.top();
                s.pop();
                ans[j] = i - j;
            }
            s.push(i);
        }
        return ans;
    }

public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int max_temp = *max_element(temperatures.begin(), temperatures.end());
        int max_temp_index = 0;

        int n = temperatures.size();
        for (int i = 0; i < n; i++)
            if (temperatures[i] == max_temp)
            {
                max_temp_index = i;
                break;
            }
        cout << max_temp_index;
        vector<int> ans(n, 0);
        for (int i = 0; i < max_temp_index; i++)
        {
            int steps = 1;
            int j = i + 1;
            while (j <= max_temp_index)
            {
                cout << temperatures[i] << " " << temperatures[j] << endl;
                if (temperatures[i] < temperatures[j])
                    break;
                steps++, j++;
            }
            ans[i] = steps;
        }

        for (auto it : ans)
            cout << it << " ";
        return solve(temperatures);
    }
};

int main()
{
    Solution s;
    vector<int> arr = {55, 38, 53, 81, 61, 93, 97, 32, 43, 78};
    s.dailyTemperatures(arr);
    return 0;
}