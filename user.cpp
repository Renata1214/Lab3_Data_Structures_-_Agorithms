#include <iostream>
#include <string>
#include "myvector.h"
#include "mylist.h"

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

template <class Container> void run(string message, int
n)
{
cout <<
message <<
'\n';
Container c;
fill_back(c, n); 
show(c);
modify(c); 
show(c);
modify(c); 
show(c);
modify(c);
show(c);
remove_back(c);
show(c);
fill_front(c,n); 
show(c);
print(c);
remove_front(c);
show(c);
cout << '\n';
}


int main()
{
run<Vector>("Vector", 10);
run<List>("List", 10);
}
