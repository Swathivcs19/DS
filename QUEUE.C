#include<stdio.h>
#include<conio.h>
#define size 5
int q[size];
int rear=-1,front=-1;
void enqueue(void);
void dequeue(void);
void display(void);
void main()
{
int chioce;
while(1){
printf("enter your choice\n");
printf("1:enqueue\n2:dequeue\n3:display\n4:exit\n");
scanf("%d",&chioce);
switch(chioce)
{
case 1:enqueue();
	break;
case 2:dequeue();
	break;
case 3:display();
	break;
case 4:exit(0);
	break;
default:printf("you have entered an invalid option\n");
}
}
}
void enqueue()
{
int ele;
if(rear==size-1)
{printf("queue overflow\n");}
else
{
printf("enter element to be inserted\n");
scanf("%d",&ele);
rear=rear+1;
q[rear]=ele;
}
}
void dequeue()
{
int ele;
if(front==-1&&front>rear)
{printf("queue underflow\n");}
else
{
ele=q[front];
printf("item deleted from queu is %d",ele);
front=front+1;
}
}
void display()
{
int i;
if(front==-1)
{printf("queue is empty\n");}
else
{
for(i=front;i<rear;i++)
{printf("%d",q[i]);}
printf("%d",q[i]);
}
}




