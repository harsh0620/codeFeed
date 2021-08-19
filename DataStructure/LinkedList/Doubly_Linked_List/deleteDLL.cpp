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
node *insertBegin(node *head, int x)
{
    node *temp = new node(x);
    temp->next = head;
    if (head != NULL)
    {
        head->prev = temp;
    }
    return temp;
}
node *deleteHeadDLL(node *head)
{

    if (head == NULL)
    {

        return NULL;
    }

    if (head->next == NULL)
    {

        delete head;
        return NULL;
    }
    else
    {

        node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return head;
    }
}
node *deleteLastDLL(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        node *curr = head;
        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }
        node *temp = curr->next;
        curr->next = NULL;
        delete (temp);
        return head;
    }
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
    head = deleteHeadDLL(head);
    head = deleteLastDLL(head);

    displayLL(head);

    return 0;
}
