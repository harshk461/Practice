#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet
{
public:
    set<int> s;
    SmallestInfiniteSet()
    {
        for (int i = 1; i <= 1000; i++)
        {
            visited.insert(i);
        }
    }

    int popSmallest()
    {
        int top = *s.begin();
        visited.erase(top);
        return top;
    }

    void addBack(int num)
    {
        if (visited.find(num) == visited.end())
        {
            visited.insert(num);
        }
    }
};

int main()
{

    return 0;
}