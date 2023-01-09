#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int key;
    Node *left;
    Node *right;
    Node(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};
Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        return new Node(key);
    }
    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}
bool search(Node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->key == key)
        return true;
    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}
Node *findMin(Node *root){
    while (root->left!=NULL)
    {
        root = root->left;
    }
    return root; 
}
Node *remove(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    else if (key < root->key)
    {
        root->left = remove(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = remove(root->right, key);
    }
    else
    {
        // no child
        if(root->left==NULL and root->right==NULL){
            delete root;
            root = NULL;
            return root;
        }
        // 1 child
        else if(root->left==NULL){
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right==NULL){
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // 2 child
        else{
            Node *temp = findMin(root->right);
            root->key = temp->key;
            root->right = remove(root->right,temp->key);
        }
    }
    return root;
}
void InOrder(Node *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->key << " ,";
    InOrder(root->right);
}
void printRange(Node *root,int k1,int k2){
    if(root==NULL) return;
    if(root->key>=k1 and root->key<=k2){
        printRange(root->left,k1,k2);
        cout<<root->key<<" ";
        printRange(root->right,k1,k2);
    }
    else if(root->key>2){
        printRange(root->left,k1,k2);
    }
    else{
        printRange(root->right,k1,k2);
    }
}

int main()
{
    Node *root = buildtee();
    Node *root = NULL;
    // int arr[] = {8, 3, 4, 2, 14, 7, 13, 1, 6};
    // for (int x : arr)
    // {
    //     root = insert(root, x);
    // }
    // InOrder(root);
    // cout << endl;
    // int k;
    // cin >> k;
    // root = remove(root,k);
    // InOrder(root);
    // if ((search(root, k)))
    //     cout << "Present\n";
    // else
    //     cout << "Not Present\n";
    // printRange(root,3,8);
    return 0;
}