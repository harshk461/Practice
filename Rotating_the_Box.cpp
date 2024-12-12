#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false); // Disable synchronization with C-style I/O for faster input/output
    cin.tie(0);                  // Untie cin from cout for faster input/output
    cout.tie(0);                 // Untie cout from cin for faster output
    return 'c';
}();

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int n = box.size();    // Number of rows in the box
        int m = box[0].size(); // Number of columns in the box

        // Step 1: Create a matrix `mat` that will store the rotated version of the box
        vector<vector<char>> mat(m, vector<char>(n));

        // Rotate the box 90 degrees clockwise
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                mat[i][j] = box[j][i]; // Transpose the matrix
        }

        // Step 2: Reverse each row of the matrix `mat` to complete the rotation
        for (int i = 0; i < m; i++)
        {
            reverse(mat[i].begin(), mat[i].end()); // Reverse the elements of each row
        }

        // Step 3: Adjust the positions of stones ('#') to let them "fall down"
        for (int i = 0; i < n; i++) // Loop through each column in the rotated matrix
        {
            for (int j = m - 1; j >= 0; j--) // Start from the bottom of the column
            {
                // If the current cell is empty ('.')
                if (mat[j][i] == '.')
                {
                    int next_row = -1; // Variable to track the next row where the stone can fall

                    // Find the nearest stone ('#') above the current cell
                    for (int k = j - 1; k >= 0; k--)
                    {
                        if (mat[k][i] == '*') // Stop if a wall ('*') is encountered
                            break;
                        if (mat[k][i] == '#') // Stone found
                        {
                            next_row = k;
                            break;
                        }
                    }

                    // If a stone is found, make it fall to the current position
                    if (next_row != -1)
                    {
                        mat[next_row][i] = '.'; // Clear the original position of the stone
                        mat[j][i] = '#';        // Place the stone in the empty cell
                    }
                }
            }
        }

        return mat; // Return the rotated and adjusted matrix
    }
};

int main()
{

    return 0;
}