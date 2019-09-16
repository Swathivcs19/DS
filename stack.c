#include<stdio.h>
#define size 3
struct stack
{
	int top=-1;
	int a[size];
}s1;

void push(int item)
{
	int i;
	if(s1.top=size-1)
	{
		printf("stack overflow\n");
	}
	else
	{
		s1.top++;
		s1.a[i]=item;
		printf("item is pushed into stack\n")
	}
}
void pop()
{
	int item;
	if(s1.top=-1)
	{
		printf("stack underflow\n");
	}
	else
	{
		item=s1.top;
		printf("item is poped out from stack\n");
		s1.top--;
	}
}
void display()
{
	int i;
	if(s1.top=-1)
	{
		printf("stack is empty\n");
	}
	else
	{
		for(i=0;i<size-1;i++)
		printf("%d",s1.a[i]);
	}
}
void main()
{
	int choice;
	int item;
	printf("enter your choice\n");
	printf("1:push 2:pop 3:display 4:exit\n");
	scanf("%d",choice);
	switch(choice)
	{
	case 1:printf("enter the item to be inserted\n");
		scanf("%d",item);
		push(item);
		break;
	
	case 2:pop();
		break;

	case 3:display();
		break;
	
	case 4:exit(0);
	}
}

		
		

