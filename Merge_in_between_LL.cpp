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

ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
{
    ListNode *head = NULL;
    ListNode *last = NULL;
    int i = 1;
    ListNode *t = list1;
    while (t != NULL)
    {
        if (i == a)
        {
            head = t;
        }
        if (i = (b + 1))
        {
            last = t->next;
            break;
        }
        t = t->next;
        i++;
    }
    head->next = list2;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = last;
    return list1;
}

ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2){
    ListNode* prev=NULL;
    ListNode* last=list1;
    for(int i=0;i<b;i++){
        if(i==a-1){
            prev=last;
        }
        last=last->next;
    }

    prev->next=list2;
    while(list2->next!=NULL){
        list2=list2->next;
    }
    list2->next=last;
    last->next=NULL;
    return list1;
}

int main()
{
    return 0;
}