#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> visited;
    int p;
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        int temp;
        cin >> temp;
        visited.insert(temp);
    }
    int q;
    cin >> q;
    vector<int> q_arr;
    for (int i = 0; i < q; i++)
    {
        int temp;
        cin >> temp;
        q_arr.push_back(temp);
        visited.insert(temp);
    }

    if (visited.size() == n)
        cout << "I become the guy." << endl;
    else
        cout << "Oh, my keyboard!" << endl;

    return 0;
}