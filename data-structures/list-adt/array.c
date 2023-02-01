#include <stdio.h>

void insert(int array[],int element,int* length,int position) {
	int i;
	for(i=*length-1;i>=position;i--) {
		array[i+1] = array[i];
	}
	array[position] = element;
	(*length) = (*length) + 1;
}

void shift(int array[],int element,int* length) {
	int i;
	for(i=(*length)-1;i>=0;i--) {
		array[i+1] = array[i];
	}
	array[0] = element;
	(*length) = (*length) + 1;
}

void append(int array[],int element,int* length) {
	array[*length] = element;
	(*length) = (*length) + 1;

}

void traverseArray(int array[],int* length) {
	int i;
	for(i=0;i<*length;i++) {
		printf("%d ",array[i]);
	}
}

void pop(int array[],int* length) {
	(*length) = (*length) - 1;
	array[*length] = 0;
}

void unshift(int array[],int* length) {
	int i;
	for(i=0;i<(*length);i++) {
		array[i] = array[i+1];
	}
	(*length) = (*length) - 1;
}

void deletePosition(int array[],int position,int*length) {
	int i;
	for(i = position;i<(*length);i++) {
		array[i]=array[i+1];
	}
	(*length) = (*length) - 1;
}

int main(void) {
	int a[50];
	int length = 0;
	append(a,3,&length);
	append(a,5,&length);
	append(a,7,&length);
	shift(a,1,&length);
	insert(a,2,&length,1);
	traverseArray(a,&length);
	deletePosition(a,1,&length);
	traverseArray(a,&length);
	printf("%d",a);
	int *p = a;
	printf("%d",&p[0]);
	return 0;
}
