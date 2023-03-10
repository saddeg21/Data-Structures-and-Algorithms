#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct Queue {
	int front;
	int rear;
	int size;
	int* queue;
} Queue;

int isEmpty(Queue* queueArray) {
	if(queueArray->front == -1 && queueArray->rear == -1) {return 1;} else {return 0;}
}

int isFull(Queue* queueArray) {
	if(queueArray->rear == queueArray->size - 1) {
		printf("Queue Overflow !");
		return 1;
	} else{
		return 0;
	}
}

void enqueue(Queue* queueArray,int data) {
	if(isEmpty(queueArray)) {
		queueArray->front= queueArray->front + 1;
		queueArray->rear = queueArray->rear + 1;
		queueArray->queue[queueArray->rear] = data;
	} else if(isFull(queueArray)) {
		return;
	} else {
		queueArray->rear = queueArray->rear + 1;
		queueArray->queue[queueArray->rear] = data;
	}
}

int dequeue(Queue* queueArray) {
	if(isEmpty(queueArray)) {
		printf("Queue is empty.");
		//INT_MIN is falsy value so check while gettin dequeue
		return INT_MIN;
	} else if(queueArray->front == queueArray->rear) {
		queueArray->rear = - 1;
		queueArray->front = - 1 ;
	} else {
		queueArray->front = queueArray->front + 1 ;
	}
}

void display(Queue* queueArray) {
	if(isEmpty(queueArray)) {
		printf("Queue is empty");
	} else {
		printf("\nfront_______________________rear\n\n");
		int temp = queueArray->front;
		for(;temp<queueArray->rear+1;temp++) {
			printf("%d ",queueArray->queue[temp]);
		}
		printf("\n________________________________");
	}
}

int main(void) {
	Queue* queueArray = (Queue*) malloc(sizeof(Queue));
	queueArray->front = -1;
	queueArray->rear = -1; 
	int size;
	printf("Enter the size of queue that you wished:\t");
	scanf("%d",&size);
	queueArray->size = size;
	queueArray->queue = (int*) malloc(sizeof(int)*size);
	enqueue(queueArray,3);
	enqueue(queueArray,4);
	enqueue(queueArray,5);
	display(queueArray);
	printf("\n");
	dequeue(queueArray);
	enqueue(queueArray,32);
	display(queueArray);
	return 0;
	
	
}
