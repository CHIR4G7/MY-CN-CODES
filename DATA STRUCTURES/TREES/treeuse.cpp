#include <iostream>
#include "treenode.h"
#include <queue>
using namespace std;

void printTree(TreeNode<int> *root)
{
    // EDGE CASE--WHERE USER SENDS A ROOT WITH NO DATA OR WE CAN SAY ITS NULL

    if (root == NULL)
    {
        return;
    }

    // pehle root ne apna data print kra diya;
    cout << root->data << ":";

    // fir root apne dono children pr one by one gya aur unka data print karadiya
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;

    // fir ab har chote children ya TreeNode ne apne upar recursion call krliya aur ab voapne chilren print karwayega
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

// COMPLICATED METHOD OF GIVING AN INPUT
//  user se input leke mujhe root return karega
TreeNode<int> *takeinput()
{
    // ek root enter karwai uska data liya.
    int rootData;
    cout << "Enter data : ";
    cin >> rootData;

    // fir hamne ek root node banai aur then we asked for number of children of that node
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter number of children : ";
    cin >> n;

    // then for each children we repeated the same process
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeinput();
        root->children.push_back(child);
    }
    return root;
}

// BETTER WAY OR LEVEL WISE INPUT
// ek ek node aati jayegi ham use queue me rkhte jayenge aur ek ek krke queueu se jab nikalenge then we will ask formits h=children and then store them in queue and repeat the same process

TreeNode<int> *takeinputlevelwise()
{
    int rootData;
    cout << "Enter RootData : ";
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    // ab queue bana lo aur usme root ddaldo kyunki iske children ke baare me abhi niche poochenge tab nikal lenge isko
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        // ab mai kaam karunga.jo sbse pehli node hai queue me usko nikala bahar
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter Number of children of : " << front->data << endl;
        int numChild; // number of children of rootnode;
        cin >> numChild;

        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

// printing levelwise
void printlevelwise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pending;
    pending.push(root);

    while (pending.size() != 0)
    {
        TreeNode<int> *front = pending.front();
        pending.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            if (i == 0)
            {
                cout << front->children[i]->data;
            }
            else
            {
                cout << "," << front->children[i]->data;
            }
            pending.push(front->children[i]);
        }
        cout << endl;
    }
}

int numNodes(TreeNode<int> *root)
{
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

int sumofNode(TreeNode<int> *root)
{
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum = sum + (sumofNode(root->children[i]));
    }
    return sum;
}

TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    // maximum root ko maan loiya start me
    int max = root->data;

    // ab upr wale variable data compare krenge aur jaise jaise ham aage badhenge accordingly ek node pointer mantain krke rakhenge aur use vaha shift karate rahenge
    TreeNode<int> *Node = root; // basically it would point to max node at that instance
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *temp = maxDataNode(root->children[i]); // recursive call
        if (temp->data > max)
        {
            max = temp->data;
            Node = temp;
        }
    }
    return Node;
}

int getHeight(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int height = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int childheight = getHeight(root->children[i]);
        if (childheight > height)
        {
            height = childheight;
        }
    }
    return height + 1;
}

void printatlevelk(TreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        printatlevelk(root->children[i], k - 1);
    }
}

int getLeafNodeCount(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->children.size() == 0) // case where only root is there
    {
        return 1;
    }

    else
    {
        int sum = 0;
        for (int i = 0; i < root->children.size(); i++)
        {
            sum = sum + getLeafNodeCount(root->children[i]);
        }
        return sum;
    }
}

void preorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ";
    }
    cout << root->data << " ";
}

void deleteTree(TreeNode<int> *root)
{
    // first delete the children and delete the root.
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

bool isPresent(TreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        bool smallans = isPresent(root->children[i], x);
        if (smallans == true)
        {
            return true;
        }
    }
    if (root->data == x)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int getLargeNodeCount(TreeNode<int> *root, int x)
{

    if (root == NULL)
    {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        count = count + getLargeNodeCount(root->children[i], x);
    }
    if (root->data > x)
    {
        return 1 + count;
    }
    else
    {
        return count;
    }
}

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    // creating a queue to keep track of the nodes whose immediate children are being added
    queue<TreeNode<int> *> pending;
    pending.push(root);
    int maxsum = 0;
    TreeNode<int> *maxNode = root;

    while (pending.size() != 0)
    {
        TreeNode<int> *front = pending.front();
        pending.pop();
        int sum = 0;
        for (int i = 0; i < front->children.size(); i++)
        {
            sum = sum + front->children[i]->data;
            pending.push(front->children[i]);
        }
        if (sum > maxsum)
        {
            maxsum = sum;
            maxNode = front;
        }
        else
        {
            continue;
        }
    }
    return maxNode;
}

bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1->children.size() != root2->children.size())
    {
        return false;
    }
    for (int i = 0; i < root1->children.size(); i++)
    {
        bool small = areIdentical(root1->children[i], root2->children[i]);
        if (small == false)
        {
            return false;
        }
    }
    if (root1->data != root2->data)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// GET NEXT LARGER ELEMENT .

TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return 0;
    }
    TreeNode<int> *ans = NULL; // create an answer to store the current next larger element

    if (root->data > x) // if the current element is greater than x then updating ans
    {
        ans = root;
    }

    for (int i = 0; i < root->children.size(); i++) // calling on its children.
    {
        TreeNode<int> *temp = getNextLargerElement(root->children[i], x);

        // comparison bw ans and temp and then updating.
        if (ans == NULL)
        {
            ans = temp;
        }
        else if (temp != NULL && temp->data < ans->data)
        {
            ans = temp;
        }
    }
    return ans;
}

// recursive
void replacewithdepthhelp(TreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    root->data = k;
    for (int i = 0; i < root->children.size(); i++)
    {
        replacewithdepthhelp(root->children[i], k + 1);
    }
}

void replaceWithDepthValue(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    replacewithdepthhelp(root, 0);
    int k = getHeight(root);
    for (int i = 0; i <= k; i++)
    {
        printatlevelk(root, i);
        cout << endl;
    }
}

// SECOND LARGEST ELEMENT IN AN ARRAY

template <typename T>
class Custom
{
public:
    TreeNode<T> *max;
    TreeNode<T> *sec_max;

    Custom(TreeNode<T> *max, TreeNode<T> *sec_max)
    {
        this->max = max;
        this->sec_max = sec_max;
    }
};

Custom<int> *getSecondLargestNode(TreeNode<int> *root)
{
    if(root==NULL)
    {
        Custom<int> *ans = new Custom<int>(NULL,NULL);
        return ans;
    }
    Custom<int> *ans = new Custom<int>(root,NULL);//custom ans;
    for(int i=0;i<root->children.size();i++)
    {
        Custom<int> *small = getSecondLargestNode(root->children[i]);//calling on to its children
        if(ans->max->data < small->max->data)//if root ka max smaller than child max
        {
            TreeNode<int> *discarded = ans->max;//then creating a discared value
            ans->max = small->max;
            if(discarded->data > ans->sec_max->data)//comparing the discared value with sec_max of root
            {
                ans->sec_max = discarded;
            }
            if(ans->sec_max->data < small->sec_max->data)//comparing the sec max of ans with sec max of child.
            {
                ans->sec_max->data = small->sec_max->data;
            }
        }
    }
    return ans;
}
TreeNode<int> *secondLarger(TreeNode<int> *root)
{
    Custom<int> *ans = getSecondLargestNode(root);
    return ans->sec_max;
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

int main()
{
    /*
    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);

    //connections
    root->children.push_back(node1);
    root->children.push_back(node2);

    cout << endl;
    printTree(root);
    */

    TreeNode<int> *root = takeinputlevelwise();
    // printlevelwise(root);
    cout << endl;
    TreeNode<int> *sec = secondLarger(root);
    cout << sec->data;

    // printatlevelk(root,1);

    // cout << sumofNode(root);
    // cout << maxDataNode(root) << endl;

    // cout << getHeight(root) << endl;
    // cout << getLeafNodeCount(root) << endl;
    // preorder(root);

    // cout << isPresent(root, 7);

    // cout << getLargeNodeCount(root, 35);
    // cout << maxSumNode(root) << endl;
    // replaceWithDepthValue(root);
    // printlevelwise(root);
    // int x;
    // cin >> x;

}