#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#include "linked_list.cpp"


int main()
{
    Node* ans=new Node(10);
    Node* head=ans;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, -1);

    
    while(ans)
    {
        cout<<ans->val<<" ";
        ans=ans->next;

    }
    return 0;
}