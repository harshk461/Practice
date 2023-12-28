#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> board = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
    };
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int i = s[0] - 'a'; // col
        int j = s[1] - '0'; // row
        for (int row = 0; row < 8; row++)
        {
            string temp = "";
            temp.push_back(row + 'a');
            temp.push_back(j + '0');
            if (temp != s)
                cout << temp << endl;
        }
        for (int col = 0; col < 8; col++)
        {
            string temp = "";
            temp.push_back(i + 'a');
            temp.push_back((col + 1) + '0');
            if (temp != s)
                cout << temp << endl;
        }
    }
    return 0;
}