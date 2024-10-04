#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool check(int row, int col, vector<vector<int>> &grid)
    {
        int start_i = row;
        int start_j = col;

        int end_i = row + 3;
        int end_j = col + 3;

        vector<int> arr(16, 0);
        set<int> all_sum;

        for (int i = start_i; i < end_i; i++)
        {
            for (int j = start_j; j < end_j; j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
        cout << endl;

        cout << "row sum : ";
        for (int i = start_i; i < end_i; i++)
        {
            int sum = 0;
            for (int j = start_j; j < end_j; j++)
            {
                arr[grid[i][j]] = 1;
                sum += grid[i][j];
            }
            cout << sum << " ";
            all_sum.insert(sum);
        }
        cout << endl;

        // col check
        cout << "Col sum : ";
        for (int j = start_j; j < end_j; j++)
        {
            int sum = 0;
            for (int i = start_i; i < end_i; i++)
            {
                sum += grid[i][j];
            }
            cout << sum << " ";
            all_sum.insert(sum);
        }
        cout << endl;

        int count = 0;
        for (int i = 1; i <= 9; i++)
            if (arr[i])
                count++;

        // diagonal check
        int r_diag = start_i;
        int c_diag = start_j;
        int sum_diag1 = 0;
        for (int i = 0; i < 3; i++)
            sum_diag1 += grid[r_diag++][c_diag++];

        int r_diag2 = start_i;
        int c_diag2 = start_j + 2;
        int sum_diag2 = 0;
        for (int i = 0; i < 3; i++)
            sum_diag2 += grid[r_diag2++][c_diag2--];

        cout << "Diaglonal Sum : ";
        cout << sum_diag1 << " " << sum_diag2 << endl;
        cout << endl;

        all_sum.insert(sum_diag1);
        all_sum.insert(sum_diag2);

        if (count == 9 && all_sum.size() == 1)
            return true;
        return false;
    }

public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        // cout<<n<<" "<<m<<endl;
        if (n < 3 || m < 3)
            return 0;
        int ans = 0;
        for (int i = 0; i <= n - 3; i++)
        {
            for (int j = 0; j <= m - 3; j++)
            {
                // cout<<i<<" "<<j<<endl;
                // check(i,j,grid);
                // cout << endl;
                if (check(i, j, grid))
                    ans++;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}