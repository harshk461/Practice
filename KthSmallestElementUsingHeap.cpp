#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    // SC-O(k)
    int kthSmallest(int arr[], int l, int r, int k)
    {
        // step 1 is to make a max heap using array
        priority_queue<int> pq;
        for (int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }

        // step 2 is to push remaining r-k elements
        for (int i = k; i <= r; i++)
        {
            if (arr[i] < pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        // step 3 is to return answer
        // and answer is at the top of heap
        return pq.top();
    }
};

int main()
{

    return 0;
}