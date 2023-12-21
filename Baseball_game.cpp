#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        vector<int> record;
        for (auto it : operations)
        {
            if (it == "+")
            {
                int sum = record[record.size() - 1] + record[record.size() - 2];
                record.push_back(sum);
            }
            else if (it == "D")
                record.push_back(2 * record[record.size() - 1]);
            else if (it == "C")
                record.pop_back();
            else
                record.push_back(stoi(it));

            for (auto j : record)
                cout << j << " ";
            cout << endl;
        }

        return accumulate(record.begin(), record.end(), 0);
    }
};

int main()
{
    Solution s;
    vector<string> arr = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    s.calPoints(arr);
    return 0;
}