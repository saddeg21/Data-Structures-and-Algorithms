#include <stdio.h>
#include <stdlib.h>

typedef struct Node {int data;struct Node *next;} Node;
typedef struct NodeList {struct Node *head;} NodeList;


int lengthLL(NodeList* llist) {
	int i = 0;
	Node* temp = llist->head;
	while(temp!=NULL) {
		i++;
		temp = temp->next;
	}
	return i;
}

NodeList* createSinglyLinkedList() {
	//CREATE A LINKED LIST OBJECT FOR DIFFERENTIATE SIMILAR TYPES OF LINKED LISTS
	NodeList* llist = (NodeList*) malloc(sizeof(NodeList));
	//DEFINING AND DECLARING HEAD OUTSIDE OF A FUNCTION AS GLOBAL VARIABLE CAUSES ERROR, IT STAYS AT THE NULL POSITON OF RAM
	llist->head = NULL;
	return llist;
}

Node* insertEnd(NodeList* llist,int data) {
	Node *newInstance = (Node*) malloc(sizeof(Node));
	newInstance->next= NULL;
	newInstance->data = data;
	
	//CHECK WHETHER THE LIST IS EMPTY OR NOT
	if(llist->head == NULL) {
		//IF SO, INSERT IT AS FIRST ELEMENT
		llist->head = newInstance;
		return llist->head;
	}
	//ELSE FIND THE LAST NODE AND APPEND THE NODE WHICH HAS BEEN CREATED YET
	Node *temp = llist->head;
	while(temp!=NULL) {
		if(temp->next==NULL) {
			temp->next = newInstance;
			return temp->next;
		}
		temp = temp->next;
	}
	return NULL;
}

void printLinkedList(NodeList* llist) {
	//IF LIST IS EMPTY RETURN VOID
	if(llist->head == NULL) return;
	//ELSE PRINT THE LINKED LIST AS A DIAGRAM
	Node* temp = llist->head;
	while(temp!=NULL) {
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

Node* insertFirst(NodeList* llist,int data) {
	Node *newInstance = (Node*) malloc(sizeof(Node));
	newInstance->data =data;
	newInstance->next = NULL;
	
	//CHECK WHETHER THE LIST IS EMPTY OR NOT
	if(llist->head == NULL) {
		//IF SO, INSERT IT AS FIRST ELEMENT
		llist->head = newInstance;
		return llist->head;
	}
	//ELSE FIND THE HEAD AND SHIFT THE NODE WHICH HAS BEEN CREATED YET
	newInstance->next = llist->head;
	llist->head = newInstance;
	
	return llist->head;
}

Node* insertPosition(NodeList* llist,int data, int position) {
	//USE IT WITH INDICES EXCLUDING LAST INDEX AND 0(FIRST)
	Node *newInstance = (Node*) malloc(sizeof(Node));
	newInstance->next= NULL;
	newInstance->data = data;
	
	//INDEXING STARTS AT 0
	int i = 0;
	int length = lengthLL(llist);
	//IF LIST IS EMPTY
	if(llist->head == NULL) {
		llist->head = newInstance;
		return llist->head;
	}
	
	Node *current = llist->head;
	Node *next = current->next;
	//ELSE FIND THE POSITION AND INSERT NODE
	while(current!=NULL && i<length ) {
		if(position-i==1) {
			current->next = newInstance;
			newInstance->next = next;
			return current->next;
		}
		current = current->next;
		next = next->next;
		i++;
	}
	return NULL;
}

void deleteEnd(NodeList* llist) {
	//IF LIST IS EMPTY RETURN VOID
	if(llist->head == NULL) return;
	//ELSE GO TO THE END OF THE LIST FREE THE MEMORY, ASSIGN NEXT POINTER OF NODES AGAIN
	Node* temp = llist->head;
	while(temp->next->next!=NULL){
	   temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
}

void deleteFirst(NodeList* llist) {
	//IF LIST IS EMPTY RETURN VOID
	if(llist->head == NULL) return;
	//ELSE DELETE THE FIRST ELEMENT AND SET THE HEAD AGAIN
	Node* temp = llist->head->next;
	free(llist->head);
	llist->head = temp;
}

void deletePosition(NodeList* llist,int position) {
	/*USE IT WITH INDICES EXCLUDING LAST INDEX AND 0(FIRST INDEX)*/
	//IF LIST IS EMPTY RETURN VOID
	if(llist->head == NULL) return;
	// SET INDEX 0
	int i = 0;
	int length  = lengthLL(llist);
	Node* current = llist->head;
	Node* prev = NULL;
	
	while(current!=NULL && i<length) {
		if(i==position){
			prev->next = current->next;
			free(current);
			return;
		}
		prev = current;
		current = current->next;
		i++;
	}
}

Node* linearSearch(NodeList* llist,int match) {
	if(llist->head == NULL) {
		printf("-EMPTY LINKED LIST-\n");
		return NULL;
	}
	
	int idx=0;
	Node* temp = llist->head;
	
	while(temp!=NULL) {
		if(temp->data == match) {
			printf("THE ELEMENT FOUND AT %d INDEX\n",idx);
			return temp;
		}
		temp = temp->next;
		idx++;
	}
	printf("-NO ELEMENT HAS BEEN FOUND!-\n");
	return NULL;
}

void bubbleSortLL(NodeList* llist) {
	/*WE ARE GONNA USE BUBBLESORT, CHECK FOR DETAILS : https://www.programiz.com/dsa/bubble-sort*/
	
	//Check whether the list is empty or not
	if(llist->head == NULL) {
		return;
	}
	
	Node* current = llist->head;
	Node* next = NULL;
	//FOR HOLDING THE VALUE WHILE EXCHANGING THE VALUE BETWEEN NODES
	int temp;
	
	while(current!=NULL) {
		//IT ITERATES EVERY ELEMENT OF LINKED LIST
		next = current->next;
		
		while(next!=NULL) {
			//IT ITERATES EVERY ELEMENT STAYS ON THE RIGHT OF CURRENT NODE
			if(current->data > next->data) {
				//CHECKS IF CURRENTS DATA IS BIGGER THAN THAT NODE
				//IF SO, EXCHANGES VALUES
				temp = current->data;
				current->data = next->data;
				next->data = temp;
			}
			next = next->next;
		}
		current = current->next;
	}
}

int main(void) {
	NodeList *llist = createSinglyLinkedList();
	linearSearch(llist,5);
	insertEnd(llist,3);
	insertEnd(llist,5);
	printLinkedList(llist);
	linearSearch(llist,5);
	insertFirst(llist,321);
	printLinkedList(llist);
	insertPosition(llist,21,1);
	printLinkedList(llist);
	deletePosition(llist,2);
	printLinkedList(llist);
	linearSearch(llist,5);
	bubbleSortLL(llist);
	printLinkedList(llist);
	printf("\n\nEND OF EXAMPLES...");
	return 0;
}
