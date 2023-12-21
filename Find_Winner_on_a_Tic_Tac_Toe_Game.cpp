#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string tictactoe(vector<vector<int>> &moves)
    {
        if (moves.size() == 9)
            return "Draw";

        vector<int> row(3, 0);
        vector<int> col(3, 0);
        int diag = 0;
        int antidiag = 0;

        for (int i = 0; i < moves.size(); i++)
        {
            int x = moves[i][0];
            int y = moves[i][1];

            if (i % 2 = 0)
            {
                row[x] += 1;
                col[y] += 1;
                if (x == y)
                    diag++;
                if (x == 2 - y)
                    antidiag++;
            }
            else
            {
                row[x] = -1;
                col[y] = -1;
                if (x == y)
                    diag--;
                if (x == 2 - y)
                    antidiag--;
            }
        }
        if (row[x] == 3 || col[y] == 3 || diag == 3 || antidiag == 3)
            return "A";
        if (row[x] == -3 || col[y] == -3 || diag == -3 || antidiag == -3)
            return "B";

        return "";
    }
};

int main()
{
    vector<vector<int>> moves = {{0, 0}, {2, 0}, {1, 1}, {2, 1}, {2, 2}};
    Solution s;
    s.tictactoe(moves);
    return 0;
}