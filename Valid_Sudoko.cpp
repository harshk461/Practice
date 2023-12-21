#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool rowCheck(vector<char> &row)
    {
        unordered_map<char, int> map;
        for (auto it : row)
            if (it != '.')
                map[it]++;

        for (auto it : map)
            if (it.second > 1)
                return false;
        return true;
    }

    bool colCheckUtil(vector<char> &col)
    {
        unordered_map<char, int> map;
        for (auto it : col)
            if (it != '.')
                map[it]++;

        for (auto it : map)
            if (it.second > 1)
                return false;
        return true;
    }

    bool colCheck(vector<vector<char>> &board)
    {
        int col = 0;
        vector<char> colArray;
        while (col < 9)
        {
            for (int i = 0; i < 9; i++)
                colArray.push_back(board[i][col]);

            if (!colCheckUtil(colArray))
                return false;
            colArray.clear();

            col++;
        }
        return true;
    }

    bool eachBoxCheck(vector<vector<char>> &board)
    {
        unordered_map<char, int> map;

        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                map.clear();
                for (int x = i; x < i + 3; x++)
                {
                    for (int y = j; y < j + 3; y++)
                    {
                        if (board[x][y] != '.')
                            map[board[x][y]]++;
                        if (map[board[x][y]] > 1)
                            return false;
                    }
                }
            }
            for (auto it : map)
                cout << it.first << " " << it.second << endl;
            cout << endl;
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool colCheckBool = colCheck(board);

        if (!colCheckBool)
            return false;

        for (auto it : board)
        {
            bool rowCheckBool = rowCheck(it);
            if (!rowCheckBool)
                return false;
        }

        // 3x3 Matrix check
        bool eachBox = eachBoxCheck(board);
        if (!eachBox)
            return false;

        return true;
    }
};

int main()
{
    vector<vector<char>> board = {
        {'.', '.', '.', '.', '5', '.', '.', '1', '.'},
        {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
        {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
        {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
        {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
        {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
        {'.', '.', '4', '.', '.', '.', '.', '.', '.'},
    };

    Solution s;
    cout << s.isValidSudoku(board);
    return 0;
}