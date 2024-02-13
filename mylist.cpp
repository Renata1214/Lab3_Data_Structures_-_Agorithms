#include "payload.h"
#include "mylist.h"
#include <iostream>

//Ask whether the names are supposed to be given to the node or to the payload objects.

using std::string;
using std::cout;

//Node initializer
Node:: Node (Payload n){
    instance = (n);
    next_link = nullptr;
}

List :: List (){
    Head_List= nullptr;
}

List::~List (){
     while (Head_List != nullptr) {
        Node* temp = Head_List;
        Head_List = Head_List->next_link;
        delete temp;
    }
};  

//Push front
void List::push_front (const Payload& name){
    Node *newNode= new Node (name); //Ask if i need a variable or if i can just declare it inside the function
    newNode->next_link= Head_List;
    Head_List = newNode;
    }

//Pop front
void List::pop_front (){
    if(Head_List == nullptr){
        cout << "No elements inside the list" << '\n';
    }
    else{
    Node * temp = Head_List->next_link;
    Head_List -> ~Node ();
    Head_List = temp;}
}


//Push Back

void List::push_back (const Payload& name){
     Node * tale = Head_List;
    while (tale->next_link!=nullptr){
        tale=tale ->next_link;
    }
    Node *newNode= new Node (name);
    tale->next_link=newNode;
}

//Pop back
void List::pop_back(){
    if(Head_List == nullptr){
        cout << "No elements inside the list" << '\n';
    }
    else{
    Node * tale = Head_List;
   // iterator = Head_List -> next_link;
    while (tale->next_link->next_link!=nullptr){
        tale=tale ->next_link;
    }
    delete tale->next_link;
    tale -> next_link = nullptr;}

}


//size, not as a variable.
int List::size ()const{
    int counter =0;
    Node * temp = Head_List;
    while (temp !=nullptr){
        temp = temp -> next_link;
        counter ++;
    }
    return counter;
}

//print function
void List::print ()const{
    Node * temp = Head_List;
    while (temp !=nullptr){
        temp->instance.print();
         temp = temp -> next_link;
    }
}

//Operator
Payload& List::operator[](int i) {
Node * iterator = Head_List;
for (int j=0; j<i+1;j++){
    iterator= iterator ->next_link;
}

return (iterator->instance);
}


