#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int n, k;
        vector<int> arr;
        cin >> n >> k;
        for (int j = 0; j < n; j++)
        {
            int ele;
            cin >> ele;
            arr.push_back(ele);
        }
        int index = 0;

        while (k >= 0 && index < n)
        {
            if (arr[index] <= k)
            {
                k -= arr[index];
                index++;
                cout << 1;
            }
            else
            {
                index++;
                cout << 0;
            }
        }
        cout << endl;
    }
    return 0;
}
