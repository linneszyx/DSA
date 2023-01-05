#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};
//Preorder build of the tree root left right tree
Node * buildTree(){
    int d;
    cin>>d;
    if(d==-1) return NULL;
    Node *n = new Node(d);
    n->left = buildTree();
    n->right= buildTree();
    return n;
}
void printPreorder(Node *root){
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}
int main(){
    Node *root = buildTree();
    printPreorder(root);
return 0;
}