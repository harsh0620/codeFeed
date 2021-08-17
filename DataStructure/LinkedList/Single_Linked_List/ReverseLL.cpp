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
node *reverseLLNaive(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    vector<int> v;

    for (node *curr = head; curr != NULL; curr = curr->next)
    {
        v.push_back(curr->data);
    }

    for (node *curr = head; curr != NULL; curr = curr->next)
    {
        curr->data = v.back();
        v.pop_back();
    }
    return head;
}
node *reverseLLEfficient(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *curr = head;
    node *prev = NULL;

    while (curr != NULL)
    {
        node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

node *reverseLLRecursive1(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *restHead = reverseLLRecursive1(head->next);
    node *restTail = head->next;

    restTail->next = head;
    head->next = NULL;
    return restHead;
}

node *reverseLLRecursive2(node *curr, node *prev)
{
    if (curr == NULL)
    {
        return prev;
    }
    node *nextt = curr->next;
    curr->next = prev;
    return reverseLLRecursive2(nextt, curr);
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

    head = reverseLLRecursive2(head, NULL);
    displayLL(head);

    return 0;
}