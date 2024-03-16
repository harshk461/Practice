#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> ans;
        string s = "123456789";
        for (int i = 0; i < s.length(); i++)
        {
            string x = "";
            for (int j = i; j < s.length(); j++)
            {
                x += s[j];
                int n = stoi(x);
                if (n >= low && n <= high)
                    ans.push_back(n);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}