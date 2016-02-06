/*

           Copyright (C) 2016, B.Raghavendra Gautam (rgautam98)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.


 Header File for the implimentation of the stack operations in the C/C++ program

The Docummentation for the header file can be obtained at:

https://github.com/rgautam98/data-structures/blob/master/c/stack/with%20arrays/README.md

*/

#ifndef STACKARR_H
 #define STACKARR_H

#ifndef _STDIO_H
#include<stdio.h>
#endif

#ifndef _STDLIB_H
#include<stdlib.h>
#endif

#ifndef _MALLOC_H
#include<malloc.h>
#endif


// some global variables commonly used in the functions

int i,j;

struct astack
{
    int n;
    int *a;
};

void init(struct astack *s)
{
   s->n=0;
   s->a=(int *)malloc(1*sizeof(int));
}
   
   ///////////////////////////////          INSERT    ///////////////////////////////////////////////
 int sinsert(struct astack *s,int index,int inse)
   {
    if(index>s->n)
    {
      fprintf(stderr,"Error: index out of the range.\n\n");
      return 0;
    }
    s->n++;
    realloc(s->a,s->n*sizeof(int));
    
    for(i=s->n-2;i>=index;i--)
            s->a[i+1]=s->a[i];

    s->a[index]=inse;
    
    return 1;
   } // done

     ////////////////////////////  APPEND  or PUSH ////////////////////////////////////////////////////

    int push(struct astack *s,int inse)
    {

     if((s->n)==0)
     {
         s->a[0]=inse;
         s->n++;
         return 1;
     }

      s->n++;
      realloc(s->a,s->n*sizeof(int));
      s->a[s->n-1]=inse;
      return 1;

    } // done

     ///////////////////////////////////  SORT  /////////////////////////////////////////////////////////

    int sort(struct astack *s) // sorting
    {
     for(i=0;i<s->n;i++)
      for(j=i+1;j<s->n;j++)
          if(s->a[i]>s->a[j])
                s->a[i]=s->a[i]+s->a[j]-(s->a[j] = s->a[i]);
    } // done

////////////////////////////////////////   DELETE    ////////////////////////////////////////////////////////
     int del(struct astack *s,int inse)
     {
         int flag=0,k;
         for(i=0;i<s->n;i++)
            if(s->a[i]==inse)
                 flag=1,k=i;
        if(flag)
       {
         for(j=k;j<s->n;j++)
                s->a[j]=s->a[j+1];

         s->n--;
         realloc(s->a,s->n*sizeof(int));
         return 1;
      }
       else
       {
          fprintf(stderr,"element not found\n\n");
          return 0;
       }
     }
/////////////////////////        POP    ///////////////////////////////////

int pop(struct astack *s)
{
   s->n--;
   realloc(s->a,s->n*sizeof(int));
   return 1;
}

//////////////////          PEEK        ////////////////////////////////////

int peek(struct astack *s)
{
   return s->a[(s->n)-1];
}

//////////////////////////////////////////       TRAVERSE         /////////////////////////////////////////////////////

  void traverse(struct astack *s)
  {
        printf("\n\n The elements are:\n\n");
        printf("====================================================================================================\n\n");
        for(i=0;i<s->n;i++)
             printf(" %d  ",s->a[i]);

        printf("\n\n======================================================================================================");

        return;

  } // done

  ///////////////////////////////    CLEAR THE MEMORY. ////////////////////////////////////////////////////////////

/* This function, clrmem(struct astack *); is still under development and is not operational.
 *
 * */


///////////////////////////////////         EXIT        //////////////////////////////////////////////////////////
  void save(struct astack *s)
  {
     printf("You are now quitting \n\nPress \" 1  \" to save the data or \"  2  \" to quit without saving \n\n\t:     ");
     scanf("%d",&i);

     if(i==1)
     {
        FILE *rg;
        rg = fopen("stack.txt","w");
        fprintf(rg,"The data present in the STACK is\n\n");
        fprintf(rg,"________________________________________________________________\n\n");

        for(i=0;i<s->n;i++)
               fprintf(rg," %d  ",s->a[i]);

       fprintf(rg,"\n\n_________________________________________________________________");

       fclose(rg);

       printf("\n\n\n The Stack has been stored in the file named \" stack.txt \"\n\n");
     }
  }


#endif
