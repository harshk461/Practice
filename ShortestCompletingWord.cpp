#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        unordered_map<char, int> m;
        for (auto i : licensePlate)
        {
            if (i >= 'A' || i <= 'Z' || i >= 'a' || i <= 'z')
            {
                m[tolower(i)]++;
            }
        }
        string answer = string(16, 'a');
        for (auto word : words)
        {
            unordered_map<char, int> mn;
            for (auto i : word)
            {
                mn[tolower(i)]++;
            }
            bool cant = false;
            for (char i = 'a'; i <= 'z'; i++)
            {
                if (mn[i] < m[i])
                {
                    cant = true;
                }
            }
            if (!cant)
            {
                if (word.length() < answer.length())
                {
                    answer = word;
                }
            }
        }

        return answer;
    }
};

int main()
{

    return 0;
}