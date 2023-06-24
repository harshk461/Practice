#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *oddPointer = head;
    ListNode *evenPointer = head->next;
    ListNode *even = head->next;
    while (evenPointer != NULL && evenPointer->next != NULL)
    {
        oddPointer->next = oddPointer->next->next;
        oddPointer = oddPointer->next;
        evenPointer->next = evenPointer->next->next;
        evenPointer = evenPointer->next;
    }
    oddPointer->next = even;
    return head;
}

int main()
{

    return 0;
}