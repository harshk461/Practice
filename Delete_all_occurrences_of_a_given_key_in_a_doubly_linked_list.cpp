#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

class Solution
{
public:
    void deleteAllOccurOfX(struct Node **head, int x)
    {
        Node *current = *head; // Dereference the double pointer to get the actual head node

        while (current != NULL)
        {
            Node *next = current->next;

            if (current->data == x)
            {
                // Unlink the current node
                if (current->prev != NULL)
                    current->prev->next = current->next;
                if (current->next != NULL)
                    current->next->prev = current->prev;

                // Update the head pointer if the current node is the head
                if (current == *head)
                    *head = current->next;

                // Free memory of the current node
                delete current;
            }

            current = next;
        }
    }
};

int main()
{

    return 0;
}