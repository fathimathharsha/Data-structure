#include&lt;stdlib.h&gt;
struct node
{ struct node *left;
int data;
struct node *right;
} ;
struct node *head=NULL;
struct node * GetNode() ;
void insertLast() ;
void insertFirst();
void display();
void search();
void insertpos();
void deletefirst();
void deletelast();
void deletePos();
void main()
{ int opt=0 ;
while(opt!=9)
{ printf(&quot;\nMenu\n1.INSERT FIRST \n2.INSERT LAST
\n3.INSERT at POSITION\n4.DELETE FIRST \n5.DELETE
LAST \n6.DELETE AT POSITION\n 7.SEARCH \n8.DISPLAY
\n9.Exit \nEnter the Choice:&quot;);
scanf(&quot;%d&quot;,&amp;opt);
switch(opt)
{ case 1:insertFirst();

break;
case 2:insertLast();
break ;
case 3:insertpos();
break;
case 4:deletefirst();
break;
case 5:deletelast();
break;
case 6:deletePos();

break;
case 7:search();
break;
case 8:display();
break;

}
}
printf(&quot;Good Bye&quot;);
getch();
}
void display()
{ struct node *ptr=head;
if (head==NULL)
{ printf(&quot;\n List Empty&quot;);
return;
}
printf(&quot;The Elements are\n&quot;);
while(ptr!=NULL)
{ printf(&quot;%d\t&quot;,ptr-&gt;data);
ptr=ptr-&gt;right;
}
}
struct node * GetNode()
{ int x;
struct node *ne=(struct node *)malloc(sizeof(struct node ));
if (ne==NULL)
printf(&quot;insufficient memory\n&quot;);
else
{ printf(&quot;Enter the value to insert &quot;);
scanf(&quot;%d&quot;,&amp;x);
ne-&gt;left=NULL ;
ne-&gt;right=NULL ;
ne-&gt;data=x;
}
return ne;
}
void insertFirst()

{ struct node *ne;
ne=GetNode();
if (ne==NULL) return;
if (head==NULL)
head=ne;
else
{ head-&gt;left=ne;
ne-&gt;right=head;
head=ne;
}
display();
}
void insertLast()
{ struct node *ne,*ptr;
ne=GetNode();
if (ne==NULL) return;
if (head==NULL)
head=ne;
else
{ ptr=head;
while(ptr-&gt;right!=NULL)
{ ptr=ptr-&gt;right;
}
ptr-&gt;right=ne;
ne-&gt;left=ptr;
}
display();
}
void insertpos()
{ int value;
struct node *ne,*ptr,*ptr1;
ne=GetNode();
if (ne==NULL) return;
if (head==NULL)
{ printf(&quot;List is Empty so the node is inserted as the first
node&quot;);
head=ne;

return;
}
printf(&quot;Enter the key value after which the node has to be
inserted\n &quot;);
scanf(&quot;%d&quot;,&amp;value);
ptr=head;
while(ptr-&gt;right!=NULL &amp;&amp; ptr-&gt;data!=value)
{ ptr=ptr-&gt;right;
}
if (ptr-&gt;right==NULL)
{ ptr-&gt;right=ne;
ne-&gt;left=ptr;
printf(&quot;\n node is inserted at the last position&quot;);
}
else
{ ptr1=ptr-&gt;right;
ne-&gt;right=ptr1;
ne-&gt;left=ptr;
ptr-&gt;right=ne ;
ptr1-&gt;left=ne;

}
printf(&quot;\nthe Element is inserted\n&quot;);
display();
}
void deletefirst()
{ struct node *ptr;
if (head==NULL)
{ printf(&quot;list is empty\n&quot;);
return;
}
ptr=head;
head=head-&gt;right;
if (head!=NULL)
head-&gt;left=NULL;

free(ptr);
display();
}
void deletelast()
{ struct node *ptr,*prev;
if (head==NULL)
{ printf(&quot;\nList is empty\n&quot;);
return;
}
if (head-&gt;right==NULL)
{ free(head);
head=NULL;
}
ptr=head-&gt;right;
while(ptr-&gt;right!=NULL)
{ ptr=ptr-&gt;right;
}
prev=ptr-&gt;left;
prev-&gt;right=NULL;
free(ptr);
display();
}
void deletePos()
{ struct node *ptr,*prev,*next;
int x;
if (head==NULL)
{ printf(&quot;\nlist is empty\n&quot;);
return;
}
printf(&quot;Enter the element to delete; &quot;);
scanf(&quot;%d&quot;,&amp;x);
if (head-&gt;data==x)
{ ptr=head;
head=ptr-&gt;right;
if (head!=NULL)
{ head-&gt;left=NULL;}
free(ptr);

return;
}
ptr=head;
while(ptr-&gt;data!=x &amp;&amp; ptr-&gt;right!=NULL)
{ ptr=ptr-&gt;right;
}
if (ptr-&gt;data==x)
{ next=ptr-&gt;right;
prev=ptr-&gt;left;
prev-&gt;right=ptr-&gt;right;
if (next!=NULL)
next-&gt;left=ptr-&gt;left;
free(ptr);
return;
}
printf(&quot;\nElement not present in the list\n&quot;);
}
void search()
{ struct node *ptr;
int x;
if (head==NULL)
{ printf(&quot;\nLinkedList Empty&quot;);
return;
}
printf(&quot;Enter element to search : &quot;);
scanf(&quot;%d&quot;,&amp;x);
ptr=head;
while(ptr!=NULL)
{ if (ptr-&gt;data==x)
{ printf(&quot;\nElement present in the list\n&quot;);
break;
}
ptr=ptr-&gt;right;
}
if (ptr==NULL)
printf(&quot;\n Element not in the List\n&quot;);

}