#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    //constructor
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

Node *reverse(Node *head)
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

Node *kReverse(Node *head,int k)
{
    if(k==0 || k==1)
    {
        return head;
    }
    Node *current = head;
    Node *fwd = NULL;
    Node *prev = NULL;

    int count = 0;
    while(count<k && current!=NULL)
    {
        fwd = current->next;
        current->next = prev;
        prev = current;
        current = fwd;
        count++;
    }
    if(fwd!=NULL)
    {
        head->next = kReverse(fwd,k);
    }
    return prev;
}
 
int main()
{
    Node *head = takeinput();
    Node *krev = kReverse(head,3);
    print(krev);
}