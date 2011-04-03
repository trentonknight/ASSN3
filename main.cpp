#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstddef>

#ifdef _WIN32 
#include <windows.h>
#endif

using namespace std;


struct List{
  char letters;
  List *link;
};

List *makeTopNode(List*);
List *addListToMiddleNodes(List*,string);
string usersList();

int main(){
 
  string userInput;

    List *pPass = new(nothrow) List;
    if(!pPass){
      cout << "Allocation Error!" << endl;
      return 1;
    }
    List *head = new(nothrow) List;
    if(!head){
      cout << "Allocation Error!" << endl;
      return 1;
    }
    head->link = 0;
    head->letters = '\0';
    pPass = makeTopNode(head);   
    userInput = usersList();
    addListToMiddleNodes(pPass,userInput);    

    return 0;
 }

List *makeTopNode(List *top){
  List *newNode = new(nothrow) List;
  newNode->link = 0;
  newNode->letters = '\0';

  if(!newNode){
    cout << "Allocation Error!" << endl;
  }
  else{
    newNode->link = top;
    top = newNode;
  }
  return top;
}
string usersList(){
  string user;

  cout << "Please enter a list of lowercase letters." << endl;
  getline(cin,user);

  return user;
}
List *addListToMiddleNodes(List* mid,string lets){
  int letter = 0;
  List *newNode = new(nothrow) List;
  if(!newNode){
    cout << "Allocation Error!" << endl;
  }
  else{
  while(lets[letter] != '\000'){
    newNode->letters = lets[letter];
    ///add new node to middle of the list
    while(mid != 0){
     mid = mid->link;
    }
    newNode->link = 0;
    mid = new(nothrow) List;
    mid->link = newNode;
    letter++;
  }
  }
  return mid;
}
