#include <bits/stdc++.h>
using namespace std;

class NestedIterator
{
private:
    vector<NestedInteger> arr;
    vector<int> flattened;
    int index = 0;

    void flat(vector<NestedInteger> &nestedList)
    {
        for (int i = 0; i < nestedList.size(); i++)
        {
            if (nestedList[i].isInteger())
                flattened.push_back(nestedList[i].getInteger());
            else
                flat(nestedList[i].getList());
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        arr = nestedList;
        flat(arr);
    }

    int next()
    {
        return flattened[index++];
    }

    bool hasNext()
    {
        return index < flattened.size();
    }
};

int main()
{

    return 0;
}