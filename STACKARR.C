#include<stdio.h>
#include<conio.h>
#define size 5
int s[size];
int top=-1;
void push(void);
void pop(void);
void display(void);
void main()
{
int choice;
while(1){
printf("enter your choice:\n");
printf("1:push\n2:pop\n3:display\n4:exit\n");
scanf("%d",&choice);
{
switch(choice)
{
case 1:push();
	break;
case 2:pop();
	break;
case 3:display();
	break;
case 4:exit(0);
}
}
}
}
void push()
{
int ele;
if(top==size-1)
{printf("stack overflow\n");}
else
{
printf("enter item to be inserted\n");
scanf("%d",&ele);
top++;
s[top]=ele;
}
}
void pop()
{
int ele;
if(top==-1)
{printf("stack underflow\n");}
else
{
ele=s[top];
printf("item deleted from stack %d",ele);
top--;
}
}
void display()
{
int i;
if(top==-1)
{printf("stack is empty\n");}
else
{
for(i=top;i==0;i++)
{
printf("%d",s[i]);
}
}
}