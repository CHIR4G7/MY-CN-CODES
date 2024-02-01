#include <iostream>
#include "Binarytreenodeclass.h"
#include <queue>
using namespace std;

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

void print(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
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
        cout << endl;
    }
}

bool searchinBST(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == k)
    {
        return true;
    }
    else
    {
        if (k > root->data)
        {
            bool small = searchinBST(root->right, k);
            if (small == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            bool small = searchinBST(root->left, k);
            if (small == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

// CHECK BST-1

int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL) // EMPTY SET
    {
        return INT32_MAX; // agar koi set khali hai to sbse chota number int max hi ho skta.
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT32_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool isBST_1(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST_1(root->left) && isBST_1(root->right);
    return output;
}

// CHECK BST-2(IMPROVE TIME COMPLEXITY)

class IsBSTReturn
{
public:
    bool Isbst;
    int minimum;
    int maximum;
};

// IsBSTReturn isBST_2(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//     {
//         IsBSTReturn output;
//         output.Isbst = true;
//         output.minimum = INT64_MAX;
//         output.maximum = INT64_MIN;
//         return output;
//     }

//     IsBSTReturn leftoutput = isBST_2(root->left);
//     IsBSTReturn rightoutput = isBST_2(root->right);
//     int minimum = min(root->data,min(leftoutput.minimum,rightoutput.minimum));
//     int maximum = max(root->data,max(leftoutput.maximum,rightoutput.maximum));
//     bool isbst = (root->data > leftoutput.maximum) && (root->data < rightoutput.minimum) && leftoutput.Isbst && rightoutput.Isbst;
//     IsBSTReturn output;
//     output.Isbst = isbst;
//     output.maximum = maximum;
//     output.minimum = minimum;
// }

// construct BST from sorted array

BinaryTreeNode<int> *contructTreeHelp(int arr[], int si, int ei)
{
   if(si>ei)
   {
    return NULL;
   }
   int mid = (si+ei) / 2;
   BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);
   root->left = contructTreeHelp(arr,si,mid-1);
   root->right = contructTreeHelp(arr,mid+1,ei);
   return root;
}

BinaryTreeNode<int> *constructTree(int arr[], int n)
{
    int si = 0;
    int ei = n - 1;
    return contructTreeHelp(arr, si, ei);
}

void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data >= k1 && root->data <= k2)
    {

        elementsInRangeK1K2(root->left, k1, k2);
        cout << root->data << " ";
        elementsInRangeK1K2(root->right, k1, k2);
    }
    else if (root->data > k2)
    {
        elementsInRangeK1K2(root->left, k1, k2);
    }
    else if (root->data < k1)
    {
        elementsInRangeK1K2(root->right, k1, k2);
    }
}

//BST TO SORTED LINKED LIST
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

void printLL(Node *head)
{
    if(head==NULL)
    {
        return;
    }
    Node *temp = head;
    while(temp!=NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}

/*
is approach me pehle maine inorder traverse krke sorted order me saare nodes ko vector me daal liya, aur fir us vector se linked ,ist bana di
*/

void inorder_path(BinaryTreeNode<int> *root,vector<int> &path)
{
    if(root==NULL)
    {
        return;
    }
    inorder_path(root->left,path);
    path.push_back(root->data);
    inorder_path(root->right,path);
}

Node *contructLinkedList(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    vector<int> path;
    inorder_path(root,path);
    Node *head = NULL;
    Node *tail = NULL;

    for(int i=0;i<path.size();i++)
    {
        if(head==NULL)
        {
            Node *newnode = new Node(path[i]);
            head = newnode;
            tail = newnode;
        }
        else
        {
            Node *newnode = new Node(path[i]);
            tail->next = newnode;
            tail = tail->next;
        }
    }
    return head;
}

//path from root to node
vector<int> *getRootToNodePath(BinaryTreeNode<int> *root, int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftOutput = getRootToNodePath(root->left,data);
    if(leftOutput!=NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int> *rightOutput = getRootToNodePath(root->right,data);
    if(rightOutput!=NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else
    {
        return NULL;
    }
}

void insertDuplicateNode(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left!=NULL)
    {
    BinaryTreeNode<int> *copynode = new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int> *l = root->left;
    root->left = copynode;
    copynode->left = l;
    }
    else
    {
        BinaryTreeNode<int> *copynode = new BinaryTreeNode<int>(root->data);
        root->left = copynode;
    }
    insertDuplicateNode(root->left->left);//cuz immediate left pe to copy attachhogi
    insertDuplicateNode(root->right);
}

void PairSum(BinaryTreeNode<int> *root, int sum)
{
    if(root==NULL)
    {
        return;
    }
    int x = sum - (root->data);//this is what we need to search for.
    if(x < root->data)
    {
        //search in left
        if(searchinBST(root->left,x)==true)
        {
            cout << root->data << " " << x << endl;
        }
    }
    if(x > root->data)
    {
        //search in right
        if(searchinBST(root->right,x)==true)
        {
            cout << root->data << " " << x << endl;
        }
    }

    PairSum(root->left,sum);
    PairSum(root->right,sum);

}

int getLCA_binary_tree(BinaryTreeNode<int> *root,int a,int b)
{
    if(root==NULL)
    {
        return -1;
    }

    //get the paths of two of the ndodes and then print the first coomon values of the vector.
    vector<int> *path_a = getRootToNodePath(root,a);
    vector<int> *path_b = getRootToNodePath(root,b);

   for(int i=0;i<path_a->size();i++)
   {
    for(int j=0;i<path_b->size();j++)
    {
        if(path_a->at(i)==path_b->at(i))
        {
            int a = path_a->at(i);
            return a;
        }
    }
   }
   return -1;
}

//LARGEST BST

class LargestBST
{
    public :
    int maximum;
    int minimum;
    bool isBST;
    int size;

};

LargestBST L_BST_help(BinaryTreeNode<int> *root,int &maxsize)
{
    //base case
    if(root==NULL)
    {
        LargestBST ans;
        ans.maximum = INT32_MAX;
        ans.minimum = INT32_MIN;
        ans.isBST = true;
        ans.size = 0;
        return ans;
    }

    LargestBST left = L_BST_help(root->left,maxsize);
    LargestBST right = L_BST_help(root->right,maxsize);

    LargestBST current;
    current.size = left.size + right.size;
    current.maximum = max(root->data,right.maximum);
    current.minimum = min(root->data,left.minimum);

    if(left.isBST==true && right.isBST && (root->data > left.maximum) && (root->data < right.minimum))
    {
        current.isBST = true;
    }
    else
    {
        current.isBST = false;
    }
//ans update;
if(current.isBST==true)
{
    maxsize = max(maxsize,current.maximum);
}
return current;
}

int LargestBSTSisze(BinaryTreeNode<int>* root)
{
    int maxsize = 0;
    LargestBST temp = L_BST_help(root,maxsize);
    return maxsize;
}


//replace every node with sum of thode greater than and equal to nodes data.

/*
LOGIC - 
hum agar BST ko reverse inorder me travel karien to hum dekhenge ki hame nodes decreasing order me milte rahenge...to hum is fact ka use karenge aur every node we go we upadate the sum by adding that nodes data and then also changing that nodes data and making it equal to the sum, and then moving forward.
*/
int replaceWithLargerNodesSum_helper(BinaryTreeNode<int> *root, int &sum)
{
    if(root==NULL)
    {
        return sum;
    }

    //reverse inorder
    replaceWithLargerNodesSum_helper(root->right,sum);
    sum = sum + root->data;
    root->data = sum;
    replaceWithLargerNodesSum_helper(root->left,sum);
    return sum;
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root)
{
    int sum = 0;
    sum = replaceWithLargerNodesSum_helper(root,sum);
}

//path sum root to leaf

//path from root to leaves



// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int> *root = takeinput();
    print(root);
    // cout << endl;
    // int k1, k2;
    // cin >> k1 >> k2;

    // cout << isBST_1(root);
    // elementsInRangeK1K2(root, 6, 10);
    // vector<int> *getoutput = getRootToNodePath(root,8);
    // for(int i=0;i<getoutput->size();i++)
    // {
    //     cout << getoutput->at(i) << " ";
    // }
    // delete getoutput;
    // replaceWithLargerNodesSum(root);
    Node *bsttoll = contructLinkedList(root);
    printLL(bsttoll);
   
    
}