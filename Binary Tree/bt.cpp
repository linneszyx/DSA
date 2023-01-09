#include <bits/stdc++.h>
using namespace std;
// IP : 1 2 4  -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
Node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    Node *n = new Node(d); 
    n->left = buildTree();
    n->right = buildTree();
    return n;
}
void printPreorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}
void printInorder(Node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
void printPostorder(Node *root)
{
    if (root == NULL)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}
/*

Expected OP
1
23
456
7
*/
void levelOrderPrint(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        if (temp == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return;
}
int height(Node *root)
{
    if(root==NULL) return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1 + max(h1,h2);
}
int diameter(Node *root){
    if(root==NULL) return 0;
    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);
    return max(D1,max(D2,D3));
}
void leafpaths(Node *root,vector<int> &path){
    if(root==NULL) return;
    if(root->left==NULL and root->right==NULL){
      for(int node : path){
        cout<<node<<"-->";
      }  
      cout<<root->data<<"-->";
      cout<<endl;
      return;
    }
    //rec case
    path.push_back(root->data);
    leafpaths(root->left,path);
    leafpaths(root->right,path);
    path.pop_back();
    return;
}
class HIGHDIA{
    public:
    int h,d;
};
HIGHDIA optDia(Node *root){
    HIGHDIA p;
    if(root==NULL){
        p.h = p.d = 0;
        return p;
    }
    HIGHDIA Left = optDia(root->left);
    HIGHDIA Right = optDia(root->right);
    p.h = max(Left.h,Right.h) + 1;
    int D1 = Left.h + Right.h;
    int D2 = Left.d;
    int D3 = Right.d;
    p.d = max(D1,max(D2,D3));
    return p;
}
Node *levelOrderBuild()
{
    int d;
    cin >> d;
    Node *root = new Node(d);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        int c1, c2;
        cin >> c1 >> c2;
        if (c1 != -1)
        {
            curr->left = new Node(c1);
            q.push(curr->left);
        }
        if (c2 != -1)
        {
            curr->right = new Node(c2);
            q.push(curr->right);
        }
    }
    return root;
}
int main()
{
    Node *root = buildTree();
    // levelOrderPrint(root);
    // cout<<"Diameter "<<diameter(root)<<"\n";
    // cout<<"Optimesed Diameter "<<optDia(root).d<<endl;
    // cout<<"Printing InOrder Traversal\n";
    // printInorder(root);
    // cout<<"Printing PreOrder Traversal\n";
    // cout << "\n";
    // printPreorder(root);
    // cout << "\n";
    // cout<<"Printing PostOrder Traversal\n";
    // printPostorder(root);
    // cout << "\n";
    // cout<<"Printing Level Order Traversal\n";
    // levelOrderPrint(root);
    // cout << "\n";
    // Node *root1 = levelOrderBuild();
    // levelOrderPrint(root);
    vector<int> path;
    leafpaths(root,path);
    return 0;
}