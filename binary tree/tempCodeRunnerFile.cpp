#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include "binary_tree.cpp"

void helper(Node *root, vector <int> &ans)
{
    queue <Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node *temp=q.front();
        ans.push_back(temp->val);
        q.pop();

        if(temp->left)
        q.push(temp->left);

        if(temp->right)
        q.push(temp->right);
    }
}
vector<int> getLevelOrder(Node *root)
{
    //  Write your code here.
    if(!root)
    return {};
    
    vector<int> ans;

     helper(root,ans);

     return ans;

}

int main()
{
    BinaryTree tree;

    Node *root=tree.build(tree.root);

    vector<int> v=getLevelOrder(root);

    for(auto i : v)
    cout<<i<<" ";
return 0;

}