//Implement two stacks in an array

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Stack{
	int top1;
	int top2;
	unsigned capacity;
	unsigned capacity1;
	unsigned capacity2;
	int *array;
};

struct Stack* createStack(unsigned capacity){
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	
	stack->capacity = capacity;
	stack->top1 = -1;
	stack->capacity1 = capacity/2;
	
	stack->top2 = capacity/2;
	stack->capacity2 = capacity;
	
	stack->array = (int *)malloc(capacity*sizeof(int));
	
	if(stack->array != NULL)
		return stack;
}

bool isFull1(struct Stack* stack){
	return stack->top1 == stack->capacity1-1;
}

bool isFull2(struct Stack* stack){
	return stack->top2 == stack->capacity2-1;
}

void push1(struct Stack* stack, int data){
	
	if(isFull1(stack))
		return;
	
	stack->array[++stack->top1] =  data;
}


void push2(struct Stack* stack, int data){
	if(isFull2(stack))
		return;
	
	stack->array[++stack->top2] =  data;	
}

bool isEmpty1(struct Stack* stack){
	return stack->top1 == -1;
}

bool isEmpty2(struct Stack* stack){
	return stack->top2 == (stack->capacity/2);
}

int pop1(struct Stack* stack){
	
	int data;
	
	if(!isEmpty1(stack))
		data = stack->array[stack->top1--];
	else
		data = NULL;
	
	return data;			
}

int pop2(struct Stack* stack){
	
	int data;
	
	if(!isEmpty2(stack))
		data = stack->array[stack->top2--];
	else
		data = NULL;
	
	return data;	
		
}

void printList1(struct Stack* stack){
	int top = stack->top1;
	while(top >= 0){
		printf("%d ",stack->array[top--]);
	}
	printf("\n");
}

void printList2(struct Stack* stack){
	int top = stack->top2;
	while(top > stack->capacity1){
		printf("%d ",stack->array[top--]);
	}
}

int main(){
	struct Stack* stack = createStack(10);
	
	push1(stack,1);
	push1(stack,5);
    push2(stack,10);
    push2(stack,15);
    push1(stack,11);
    push2(stack,7);
    
    printList1(stack);
    printList2(stack);
    
    printf("\nPopped element from stack1 is %d", pop1(stack));
    push2(stack,40);
    printf("\nPopped element from stack2 is %d", pop2(stack));
    return 0;
}
