/* to perform the insertion, sorting and the deletion in an array */



#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define True 1
#define False 0

int main()
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
    printf("Press\n\n\t 1. To insert,\n\n\t 2. To append,\n\n\t 3. For sorting,\n\n\t");
    printf(" 4. For deletion,\n\n\t 5. To traverse the elements of the array\n\n\t 7. To quit the application\n\n\t");
    scanf("%d",&i);
    i--;
     system("clear");
///////////////////////////    INSERT    //////////////////////////////////////////////

     if(i==0)
     {

    //int index;

    x:
    printf("Enter the position of the element you want to insert to (starting from 1, to %d):  ",n);
    scanf("%d",&index);
    index--;
    if(index>=n)
    {
      printf("This is way out of the limit. Please try again\n\n");
      goto x;
    }
    printf(" \n\nEnter the element you want to insert to:  ");
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
    printf(" \n\nEnter the element you want to insert to:  ");
    scanf("%d",&inse);

    n++;
    realloc(a,n*sizeof(int));
    a[n-1]=inse;
    }
//////////////////////////////  SORTING      ////////////////////////////////////////////////////////////
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
         int flag=0;
         printf("Enter the element you want to delete:   ");
         scanf("%d",&inse);
         for(i=0;i<n;i++)
            if(a[i]==inse)
                 flag=1;

        if(flag)
       {
         for(j=i;j<n;j++)
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
        printf("__________________________________________________________________\n\n");
        for(i=0;i<n;i++)
             printf(" %d  ",a[i]);

        printf("\n\n__________________________________________________________________");

  }


///////////////////////////////////         EXIT        //////////////////////////////////////////////////////////
  else if(i==5)
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
