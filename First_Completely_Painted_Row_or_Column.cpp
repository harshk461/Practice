#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false); // Disable synchronization between C++ and C I/O streams for faster input/output.
    cin.tie(0);                  // Untie cin from cout to avoid flushing cout before every cin operation.
    cout.tie(0);                 // Untie cout from cin to improve output performance.
    return 'c';                  // Return a char to prevent compiler optimizations.
}();

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int n = mat.size();    // Number of rows in the matrix.
        int m = mat[0].size(); // Number of columns in the matrix.

        vector<int> row(n, 0); // Track the count of marked elements in each row.
        vector<int> col(m, 0); // Track the count of marked elements in each column.

        int size = m * n; // Total number of elements in the matrix.

        // Create a mapping of each matrix element to its (row, column) index.
        vector<pair<int, int>> val(size + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                val[mat[i][j]] = {i, j}; // Store the row and column indices for each element.
            }
        }

        // Iterate over the array to mark elements in the matrix.
        for (int i = 0; i < arr.size(); i++)
        {
            auto t = val[arr[i]]; // Retrieve the (row, column) index of the current element.

            int r = t.first;  // Row index of the current element.
            int c = t.second; // Column index of the current element.

            row[r]++; // Increment the count of marked elements in row r.
            col[c]++; // Increment the count of marked elements in column c.

            // Debugging output to track the progress of marking elements.
            cout << "num -> " << arr[i] << " row -> " << r << " col -> " << c << endl;
            cout << row[r] << " " << col[c] << endl;

            // Check if any row or column is completely marked.
            // We check if row[r] == m because there are m elements in a row.
            // Similarly, check if col[c] == n because there are n elements in a column.
            if (row[r] == m || col[c] == n)
                return i; // Return the current index as the first complete index.
        }

        return -1; // Return -1 if no row or column is completely marked.
    }
};

int main()
{

    return 0;
}