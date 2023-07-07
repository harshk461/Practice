#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int s)
    {
        if (i < 0 || i == board.size() || j < 0 || j == board[0].size())
            return false;

        if (board[i][j] != word[s] || board[i][j] == '*')
            return false;

        if (s == word.length() - 1)
            return true;

        char ch = board[i][j];
        board[i][j] = '*';
        bool isExist = df(board, word, i + 1, j, s + 1) ||
                       dfs(board, word, i - 1, j, s + 1) ||
                       dfs(board, word, i, j + 1, s + 1) ||
                       dfs(board, word, i, j - 1, s + 1);

        board[i][j] = ch;
        return isExist;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    Solution s;
    cout << s.exist(board, "ABCCED");
    return 0;
}