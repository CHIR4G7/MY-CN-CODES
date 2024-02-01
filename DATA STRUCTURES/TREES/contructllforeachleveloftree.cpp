#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "nodewithtemp.h"
#include "Binarytreenodeclass.h"
#include <queue>
using namespace std;

BinaryTreeNode<int> *takeinputtree()
{
    int rootData;
    cout << "Enter data : ";
    cin >> rootData;

    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter Left Child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter Right Child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        int n = pendingNodes.size();
        while (n != 0)
        {
            BinaryTreeNode<int> *front = pendingNodes.front();
            pendingNodes.pop();
            cout << front->data << ": ";
            if (front->left != NULL)
            {
                cout << "L" << front->left->data << " ";
                pendingNodes.push(front->left);
            }
            if (front->right != NULL)
            {
                cout << "R" << front->right->data << " ";
                pendingNodes.push(front->right);
            }
            n--;
        }
        cout << endl;
    }
}

void printLL(Node<int> *head)
{
    Node<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void helpercontructLL(BinaryTreeNode<int> *root, vector<Node<int> *> &ans)
{
    if (root == NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        int n = pendingNodes.size();
        Node<int> *head = NULL;
        Node<int> *tail = NULL;
        while (n != 0)
        {
            BinaryTreeNode<int> *front = pendingNodes.front();
            pendingNodes.pop();
            Node<int> *newnode = new Node<int>(front->data);
            if(head==NULL)
            {
                head = newnode;
                tail = newnode;
            }
            else
            {
                tail->next = newnode;
                tail = tail->next;
            }

            //pushing the children in.
            if(front->left!=NULL)
            {
                pendingNodes.push(front->left);
            }
            if(front->right!=NULL)
            {
                pendingNodes.push(front->right);
            }
            n--;
        }
        ans.push_back(head);
    }
}

vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    vector<Node<int> *> ans;
    helpercontructLL(root,ans);
    return ans;
}

int main()
{
    BinaryTreeNode<int> *root = takeinputtree();
    printTree(root);

    vector<Node<int> *> ans;
}