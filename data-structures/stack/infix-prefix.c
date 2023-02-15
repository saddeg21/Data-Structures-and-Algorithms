#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int precedence(char operator) {
	switch(operator) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return -1;
	}
}

int isOperator(char letter) {
	return (letter == '+' || letter == '-' || letter == '*' || letter == '/' || letter == '^');
}


void input(char* temp,int size) {
	printf("Write the infix expression you want it to be converted :\t");
	fgets(temp,size,stdin);
	printf("\n");
}

char* reverseInfix(char* infix) {
	int i,j;
	char* reverse = (char*) malloc(sizeof(char)*MAX);
	for(i=strlen(infix)-1,j=0;i>=0;i--) {
		reverse[j++] = infix[i];
	}
	
	return reverse;
}

char* infixToPrefix(char* reverse) {
	int i,j;
	char size = strlen(reverse);
	char* prefix = (char*) malloc(sizeof(char)*(size+2));
	char stack[MAX];
	int top = -1;
	
	for(i = 0,j = 0;i<size;i++) {
		if(reverse[i]==' ' || reverse[i]=='\t') {
			continue;
		}
		
		if(isalnum(reverse[i])) {
			prefix[j++] = reverse[i];
		} else if (reverse[i] == ')') {
			stack[++top] = reverse[i];
		} else if (reverse[i] == '(') {
			while(top>-1 && stack[top]!=')') {
				prefix[j++] = stack[top--];
			}
			if (top > -1 && stack[top] != ')')
                return "Invalid Expression";
            else
                top--;
		} else if(isOperator(reverse[i])) {
			if(reverse[i]!='^') {
				while(top>-1 && (precedence(reverse[i])<precedence(stack[top]))) {
				prefix[j++] = stack[top--];
			}
			} else {
				while(top>-1 && (precedence(reverse[i])==precedence(stack[top]) && reverse[i]=='^')) {
				prefix[j++] = stack[top--];
			}
			}
			
			
			stack[++top] = reverse[i];
		}
	}
	
	while(top>-1) {
		prefix[j++] = stack[top--];
	}
	
	prefix[j]= '\0';
	
	
	return reverseInfix(prefix);
	
}

int main(void) {
	char infix[MAX];
	char* reverse;
	input(infix,MAX);
	printf("INFIX:\t%s\n",infix);
	reverse = reverseInfix(infix);
	printf("Reversed String is:\t%s\n",reverse);
	printf("PREFIX:\t%s\n",infixToPrefix(reverse));
	printf("\nTHE BEST TEST CASE IS:\n");
	printf("INFIX:\tK+L-M*N+(O^P)*W/U/V*T+Q\n");
	printf("POSTFIX:\t%s",infixToPrefix(reverseInfix("K+L-M*N+(O^P)*W/U/V*T+Q")));
	
	return 0;
}
