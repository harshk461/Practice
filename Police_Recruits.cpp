#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int count_case = 0;
    int count_police = 0;
    int curr_case = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            if (count_police <= curr_case)
                count_case++;
            else
                count_police--;
        }
        else
            count_police += arr[i];
    }
    cout << count_case;
    return 0;
}