#include <iostream>
#include <vector>
#include <algorithm>
#include "Binarytreenodeclass.h"
#include <queue>
#include <cmath>
using namespace std;

void help(BinaryTreeNode<int> *root, vector<int> ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        ans.push_back(root->data);
        help(root->left, ans);
    }
}

vector<int> leftview(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        vector<int> p;
        return p;
    }
    vector<int> ans;
    help(root,ans);
    return ans;
}

BinaryTreeNode<int> *takeinput()
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

int main()
{
    BinaryTreeNode<int> *root = takeinput();
    vector<int> p;
    p = leftview(root);
    for(int i=0;i<p.size();i++)
    {
        cout << p[i] << " ";
    }
}