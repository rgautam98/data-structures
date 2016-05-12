/* This program is a collection of functions for the implementation of a hash table, in the C programming language.
  */

/*
 * BUGS:
 * 			Till now, not any, but need to check for extremely large values. Will file then
 */

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"hash-table.h"

struct node
{
    int data;
    struct node *next_node;
};

struct index
{
    int data,node_count;
    struct index *next_index;
    struct node *start;
};

struct index *insert_index(struct index *start,int data,int pos)
{
    int i;
    struct index *tmp,*toInsert;
    tmp = start;
    toInsert = (struct index *)malloc(sizeof(struct index));
    toInsert->data = data;
    toInsert->start = NULL;
    toInsert->node_count=0;
    if(pos==0||start==NULL)
    {
        toInsert->next_index = start;
        start = toInsert;
    }
    else
    {
      for(i=0;i<pos && tmp!=NULL;i++)
      {
          tmp = tmp->next_index;
          if(tmp == NULL)
          {
            printf("ERROR: Exceeded the limit of the list. Insert operation canceled.\n\n");
            free(toInsert);
            return start;
          }
      }
      if(tmp!=NULL)
         toInsert->next_index = tmp->next_index;
      else
          toInsert->next_index = NULL;

      tmp->next_index = toInsert;
    }

    return start;
}

struct index *append_index(struct index *start,int data)
{
    struct index *tmp, *toInsert;
    tmp = start;
    toInsert = (struct index *)malloc(sizeof(struct index));
    toInsert->data = data;
    toInsert->start = NULL;
    toInsert->next_index=NULL;
    toInsert->node_count=0;

    if(tmp==NULL)
    {
    	start=toInsert;
    	return start;
    }
    while(tmp->next_index!=NULL)
        tmp = tmp->next_index;
    tmp->next_index = toInsert;

    return start;
}

struct index *insert_node(struct index *start_I, int pos, int data, int indexNo)
{
	// This function has too be duly tested
	struct index *tmp_I=start_I;
    struct node *tmp=start_I->start,*toInsert;
    int i;

// We first get the index, which holds the series of nodes

  for(i=0;i<indexNo;i++)
   {
  	   if(tmp_I==NULL)
  	   {
  		   printf("ERROR:  Invalid Index count. Insertion operation cancelled. \n\n");
  		   return start_I;
  	   }
         tmp_I=tmp_I->next_index;
   }

  tmp=tmp_I->start;
  toInsert = (struct node *)malloc(sizeof(struct node));
  toInsert->data = data;
  if(pos > tmp_I->node_count)
  {
    printf("ERROR: Position exceeds limit. Insertion aborted\n\n");
    free(toInsert);
    return start_I;
  }

  // Now that we have the required index, we need to insert the node. This sometimes can get tricky

  if(pos==0 || tmp==NULL)
  {
	  // i.e, here we are inserting the starting position, of the index, or in other words, the "tmp_I->start" position
    toInsert->next_node=tmp_I->start;
    tmp_I->start = toInsert;
    tmp_I->node_count++;
    return start_I;
  }

  // else
  for(i=0;i<pos-1 && tmp->next_node!=NULL;i++)
  {
	  // Just get the node you need, mainly the one before, you need to insert
	  // If you do not understand, the above statement, please go through the code :)
    if(tmp==NULL)
    {
        printf("ERROR: Index exceeded the limit. Invalid Index \n\n\n");
        free(toInsert);
        return start_I;
    }
    tmp = tmp->next_node;
  }

  toInsert->next_node=tmp->next_node;
  tmp->next_node= toInsert;
  tmp_I->node_count++;
  return start_I;
}

struct index *append_node(struct index *start_I, int data, int indexNo)
{
   struct index *tmp_I=start_I;
   struct node *start,*tmp = start_I->start, *toInsert;
   int i;

   for(i=0;i<indexNo;i++)
   {
	   if(tmp_I==NULL)
	   {
		   printf("ERROR:  Invalid Index count. Appending operation cancelled. \n\n");
		   return start_I;
	   }
       tmp_I=tmp_I->next_index;
   }

   // and now we get the node starting of the linked list
   tmp=tmp_I->start;
   start=tmp_I->start;
   toInsert = (struct node *)malloc(sizeof(struct node));
   toInsert->next_node=NULL;
   toInsert->data = data;

   if(tmp==NULL)
   {
       tmp_I->start = toInsert;
       return start_I;
   }

   while(tmp->next_node!=NULL)
           tmp = tmp->next_node;
   tmp->next_node=toInsert;

   start_I->start=start;
   return start_I;
}

// Now that we are done with inserting, lets go for some deletion of elements. No worries, you can add them again :)

struct index *delete_index(struct index *start, int data)
{
	/*
	 * BUGS:
	 *
	 *  -  This function is throwing a segmentation fault, if the index has nodes, especially for the starting node, the "struct node *start" node
	 */
  struct index *tmp=start, *toDelete;
  struct node *temp, *toDel;

  if(data == start->data)
  {
    toDelete = start;
    start=start->next_index;
  }
  else
  {
    while(tmp->next_index->data != data)
    {
        tmp=tmp->next_index;

        if(tmp==NULL)// && tmp->data!=data)
        {
        	printf("The delete operation cancelled. Index not found\n\n");
        	return start;
        }
    }
    toDelete = tmp->next_index;

    if(toDelete->next_index!=NULL)
        tmp->next_index = toDelete->next_index;
    else
    	tmp->next_index =NULL;
  }

  // Delete the nodes in the index now.
  temp=toDelete->start;
  toDel=temp;

  if(toDel!=NULL)
  {
  temp=temp->next_node;
  while(temp!=NULL)// this should be toDel!=NULL
  {
	  free(toDel);
	  toDel=temp;
	  temp=temp->next_node;
  }
  }


  if(toDel!=NULL)
      free(toDel);
   /*
   This is because, we are checking upto the temp!=NULL condition. This will not remove the last node from the linked list, when in the loop. So in  order to do this, we need to free the last element also.
   */
   free(toDelete);
   return start;
}

struct index *delete_node(struct index *start_I, int data, int indexNo)
{
  struct index *tmp_I=start_I;
  struct node *tmp=start_I->start, *toDelete;
  int i;
  for(i=0;i<indexNo;i++)
  {
		  if(tmp_I==NULL)
		    {
		       printf("ERROR:  Invalid Index count. Deletion operation cancelled. \n\n");
		       return start_I;
		    }
	  tmp_I=tmp_I->next_index;
  }

  tmp=tmp_I->start;
  if(tmp==NULL)
  {
	   printf("Nodes  do not exist. Deletion operation cancelled \n\n\n");
       return start_I;
  }

  // Now that we have the index you need, then we have to go for deleting the node

  if(data == tmp->data)
  {
	  // If we want to delete the first node, then
    toDelete = tmp;
    if(tmp->next_node!=NULL)
        tmp_I->start=tmp->next_node;
    else
    	tmp_I->start=NULL;
  }
  else
  {
	  // Or else, then just get the correct node, and voila
    while(tmp->next_node->data != data)
    {
        if(tmp==NULL)
        {
        	printf("The deletion operation is not possible. The data passed is not valid. \n\n\n\n");
        	return start_I;
        }
        tmp=tmp->next_node;
    }
    toDelete = tmp->next_node;
    tmp->next_node = toDelete->next_node;
  }
  free(toDelete);
  return start_I;
}

// With this function, you can delete the whole hash table.
void *freeallnow(struct index *start)
{

    struct index *tmp=start, *toDelete;
    struct node *tmp_node, *toDelete_node;
    while(tmp!=NULL)
    {
        toDelete=tmp;
        tmp=tmp->next_index;
        tmp_node=toDelete->start;
        while(tmp_node!=NULL)
        {
            toDelete_node=tmp_node;
            tmp_node = tmp_node->next_node;
            free(toDelete_node);
        }
        free(toDelete);
    }
    return NULL;
}

/* Now that you have an insertion and a deletion, in order to see the data, you have to have a display function.
 *
 * And Bingo. Here it is.
 */
void display(struct index *start)
{
    struct index *tmp=start;
    struct node *tmp_node;
    while(tmp!=NULL)
    {
        printf("  --> %d :  ",tmp->data);
        tmp_node=tmp->start;
        while(tmp_node!=NULL)
        {
            printf("  %d",tmp_node->data);
            tmp_node = tmp_node->next_node;
        }
        tmp=tmp->next_index;
        printf("\n\n");
    }
    return;
}
