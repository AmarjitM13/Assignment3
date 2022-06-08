#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct stack{
    int size;
    int top;
    int *arr;
};

void push(struct stack *s,int value){
    if(s->top == s->size-1){
            printf("Stack overflow!");
            return;
        }
        else{
            s->top++;
            s->arr[s->top]=value;
        }
}

bool checkEquality(struct stack *s1, struct stack *s2){
    if(s1->size != s2->size){
        return 0;
    }
    else{
        for(int i=s1->top;i>=0;i--){
            if(s1->arr[i] == s2->arr[i]){
                continue;
            }
            else{
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    int value;
    struct stack *s1=(struct stack *)malloc(sizeof(struct stack));
    struct stack *s2=(struct stack *)malloc(sizeof(struct stack));
    
    printf("Enter size of stack 1: ");
    scanf("%d",&s1->size);

    printf("Enter size of stack 2: ");
    scanf("%d",&s2->size);


    s1->arr=(int *)malloc(s1->size*sizeof(int));
    s1->top=-1;

    s2->arr=(int *)malloc(s2->size*sizeof(int));
    s2->top=-1;

    printf("Enter elements in the stack 1: \n");
    for(int i=0;i<s1->size;i++){
        scanf("%d",&value);
        push(s1,value);
    }

    printf("Enter elements in the stack 2: \n");
    for(int i=0;i<s2->size;i++){
        scanf("%d",&value);
        push(s2,value);
    }
    if(checkEquality(s1,s2)){
        printf("Stacks are equal");
    }
    else{
        printf("Stacks are not equal");
    }
    return 0;
}
