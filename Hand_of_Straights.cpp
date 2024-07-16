#include <iostream>
using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
            return false;

        // sort(hand.begin(), hand.end());
        map<int, int> count; // sorted way
        for (auto it : hand)
            count[it]++;

        for (auto it = count.begin(); it != count.end(); ++it)
        {
            if (it->second > 0)
            {
                int c = it->second;
                for (int i = 0; i < groupSize; i++)
                {
                    if (count[it->first + i] < c)
                        return false;

                    count[it->first + i] -= c;
                }
            }
        }

        return true;
    }
};

int main()
{

    return 0;
}