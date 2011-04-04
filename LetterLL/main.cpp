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
Stack *pushStack(Stack*,string,int);
char popStack(Stack*);
string usersList();



int main(){
 
  string userInput;
  char letter;
  int readString = 0;
  
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
  pushStack(list,userInput,readString);

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
Stack *pushStack(Stack* push,string data,int index){
  Stack *newPtr = new(nothrow) Stack;
  if(!newPtr){
    cout << "Allocation Error!" << endl;
  }  
  else{
    if(data[index] != '\0'){
    newPtr->data = data[index];
    newPtr->next = push->top;
    push->top = newPtr;
    push->count = push->count + 1;
    index++;
    pushStack(push,data,index);
    }
 
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

