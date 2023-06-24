#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> displayTable(vector<vector<string>> &orders)
{
    unordered_map<pair<int, string>, int> map;
    set<string> dishes;
    vector<vector<string>> ans;
    for (auto i : orders)
    {
        dishes.insert(i[2]);
        pair<int, string> temp = make_pair(stoi(i[1]), i[2]);
        map[temp]++;
    }

    vector<string> dish;
    dish.push_back("Table");
    for (auto i : dishes)
    {
        dish.push_back(i);
    }

    for (auto i : map)
    {
        cout << i.first.second << " " << i.second << endl;
    }

    return ans;
}

int main()
{
    vector<vector<string>> arr = {{"David", "3", "Ceviche"}, {"Corina", "10", "Beef Burrito"}, {"David", "3", "Fried Chicken"}, {"Carla", "5", "Water"}, {"Carla", "5", "Ceviche"}, {"Rous", "3", "Ceviche"}};
    displayTable(arr);
    return 0;
}