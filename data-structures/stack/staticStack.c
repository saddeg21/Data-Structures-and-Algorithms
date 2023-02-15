#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100

struct Stack {
	int top;
	unsigned capacity;
	int* arr;
};

struct Stack* createStack(unsigned capacity) {
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->capacity = capacity;
	stack->arr = (int*) malloc(sizeof(stack->capacity*sizeof(int)));
	
	return stack;
}

int isFull(struct Stack* stack) {
	return stack->top == stack->capacity-1;
}

int isEmpty(struct Stack* stack) {
	return stack->top == -1;
}

void push(struct Stack* stack, int data) {
	if(isFull(stack)) {
		return;
	}
	stack->top = stack->top + 1;
	stack->arr[stack->top] = data;
	printf("%d pushed to stack as %d'th element\n",data,stack->top);
}

int pop(struct Stack* stack) {
	if(isEmpty(stack)) {
		return INT_MIN;
	}
	return stack->arr[stack->top--];
}

int peek(struct Stack* stack) {
	if(isEmpty(stack)) {
		return INT_MIN;
	}
	return stack->arr[stack->top];
} 

void display(struct Stack* stack){
	int i;
	for(i = stack->top;i>-1;i--) {
		printf("|----------|\n");
		printf("|    %d     |\n",stack->arr[i]);
	}
	printf("|----------|\n");

}


int main(void) {
	struct Stack* stack = createStack(MAX);
	
	push(stack,3);
	push(stack,5);
	push(stack,7);
	display(stack);
	pop(stack);
	printf("%d",peek(stack));
	
	return 0;
}
