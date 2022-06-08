#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct queue{
	int rear;
	int front;
	int max_size;
	int *arr;
}QU;

void create(QU *p)
{
	printf("Enter the size of the queue = ");
	scanf("%d",&(p->max_size));
	p->front=-1;
	p->rear=-1;
	p->arr=(int *)malloc(sizeof(int)*(p->max_size));
	return;
}

bool isfull(QU p)
{
	if(p.rear+1==p.max_size)
		return true;
	else
		return false;
}

bool isempty(QU p)
{
	if((p.rear==-1)&&(p.front==-1))
		return true;
	else
		return false;
}

void enqueue(QU *p,int n)
{
	if(isfull(*p))
	{
		printf("Overflow\n");
		return;
	}
	else if(isempty(*p))
	{
		p->front=0;
		p->rear=0;
	}
	else
		p->rear++;
	p->arr[p->rear]=n;
	printf("Element Enqueueed\n");
	return;
}

int dequeue(QU *p)
{
	int x;
	if(isempty(*p))
	{
		printf("Underflow.\n");
		return(-1);
	}
	x=p->arr[p->front];
	if(p->front==p->rear)
	{
		p->front=-1;
		p->rear=-1;
	}
	else
		p->front++;
	return(x);
}

int getfront(QU p)
{
	if(isempty(p))
	{
		printf("Underflow\n");
		return(-1);
	}
	return(p.arr[p.front]);
}

void display(QU p)
{
	int i;
	if(isempty(p))
	{
		printf("Queue is empty\n");
		return;
	}
	for(i=0;i<p.max_size;i++)
	{
		if(i<p.front||i>p.rear)
			printf("  ");
		else
			printf("%d    ",p.arr[i]);
	}
	printf("\n");
	return;
}

int main()
{
	QU q;
	int x,c;
	create(&q);
	do
	{
		printf("\nEnter your choice :\nEnter 0 for exit\nEnter 1 for enqueue\nEnter 2 dequeue\nEnter 3 for get the front element\n");
		scanf("%d",&c);
		switch(c)
		{
			case 0:
				break;
			case 1:
				printf("Enter the element to be enqueued = ");
				scanf("%d",&x);
				enqueue(&q,x);
				display(q);
				break;
			case 2:
				if((x=dequeue(&q))!=-1)
					printf("Dequeued element is = %d\n",x);
				display(q);
				break;
			case 3:
				if((x=getfront(q))!=-1)
					printf("Front element is = %d\n",x);
				display(q);
				break;
			default:
				printf("Enter a valid option between 0 to 3\n");
				break;
		}
	}while(c!=0);
	return(0);
}
