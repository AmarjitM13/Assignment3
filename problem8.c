#include<stdio.h>
#include <stdbool.h>
#include<string.h>
#include<stdlib.h>

char stack[20];
int top=-1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

bool isEmpty(){
    if(top == -1){
        printf("top value from true:%d\n",top);
        return true;
    }
    else{
        printf("top value from false:%d\n",top);
        return false;
    }
}

bool parenthesisMatch(char exp[]){
    int i =0;
    while(exp[i] != '\0'){
        if(exp[i] == '('){
            push(exp[i]);
            printf("pushed:%c \n",stack[top]);
            printf("top value: %d\n",top);
        }

        else if(exp[i] == ')'){
            if(isEmpty()){
                return false;
            }
            printf("popped: %c\n",pop());
        }
        i++;
    }
    if(isEmpty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    char expression[20];
    
    printf("Enter expression: ");
    scanf("%s",expression);
    
    if(parenthesisMatch(expression)){
        printf("\nBrackets are balanced");
    }
    else{
        printf("\nBrackets are not balanced");
    }
    return 0;
}