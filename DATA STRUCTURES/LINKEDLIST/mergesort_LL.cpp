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
    while(temp!=NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void mergeSorthelper(Node *head, int l, int mid, int r)
{
    Node *temp1 = head;
    int count = 0;
    while(count!=mid)
    {
        temp1 = temp1->next;
        count++;
    }
}

Node *mergeSort(Node *head,int l,int r)
{

    if(l<r)
    {
        int mid = (l+r) / 2;
        mergeSort(head,l,mid);
        mergeSort(head,mid+1,r);

        mergeSorthelper(head,l,mid,r);

    }
    
}

int main()
{
    Node *head = takeinput();
    print(head);
}