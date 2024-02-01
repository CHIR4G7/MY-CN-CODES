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
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void printIthNode(Node *head, int i)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (count != i)
        {
            temp = temp->next;
            count++;
        }
        else
        {
            cout << temp->data << endl;
            return;
        }
    }
}

Node *deletenode(Node *head, int pos)
{
    int i = 0;
    Node *current = head;
    if (head == NULL)
        return head;
    if (pos == 0)
    {
        head = current->next;
        delete current;
        return head;
    }
    while (i < pos - 1 && current->next != NULL)
    {
        current = current->next;
        i++;
    }
    if (current->next != NULL)
    {
        Node *temp = current->next->next;
        delete current->next;
        current->next = temp;
    }
    return head;
}

int lengthRec(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return 1 + length(head->next);
}

Node *appendLastNToFirst(Node *head, int n)
{

    if (n == 0)
    {
        return head;
    }
    else if (head == NULL)
    {
        return NULL;
    }
    int i = 0;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }
    Node *current = head;
    // int i = len - n;
    i = i - n;
    while (i)
    {
        // prevtail = current;
        current = current->next;
        i--;
    }
    Node *final_head = current->next;
    current->next = NULL;
    temp->next = head;

    return final_head;
}

Node *removeDuplicates(Node *head)
{
    // Write your code here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    Node *t1 = head;
    Node *t2 = head->next;
    while (t2 != NULL)
    {
        if (t1->data == t2->data)
        {
            Node *a = t2;
            t1->next = t2->next;
            t2 = t2->next;
            delete[] a;
        }
        else
        {
            t1 = t2;
            temp->next = t2;
            temp = temp->next;
            t2 = t2->next;
        }
    }
    return head;
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

bool isPalindrome(Node *head)
{
    // Write your code here
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    Node *newll = head;
    Node *oldll = head;

    while (oldll != NULL && oldll->next != NULL)
    {
        newll = newll->next;
        oldll = oldll->next->next;
    }

    oldll = head;
    newll = reverseLL(newll);
    int flag = 1;

    while (oldll != NULL && newll != NULL)
    {
        if (oldll->data != newll->data)
        {
            flag = 0;
            break;
        }
        oldll = oldll->next;
        newll = newll->next;
    }
    if (flag == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

Node *midPoint(Node *head)
{
    // Write your code here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow->next = NULL;
    return slow;
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    // Write your code here

    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }
    Node *fhead = NULL;
    Node *ftail = NULL;

    if (head1->data > head2->data)
    {
        fhead = head2;
        ftail = head2;
        head2 = head2->next;
    }
    else
    {
        fhead = head1;
        ftail = head1;
        head1 = head1->next;
    }

    while (head2 != NULL && head1 != NULL)
    {
        if (head1->data > head2->data)
        {
            ftail->next = head2;
            head2 = head2->next;
            ftail = ftail->next;
        }
        else
        {
            ftail->next = head1;
            head1 = head1->next;
            ftail = ftail->next;
        }
    }

    if (head1 != NULL)
    {
        ftail->next = head1;
        ftail = ftail->next;
    }
    else
    {
        ftail->next = head2;
        ftail = ftail->next;
    }
    return fhead;
}

Node *evenAfterOdd(Node *head)
{
    Node *oddhead = NULL;
    Node *evenhead = NULL;
    Node *oddtail = NULL;
    Node *eventail = NULL;

    while (head != NULL)
    {
        if (head->data % 2 == 0)
        {
            if (evenhead == NULL)
            {
                evenhead = head;
                eventail = head;
            }
            else
            {
                eventail->next = head;
                eventail = eventail->next;
            }
        }
        else
        {
            if (oddhead == NULL)
            {
                oddhead = head;
                oddtail = head;
            }
            else
            {
                oddtail->next = head;
                oddtail = oddtail->next;
            }
        }
        head = head->next;
    }
    if (oddhead == NULL)
    {
        return evenhead;
    }
    else
    {
        oddtail->next = evenhead;
        eventail->next = NULL;
        return oddhead;
    }
}

Node *skiMdeleteN(Node *head, int M, int N)
{
    int m = M;
    int n = N;
}

Node *swapNodes(Node *head, int i, int j)
{
    if (head == NULL)
    {
        return head;
    }
    Node *current = head;
    Node *s1 = NULL;
    Node *s2 = NULL;
    int k = 0;
    while (k <= i || k <= j)
    {
        if (k == i)
        {
            s1 = current;
        }
        if (k == j)
        {
            s2 = current;
        }
        current = current->next;
        k++;
    }
    int data = s1->data;
    s1->data = s2->data;
    s2->data = data;
    return head;
}

// kReverse

Node *kReverse(Node *head, int k)
{
    if (k == 0 || k == 1)
    {
        return head;
    }
    Node *prev = NULL;
    Node *current = head;
    Node *nxt = NULL;

    int count = 0;
    while (count < k && current != NULL)
    {
        nxt = current->next;
        current->next = prev;

        prev = current;
        current = nxt;
        count++;
    }
    if (nxt != NULL)
    {
        head->next = kReverse(nxt, k);
    }
    return prev;
}

// delete alternate nodes
void deleteAlternateNode(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    Node *current = head;
    Node *nxt = head->next;

    while (nxt != NULL)
    {
        Node *a = nxt;
        nxt = nxt->next;
        delete a;

        current->next = nxt;
        current = nxt;
        nxt = nxt->next;
    }
}

Node *NextLargeNumber(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    head = reverseLL(head);
    int carry = 1;
    Node *current = head;

    while (head != NULL)
    {
        head->data = head->data + carry;
        if (head->data > 9)
        {
            head->data = head->data % 10;
            carry = head->data / 10;
        }
        head = head->next;
    }
    if (carry != 0)
    {
        Node *c = new Node(carry);
        head->next = c;
        head = reverseLL(head);
        return head;
    }
    else
    {
        return head;
    }
}

Node *findlongestlist(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* temp = head;
    int maxlen = INT_MIN;
    Node* maxi = NULL;
    int count;

    while(temp!=NULL)
    {
        Node* temp2 = temp;
        count = 0;
        while(temp2!=NULL && temp2->data<=temp->data)
        {
            count++;
            temp2 = temp2->next;
        }
        if(count>maxlen)
        {
            maxlen = count;
            maxi = temp;
        }
        temp = temp->next;
    }
    cout << maxlen << endl;
    Node *t1 = maxi;
    while(maxlen>1)
    {
        t1 = t1->next;
        maxlen--;
    }
    t1->next = NULL;
    return maxi;
}
Node* doubleit(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* revh = reverseLL(head);
    Node* revt = reverseLL(head);
    int carry = 0;

    // while(revt!=NULL)
    // {
    //     int currv = revt->data;
    //     // currv = 2*currv;
    //     cout << currv << " ";
    //     revt = revt->next;
    // }
    // cout << endl;
    return revh;
}

int main()
{
    Node *head = takeinput();
    print(head);
    cout << endl;
    // deleteAlternateNode(head);
    // head = NextLargeNumber(head);
    // print(head);
    // Node *mid = midPoint(head);
    // cout << mid->next->data;
    // Node* t = findlongestlist(head);
    Node* t = doubleit(head);
    print(t);
}