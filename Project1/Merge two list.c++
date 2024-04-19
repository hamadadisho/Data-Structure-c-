
#include <bits/stdc++.h>
using namespace std;

/*
o(n)
where n is the largest list
*/

    Node*  MergeTwoSortedLists(Node* list1, Node* list2) {
        Node* head=nullptr;
        Node* t1=list1;
        Node* t2=list2;
        if(t1==nullptr && t2!=nullptr){
            return t2;
        }
         if(t1!=nullptr && t2==nullptr){
            return t1;
         }
         if(!t1&&!t2){
            return head;
         }
        if(t1->val<=t2->val){
            head=t1;
            t1=t1->next;
            if(t1->val==t2->val) t2=t2->next;
        }
        else if(t2->val < t1->val){
            head=t2;
            t2=t2->next;
        }
        Node* curr=head;
    while(t1&&t2){
        if(t1->val<=t2->val){
        curr->next=t1;
        t1=t1->next;
        if(t1->val==t2->val) t2=t2->next;
        }
        else if(t2->val < t1->val){
            curr->next=t2;
            t2=t2->next;
        }
        curr=curr->next;
    }
    while(t1){
        curr->next=t1;
        curr=curr->next;
        t1=t1->next;
    }
    while(t2){
        curr->next=t2;
        curr=curr->next;
        t2=t2->next;
    }
    return head;
    }