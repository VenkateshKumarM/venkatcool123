// 231*+9-

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct node {
	int top;
	unsigned capacity;
	int* array;
};



void push(struct node* stack,int ch){
	stack->array[++stack->top] = ch;
	return;
}


bool isEmpty(struct node* stack){
		return stack->top == -1;
}

int pop(struct node* stack){
	if(!isEmpty(stack))
		return stack->array[stack->top--];
}

void peek(struct node* stack){
	printf("%d",stack->array[stack->top]);
}

void printStack(struct node* stack){
	int i;
	printf("\nList:%d",stack->top);
	for(i=stack->top;i>=0;i--){
		printf("\n%d",stack->array[i]);
	}
}

int operation(struct node* stack,char ch){
    int b = pop(stack);
    int a = pop(stack);
    printf("\n%d,%d",a,b);
	switch(ch){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':	
			return a/b;
	}
}

struct node* createNode(unsigned len){
	struct node* stack = (struct node*)malloc(sizeof(struct node));
	stack->top = -1;
	stack->capacity = len;
	stack->array = (int *)malloc(len*sizeof(int));
	
	if(stack->array == NULL)
		return NULL;
	
	return stack;
}

void evalPostfix(char* exp){
	struct node* stack = createNode(strlen(exp));	
	
	if(stack == NULL)
		return;
	
	int i,res;
	for(i=0;i<strlen(exp);i++){
		if(isdigit(exp[i])){
			//printf("isdigit=%d\n",exp[i]-'0');
			push(stack,exp[i]-'0');
		}
		else {
			printStack(stack);
			res = operation(stack, exp[i]);
			printf("res=%d\n",res);
			push(stack,res);
		}
	}
	peek(stack);
}	

int main(){
	char exp[] = "231*+9-";
	evalPostfix(exp);
	return 0; 
}
