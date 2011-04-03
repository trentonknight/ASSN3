#include <iostream>

#ifdef _WIN32 
#include <windows.h>
#endif

using namespace std;

struct Stack{
  char data;
  int count;
  Stack *top;
  Stack *next;
};

Stack *createStack(Stack*);
Stack *pushStack(Stack*,char);
char popStack(Stack*);
string usersList();



int main(){
 
  string userInput;
  char letter;
  int readString;
  
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
  list->top = node;
  userInput = usersList();
  createStack(list);
  while(userInput[readString] != '\0'){
    letter = userInput[readString];
    pushStack(list,letter);
    readString++;
  }
  while(list->count != 0){
    letter = popStack(list);
    cout << letter << " ";
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
Stack *pushStack(Stack* push,char data){
  Stack *newPtr = new(nothrow) Stack;
  if(!newPtr){
    cout << "Allocation Error!" << endl;
  }  
  else{
    newPtr->data = data;
    newPtr->next = push->top;
    push->top = newPtr;
    push->count = push->count + 1;
  }
  return push;
}

char popStack(Stack* pop){
 char outData;
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
string usersList(){
  string user;

  cout << "Please enter a list of lowercase letters." << endl;
  getline(cin,user);

  return user;
}

