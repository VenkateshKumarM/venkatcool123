//Stack

#include<bits/stdc++.h>
using namespace std;

#define MAX 5
class Stack {
		int top;				
	public:
		int a[MAX];
		
		Stack() {			
			 top =-1;
		}
		
		bool push(int data);
		int pop();
		bool isEmpty();
		int peek();
};


bool Stack::push(int data){
	//cout<<top;
	if(top>=MAX){
		cout<<"Stack Overflow";
		return false;
	}
	else {
		a[++top] = data;
		return true;
	}
}

int Stack::pop(){
	int elem;
	if(top<0){
		cout<<"Stack Underflow";
		return 0;
	}
	else {
		elem = a[top--];
		return elem;
	}
}

bool Stack::isEmpty(){
		return(top < 0);
}

int Stack::peek() {
	return a[top];
}

int main(){
	struct Stack s;
	s.push(5);
	s.push(6);
	s.push(7);
	s.pop();
	cout<<s.isEmpty();
	cout<<s.peek();
	
	
}
