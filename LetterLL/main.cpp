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
Stack *recurseIN(Stack*,int);
Stack *destroyStack(Stack*);
Stack *pushStack(Stack*,string,int);
Stack *pushStackTwo(Stack*,char);
char popStack(Stack*);
string usersList();



int main(){
  char letter;
  int count = 0,
    countTwo = 0,
    check = 0;
  
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
  recurseIN(list,check);
  count = list->count;
  countTwo = list->count;
  while(count != 0){
    letter = popStack(list);
    letter = toupper(letter);
    pushStackTwo(node,letter);
    count--;
  }
  destroyStack(list);

  while(countTwo != 0){
    letter = popStack(node);
    cout << letter;
    countTwo--;
  }
  cout << endl;
  
  destroyStack(node);
   
#ifdef _WIN32 
  system ("PAUSE");
#endif
  return 0;
}
Stack *recurseIN(Stack* in,int checkChars){
  string userInput;
  int readString = 0;

  userInput = usersList();
  createStack(in);
  //recursive push stack
  if(!isalpha(userInput[checkChars])){
    cout << "Whoops! Invalid Character." << endl;
    userInput.clear();
    checkChars = 0;
    recurseIN(in,checkChars);
  }
 else{
   if(userInput[checkChars] != '\0'){
     checkChars++;
   }
   pushStack(in,userInput,readString);
 }
return in;
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
Stack *pushStackTwo(Stack* push,char data){
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
Stack *destroyStack(Stack* del){
  Stack *temp = new(nothrow) Stack;
  if(!temp){
    cout << "Allocation Error!" << endl;
  }
  temp = del->top;
   if(del->top != 0){ 
  del->top = del->top->next;
   }
  del->count = del->count  - 1;

  delete temp;
  return del;
}
string usersList(){
  string user;

  cout << "Please enter a list of lowercase letters." << endl;
  getline(cin,user);

  return user;
}

