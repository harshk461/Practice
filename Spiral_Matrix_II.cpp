#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> arr(n, vector<int>(n, 0));
        int row = n;
        int col = n;

        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row - 1;
        int endingCol = col - 1;
        int total = row * col;

        int count = 1;

        vector<int> ans;
        while (count <= total)
        {

            // staring row
            for (int i = startingCol; count <= total && i <= endingCol; i++)
            {
                arr[startingRow][i] = count;
                count++;
            }
            startingRow++;
            // staring row
            for (int i = startingRow; count <= total && i <= endingRow; i++)
            {
                arr[i][endingCol] = count;
                count++;
            }
            endingCol--;

            // staring row
            for (int i = endingCol; count <= total && i >= startingCol; i--)
            {
                arr[endingRow][i] = count;
                count++;
            }
            endingRow--;

            // staring row
            for (int i = endingRow; count <= total && i >= startingRow; i--)
            {
                arr[i][startingCol] = count;
                count++;
            }
            startingCol++;
        }
        return arr;
    }
};

int main()
{

    return 0;
}