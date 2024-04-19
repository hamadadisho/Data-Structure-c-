#include <bits/stdc++.h>
using namespace std;

//o(n)
Node* split(Node* list1){

Node* temp=list1;
int count=0;
while(temp!=nullptr){
    count++;
    temp=temp->next;
}
count/=2;

temp=list1;
for(int i=0;i<count;i++) temp=temp->next;


Node* n=temp->prev;
n->next=nullptr;
temp->prev=nullptr;

Node* list2=temp;

return list2;
}



int main(){

    return 0;
}