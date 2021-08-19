#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};
node *insertionCDLL(node *head, int data)
{
    node *temp = new node(data);
    if (head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
    temp->next = head;
    temp->prev = head->prev;
    temp->prev->next = temp;
    return temp;
    //for last node deletion we
    //just return head instead of temp;
}
int main()
{
    node *head = NULL;
    head = insertionCDLL(head, 40);
    head = insertionCDLL(head, 30);
    head = insertionCDLL(head, 20);
    head = insertionCDLL(head, 10);

    cout << head->prev->data;

    return 0;
}
