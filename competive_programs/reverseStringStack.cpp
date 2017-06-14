//Reverse String using Stack

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	int top;
	unsigned capacity;
	char* array;
};

struct node* createNode(unsigned len){
	struct node* stack = (struct node*)malloc(sizeof(struct node));
	stack->top = -1;
	stack->capacity = len;
	stack->array = (char *)malloc(len*sizeof(char));
	
	if(stack->array == NULL)
		return NULL;
	
	return stack;	
}

bool isFull(struct node* stack){
		return stack->top == (stack->capacity-1);
}

void push(struct node* stack,char ch){
	//printf("%c",stack->array[stack->top]);
	if(!isFull(stack)){
		stack->array[++stack->top] = ch;
		printf("%c",stack->array[stack->top]);
	}
	//printf("%c",stack->array[stack->top]);
	return;
}

bool isEmpty(struct node* stack){
	return stack->top == -1;
}

char pop(struct node* stack){
	//printf("%d",stack->top);
	if(!isEmpty(stack)){		
		//printf("%c",stack->array[stack->top]);
		return stack->array[stack->top--];
	}
}

void reverse(char str[]){
	
	int len = strlen(str);
	
	struct node* stack = createNode(len);
	
	if(stack == NULL){
		//printf("null..");
		return;
	}		
	
	int i;
	
	//printf("%d",len);
	for(i=0;i<len;i++){
		//printf("%c",str[i]);
		push(stack,str[i]);
	}
	
	for(i=0;i<len;i++){		
		str[i] = pop(stack);
		//printf("%s",str[i]);
	}
	
	printf("\n%s",str);
}

int main(){
	char str[] = "GeeksQuiz";
	reverse(str);
	
	return 0;
}
