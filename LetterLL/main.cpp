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
Stack *verifyIN(Stack*,int,string);
bool checkThisChar(char);
Stack *pushStack(Stack*,char);
char popStack(Stack*);
string usersList();



int main(){
  char letter;
  int count = 0,
    countTwo = 0,
    check = 0;
  string userInput;
  
  Stack *node = new(nothrow) Stack;
  if(!node){
    cout << "Allocation Error!" << endl;
    return 1;
  }
  node->count = 0;
  node->top = 0;
  node->next = 0;
  node->data = '\0';
  
  Stack *list = new(nothrow) Stack;
  if(!list){
    cout << "Allocation Error!" << endl;
    return 1;
  } 
  list->count = 0;
  list->top = 0;
  list->next = 0;
  list->data = '\0';
 
  userInput = usersList();  
  verifyIN(list,check,userInput);
  count = list->count;
  countTwo = list->count;
  while(count != 0){
    letter = popStack(list);
    letter = toupper(letter);
    pushStack(node,letter);
    count--;
  }

  while(countTwo != 0){
    letter = popStack(node);
    cout << letter;
    countTwo--;
  }
  cout << endl;
  
#ifdef _WIN32 
  system ("PAUSE");
#endif
  return 0;
}
Stack *verifyIN(Stack* in,int checkChars,string userInput){
  createStack(in);
  //recursive push stack
  if(userInput[checkChars] != '\0'){
    if(!checkThisChar(userInput[checkChars])){
      userInput.clear();
      checkChars = 0;
      verifyIN(in,checkChars,userInput);
    }
    else{
      pushStack(in,userInput[checkChars]);
      checkChars++;
      verifyIN(in,checkChars,userInput);
    }
  }
  return in;
}
bool checkThisChar(char input){

  bool goodChar = true;

  switch (input)
    {
    case 'a':
      goodChar = true;
      break;
    case 'b':
      goodChar = true;
      break;
    case 'c':
      goodChar = true;
      break;
    case 'd':
      goodChar = true;
      break;
    case 'e':
      goodChar = true;
      break;
    case 'f':
      goodChar = true;
      break;
    case 'g':
      goodChar = true;
      break;
    case 'h':
      goodChar = true;
      break;
    case 'i':
      goodChar = true;
      break;
    case 'j':
      goodChar = true;
      break;
    case 'k':
      goodChar = true;
      break;
    case 'l':
      goodChar = true;
      break;
    case 'm':
      goodChar = true;
      break;
    case 'n':
      goodChar = true;
      break;
    case 'o':
      goodChar = true;
      break;
    case 'p':
      goodChar = true;
      break;
    case 'q':
      goodChar = true;
      break;
    case 'r':
      goodChar = true;
      break;
    case 's':
      goodChar = true;
      break;
    case 't':
      goodChar = true;
      break;
    case 'u':
      goodChar = true;
      break;
    case 'v':
      goodChar = true;
      break;
    case 'w':
      goodChar = true;
      break;
    case 'x':
      goodChar = true;
      break;
    case 'y':
      goodChar = true;
      break;
    case 'z':
      goodChar = true;
      break;
    default:
      goodChar = false;
      cout << "ERROR! Please enter a lower case letter." << endl; 
    }
  return goodChar;
}
Stack *createStack(Stack*){
  Stack *first = new(nothrow) Stack;
  if(!first){
    cout << "Allocation Error!" << endl;
  }
  first->count = 0;
  first->top = 0;
  first->next = 0;
  first->data = '\0';

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
  cout << "This program takes lowercase letters and converts them" << endl;
  cout <<"to uppercase with the use of two push and pops to a stack." << endl;
  cout << "Please enter a list of lowercase letters.: " << endl;
  getline(cin,user);

  return user;
}

