#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct StackNode {
	int data;
	struct StackNode* next;
};

int isEmpty(struct StackNode* top) {
	return !top;
}


struct StackNode* createNewNode(int data){
	struct StackNode* node = (struct StackNode*) malloc(sizeof(struct StackNode));
	node->data = data;
	node->next = NULL;
	
	return node;
};

void push(struct StackNode** top,int data) {
	struct StackNode* newNode = createNewNode(data);
	newNode->next = *top;
	(*top) = newNode;
	printf("%d pushed to stack\n",data);
	
}

int pop(struct StackNode** top) {
	if(isEmpty(*top)) {
		//Returned the minimum integer number comes from limit.h file.
		return INT_MIN;
	}
	struct StackNode* temp = *top;
	int tempedData = temp->data;
	*top = (*top)->next;
	free(temp);
	
	printf("%d popped from stack\n",tempedData);
	return tempedData;
	
}

void display(struct StackNode** top) {
	if(isEmpty(*top)) {
		return;
	}
	
	struct StackNode* temp = *top;
	while(temp!=NULL) {
		printf("|----------|\n");
		printf("|    %d    |\n",temp->data);
		temp = temp->next;
	}
	printf("|----------|");
}

int peek(struct StackNode** top) {
	if(isEmpty(*top)) {
		return INT_MIN;
	}
	return (*top)->data;
}

int main(void) {
	struct StackNode* top = NULL;
	
	push(&top,12);
	push(&top,13);
	push(&top,10);
	pop(&top);
	printf("The peek is: %d\n",peek(&top));
	display(&top);
	return 0;
}


