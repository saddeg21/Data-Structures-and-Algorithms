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

char* infixToPostfix(char* infix) {
	int i,j;
	char size = strlen(infix);
	char* postfix = (char*) malloc(sizeof(char)*(size+2));
	char stack[MAX];
	int top = -1;
	
	for(i = 0,j = 0;i<size;i++) {
		if(infix[i]==' ' || infix[i]=='\t') {
			continue;
		}
		
		if(isalnum(infix[i])) {
			postfix[j++] = infix[i];
		} else if (infix[i] == '(') {
			stack[++top] = infix[i];
		} else if (infix[i] == ')') {
			while(top>-1 && stack[top]!='(') {
				postfix[j++] = stack[top--];
			}
			if (top > -1 && stack[top] != '(')
                return "Invalid Expression";
            else
                top--;
		} else if(isOperator(infix[i])) {
			while(top>-1 && (precedence(infix[i])<=precedence(stack[top]) && infix[i]!='^')) {
				postfix[j++] = stack[top--];
			}
			stack[++top] = infix[i];
		}
	}
	
	while(top>-1) {
		postfix[j++] = stack[top--];
	}
	
	postfix[j]= '\0';
	
	return postfix;
	
}

void input(char* temp,int size) {
	printf("Write the infix expression you want it to be converted :\t");
	fgets(temp,size,stdin);
	printf("\n");
}

int main(void) {
	char infix[MAX];
	input(infix,MAX);
	
	char* postfix = infixToPostfix(infix);
	printf("Your test case is :\t");
	printf("%s\n",postfix);
	printf("The best test case is :\nINFIX:\tK+L-M*N+(O^P)*W/U/V*T+Q\n");
	printf("POSTFIX:\t%s",infixToPostfix("K+L-M*N+(O^P)*W/U/V*T+Q"));
	return 0;
}
