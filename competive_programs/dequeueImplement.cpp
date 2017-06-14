//Implementation of Deque using circular array

#include<stdlib.h>
#include<stdio.h>
#include<bits/stdc++.h>

#define MAX 10

using namespace std;

class Dequeue
{
	int front;
	int rear;
	int arr[MAX];
	int size;
	
	public:
		
		Dequeue(int size){
			front = -1;
			rear =0;
			this->size = size;
		}
		
		bool isFull();
		bool isEmpty();
		void insertFront(int k);
		void insertRear(int k);
		int deleteFront();
		int deleteRear();
		int getFront();
		int getRear();
	
};


bool Dequeue::isFull(){	
	return (front==0 && rear==size-1) || (front == rear+1);
}

bool Dequeue::isEmpty(){
	return front == -1;
}

void Dequeue::insertFront(int key){
	
	if(isFull()){
		printf("Overflow..");
		return;
	}
	
	if(front == -1){
		front = 0;
		rear = 0;
	}
	else if(front == 0){
		front = size-1;
	}
	else {
		front = front -1;
	}
	
	arr[front] = key;
	
	printf(" %d",arr[front]);
}

void Dequeue::insertRear(int key){
	
	if(isFull()){
		printf("Overflow..");
		return;
	}
	
	
	if(front == -1){
		front = 0;
		rear = 0;
	}
	else if(rear == size -1 ){
		rear = 0;
	}
	else {
		rear = rear+1;
	}
	
		arr[rear] = key;
}

int Dequeue::deleteFront(){
	
	if(isEmpty()){
		printf("Empty");
		return -1;
	}
	
	int item = arr[front];
	
	
	if(front == rear){
		front = -1;
		rear = -1;
	}
	else if(front == size-1){
		front =0;
	}
	else {
		front = front +1;
	}
	
	return item;
}


int Dequeue::deleteRear(){
	
	if(isEmpty()){
		printf("Empty");
		return -1;
	}
	
	int item = arr[rear];
	
	if(rear == front){
		rear = -1;
		front = -1;
	}
	else if(rear == 0 ){
		rear = size -1;
	}
	else {
		rear = rear -1;
	}
	
	return item;
}


int Dequeue::getFront() {
	if(isEmpty())
		return -1;
	
	return arr[front];
}

int Dequeue::getRear() {
	if(isEmpty())
		return -1;
	
	return arr[rear];
}

int main(){	
    Dequeue dq(5);
    
    cout << "Insert element at rear end  : 5 \n";
    dq.insertRear(5);
 
    cout << "insert element at rear end : 10 \n";
    dq.insertRear(10);
 
    cout << "get rear element " << " "
         << dq.getRear() << endl;
 
    dq.deleteRear();
    cout << "After delete rear element new rear"
         << " become " << dq.getRear() << endl;
 
    cout << "insert element at front end \n";
    dq.insertFront(15);
 
    cout << "get front element " << " "
         << dq.getFront() << endl;
 
    dq.deleteFront();
 
    cout << "After delete front element new "
       << "front become " << dq.getFront() << endl;
       
    return 0;
}
