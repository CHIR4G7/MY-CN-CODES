#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class QueueusingLL
{
private:
    int size;
    Node *head;
    Node *tail;

public:
    QueueusingLL()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize()
    {

        return size;
    }
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(int data)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
            size++;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
            size++;
        }
    }
    int dequeue()
    {

        if (head == NULL)
        {
            return -1;
        }
        else
        {
            Node *de = head;
            head = head->next;
            size--;
            int deint = de->data;
            delete[] de;
            return deint;
        }
    }

    int front()
    {

        if (head == NULL)
        {
            return -1;
        }
        else
        {
            return head->data;
        }
    }
};