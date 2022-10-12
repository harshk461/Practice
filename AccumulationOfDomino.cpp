#include <iostream>
using namespace std;

void printArray(int **arr, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << arr[i][j];
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    int **arr[1000][1000];
    int row;
    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < M; j++)
        {
            row = i * M + 1;

            arr[i][j] = row;
        }
        row++;
    }
    printArray(arr, N, M);
}