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
node *insertHead(node *head, int data)
{
    node *temp = new node(data);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;
        int x = temp->data;
        temp->data = head->data;
        head->data = x;
        return head;
    }
}
node *insertLast(node *head, int data)
{
    node *temp = new node(data);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;
        int x = temp->data;
        temp->data = head->data;
        head->data = x;
        return temp;
    }
}
void displayCLL(node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    for (node *i = head->next; i != head; i = i->next)
    {
        cout << i->data << " ";
    }
}
void displayCLL1(node *head)
{
    if (head == NULL)
    {
        return;
    }
    node *i = head;
    do
    {
        cout << i->data << " ";
        i = i->next;

    } while (i != head);
}
int main()
{
    node *head = NULL;
    head = insertHead(head, 40);
    head = insertHead(head, 30);
    head = insertHead(head, 20);
    head = insertHead(head, 10);
    head = insertLast(head, 10);

    displayCLL1(head);

    return 0;
}
