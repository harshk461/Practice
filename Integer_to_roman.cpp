#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        const vector<pair<int, string>> valueSymbols{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        string ans;
        for (auto i : valueSymbols)
        {
            if (num == 0)
                break;
            while (num >= i.first)
            {
                num -= i.first;
                ans+=i.second;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}