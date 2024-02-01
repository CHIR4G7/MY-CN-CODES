#include "Binarytreenodeclass.h"
#include <queue>
#include <iostream>

class BST
{
    private :
    BinaryTreeNode<int> *root;

    public :

    BST()//constructor.
    {
        root = NULL;
    }

//INSERT FUNCTION

private :

BinaryTreeNode<int>* inserthelp(BinaryTreeNode<int> *node,int data)
{
    if(node==NULL)
    {
        BinaryTreeNode<int> *newnode = new BinaryTreeNode<int>(data);
        return newnode;
    }
    if(node->data > data)
    {
        node->left = inserthelp(root->left,data);
    }
    else if(node->data < data)
    {
        node->right = inserthelp(root->right,data);
    }
    return node;
}

public :

    void insertData(int data)
    {
        this->root = inserthelp(root,data);
    }


//SEARCH FUNCTION.
    private :

    bool hasDatahelper(BinaryTreeNode<int> *node, int data)
    {
        if(node==NULL)
        {
            return false;
        }
        if(node->data==data)
        {
            return true;
        }
        else if(node->data < data)
        {
            bool small = hasDatahelper(node->right,data);
            if(small==true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(node->data > data)
        {
            bool small = hasDatahelper(node->left,data);
            if(small==true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    public : 

    bool hasData(int data)
    {
        return hasDatahelper(root,data);
    }


//DELETE FUNCTION

private :

BinaryTreeNode<int> *deletehelp(BinaryTreeNode<int> *node,int data)
{
    if(node==NULL)
    {
        return NULL;
    }
     
    if(data > node->data)
    {
        node->right = deletehelp(node->right,data);
    }
    else if(data < node->data)
    {
        node->left = deletehelp(node->left,data);
    }
    else
    {
        if(node->left==NULL && node->right==NULL)
        {
            delete node;
            return NULL;
        }
        else if(node->left==NULL)
        {
            BinaryTreeNode<int> *temp = node->right;//ek temp me node ke right ko sav ekrlia taaki jab node dlt karu to vo na delete hoajye
            node->right = NULL;//node ka right se connection tod diya
            delete node;
            return temp;
        }
        else if(node->right==NULL)
        {
            BinaryTreeNode<int>* temp = node->left;
            node->left = NULL;
            delete node;
            return temp;
        }
        else//dono left right me se koi null nhi hai
        {
            //find replacement - right ka min mera replacement hai.
            BinaryTreeNode<int> *minNode = node->right;
            while(minNode->left!=NULL)
            {
                minNode = minNode->left;
            }
            //after this we have our minimum with us.
            int rightMin = minNode->data;
            node->data = rightMin;
            node->right = deletehelp(node->right,rightMin);//bas usko replace krne ke baad tree se delete krna hai ..aur ye to vaise hi leaf node hai.
            return node;
        }
    }

}

public :
    void deleteData(int data)
    {
        this->root = deletehelp(root,data);
    }

//PRINT FUNCTION


void printhelp(BinaryTreeNode<int>*node)
{
    if(node==NULL)
    {
        return;
    }
    cout << node->data << ":";

    if(node->left!=NULL)
    {
        cout << "L:" << node->left->data << ","; 
    }
    if(node->right!=NULL)
    {
        cout << "R:" << node->right->data;
    }
    printhelp(node->left);
    printhelp(node->right);
}

public :

void print()
{
    printhelp(root);
}

    ~BST()
    {
        delete root;
    }
};