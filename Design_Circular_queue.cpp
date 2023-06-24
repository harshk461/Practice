#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue
{
private:
    const int k;
    vector<int> q;
    int size = 0;
    int front = 0;
    int rear;

public:
    MyCircularQueue(int k) : k(k), q(k), rear(k - 1) {}

    bool enQueue(int value)
    {
        if (isFull())
            return false;

        rear = ++rear % k;
        q[rear] = value;
        ++size;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }

        front = ++front % k;
        --size;
        return true;
    }

    int Front()
    {
        return isEmpty() ? -1 : q[front];
    }

    int Rear()
    {
        return isEmpty() ? -1 : q[rear];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == k;
    }
};

int main()
{

    return 0;
}