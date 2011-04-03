#include <iostream>

#ifdef _WIN32 
#include <windows.h>
#endif

using namespace std;


struct Stack{
  int data;
  int count;
  Stack *top;
  Stack *tail;
  Stack *next;
};

Stack *createStack(Stack*);
Stack *pushStack(Stack*,int,int,int);
int popStack(Stack*);
int usersNUM();



int main(){
 
  int userInput = 0;
  int outPut = 0;
  int place = 10;
  int rmZero = 0;
  int count = 0;
  
  Stack *node = new(nothrow) Stack;
  if(!node){
    cout << "Allocation Error!" << endl;
    return 1;
  }
  Stack *list = new(nothrow) Stack;
  if(!list){
    cout << "Allocation Error!" << endl;
    return 1;
  }
  userInput = usersNUM();
  createStack(list);
  //recursive push function
  pushStack(list,userInput,place,rmZero);
  count = list->count;
  while(count != 0){
  outPut = popStack(list);
  cout << outPut << endl;
  count--;
  }
   
#ifdef _WIN32 
  system ("PAUSE");
#endif
  return 0;
}
Stack *createStack(Stack*){
  Stack *first = new(nothrow) Stack;
  if(!first){
    cout << "Allocation Error!" << endl;
  }
  else{
    first->count = 0;
    first->top = 0;
  }
  return first;
}
Stack *pushStack(Stack* push,int data,int numPlace,int rmZero){
  int num = 0;
  Stack *newPtr = new(nothrow) Stack;
  if(!newPtr){
    cout << "Allocation Error!" << endl;
  }  
  else{
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
      numPlace = numPlace * 10;
      rmZero = rmZero * 10;
      pushStack(push,data,numPlace,rmZero);
    }
    else{
      push->next = 0;
      push->tail = push;
    }
  }
  return push;
}

int popStack(Stack* pop){
  int outData;
  Stack *dltPtr = new(nothrow) Stack;
  if(!dltPtr){
    cout << "Allocation Error!" << endl;
  } 
  dltPtr = pop->top;
  outData = pop->top->data;
  pop->top = pop->top->next;
  pop->count = pop->count - 1;

  delete dltPtr;
  return outData;
}
int usersNUM(){
  int user;
  cout << "Please enter a number." << endl;
  cin >> user;
  return user;
}

