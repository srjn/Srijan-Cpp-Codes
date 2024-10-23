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

Node* build(Node* root)
{
    int data;
cout<<"enter data ";
cin>>data;
root=new Node(data);

if(data==-1)
return nullptr;

root->left=build(root->left);
root->right=build(root->right);

return root;
}