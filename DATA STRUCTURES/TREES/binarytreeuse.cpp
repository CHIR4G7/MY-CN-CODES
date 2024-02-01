#include <iostream>
#include "Binarytreenodeclass.h"
#include <queue>
#include <cmath>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

void printTree(BinaryTreeNode<int> *root)
{
    // in case of binaary trees base case necessary
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";

    if (root->left != NULL)
    {
        cout << "L" << root->left->data << " ";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data << " ";
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

// NOOB METHOD
BinaryTreeNode<int> *takeinput()
{
    int rootData;
    cout << "Enter Data : ";
    cin >> rootData;

    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeinput();
    BinaryTreeNode<int> *rightChild = takeinput();

    root->left = leftChild;
    root->right = rightChild;
    return root;
}

// ACTUAL WAY
BinaryTreeNode<int> *takeinputLevelWise()
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

// printing level wise
void printLevelWise(BinaryTreeNode<int> *root)
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

int countNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int right = countNodes(root->right);
    int left = countNodes(root->left);

    return 1 + right + left;
}

bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->left != NULL)
    {
        bool left = isNodePresent(root->left, x);
        if (left == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (root->right != NULL)
    {
        bool right = isNodePresent(root->right, x);
        if (right == true)
        {
            return true;
        }
        else
        {
            return false;
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

int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return 1 + max(left, right);
}

void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    BinaryTreeNode<int> *temp = root->left; // jist sawp nodes and call for chilfren nodes
    root->left = root->right;
    root->right = temp;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}

// inorder traversal(left->root->right)
void inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// preorder traversal(root before nodes)
void preorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// postorder traversal(nodes before root)
void postOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// contructing a tree from inorder and preorder

BinaryTreeNode<int> *bTreeHelper(int *preorder, int *inorder, int ino_s, int ino_e, int pre_s, int pre_e)
{
    if (pre_s > pre_e || ino_s > ino_e)
    {
        return NULL;
    }

    int rootVal = preorder[pre_s];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootVal);
    int k = 0; // ye vo index hai jahan pr inordere me root milega (jis index par).
    for (int i = ino_s; i <= ino_e; i++)
    {
        if (inorder[i] == rootVal)
        {
            k = i;
            break;
        }
    }
    root->left = bTreeHelper(preorder, inorder, ino_s, k - 1, pre_s + 1, pre_s + (k - ino_s));
    root->right = bTreeHelper(preorder, inorder, k + 1, ino_e, pre_s + (k - ino_s) + 1, pre_e);
    return root;
}
BinaryTreeNode<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
{
    int ino_s = 0;
    int ino_e = inLength - 1;
    int pre_s = 0;
    int pre_e = preLength - 1;
    return bTreeHelper(preorder, inorder, ino_s, ino_e, pre_s, pre_e);
}

/*

diameter of a tree--this way has a time complexity of O(n^2) becaus we call once of height and then for diamete we again call fro height./

int diameter(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return 1+  max(option1,option2,option3);
}

*/

// to decrease the time complxity of this above problem we need the function to return height and diameter at the same time
// we will use inbuilt pair class
pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int ld = leftAns.second; // diameter will come after height
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> ans;
    ans.first = height;
    ans.second = diameter;
    return ans;
}

pair<int, int> getminandmax(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> ans;
    ans.first = root->data;
    ans.second = root->data;

    if (root->left != NULL)
    {
        pair<int, int> small = getminandmax(root->left);
        if (small.first < ans.first)
        {
            ans.first = small.first;
        }
    }
    if (root->right != NULL)
    {
        pair<int, int> small = getminandmax(root->right);
        if (small.second > ans.second)
        {
            ans.second = small.second;
        }
    }
    return ans;
}

// ist approach
// this approach has a tie complexity of O(n*height of tree).

/*
bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }

//induction
    int lefth = height(root->left);
    int righth = height(root->right);

    if((lefth-righth)<=1 && (lefth-righth)>=-1)
    {
        return true;
    }
    else
    {
        return false;
    }

//hypothesis
    if(root->left!=NULL)
    {
        bool small = isBalanced(root->left);
        if(small==true)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    if(root->right!=NULL)
    {
        bool small = isBalanced(root->right);
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
*/

// 2nd approach

pair<int, bool> isBalancedhelp(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, bool> p;
        p.first = 0;
        p.second = false;
        return p;
    }
    pair<int, bool> ans;

    // recursive calls
    pair<int, bool> left = isBalancedhelp(root->left);
    pair<int, bool> right = isBalancedhelp(root->right);

    // inducion steps

    // cheking height;
    int lh = left.first;
    int rh = right.first;

    // balanced
    if ((lh - rh) >= 1 && (lh - rh) <= -1)
    {
        left.second = true;
        right.second = true;
    }
    else
    {
        left.second = false;
        right.second = false;
    }

    ans.first = max(lh, rh) + 1;
    ans.second = (left.second) && (right.second);
    return ans;
}

bool isBalanced(BinaryTreeNode<int> *root)
{
    pair<int, bool> p = isBalancedhelp(root);
    return p.first;
}

// 3 rd approach which is in O(N) time complexity
// in this approach we tend to find the height of the subtrees and return it to te parent only if it is balanced otherwise we are going to return -1, which signifies that the tree si not balanced.

int height_custom(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = height_custom(root->left);
    int r = height_custom(root->right);

    if (l == -1 || r == -1)
    {
        return -1;
    }
    if (abs(l - r) > 1)
    {
        return -1;
    }
    return 1 + max(l, r);
}

bool isBalanced_3(BinaryTreeNode<int> *root)
{
    if (height_custom(root) == -1)
    {
        return false;
    }
    return true;
}

void printLevelWisecn(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        int n = pendingNodes.size();
        while (n != 0)
        {
            BinaryTreeNode<int> *front = pendingNodes.front();
            pendingNodes.pop();
            cout << front->data << " ";
            if (front->left != NULL)
                pendingNodes.push(front->left);
            if (front->right != NULL)
                pendingNodes.push(front->right);
            n--;
        }
        cout << "\n";
    }
}

BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return NULL;
    }
    if (root->left != NULL)
    {
        root->left = removeLeafNodes(root->left);
    }
    if (root->right != NULL)
    {
        root->right = removeLeafNodes(root->right);
    }
    return root;
}

// CONTRUCT LINKED LIST FOR EACH LEVEL OF A TREE
// another file created... usme kiya hai

int countNonLeafNodes(BinaryTreeNode<int> *root)
{

    // Code here
    if (root == NULL)
    {
        return 0;
    }
    int count = 0;

    // dono me se kisi ek side bhi agar child hai to count +1 kardo.
    if (root->left != NULL || root->right != NULL)
    {
        count += 1;
    }
    if (root->left != NULL)
    {
        count = count + countNonLeafNodes(root->left);
    }
    if (root->right != NULL)
    {
        count = count + countNonLeafNodes(root->right);
    }
    return count;
}

// left view

void left(BinaryTreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    ans.push_back(root->data);
    left(root->left, ans);
    if (root->right != NULL)
    {
        root = root->right;
        left(root->left, ans);
    }
}

vector<int> leftView(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    left(root, ans);
    return ans;
}

// ZIG ZAG

/*
void zigzagorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    int k = 1;

    while (pendingNodes.size() != 0 && k != height(root))
    {
        int n = pendingNodes.size();
        while (n != 0)
        {
            BinaryTreeNode<int> *front = pendingNodes.front();
            pendingNodes.pop();
            cout << front->data << " ";

            if (k % 2 != 0)
            {
                if (front->right != NULL)
                {
                    pendingNodes.push(front->right);
                }
                if (front->left != NULL)
                {
                    pendingNodes.push(front->left);
                }
            }
            else
            {
                if (front->left != NULL)
                {
                    pendingNodes.push(front->left);
                }
                if (front->right != NULL)
                {
                    pendingNodes.push(front->right);
                }
            }
            n--;
        }
        k++;
        cout << "\n";
    }

}
*/

void zigzagorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    bool flag = true; // true for staright;

    while (pendingNodes.size() != 0)
    {
        int n = pendingNodes.size();

        while (n != 0)
        {
            BinaryTreeNode<int> *front = pendingNodes.front();
            pendingNodes.pop();
            cout << front->data << " ";
            if (flag == true)
            {
                if (front->right != NULL)
                {
                    pendingNodes.push(front->right);
                }
                if (front->left != NULL)
                {
                    pendingNodes.push(front->left);
                }
            }
            else
            {
                if (front->left != NULL)
                {
                    pendingNodes.push(front->left);
                }
                if (front->right != NULL)
                {
                    pendingNodes.push(front->right);
                }
            }
            n--;
        }
        if (flag == true)
        {
            flag = false;
        }
        else
        {
            flag = true;
        }
        cout << endl;
    }
}

void reverse_inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    reverse_inorder(root->right);
    cout << root->data << " ";
    reverse_inorder(root->left);
}

int level(BinaryTreeNode<int> *root, int p)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<BinaryTreeNode<int> *> pending;
    pending.push(root);
    int level = 0;

    while (pending.size() != 0)
    {
        int n = pending.size();

        while (n != 0)
        {
            BinaryTreeNode<int> *front = pending.front();
            pending.pop();

            if (front->data == p)
            {
                return level;
            }

            if (front->left != NULL)
            {
                pending.push(front->left);
            }
            if (front->right != NULL)
            {
                pending.push(front->right);
            }
            n--;
        }
        level += 1;
    }
    return level;
}

void dfs(BinaryTreeNode<int> *root, unordered_map<BinaryTreeNode<int> *, bool> &visited, vector<int> &ans)
{
    ans.push_back(root->data);
    visited[root] = true;

    if (root->left != NULL)
    {
        if (visited[root->left] == false)
        {
            dfs(root->left, visited, ans);
        }
        else
        {
            dfs(root->right, visited, ans);
        }
    }
    if (root->right != NULL)
    {
        if (visited[root->right] == false)
        {
            dfs(root->right, visited, ans);
        }
        else
        {
            dfs(root->left, visited, ans);
        }
    }
}

vector<int> dfs_tree(BinaryTreeNode<int> *root)
{
    vector<int> v;
    if (root == NULL)
    {
        return v;
    }
    unordered_map<BinaryTreeNode<int> *, bool> visited;
    dfs(root, visited, v);
    return v;
}

// flatten

void preorder(BinaryTreeNode<int> *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    v.push_back(root->data);
    preorder(root->left);
    preorder(root->right);
}

void flattentoLL(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    vector<int> v;
    preorder(root, v);

    BinaryTreeNode<int> *ll = NULL;
    BinaryTreeNode<int> *tail = NULL;

    for (int i = 0; i < v.size(); i++)
    {
        BinaryTreeNode<int> *n = new BinaryTreeNode<int>(v[i]);
        if (ll == NULL)
        {
            ll = n;
            tail = n;
        }
        else
        {
            tail->right = n;
            tail = tail->right;
            tail->left = NULL;
        }
    }
}

int deepestLeavesSum(BinaryTreeNode<int> *root)
{
    int depth = height(root);
    queue<BinaryTreeNode<int> *> pending;
    pending.push(root);
    int level = 0;
    int sum = 0;

    while (level != depth - 1 && pending.size() != 0)
    {
        int n = pending.size();

        while (n != 0)
        {
            BinaryTreeNode<int> *front = pending.front();
            pending.pop();
            if (front->left != NULL)
            {
                pending.push(root->left);
            }
            if (front->right != NULL)
            {
                pending.push(root->right);
            }
            n--;
        }
        level++;
    }
    while (pending.size() != 0)
    {
        sum += pending.front()->data;
        pending.pop();
    }
    return sum;
}

// bst tp gst

void inorder_new(BinaryTreeNode<int> *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }
    inorder_new(root->left, in);
    in.push_back(root->data);
    inorder_new(root->right, in);
}

void suffixsum(vector<int> &nums)
{
    int n = nums.size();
    int suffix = nums[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        nums[i] = nums[i] + suffix;
        suffix = nums[i];
    }
}

BinaryTreeNode<int> *gst(vector<int> &nums, int si, int ei)
{
    if (si > ei)
    {
        return NULL;
    }
    int mid = (si + ei) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(nums[mid]);
    root->left = gst(nums, si, mid - 1);
    root->right = gst(nums, mid + 1, ei);
    return root;
}

BinaryTreeNode<int> *bsttoGst(BinaryTreeNode<int> *root)
{
    vector<int> in;
    inorder_new(root, in);
    suffixsum(in);
    return gst(in, 0, in.size() - 1);
}

// avg of tree (TLE)
pair<int, int> avgtree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return make_pair(0, 0);
    }
    pair<int, int> p;
    p.first = root->data;
    p.second = 1;

    if (root->left != NULL)
    {
        p.first += avgtree(root->left).first;
        p.second += avgtree(root->left).second;
    }
    if (root->right != NULL)
    {
        p.first += avgtree(root->right).first;
        p.second += avgtree(root->right).second;
    }
    return p;
}

int averageOfSubtree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = 0;
    pair<int, int> p = avgtree(root);
    int avg = ((p.first) / (p.second));
    if (avg == root->data)
    {
        count++;
    }
    if (root->left != NULL)
    {
        count += averageOfSubtree(root->left);
    }
    if (root->right != NULL)
    {
        count += averageOfSubtree(root->right);
    }
    return count;
}

//k the largest sum

long long kthlargest(BinaryTreeNode<int> *root,int k)
{
    queue<BinaryTreeNode<int> *> pending;
        priority_queue<long long> sums;
        int level = 0;
        pending.push(root);
        
        while(pending.size()!=0)
        {
            long long sum = 0;
            level++;
            int n = pending.size();
            while(n!=0)
            {
                BinaryTreeNode<int> *front = pending.front();
                pending.pop();
                sum+=front->data;
                if(front->left!=NULL)
                {
                    pending.push(front->left);
                }
                if(front->right!=NULL)
                {
                    pending.push(front->right);
                }
                n--;
            }
            sums.push(sum);
        }
        int size = sums.size();
        if(size<k)
        {
            return -1;
        }
        while((k-1)>0)
        {
            sums.pop();
            k--;
        }
        return sums.top();
}

//sum of root to leaf numbers


//code to get all paths in a binary Tree.
void sum(BinaryTreeNode<int> *root,vector<int> &a,vector<vector<int> > &nums)
{
    if(root==NULL)
    {
        nums.push_back(a);
        return;
    }

    a.push_back(root->data);
    
    if((root->left==NULL && root->right==NULL) || (root->right==NULL && root->left==NULL))
    {
        nums.push_back(a);
        return;
    }

    if(root->left!=NULL)
    {
        sum(root->left,a,nums);
        a.pop_back();
    }
    
    if(root->right!=NULL)
    {
        sum(root->right,a,nums);
        a.pop_back();
    }
    
}

int num(vector<int> &v)
{
    int ans = 0;
    for(int i=0;i<v.size();i++)
    {
        ans = (ans*10)+v[i];
    }
    return ans;
}

int sumNumbers(BinaryTreeNode<int> *root)
{
    
        vector<vector<int> > ans;
        vector<int> ds;
        sum(root,ds,ans);
        int s = 0;
        for(int i=0;i<ans.size();i++)
        {
            s+=num(ans[i]);
        }
        return s;
}

//GET ALL ROOT TO NODE PATHS IN A BINARY TREE

void paths(BinaryTreeNode<int> *root,vector<int> &ds,vector<vector<int> > &ans)
{
    if(root==NULL)
    {
        return;
    }

    //pehle add kiya data stucutr me vo node fir check kro ki uske koi children nhi to mtlb that is the end.usko daalo ans me aur return
    ds.push_back(root->data);

    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(ds);
        return;
    }

//left wali node dali 
    if(root->left!=NULL)
    {
        paths(root->left,ds,ans);
    }
    //fir return krte wakt use hata liya taaki waahn se left ya right jaaya jaa kyunki usko incude kr liya hai ab baaki paths pr jana hai.
    ds.pop_back();

    //same with right.
    if(root->right!=NULL)
    {
        paths(root->right,ds,ans);
    }
    ds.pop_back();
}

vector<vector<int> > AllRootToNodePaths(BinaryTreeNode<int> *root)
{
    vector<vector<int> > ans;
    vector<int> ds;
    paths(root,ds,ans);
    return ans;
}

void PrintnodeswithoutSibling(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        return;
    }
    if((root->left!=NULL && root->right==NULL))
    {
        cout << root->left->data << " ";
    }
    if(root->right!=NULL && root->left==NULL)
    {
        cout << root->right->data << " ";
    }

    if(root->left!=NULL)
    {
        PrintnodeswithoutSibling(root->left);
    }
    if(root->right!=NULL)
    {
        PrintnodeswithoutSibling(root->right);
    }
}


//longest zigzag path

int countnodes(BinaryTreeNode<int> *root,bool direction)
{
    if(root->right==NULL && root->left==NULL)
    {
        return 0;
    }

}

int longestZigZag(BinaryTreeNode<int> *root)
{
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }

    queue<BinaryTreeNode<int>*> pending;
    pending.push(root);

    while(pending.size()!=0)
    {
        BinaryTreeNode<int> *front = pending.front();
        pending.pop();
        int cl = countnodes(front,true);//true indicated left, false indicated right.
        if(front->left!=NULL)
        {
            pending.push(front->left);
        }
        if(front->right!=NULL)
        {
            pending.push(front->right);
        }
    }
}





// 5 6 10 2 3 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

// 1 2 3 4 5 -1 6 7 -1 -1 -1 -1 8 -1 -1 -1 -1

int main()
{
    /*
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);


    root->left = node1;
    root->right = node2;
    */

    BinaryTreeNode<int> *root = takeinputLevelWise();
    // printLevelWise(root);
    cout << endl;
    // cout << countNodes(root);
    // cout << isNodePresent(root, 4);
    cout << height(root->left) << " " << height(root->right) << endl;
    // mirrorBinaryTree(root);
    // printLevelWise(root);

    /*
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    */

    // build tree
    // int n;
    // cin >> n;

    // int preorder[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> preorder[i];
    // }
    // int inorder[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> inorder[i];
    // }

    // //BinaryTreeNode<int> *newTree = buildTree(preorder, n, inorder, n);
    // printLevelWise(newTree);
    // pair<int, int> p = heightDiameter(root);
    // cout << "height : " << p.first << " "
    //      << "diameter : " << p.second << endl;

    // pair<int, int> minandmax = getminandmax(root);
    // cout << "min : " << minandmax.first << " "
    //      << "max : " << minandmax.second << endl;
    // pair<int, bool> p = isBalancedhelp(root);
    // cout << p.first;
    // printLevelWisecn(root);
    // removeLeafNodes(root);
    // printLevelWise(root);
    // cout << countNonLeafNodes(root);
    // vector<int> ans;
    // ans = leftView(root);
    // for(int i=0;i<ans.size();i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // printLevelWisecn(root);
    // cout << endl;
    // zigzagorder(root);
    // reverse_inorder(root);
    // zigzagorder(root);
    // int p,q;
    // cin >> p >> q;

    // if(level(root,p)==level(root,q))
    // {
    //     cout << "true" << endl;
    // }
    // else
    // {
    //     cout << "false" << endl;
    // }
    // vector<int> v = dfs_tree(root);
    // for(int i=0;i<v.size();i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << isBalanced(root) << endl;
    // cout << deepestLeavesSum(root);
    // vector<int> a;
    // for(int i=0;i<5;i++)
    // {
    //     int c;
    //     cin >> c;
    //     a.push_back(c);
    // }
    // suffixsum(a);
    // for(int i=0;i<5;i++)
    // {
    //     cout << a[i] << " ";
    // }
    // BinaryTreeNode<int> *g = bsttoGst(root);
    // printLevelWise(g);
    // pair<int,int> ans = avgtree(root);
    // cout << ans.first << " " << ans.second << endl;
    // cout << averageOfSubtree(root) << endl;
    // int k;
    // cin >> k;
    // cout << kthlargest(root,k);
    // cout << sumNumbers(root);
    // PrintnodeswithoutSibling(root);
    // vector<vector<int> > paths = AllRootToNodePaths(root);
    // for(int i=0;i<paths.size();i++)
    // {
    //     for(int j=0;j<paths[i].size();j++)
    //     {
    //         cout << paths[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}