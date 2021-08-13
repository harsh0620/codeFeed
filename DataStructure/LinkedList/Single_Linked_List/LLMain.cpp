#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void displayLL(node *head)
{
    if (head == NULL)
    {
        cout << "UNDERFLOW" << endl;
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void RecursiveDisplayLL(node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << (head->data) << " ";
    return RecursiveDisplayLL(head->next);
}
int main()
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    RecursiveDisplayLL(head);
    return 0;
}
