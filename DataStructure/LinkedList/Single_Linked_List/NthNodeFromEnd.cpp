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
node *insertBegin(node *head, int x)
{
    node *temp = new node(x);
    temp->next = head;
    return temp;
}
void printNthNodefromEndNaive(node *head, int k)
{
    if (head == NULL)
    {
        return;
    }
    int count = 0;

    for (node *curr = head; curr->next != NULL; curr = curr->next)
    {
        count++;
    }
    node *temp = head;
    for (int i = 0; i < count - k + 1; i++)
    {
        temp = temp->next;
    }
    cout << temp->data << endl;
}
void printNthNodefromEndEfficient(node *head, int k)
{
    if (head == NULL)
    {
        return;
    }
    node *first = head;

    for (int i = 0; i < k; i++)
    {
        if (first == NULL)
        {
            return;
        }
        first = first->next;
    }
    node *second = head;

    while (first != NULL)
    {
        second = second->next;
        first = first->next;
    }
    cout << second->data << endl;
}
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
int main()
{
    node *head = NULL;
    head = insertBegin(head, 40);
    head = insertBegin(head, 30);
    head = insertBegin(head, 20);
    head = insertBegin(head, 10);

    printNthNodefromEndEfficient(head, 2);
    printNthNodefromEndNaive(head, 2);
    displayLL(head);

    return 0;
}