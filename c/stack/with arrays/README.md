# Documentation
# stackarr.h  

This header file is a comprehensive implimentation of the stack in C.  

This documnetation will guide you through the various functions in the header file.  
But however in order to use this header file, you have to first have it in your inlcude directory.  

Linux users, can simply use wget to get this in the include directory by the following steps  
```shell  
cd /usr/include  

wget https://raw.githubusercontent.com/rgautam98/data-structures/master/c/stack/with%20arrays/stackarr.h 
```  

This version of the header file impliments the stack using arrays.  

The functions in the header are implimented using the structure  
```c
struct astack
{
    int n;
    int *a;
};
```

Here the *a is the pointer which is actually the stack. n is the the variable that counts the elements in the stack.   

At the beginnng of the C program, you are required to declare the stack variable using the keyword **astack**.  
A sample decleration is as follows  
```c
struct astack s
```
The elements of the stack can accessed just like an array of pointers in a structure. The structure variable I took is s, and
the pointer is a.  

*Hence the i th element of the stack can be obtained by s.a[i], for i < s.n, which is the maximum number of elements in the stack.  *  

**In the rest of the docummentation, I will refer the refer the stack by the structure variable s**

Before using the structure, and the headerfile, you have to initilise the stack. This can be done by writing 

```c
init(&s);
```
line after you declare the structure. Failing to do so will lead to errors in the program. I have used s here as an example.

This acts as a constructor for the stack.

Comming to the functions, the functions are classified into 2 types.  

* The traditional functions  
* The other functions (The functions I created in order to have maximum scalibility with the stack)

# The Traditional Functions

These are the traditional functions that are generally implimented in a stack.  

### int push(struct astack *s,int inse)

This is the push function in the stack, 
which takes in 2 argumments.  
The first argumment is the pointer which points to the location of the stack, and the second argumment is the element to be inserted.  
The general syntax goes something like  
```c
push(&s,inse);
```  
This pushes the data stored in the  variable "inse" into the stack "s".

This return true if the push is successful, and take it for granted, the element will be pushed as there is no limit and 
if the syntax entered is correct.  

### int pop(struct astack *s)  

This removes (pop's) the last element from the stack.  
**Syntax:**
```c
pop(&s);
```  

### int peek(struct astack *s)  

This returns the last element of the stack.  

**Syntax:**  
```c
var = peek(&s);
/*
Here the variable "var " contains the last entered element of the stack. 
*/
```  

And that's it for the traditional functions. I did not add the *IsFull()* and the *IsNull()* functions as the stack
made using this library is of **infinite** size, and it is never full. So lot of memory to play with.  

# The Other Functions  

So that's it for traditional functions. Now I am going to introduce you to the new(custom/other) functions which actually
make working with stacks a little fun.  

With these functions, I can no more call this a stack, as a stack is supposed to follow only the LIFO (Last In First Out)
rule. But these functions help you to use the array in a different ways.

But I did not get a good name for this type of data type. All Suggestions are welcome.  

So lets dive into the functions.  

### int sinsert(struct astack *s, int index, int inse)  

This function is used to insert an element(inse), at the given "index". This breaks the LIFO rule. 
which takes in 3 argumments.  
The first argumment is the pointer which points to the location of the stack, 
and the second argumment is the index (or the position) of the element to be inserted, and the third argumment is the 
value of the element to be inserted.  

**Syntax:**  
```c

sinsert(&s,index,element);

/* Here index is the position to which the element has to be inserted and element
is the variable holding the value of the element
*/
```  

### int sort(struct astack *s)  
This function sorts the array in ascending order.  
**Syntax:**  
```c
sort(&s);
```  

### int del(struct astack *s,int inse)  

This function deletes the sent element, encountered for the first time, from the array.  
**Syntax:**  
```c
del(&s , element_to_be deleted);
/*
This function takes in 2 argumments, the first argumment being the locaton of the structre in the memory ( the address )
and the second argumment is the value of the element to be deleted.  
*/
```

### void traverse(struct astack *s)  

This function is used to traverse the elements of the arrav.  

**Syntax:**  
```c 
traverse(&s);
```  

### void save(struct astack *s)  
This function saves the data in the array in a text file, with the name " stack.txt ", for further reference.  

**Syntax:**  
```c
save(&s);
```

So this is the end of the docummentation of the **stackarr.h**. Hope this library helps you in some way or the other.  
This library is open to all,and any new changes or edits are welcome.  

For any doubts, any explanation or any bugs, I will be on Gitter, the link for the Gitter channel is in the README of the repository.  

