/////////////////////////////////////////////////////////////////////////
///CODE FILENAME: Mansfield-ASSN3-INTprog
///DESCRIPTION:   Uses a Stack to reverse order of integers entered.
///  DATE:    	11APR11
///  DESIGNER:	Jason N Mansfield
///  FUNCTIONS: display()
///             *createStack()
///             *pushStackOne()
///             *pushStackTwo()
///             popStack()
///             usersNUM()  
////////////////////////////////////////////////////////////////////////
#include <iostream>

#ifdef _WIN32 
#include <windows.h>
#endif

using namespace std;


struct Stack{
  long int data;
  int count;
  Stack *top;
  Stack *next;
};


void display();
Stack *createStack(Stack*);
Stack *pushStackOne(Stack*, int, int, int);
Stack *pushStackTwo(Stack*, int);
int popStack(Stack*);
int usersNUM();


///////////////////////////////////////////////////////////////////////////
///  FUNCTION:	main()
///  DESCRIPTION:    Cycles through pushing and poping of stack
///  CALLS TO:  display(), userNUM(), createStack(), pushStackOne(), pushStackTwo(),
///             popStack()
//////////////////////////////////////////////////////////////////////////
int main(){
 
  int userInput = 0;
  int outPut = 0;
  int place = 10;
  int rmZero = 0;
  int count = 0;
  //node for second stack
  Stack *node = new(nothrow) Stack;
  if(!node){
    cout << "Allocation Error!" << endl;
    return 1;
  }
  node->count = 0;
  node->data = 0;
  node->top = 0;
  node->next = 0;
  //node for first stack
  Stack *list = new(nothrow) Stack;
  if(!list){
    cout << "Allocation Error!" << endl;
    return 1;
  }
  list->count = 0;
  list->data = 0;
  list->top = 0;
  list->next = 0;
  //display info to user  
  display();
  //get user input integer value
  userInput = usersNUM();
  //create top node with no data
  createStack(list);
  //recursive push function
  //breaks down integer into single integers
  //and pushes to stack
  pushStackOne(list,userInput,place,rmZero);
  //retrieve count value
  count = list->count;
  cout << "You entered: ";
  while(count > 0 ){
    //take new data from stack
    outPut = popStack(list);
    cout << outPut;
    //push outPut integer value into second stack.
    pushStackTwo(node,outPut);
    //count down
    count--;
  }
  cout << endl;
  //now pop again
  cout << "After pushing, and popping the stack twice: " << endl;
  //again get official count from list
  count = node->count;
  while(count > 0 ){
    //pop nodes from stack and get data
    //delete nodes once done.
    outPut = popStack(node);
    //now output findings to user.
    cout << outPut;
    //count down.
    count--;
  }
  cout << endl;
 
#ifdef _WIN32 
  system ("PAUSE");
#endif
  return 0;
}
///////////////////////////////////////////////////////////////////////////
///  FUNCTION:	createStack()
///  DESCRIPTION:   Makes the first and top node for list creation.
///  INPUT:
///  	Parameters: struct Stack* to begin new list 
///  OUTPUT:   
///  	Return Val: struct Stack* list with one top node.
///  	Parameters: all variables are 0
//////////////////////////////////////////////////////////////////////////
Stack *createStack(Stack*){
  Stack *first = new(nothrow) Stack;
  if(!first){
    cout << "Allocation Error!" << endl;
  }
  //set all variables to zero
  first->count = 0;
  first->data = 0;
  first->top = 0;
  first->next = 0;

  return first;
}
///////////////////////////////////////////////////////////////////////////
///  FUNCTION:	pushStackOne()
///  DESCRIPTION:   hybrid version of a normal push function. Added features due
///                 to the fact that this function must be recursive for
///                 this project the breakdown of each int is included with
///                 the normal push algorithm. Another words the number 123
///                 on the first call to this function will be broken down to
///                 merly 3, second call 2 will be recieved, finally 1. They will
///                 then be pushed during each call into the new Stack individually.                 
///  INPUT:
///  	Parameters: Stack* push: the list
///                 data: the single int
///                 numPlace: the place of number 
///                 (EXAMPLE: 123: 2 is in the tenth place
///                 while 1 is in the hundreth place.)
///                 rmZero: int strips the trailing 0's
///                 created during this algorithm.
///  OUTPUT:   
///  	Return Val: Stack* list is returned with int one per node in the same 
///                 order as given.
///  	Parameters: GDB EXAMPLE: 
///                 print *push->top
///                 {data = 1, count = 0, top = 0x0, next = 0x6020d0}
///                 print *push->top->next
///                 {data = 2, count = 0, top = 0x0, next = 0x6020a0}
///  CALLS TO: pushStackOne(),
//////////////////////////////////////////////////////////////////////////
Stack *pushStackOne(Stack* push,int data,int numPlace,int rmZero){
  int num = 0;
  Stack *newPtr = new(nothrow) Stack;
  if(!newPtr){
    cout << "Allocation Error!" << endl;
  }  
  else{
    newPtr->count = 0;
    newPtr->data = 0;
    newPtr->top = 0;
    newPtr->next = 0;
    //first break up the number for list
    num = data % numPlace;
    //get whole number in proper
    //place
    data = data - num;
    //subtract num from original number
    //for next recursive call
    if(rmZero > 0){
      //get rid of trailing zero's
      num = num / rmZero;
    }
    //rmZero first run prepair
    //int for multiplication
    //before recursive call
    else{
      rmZero = 1;
    }
    //if num or data do not equal zero
    //push onto list
    if(data != 0 || num != 0){
      //grab number
      newPtr->data = num;
      newPtr->next = push->top;
      push->top = newPtr; 
      push->count = push->count + 1;
      //prep for next recursive call with
      //place calculations.
      numPlace = numPlace * 10;
      //find previous place for removal of zero's
      rmZero = rmZero * 10;
      //recursivly call function again.
      pushStackOne(push,data,numPlace,rmZero);
    }
    else{
      //make sure tail is 0 at next node.
      push->next = 0;
    }
  }
  //push done
  return push;
}
///////////////////////////////////////////////////////////////////////////
///  FUNCTION:	pushStackTwo()
///  DESCRIPTION:   standard push function for appending to stack
///  INPUT:
///  	Parameters: Stack* list is appended to
///                 new integer data is given to newNode
///                 for adding to the stack. 
///  OUTPUT:   
///  	Return Val: return list with new node appended to the stack
///  	Parameters: newPtr node is appended to Stack list.
//////////////////////////////////////////////////////////////////////////
Stack *pushStackTwo(Stack* push,int data){
  Stack *newPtr = new(nothrow) Stack;
  if(!newPtr){
    cout << "Allocation Error!" << endl;
  }
  newPtr->count = 0;
  newPtr->data = 0;
  newPtr->top = 0;
  newPtr->next = 0;
  //retrieve new int data
  //and add node
  newPtr->data = data;
  newPtr->next = push->top;
  push->top = newPtr;
  //increment count
  push->count = push->count + 1;
  //push complete.
  return push;
}
///////////////////////////////////////////////////////////////////////////
///  FUNCTION:	popStack()
///  DESCRIPTION:    pops top node from Stack and retrieves data from node.
///                  once data is copied node is deleted. count is also reduced 
///                  by one. 
///  INPUT:
///  	Parameters: Stack* list is recieved.
///  OUTPUT:   
///  	Return Val: int value taken from node is returned after node
///                 is deleted.
///  	Parameters: outData is the returned int value.
//////////////////////////////////////////////////////////////////////////
int popStack(Stack* pop){
  int outData;
  Stack *dltPtr = new(nothrow) Stack;
  if(!dltPtr){
    cout << "Allocation Error!" << endl;
  } 
  dltPtr->count = 0;
  dltPtr->data = 0;
  dltPtr->top = 0;
  dltPtr->next = 0;  
  //point deletion pointer to address.
  dltPtr = pop->top;
  //grab data
  outData = pop->top->data;
  //traverse
  pop->top = pop->top->next;
  //increment count
  pop->count = pop->count - 1;
  //delete uneeded node and get memory back.
  delete dltPtr;
  //return found integer data
  return outData;
}
///////////////////////////////////////////////////////////////////////////
///  FUNCTION:	userNUM()
///  DESCRIPTION:   recieves and verifies user input.
///  INPUT:
///  	Parameters: integer user is recieved from user input.
///  OUTPUT:   
///  	Return Val: verified integer smaller than 100000000 
///  CALLS TO:  userNUM()
//////////////////////////////////////////////////////////////////////////
int usersNUM(){
  int user = 0;
  cout << "Enter a number: " << endl;
  cin >> user;
  //ensure number is not to large for standard int
  while(user > 100000000){
    cin.clear();
    cout << "Whoops! that number is too large for a standard INT" << endl;
    cout << "Please try something smaller than 1,000,000,000" << endl;
    //if number was too large recurse
    user = usersNUM();
  }
  return user;
}
///////////////////////////////////////////////////////////////////////////
///  FUNCTION:    display()
///  DESCRIPTION:   simply displays output to user.
//////////////////////////////////////////////////////////////////////////
void display(){

  cout << "This program takes a number of your choice and\n"
    "reverses it using a Stack Linked List" << endl;
 
}
