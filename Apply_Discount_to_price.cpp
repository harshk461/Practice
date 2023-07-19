#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string applyDiscount(string word, int discount)
    {
        if (word[0] != '$')
            return word;

        double val = stod(word.substr(1));
        setprecision(2);
        val = val - ((double)discount * val) / 100.0;

        return "$" + to_string(val);
    }

public:
    string discountPrices(string sentence, int discount)
    {
        vector<string> arr;
        string temp = "";
        for (int i = 0; i < sentence.length(); i++)
        {
            // cout << sentence[i];
            if (sentence[i] == ' ' || sentence[i] == '\0')
            {
                arr.push_back(temp);
                temp = "";
            }
            else
                temp.push_back(sentence[i]);
        }

        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = applyDiscount(arr[i], discount);
        }
        string ans = "";
        for (auto i : arr)
        {
            ans += i;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << (s.discountPrices("1 2 $3 4 $5 $6 7 8$ $9 $10$", 100));
    return 0;
}