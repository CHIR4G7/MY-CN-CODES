#include <iostream>
#include "node.cpp"
using namespace std;

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int length(Node *head)
{
    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *reverseht(Node *head, int k)
{
    if (k == 1)
    {
        return head;
    }
    int len = length(head);

    while (len % k == 0)
    {
    }
}

Node *removeNthnidefromlast(Node *head, int i)
{
    if (head == NULL)
    {
        return head;
    }

    int k = length(head) - i; // index from the start;

    if (k != 0)
    {
        Node *temp = head;
        int count = 0;
        while (count < (k - 1))
        {
            temp = temp->next;
            count++;
        }
        Node *temp1 = temp->next;
        Node *temp2 = temp1->next;
        temp->next = temp2;
        delete temp1;
        return head;
    }
    else
    {
        Node *temp = head;
        Node *n = temp->next;
        head = n;
        delete temp;
        return head;
    }
}

int main()
{
    Node *head = takeinput();
    print(head);
    cout << endl;
    int i;
    cin >> i;

    Node *nth = removeNthnidefromlast(head, i);
    print(nth);
}