#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string generate(string curr, int n, unordered_set<string> &s)
    {
        if (curr.size() == n)
        {
            if (s.find(curr) == s.end())
                return curr;
            return "";
        }

        string addZero = generate(curr + "0", n, s);
        if (addZero.size() > 0)
            return addZero;

        return generate(curr + "1", n, s);
    }

public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        int n = nums.size();
        unordered_set<string> s;
        for (auto it : nums)
            s.insert(s);

        return generate("", n, s);
    }
};

int main()
{

    return 0;
}