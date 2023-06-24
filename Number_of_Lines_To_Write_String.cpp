#include <bits/stdc++.h>
using namespace std;

vector<int> numberOfLines(vector<int> &widths, string s)
{
    if (s.empty())
    {
        return {0, 0};
    }

    int n = 1;
    int width = 0;
    for (auto i : s)
    {
        int w = widths[i - 'a'];
        width += w;
        if (width > 100)
        {
            n++;
            width = w;
        }
        cout << n << '\t' << width << endl;
    }
    return {n, width};
}

int main()
{
    vector<int> width;
    for (int i = 0; i < 26; i++)
    {
        width.push_back(10);
    }
    vector<int> ans = numberOfLines(width, "abcdefghijklmnopqrstuvwxyz");
    return 0;
}