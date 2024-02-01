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

class StackusingLL
{
private:
    Node *head;
    int size;

public:
    StackusingLL()
    {
        head = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        if (size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int element)
    {
        Node *newnode = new Node(element);
        if (head == NULL)
        {
            head = newnode;
            size++;
        }
        else
        {
            newnode->next = head;
            head = newnode;
            size++;
        }
    }

    int pop()
    {
        if (head == NULL)
        {
            return -1;
        }
        else
        {
            Node *pop = head;
            head = head->next;
            int d = pop->data;
            size--;
            delete pop;
            return d;
        }
    }

    int top()
    {
        // Implement the top() function
        if (getSize() == 0)
        {
            return -1;
        }
        else
        {
            return head->data;
        }
    }

    //mergesort
};