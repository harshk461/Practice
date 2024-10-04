#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void merge(int l, int mid, int r, vector<int> &nums)
    {
        int left_size = mid - l + 1;
        int right_size = r - mid;
        vector<int> left(left_size);
        vector<int> right(right_size);

        int index = l;

        for (int i = 0; i < left_size; i++)
            left[i] = nums[index++];

        for (int i = 0; i < right_size; i++)
            right[i] = nums[index++];

        index = l;
        int i = 0, j = 0;
        while (i < left_size && j < right_size)
        {
            if (left[i] < right[j])
                nums[index++] = left[i++];
            else
                nums[index++] = right[j++];
        }

        while (i < left_size)
            nums[index++] = left[i++];

        while (j < right_size)
            nums[index++] = right[j++];
    }
    void mergeSort(int l, int r, vector<int> &nums)
    {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;
        mergeSort(l, mid, nums);
        mergeSort(mid + 1, r, nums);

        merge(l, mid, r, nums);
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(0, nums.size() - 1, nums);
        return nums;
    }
};

int main()
{

    return 0;
}