#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx, mmx, sse2, sse3, sse4")

static const int disableSync = [](void) noexcept -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        multiset<int> window;
        vector<double> result;

        for (int i = 0; i < nums.size(); ++i)
        {
            // Insert the current number into the window
            window.insert(nums[i]);

            // Remove the element that is out of the window
            if (window.size() > k)
            {
                window.erase(window.find(nums[i - k]));
            }

            // Once we have a valid window of size k, calculate the median
            if (window.size() == k)
            {
                auto mid = next(window.begin(), k / 2); // Middle element iterator

                // If k is odd, the median is the middle element
                if (k % 2 == 1)
                {
                    result.push_back(*mid);
                }
                // If k is even, the median is the average of the two middle elements
                else
                {
                    result.push_back((*mid + *prev(mid)) / 2.0);
                }
            }
        }
        return result;
    }
};

int main()
{

    return 0;
}