#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

    struct pair_item{
    int val;
    int priority;
    };

//Lowest Priority

class priority_Queue{
int front,rear,size;
pair_item* queue;
public:
priority_Queue(int sz){
    front=-1, rear=-1;
    size=sz;
    queue=new pair_item[size];
}
bool IsEmpty()const;
bool IsFull()const;
int Dequeue();
void Enqueue(int item,int p);
void Display()const;
};
bool priority_Queue::IsEmpty()const{
    return (front==-1 && rear==-1);
}

bool priority_Queue::IsFull()const{
    return rear==size-1;
}

//o(1)
int priority_Queue::Dequeue(){
    if(IsEmpty()){
        cout<<"Queue is empty\n";
        return -1;
    }
    int v=queue[front].val;
    front++;
    return v;
}

//o(n)
void priority_Queue::Enqueue(int item,int p){
if(IsFull()){
    cout<<"Queue is full\n";
    return;
}

if(IsEmpty()){
    rear++,front++;
    queue[rear].val=item;
    queue[rear].priority=p;
}
else {
bool ok=0;
    for(int i=rear;i>=0;i--){
        if(p<queue[i].priority){
            queue[i+1].val=queue[i].val;
            queue[i+1].priority=queue[i].priority;
        }
        else{
            queue[i+1].val=item;
            queue[i+1].priority=p;
            ok=1;
            break;
        }
    }
    if(!ok){
        queue[0].val=item;
        queue[0].priority=p;
    }
    rear++;
}
}

//o(n)
void priority_Queue::Display()const{
    for(int i=0;i<=rear;i++){
        cout<<queue[i].val<<' ';
    }
    cout<<'\n';
}
int main(){
priority_Queue pq(5);
// pq.Enqueue(1,5);

// pq.Enqueue(3,8);

// pq.Enqueue(2,10);

// pq.Enqueue(10,7);

// pq.Enqueue(105,2);
// pq.Display();



    return 0;
}