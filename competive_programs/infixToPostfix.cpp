//infix to postfix   "a+b*(c^d-e)^(f+g*h)-i"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct Stack {
	int top=-1;
	unsigned capacity;
	int* array;
};

struct Stack* createStack(unsigned capacity){
	
	struct Stack* newstack = (struct Stack*)malloc(sizeof(struct Stack));
	
	newstack->capacity = capacity;
	newstack->array = (int*)malloc(sizeof(capacity));
	
	return newstack;
} 

bool isOperand(char ch){
	if((ch >= 'a' && ch <='z')||(ch >= 'A' && ch <= 'Z'))
		return true;
	return false;
}

void push(Stack* stack,char ch){
	stack->array[stack->top++] = ch;
}

void infixToPostfix(char* ch){
	
	struct Stack* stack = createStack(strlen(ch));

	int i,k;
	for(i=0,k=0;ch[i];i++){
		if(isOperand(ch[i])){
			ch[i] = 
		}
		else if(ch[i] == '('){
			push(stack,ch[i]);
		}
		else {
			while(!stack && ch[i] <= peek(stack) )
				ch[i] += pop(stack);
			push(stack,ch[i]);	
		}
	}	

	while(!stack)
		ch[i] += pop(stack);
}


int main() {
	char ch[] = "a+b*(c^d-e)^(f+g*h)-i";
	
	infixToPostfix(ch);
}
