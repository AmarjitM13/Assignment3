//A system which can handle more than one stack
#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

struct stack* insert(struct stack *s){
    int length,value;
    s=malloc(sizeof(struct stack));
    printf("Enter size of current stack: ");
    scanf("%d",&s->size);
    s->arr=(int*)malloc(s->size*sizeof(int));
    s->top=-1;
    printf("\nHow many elements you want to enter: ");
    scanf("%d",&length);
    printf("\nEnter elements in the array:\n");
    for(int i=0;i<length;i++){
        scanf("%d",&value);
        push(s,value);
    }
    return s;
}
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

void pop(struct stack *s){
    if(s->top==-1){
        printf("Stack underflow!");
        return;
    }
    else{
        printf("Popped element: %d",s->arr[s->top]);
        s->top--;
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
int main(){
    
    int n,count,ch,data;
    printf("\nEnter number of stack: ");
    scanf("%d",&n);
    struct stack **container=(struct stack**)malloc(n*sizeof(struct stack*));
    for(int i=0;i<n;i++){
        *(container+i)=insert(*(container+i));
        display(*(container+i));
    }
    printf("1.Push\n2.Pop\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            printf("In which stack you want to push element: ");
            scanf("%d",&count);
            printf("Enter data: ");
            scanf("%d",&data);
            push(container[count-1],data);
            display(container[count-1]);
            break;

        case 2:
            printf("In which stack you want to pop element: ");
            scanf("%d",&count);
            pop(container[count-1]);
            display(container[count-1]);
    }
    return 0;
}
