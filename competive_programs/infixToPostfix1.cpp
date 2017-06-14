#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	int top;
	int capacity;
	int *array;
};

struct node* createStack(int capacity){
	struct node* stack = (struct node*)malloc(sizeof(struct node));
	if(stack == NULL)
		return NULL;
	stack->top = -1;
	stack->capacity = capacity;
	
	stack->array = (int*)malloc(sizeof(stack->capacity* sizeof(int)));
	return stack;	
}

int isEmpty(struct node* stack){
	return stack->top == -1;
}

void push(struct node* stack,char ch){
	stack->array[++stack->top] = ch;
}

char pop(struct node* stack){
	if(stack == NULL)
		return '$';
	return stack->array[stack->top--];
}

bool isOperand(char ch){
	if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <='z')
		return 1;
}

char peek(struct node* stack){
	return stack->array[stack->top];
}

int Prec(char ch){
	switch(ch){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
	return -1;
}

void infixToPostfix(char* exp){
	struct node* stack = createStack(strlen(exp));
	
	int i,k;
	for(i=0,k=-1;i<strlen(exp);i++){
		if(isOperand(exp[i]))
			exp[k++] = exp[i];
		else if(exp[i] == '(')
			push(stack,exp[i]);
		else if(exp[i] == ')'){
			do {
				exp[k++] = pop(stack);
			   }while(exp[i]!='(');
			   
			  if(exp[i] == '(') 
			  	exp[k++] = pop(stack);
		}
		else {
			if(!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
				exp[k++] = pop(stack);
			push(stack,exp[i]);	
		}		
	}
	
	while(!isEmpty(stack))
		exp[k++] = pop(stack);
	
	exp[k++] = '\0';
	
	printf("%s",exp);
}

int main(){
	char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(exp);
	return 0;	
}
