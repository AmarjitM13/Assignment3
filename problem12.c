#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STACK_MAX 50

typedef struct qNode{
    int value;
    struct qNode *next;
}QNODE;


typedef struct queue{
    QNODE *front , *rear;
}QUEUE;


typedef struct stack{
    int value[STACK_MAX];
    int top;
}STACK;



int isEmpty(QUEUE *q);
QUEUE* createNewQueue(void);
void enqueue(QUEUE *q, int value);
int dequeue(QUEUE *q);
int peekQueue(QUEUE *q);
bool twoQueueComparison(QUEUE *q1, QUEUE *q2);
//void reverseQueueUsingStack(QUEUE *q, STACK *s);
STACK* intitializeStack(void);
int isEmptyStack(STACK *s);
int isFull(STACK *s);
int push(STACK *s, int x);
int pop(STACK *s, int *x);
int peek(STACK *s, int *x);



int main(int argc, const char * argv[]) {
    QUEUE *q1 = createNewQueue();
    QUEUE *q2 = createNewQueue();
    enqueue(q1, 5);
    enqueue(q1, 6);
    enqueue(q2, 5);
    enqueue(q2, 6);
    //enqueue(q2, 27);
    printf("The result of comparison is:\n");
    if(twoQueueComparison(q1, q2) == true){
        printf("two queue are same as inputs\n");
    }else{
        printf("two queue are not the same as inputs\n");
    }
    return 0;
}


int isEmpty(QUEUE *q){
    if(q->front == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int peekQueue(QUEUE *q){
    int dequeuedValue;
    if(isEmpty(q)){
        printf("QUEUE is empty\n");
        exit(0);
    }
    else{
        dequeuedValue = q->front->value;
        return dequeuedValue;
    }
}

QUEUE* createNewQueue(){
    QUEUE *q = (QUEUE*)malloc(sizeof(QUEUE));
    if(q == NULL){
        printf("memory allocation failed!\n");
        exit(0);
    }
    else{
        q->front = q->rear = NULL;
        return q;
    }
}

void enqueue(QUEUE *q, int value){
    QNODE *newNode = (QNODE*)malloc(sizeof(QNODE));
    if(newNode == NULL){
        printf("memory allocation failed\n");
        exit(0);
    }
    else{
        newNode->value = value;
        newNode->next = NULL;
        if(q->front == NULL){
            q->front = q->rear = newNode;
        }
        else{
            q->rear->next = newNode;
            q->rear = newNode;
        }
    }
}

int dequeue(QUEUE *q){
    QNODE *tempNode;
    int dequeuedValue;
    if(isEmpty(q)){
        printf("QUEUE is empty\n");
        exit(0);
    }
    else{
        dequeuedValue = q->front->value;
        tempNode = q->front;
        q->front = tempNode->next;
        free(tempNode);
        if(q->front == NULL){
            q->rear = NULL;
        }
        return dequeuedValue;
    }
}

//void reverseQueueUsingStack(QUEUE *q, STACK *s){
//    if(q->front == NULL){
//        printf("queue is empty\n");
//        exit(0);
//    }
//    while (!isEmpty(q)) {
//        push(s, dequeue(q));
//    }
//    int popStack;
//    while (!isEmptyStack(s)) {
//        pop(s, &popStack);
//        enqueue(q, popStack);
//    }
//}

bool twoQueueComparison(QUEUE *q1, QUEUE *q2){
    QUEUE *tempQueue1 = createNewQueue();
    QUEUE *tempQueue2 = createNewQueue();
    bool functionResult;
    while (!isEmpty(q1) && !isEmpty(q2)) {
        if(peekQueue(q1) == peekQueue(q2)){
            enqueue(tempQueue1, dequeue(q1));
            enqueue(tempQueue2, dequeue(q2));
        }
        else{
            functionResult = false;
            break;
        }
    }
    if(isEmpty(q1) && isEmpty(q2)){
        functionResult = true;
    }else{
        functionResult = false;
        while(!isEmpty(q1)){
            enqueue(tempQueue1, dequeue(q1));
        }
        while(!isEmpty(q2)){
            enqueue(tempQueue2, dequeue(q2));
        }
    }
    while(!isEmpty(tempQueue1)){
        enqueue(q1, dequeue(tempQueue1));
    }
    while(!isEmpty(tempQueue2)){
        enqueue(q2, dequeue(tempQueue2));
    }
    return  functionResult;
}

STACK* intitializeStack(){
    STACK *s = (STACK*)malloc(sizeof(STACK));
    s->top = 0;
    return s;
}


int isEmptyStack(STACK *s){
    if(s->top == 0){
        return 1;
    }else{
        return 0;
    }
}


int isFull(STACK *s){
    if(s->top == STACK_MAX){
        return 1;
    }else{
        return 0;
    }
}

int push(STACK *s, int x){
    if(isFull(s)){
        return 0;
    }else{
        s->value[s->top] = x;
        s->top++;
        return 1;
    }
}

int pop(STACK *s, int *x){
    if(isEmptyStack(s)){
        return 0;
    }else{
        s->top--;
        *x = s->value[s->top];
        return 1;
    }
}

int peek(STACK *s, int *x){
    if(isEmptyStack(s)){
        return 0;
    }else{
        *x = s->value[s->top-1];
        return 1;
    }
}
