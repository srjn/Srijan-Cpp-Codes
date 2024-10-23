#include <bits/stdc++.h>
using namespace std;

class Node{
    public :
    int val;
    Node* next;

    Node(int d)
    {
        this->val=d;
        this->next=nullptr;
    }

};

class LinkedList{
    public:
    Node *head;

    LinkedList(){
       head=new Node(-1); 
    }

void insert()
{
    Node *dummy=head;
    int data=0;
while(data!=-1){
    int x;
    cout<<"enter value"<<endl;
    cin>>x;
    data=x;

    Node* temp=new Node(data);
    dummy->next=temp;
    dummy=temp;
}
head=head->next;
}

void print(){
    Node *dummy=head;
    while(dummy){
        cout<<dummy->val<<" ";
        dummy=dummy->next;
    }
}

};


int main(){
    LinkedList l;
    l.insert();
    l.print();

    return 0;
}


