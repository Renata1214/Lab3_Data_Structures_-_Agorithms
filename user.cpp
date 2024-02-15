#include <iostream>
#include <string>
#include "myvector.h"
#include "mylist.h"

using std::cout; 
using std:: string;

using std::cout; 
using std:: string;

template <class C> void show(const C & v)
{
cout << "size/cap: " << v.size() << '/'
<< v.capacity() << ": "; v.print(); cout
<< '\n';
}

template <class C> void fill_back(C & v, int n)
{
    for (int i=0; i < n; i++)
    {
    v.push_back ("z"+ std::to_string(i));
    }
}


template <class C> void fill_front(C & v, int n)
{
    for (int i=0; i < n; i++)
    {
    v.push_front ("z"+ std::to_string (i));
    } 
}


template <class C> void remove_back(C & v)
{
    bool notempty= true;
    while (notempty){
        v.pop_back();
        if (v.size()==0){notempty=false;}
    }
}


template <class C> void remove_front(C & v)
{
    bool nempty= true;
    while (nempty){
        v.pop_front();
    if (v.size()==0){
        nempty=false;}
    }
}

/*e. Removing the first character of the name of each element2
f. Printing the size followed by all elements in the container without using
the print() method in Payload3*/

template <class C> void modify(C & v)
{
   
   for (int i=0; i<v.size(); i++)
   {
    
    if (!v[i].name .empty()) {
        v[i].name.erase(0, 1); // Erase the first character
    }
   
   }
    
}

template <class C> void print(C & v)
{
         v.print();
         cout<< '\n';
}


//Additional Inlab Functions
template <typename Src, typename Dest>
void reverse(const Src & src, Dest & dest) {
    if (!src.empty()) {
        for (int i = src.size() - 1; i >= 0; --i) {
            dest.push_back(src[i]);
        }
    } else {
        std::cout << "No elements in the container" << '\n';
    }
}

template <typename Container>
const Payload* find_in(const Container & c, std::string name1){
    string wanted;
    bool check=false;
    for (int i=0;i<c.size();i++){
       if(c[i].name== name1){
        check = true;
        return &c[i];
       }
    }
    // if(check==false){
    //     throw "Error";}
    return nullptr;
}

// template <class Container> void run(string message, int
// n)
// {
// cout <<
// message <<
// '\n';
// Container c;
// fill_back(c, n); 
// show(c);
// modify(c); 
// show(c);
// modify(c); 
// show(c);
// modify(c);
// show(c);
// remove_back(c);
// show(c);
// fill_front(c,n); 
// show(c);
// print(c);
// remove_front(c);
// show(c);
// cout << '\n';
// }


int main()
{
// run<Vector>("Vector", 10);
// run<List>("List", 10);

//Show functions
auto showList = [](const List & s)
 {
 cout << "List size: " << s.size() << '\n';
 s.print(); cout << '\n';
 };

auto showVector = [](const Vector & v)
 {
 cout << "Vector size/capacity: " << v.size() << '/' <<
v.capacity() << '\n';
 v.print();
 cout << '\n';
 };

List s;
Vector r;
 s.push_back("apple");
 s.push_back("pear");
 s.push_back("banana");
 s.push_back("apple1");
 s.push_back("pear1");
showList(s);

cout << "Proof for empty function" << '\n';
 cout << s.empty()<< '\n';

 cout << "Proof for front function" << '\n';
 cout << s.front().name<< '\n';

cout << "Proof for back function" << '\n';
cout << s.back().name<< '\n';

cout << "Proof for find function" << '\n';
cout << find_in <List> (s, "apple") -> name << '\n';

cout << "Proof for reverse function" << '\n';
 reverse <List, Vector> (s,r);
 showVector(r);

//cout << "I dont know" << '\n';
 cout << find_in <List> (s, "apple") -> name << '\n';

}
