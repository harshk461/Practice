#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(int i, int j, string target, string &ans, vector<string> &board)
    {
        if (i >= board.size())
            return;

        if (board[i].find(target[j]) != board.end())
            return;
    }

public:
    string alphabetBoardPath(string target)
    {
        vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
        string ans = "";

        solve(0, 0, target, ans, );
        return target;
    }
};

int main()
{

    return 0;
}