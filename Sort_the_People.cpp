#include <bits/stdc++.h>
using namespace std;

vector<string> sortPeople(vector<string> &names, vector<int> &heights)
{
    for (int i = 0; i < heights.size(); i++)
    {
        for (int j = 0; j < heights.size(); j++)
        {
            if (heights[j] < heights[i])
            {
                swap(heights[j], heights[i]);
                swap(names[i], names[j]);
            }
        }
    }
    return names;
}

int main()
{

    return 0;
}