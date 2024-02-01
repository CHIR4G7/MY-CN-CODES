#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

class Node
{
    public :
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

};

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
 
Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *currnt = head;
    Node *nxt = NULL;

    while (currnt != NULL) 
    {
        nxt = currnt->next;
        currnt->next = prev;

        prev = currnt;
        currnt = nxt;
    }
    return prev;
}

Node *nextNumber(Node *head)
{
    Node *n = reverseLL(head);
    Node *temp = n;
    int carry = 1;
    while(temp!=NULL)
    {
        temp->data = temp->data + carry;
        carry = temp->data / 10;
    }
}

int main()
{
    Node *head = takeinput();
    print(head);
    cout << endl;
}