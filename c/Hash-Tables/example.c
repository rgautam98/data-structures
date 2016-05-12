
#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>

#include<string.h> // This is for the typeofvar() function, located in typeof.c

// Now the functions from the hash table
#include"hash-table.h"

//extern struct node;

int main()
{
    int choice,pos,data,indexNo;
    struct index *start=NULL;
    system("clear");
    while(1)
    {
    	printf("\n\n =========================================================================================================================\n\n");
    	display(start);
    	printf("\n ==========================================================================================================================\n\n\n");
    printf("\t\tWelcome to the data base. \n\n\n");
    printf("Please enter your choice.\n\n 1. To insert an index.\n\n 2. To append a Index. \n\n 3. To Insert a node. \n\n");
    printf(" 4. To Append a node. \n\n 5. To delete an Index \n\n 6. To delete a node \n\n 7. To Display. \n\n 8. To exit\n\n\t:  ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: //  insert_index
            printf("Enter the data (to be inserted into the index):  ");
            scanf("%d",&data);
            printf("Enter the position you want to insert the Index:  ");
            scanf("%d",&pos);
            start=insert_index(start,data,pos);
            break;
        case 2: // append_index
            printf("Enter the data (to be inserted into the index):  ");
            scanf("%d",&data);
            start=append_index(start,data);
            break;
        case 3: // insert_node
            printf("Enter the data (to be inserted into the node):  ");
            scanf("%d",&data);
            printf("Enter the position you want to insert into the node: ");
            scanf("%d",&pos);
            printf("Enter the index number you want to insert the node:  ");
            scanf("%d",&indexNo);
            start=insert_node(start,pos,data,indexNo);
            break;
        case 4: // append node
            printf("Enter the data (to be inserted into the node):  ");
            scanf("%d",&data);
            printf("Enter the index number you want to insert the node:  ");
            scanf("%d",&indexNo);
            start=append_node(start,data,indexNo);
            break;
        case 5: // delete_index
            printf("Enter the data stored inside inside the index:  ");
            scanf("%d",&data);
            start=delete_index(start,data);
            break;
        case 6: // delete_node
            printf("Enter the data stored inside inside the node:  ");
            scanf("%d",&data);
            printf("Enter the index number you want to insert the node:  ");
            scanf("%d",&indexNo);
            start=delete_node(start,data,indexNo);
            break;
        case 7: // Gotcha!!!   this is the display
            printf("\n\n\n");
            display(start);
            break;
        case 8: //  Sad to see you go
            goto last;
        default: // All the best, in your second attempt
            printf("Invalid Option.\n\n");
    }
    printf("\n\nPress ENTER to return to menu. ");
    getchar();
    getchar();
    system("clear");
    }
    last:
            freeallnow(start);
    return 0;
}
