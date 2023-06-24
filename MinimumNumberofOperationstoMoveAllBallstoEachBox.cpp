#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        vector<int> ans;
        int total_boxes = boxes.length();
        int total;
        for (int box = 0; box < total_boxes; box++)
        {
            total = 0;
            for (int box_index = 0; box_index < total_boxes; box_index++)
            {
                total += boxes[box_index] == '1' ? abs(box - box_index) : 0;
            }
            ans.push_back(total);
        }
        return ans;
    }
};

int main()
{

    return 0;
}