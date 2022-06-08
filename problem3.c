#include<stdio.h>
#include<stdlib.h>

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

void display(struct stack *s){
    
    printf("Elements in the stack are: ");
    if(s->top==-1){
        printf("Stack is empty!");
        return;
    }
    for(int i=s->top;i>=0;i--){
        printf("%d\n",s->arr[i]);
    }
}

void displayRev(struct stack *s){
    for(int i=0;i<=s->top;i++){
        printf("%d\n",s->arr[i]);
    }
}

int main(){
    
    int value;
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    printf("Enter size of array: ");
    scanf("%d",&s->size);
    s->arr=(int *)malloc(s->size*sizeof(int));
    s->top=-1;
    printf("Enter elements in the stack: \n");
    for(int i=0;i<s->size;i++){
        scanf("%d",&value);
        push(s,value);
    }
    display(s);
    printf("Stack in reverse order: \n");
    displayRev(s);
    return 0;
}
 