#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    if (n == 0)
        return true;

    for (int i = 0; i < flowerbed.size(); ++i)
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) &&
            (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
        {
            flowerbed[i] = 1;
            if (--n == 0)
                return true;
        }

    return false;
}
int main()
{
    vector<int> arr = {1, 0, 0, 0, 1};
    cout << canPlaceFlowers(arr, 1);
    return 0;
}