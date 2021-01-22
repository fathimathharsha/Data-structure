#include<stdio.h>
#include<conio.h>
#define sz 3
int front=-1,rear=-1;
void insert(int *q)
{
if(front==(rear+1)%sz)
{
printf("queue is full");
return;
}
if(front==-1)
front=0;
rear=(rear+1)%sz;
printf("enter the elements to insert\n");
scanf("%d",&q[rear]);
}
void delet(int *q)
{
if(front==-1)
{
printf("Queue is empty");
return;
}
printf("Deleted elements %d",q[front]);
if(front==rear)
front=rear=-1;
else
front=(front+1)%sz;
return;
}
void search(int *q)
{
int x,f,pos;
if(front==-1)
{
printf("Queue is empty");
return;
}
printf("Enter the elements to be searched\n");
scanf("%d",&x);
f=front;
pos=1;
while(1)
{
if(q[f]==x)
{
printf("Element found location %d",pos);
break;
}
if(f==rear)
{
printf("Element not found");
break;
}
f=(f+1)%sz;
pos=pos+1;
}
}
void display(int *q)
{
int f;
if(front==-1)
{
printf("Q is empty");
return;
}
f=front;
while(1)
{
printf("%d",q[f]);
if(f==rear)
break;
f=(f+1)%sz;
}
}
void main()
{
int q[sz];
int opt;
clrscr();
while(1)
{
printf("Menu\n");
printf("1.INSERT\n 2.DELETE\n 3.SEARCH\n 4.DISPLAY\n 5.EXIT\n Enter the option\n");
scanf("%d",&opt);
switch(opt)
{
case 1:insert(q);
break;
case 2:delet(q);
break;
case 3:search(q);
break;
case 4:display(q);
break;
case 5:printf("Good Bye");
exit();
}
}
}