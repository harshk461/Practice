#include <bits/stdc++.h>
using namespace std;

char slowestKey(vector<int> &releaseTimes, string keysPressed)
{
    int time = releaseTimes[0];
    char ans = keysPressed[0];
    for (int i = 1; i < releaseTimes.size(); i++)
    {
        int temp = releaseTimes[i] - releaseTimes[i - 1];
        if (temp >= time)
        {
            if (temp > time)
            {
                ans = keysPressed[i];
                time = temp;
            }
            else
            {
                ans = max(keysPressed[i], ans);
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {9, 29, 49, 50};
    slowestKey(arr, "cbcd");
    return 0;
}