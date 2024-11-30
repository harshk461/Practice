#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
private:
    vector<string> spilt(string word)
    {
        string curr = "";
        vector<string> arr;
        for (int i = 0; i <= word.size(); i++)
        {
            if (word[i] == ' ' || i == word.size())
            {
                arr.push_back(curr);
                curr = "";
            }
            else
                curr += word[i];
        }

        return arr;
    }

public:
    bool isCircularSentence(string sentence)
    {
        vector<string> arr = spilt(sentence);
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i][arr[i].size() - 1] != arr[i + 1][0])
                return false;
        }

        if (arr[n - 1][arr[n - 1].size() - 1] != arr[0][0])
            return false;

        return true;
    }
};

int main()
{

    return 0;
}