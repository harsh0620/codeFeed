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
int searchLL(node *head, int x)
{
    node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return pos;
        }
        else
        {
            pos++;
            temp = temp->next;
        }
    }
    return -1;
}

int recurSearchLL(node *head, int x)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == x)
    {
        return 1;
    }
    else
    {
        int res = recurSearchLL(head->next, x);
        if (res == -1)
        {
            return -1;
        }
        else
        {
            return (res + 1);
        }
    }
}
int main()
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);
    cout << recurSearchLL(head, 30) << endl;

    return 0;
}
