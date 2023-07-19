#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSwap(int num)
    {
        string num_str = to_string(num);
        string temp = num_str;

        for (int i = 0; i < num_str.length(); i++)
        {
            for (int j = i + 1; j < num_str.length(); j++)
            {
                swap(num_str[i], num_str[j]);
                if (stoi(num_str) > stoi(temp))
                    temp = num_str;

                swap(num_str[i], num_str[j]);
            }
        }
        return stoi(temp);
    }
};

int main()
{
    Solution s;
    s.maximumSwap(98368);
    return 0;
}