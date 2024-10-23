#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    char val;
    node* children[26];
    bool isLast;

    node(char val){
        this->val=val;

        for(int i=0;i<26;i++)
        children[i]=nullptr;

        isLast=false;
    }
};

class trie{
    public : 
    node *root;

    trie(){
        root=new node('\0');
    }

    void insert(string word){

        node *temp=root;

       for(auto i : word){
        int index=i-'a';

        //present
        if(temp->children[index]){
            temp=temp->children[index];
            continue;
        }

        //absent
        else{
            node *child=new node(i);
            temp->children[index]=child;
        }

        temp=temp->children[index];

       }
       temp->isLast=true;
    }

    bool search(string word){
        node * temp=root; 
        for(auto i : word){
            int index=i-'a';

            if(!temp->children[index]){
                return false;
            }

            temp=temp->children[index];

        }
        return temp->isLast;
    }
    

};


int main(){
    trie test;

    test.insert("srijan");

    if(test.search("srijana"))
    cout<<"same";
    else
    cout<<"diff";
}