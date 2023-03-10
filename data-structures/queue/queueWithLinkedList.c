#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct QNode {
	int key;
	struct QNode* next;
}QNode;

typedef struct Queue {
	struct QNode* front;
	struct QNode* rear;
}Queue;

Queue* createQueue() {
	Queue* queue = (Queue*) malloc(sizeof(Queue));
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}

QNode* newNode(int data) {
	QNode* temp = (QNode*) malloc(sizeof(QNode));
	temp->key = data;
	temp->next = NULL;
	return temp;
}

int isEmpty(Queue* queue) {
	return queue->front == NULL;
}

void enqueue(Queue* queue, int data) {
	if(isEmpty(queue)) {
		QNode* temp = newNode(data);
		queue->front = temp;
		queue->rear = temp;
		return;
	}
	QNode* temp = newNode(data);
	queue->rear->next = temp;
	queue->rear = temp;
}

void display(Queue* queue) {
	if(isEmpty(queue)){
		printf("Queue is EMPTY!");
		return;
	}
	QNode* temp = queue->front;
	printf("\n________________________________\n\n");
	while(temp!=NULL) {
		printf("%d ",temp->key);
		temp = temp->next;
	}
	printf("\n________________________________");
}

int dequeue(Queue* queue) {
	if(isEmpty(queue)) {
		printf("Queue is EMPTY!");
		return INT_MIN;
	}
	int x = queue->front->key;
	QNode* temp = queue->front;
	queue->front = queue->front->next;
	free(temp);
	return x;
}

int main() {
	Queue* queue = createQueue();
	enqueue(queue,1);
	enqueue(queue,2);
	enqueue(queue,3);
	enqueue(queue,4);
	dequeue(queue);
	display(queue);
	return 0;
}
