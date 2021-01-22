#include<stdlib.h>
struct node
{ int data;
struct node *link;
};
struct node *TOP=NULL;
void push()
{ struct node *ne=(struct node*)malloc(sizeof(struct node));
if(ne==NULL)
{ printf(&quot;out of memory&quot;);
return;
}
printf(&quot;\nEnter the element to push\n&quot;);
scanf(&quot;%d&quot;,&amp;ne-&gt;data);
ne-&gt;link=TOP;
TOP=ne;
}
void pop()
{struct node *ptr;
if (TOP==NULL)
{ printf(&quot;stack empty&quot;);
return;
}
printf(&quot;poped the element %d\n&quot;,TOP-&gt;data);
ptr=TOP;
TOP=TOP-&gt;link;
free(ptr);
}
void search()
{ struct node *ptr;
int x,pos=1;
if (TOP==NULL)
{ printf(&quot;\nstack is empty&quot;);
return;

}
ptr=TOP;
printf(&quot;Enter the element to be searhed\n&quot; );
scanf(&quot;%d&quot;,&amp;x);
while(ptr!=NULL)
{ if(ptr-&gt;data==x)
{ printf(&quot;\nElement found at %d the position from
top\n&quot;,pos);
break;
}
ptr=ptr-&gt;link;
pos++;
}
if (ptr==NULL)
printf(&quot;Element not found&quot;);
}
void display()
{ struct node *ptr=TOP;
if (TOP==NULL)
{ printf(&quot;\nstack is empty&quot;);
return;
}
ptr=TOP;
printf(&quot;\nThe Elements are:\n&quot;);
while(ptr!=NULL)
{printf(&quot;%d &quot;,ptr-&gt;data);
ptr=ptr-&gt;link;
}
}
void main()
{ int ch=0;
clrscr();
while(ch!=5)
{
printf(&quot;\nMENU\n1.PUSH\n2.POP\n3.SEARCH\n4.DISPLAY\n5
.EXIT \nEnter ur choice&quot;);

scanf(&quot;%d&quot;,&amp;ch);
switch(ch)
{ case 1:push();
break;
case 2:pop();
break;
case 3:search();
break;
case 4:display();
break;
case 5:printf(&quot;good by&quot;);
getch();
}
}
}
