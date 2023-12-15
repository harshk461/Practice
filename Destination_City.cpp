#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string solve(vector<vector<string>> &paths)
    {
        unordered_set<string> s;
        for (int i = 0; i < paths.size(); i++)
            s.insert(paths[i][0]);

        for (int i = 0; i < paths.size; i++)
        {
            string temp = paths[i][1];
            if (s.find(temp) == s.end())
                return temp;
        }
        return "";
    }

public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_map<string, int> startPath;
        unordered_map<string, int> destPath;
        set<string> start;
        for (auto it : paths)
            start.insert(it[0]);
        for (auto itr = start.begin(); itr != start.end(); itr++)
        {
            string top = *itr;
            startPath[top] = 0;
            destPath[top] = 0;
        }

        for (auto it : paths)
        {
            startPath[it[0]]++;
            destPath[it[1]]++;
        }

        for (auto itr = start.begin(); itr != start.end(); itr++)
        {
            string top = *itr;
            if (startPath[top] == 0 && destPath[top] == 1)
                return top;
        }

        return "";
    }
};

int main()
{

    return 0;
}