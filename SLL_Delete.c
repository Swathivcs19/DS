/***************************************************************

Write a Program To Implement Single Linked List With Following Operations.

	a) Create a Linked List.
	b) Deletion Of First Element, Specified Element & Last Element in the List.
	c) Display The Contents Of The Linked List.

********************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
  int data;
  struct node *next;
};

typedef struct node *NODE;

NODE get_node ()
{
  NODE temp;
  temp = (NODE) malloc (sizeof (struct node));
  if (temp == NULL)
    printf ("No Memory..!!");
  else
    return temp;
}

//Inserts or Create a Linked List...
NODE create(NODE head,int item)
{
    NODE p,temp;
    p = get_node();
    p->data = item;
    p->next = NULL;
    if(head == NULL)
    {
        printf("\nInserted Successfully..!");
        return p;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
        printf("\nInserted Successfully..!");
        return head;
    }
}

//DELETES FROM THE BEGINING...
NODE delete_beg (NODE head)
{
  NODE p;
  if (head == NULL)
    {
      printf ("\nThere is No Element For Deletion...List is Empty..!");
      return head;
    }
  else
    {
      p = head->next;
      printf ("\n Item %d is Deleted.!", head->data);
      free (head);
      return p;
    }
}

//DELETES FROM THE END...
NODE delete_end (NODE head)
{
  NODE prev = NULL, curr = head;;
  if (head == NULL)
    {
      printf ("\nThere is No Element For Deletion...List is Empty..!");
      return head;
    }
  if (curr->next == NULL)
    {
      printf ("Item %d is Deleted..!", curr->data);
      free (curr);
      return NULL;
    }
  else
    {
      while (curr->next != NULL)
	{
	  prev = curr;
	  curr = curr->next;
	}
      printf ("Item %d is Deleted..!", curr->data);
      prev->next = NULL;
      free (curr);
    }
}

//DELETES FROM THE SPECIFIED LOCATION...
NODE delete_pos (NODE head, int pos)
{
    NODE prev=NULL,curr=head;
    int count = 1;
    if(head==NULL)
    {
        printf("\nThe List is Empty..No Element For Deletion..!!");
        return head;
    }
    if (curr->next == NULL&&pos==1)
    {
      printf ("Item %d is Deleted..!", curr->data);
      free (curr);
      return NULL;
    }
    
    else
    {
        while(curr->next!=NULL&&count!=pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        if(count==pos)
        {
            printf("\nItem %d is Deleted.!",curr->data);
            prev->next = curr->next;
            free(curr);
            return head;
        }
        else
        {
            printf("\nInvalid Position.!!");
            return head;
        }
    }
}

//DELETES BASED ON VALUE...
NODE delete_val(NODE head,int val)
{
   NODE prev = NULL, curr = head;
   int flag = 1;
   if(curr==NULL)
   {
       printf("\nList is Empty..!!");
       return head;
   }
   if(curr!=NULL&&curr->data==val)
   {
       head = curr->next;
       printf("Item %d is Deleted.!",curr->data);
       free(curr);
       return head;
   }
   else
   {
       while(curr->next!=NULL)
       {
           prev = curr;
           curr = curr->next;
           if(curr->data==val)
           {
            prev->next = curr->next;
            printf("\nItem %d is Deleted..!",curr->data);
            free(curr);
            flag = 0;
            return head;
           }
       }
       if(flag==1)
       {
        printf("The Element %d is Not Found in the List.",val);
        return head;
       }
   }
}

//DISPLAYS THE CONTENTS OF THE LIST...
void display (NODE head)
{
  NODE p;
  if (head == NULL)
    {
      printf ("\nList is Empty..!There is No Content To Display..!");
    }
  else
    {
      p = head;
      while (p != NULL)
	{
	  printf ("%d->\t", p->data);
	  p = p->next;
	}
    }
}

int main ()
{
  NODE head = NULL;
  int item, choice;
  int pos,val;
  
  do
    {
      printf ("\n-------------");
      printf ("\nMain Menu\n");
      printf ("--------------\n");
      printf ("The Choices Are : ");
      printf ("\n1.Create.\n2.Delete From Front.\n3.Delete From End.\n4.Delete From Specified Location.\n");
      printf ("5.Delete Based On Value.\n6.Display.\n7.Exit.\n");
      printf ("\nEnter Your Choice : ");
      scanf ("%d", &choice);

      switch (choice)
	{
	case 1 :
	  printf ("\nEnter The Element To Be Inserted : ");
	  scanf ("%d", &item);
	  head = create (head, item);
	  break;

	case 2 : 
	  head = delete_beg (head);
	  break;

    	case 3 :
      	  head = delete_end (head);
	  break;
	  
	case 4:
	  printf ("\nEnter The position : ");
	  scanf ("%d", &pos);
	  head = delete_pos (head, pos);
	  break;

	case 5:
	  printf("\nEnter The Value To Be Deleted : ");    
     	  scanf("%d",&val);
      	  head = delete_val(head,val);
     	  break;

	case 6:
	  display (head);
	  break;

	case 7:
	  exit(0);
	  break;
      
	default:
	  printf ("\nInvalid Choice..!!");
	}
    }
  while (choice != 7);
  return 0;
}
