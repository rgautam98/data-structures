/* to perform the insertion, sorting and the deletion, and some more things, in an array of any size.  */



#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define True 1
#define False 0


//long long ago; // IN A GALAXY FAR FAR AWAY, A function called


int main(void)
{
    int n;
     FILE *rg;
    system("clear");
    printf("enter the size of the array: ");
    scanf("%d",&n);
   int *a,i,j,index;

   a=(int *)malloc(n*sizeof(int));

   printf("Enter the elements of the array  : ");

   for(i=0;i<n;i++)
   scanf("%d",a+i);  // &a[i]);

   system("clear");
   int inse;
   while(True)
   {

    system("clear");
    printf("Press\n\n\t 1. To insert,\n\n\t 2. To append,\n\n\t 3. For sorting,\n\n\t 4. For deletion,\n\n\t");
   printf(" 5. To traverse the elements of the array\n\n\t 6. To clear the data and give new input\n\n\t"); 
   printf("7. To quit the application\n\n\t");
    scanf("%d",&i);
    i--;
     system("clear");
///////////////////////////    INSERT    //////////////////////////////////////////////

     if(i==0)
     {

    //int index;

    x:
    printf("Enter the index you want to insert to (starting from 0, to %d):  ",n);
    scanf("%d",&index);
    //index--;
    if(index>n)
    {
      printf("That index, my friend, is way out of the range. Please try again\n\n");
      goto x;
    }
    printf(" \n\nEnter the element:  ");
    scanf("%d",&inse);

    n++;
    realloc(a,n*sizeof(int));
    
    for(i=n-2;i>=index;i--)
            a[i+1]=a[i];

    a[index]=inse;
    printf("\n\nElement has been inserted.\n\n");
    }

     ////////////////////////////  APPEND  ////////////////////////////////////////////////////

     else if(i==1){ //appending
    printf(" \n\nEnter the element:  ");
    scanf("%d",&inse);

    n++;
    realloc(a,n*sizeof(int));
    a[n-1]=inse;
    }

     ///////////////////////////////////  SORT  /////////////////////////////////////////////////////////

    else if(i==2) // sorting
    {
     for(i=0;i<n;i++)
      for(j=i+1;j<n;j++)
          if(a[i]>a[j])
                a[i]=a[i]+a[j]-(a[j]=a[i]);
    printf("\n\nThe list has been sorted. Please traverse the array for confirmation\n\n");
    }

////////////////////////////////////////   DELETE    ////////////////////////////////////////////////////////
     else if(i==3)
     {
         int flag=0,k;
         printf("Enter the element you want to delete:   ");
         scanf("%d",&inse);
         for(i=0;i<n;i++)
            if(a[i]==inse)
                 flag=1,k=i;
        if(flag)
       {
         for(j=k;j<n;j++)
                a[j]=a[j+1];

         n--;
         realloc(a,n*sizeof(int));
         printf("\n\nElement deleted\n\n");
       }
       else
       {
          fprintf(stderr,"element not found\n\n");
       }
     }
 //////////////////////////////////////////       TRAVERSE         /////////////////////////////////////////////////////

  else if(i==4)
  {
        printf("\n\n The elements are:\n\n");
        printf("====================================================================================================\n\n");
        for(i=0;i<n;i++)
             printf(" %d  ",a[i]);

        printf("\n\n======================================================================================================");

  }

  ///////////////////////////////    CLEAR THE MEMORY        ////////////////////////////////////////////////////////////
  
  else if(i==5)
  {
     printf("Are you absolutely sure that you want to delete the data in the stack.");
     printf(" Press \" 1 \" to confirm or \" 2  \" to quit.\n\n\t");
     scanf("%d",&j);

     if(j==1)
     {
        free(a);
        printf("\n\nThe memory has been cleared. \n\n");  // Please Enter the new size of the stack.\n\n\t");
        a = (int *)malloc(1*sizeof(int));
        n=0;
        printf("The new stack has been created. You can now head to the main menu to add new elements to the stack.\n\n");

     }

  }


///////////////////////////////////         EXIT        //////////////////////////////////////////////////////////
  else if(i==6)
  {
     printf("You are now quitting the application \n\nPress \" 1  \" to save the data or \"  2  \" to quit without saving      ");
     scanf("%d",&i);

     if(i==1)
     {
        rg=fopen("data.txt","w");
        fprintf(rg,"The data present in the array is\n\n");
        fprintf(rg,"________________________________________________________________\n\n");

        for(i=0;i<n;i++)
               fprintf(rg," %d  ",a[i]);

       fprintf(rg,"\n\n_________________________________________________________________");

       fclose(rg);

       printf("Thank you for using the application. The data in the array has been stored in the file named \" data.txt \"\n\n");

      //return 0;
     }

     printf("\n\nThank you \n\n");
     return 0;
  }
///////////////////////////////////               GET BACK TO MAIN       ///////////////////////////////////////////////////
    else
    fprintf(stderr,"INVALID OPTION. Please try again\n\n");
     int ch;
     printf("\n\n\n\n\n\n\n\nPress \"1\" to go to the main menu\n\t");
     scanf("%d",&ch);
  }
   return 0;
}

// Did all the above said functions, in a C program.
//
// I'snt it Awesome!!!
