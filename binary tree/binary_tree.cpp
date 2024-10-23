#include <bits/stdc++.h>
using namespace std;

class Node
{   
public:
int val;
Node* left;
Node* right;

Node(int d)
{
    this->val=d;
    this->left=nullptr;
    this->right=nullptr;
}
};

class BinaryTree{
    public:
    Node *root;

    BinaryTree(){
        root=nullptr;
    }

Node* build(Node * root)
{
    int data;
cout<<"enter data ";
cin>>data;

if(data==-1)
return nullptr;

root=new Node(data);

root->left=build(root->left);
root->right=build(root->right);

return root;
}
};

