#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int countDifference(string org, string test)
    {
        int count = 0;
        int n = org.length();
        for (int i = 0; i < n; i++)
            if (org[i] != test[i])
                count++;

        return count;
    }

public:
    int minOperations(string s)
    {
        int n = s.length();
        string start_with_zero = "";
        string start_with_one = "";
        bool turn = true; // enter 1
        int i = 0;
        while (i < n)
        {
            if (turn)
            {
                start_with_zero += "0";
                start_with_one += "1";
            }
            else
            {
                start_with_zero += "1";
                start_with_one += "0";
            }
            i++;
        }
        return min(countDifference(start_with_one, s), countDifference(start_with_zero, s));
    }
};

int main()
{
    Solution s;
    s.minOperations("0100");
    return 0;
}