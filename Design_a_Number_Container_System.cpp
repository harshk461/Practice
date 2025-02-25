#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class NumberContainers
{
public:
    unordered_map<int, int> mapping;
    unordered_map<int, set<int>> indexes;

    NumberContainers() {}

    void change(int index, int number)
    {
        if (mapping.count(index))
        {
            int curr_number = mapping[index];
            if (curr_number == number)
                return;

            indexes[curr_number].erase(index);
            if (indexes[curr_number].empty())
                indexes.erase(curr_number);
        }
        mapping[index] = number;
        indexes[number].insert(index);
    }

    int find(int number)
    {
        auto it = indexes.find(number);
        return (it == indexes.end() || it->second.empty()) ? -1 : *it->second.begin();
    }
};

int main()
{

    return 0;
}