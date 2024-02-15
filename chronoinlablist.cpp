#include <iostream>
#include <string>
#include "myvector.h"
#include "mylist.h"
#include <chrono>

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


int main() {

    List trial1;
    List trial2;
    Vector trial3;
    int n=100000;

fill_back(trial1, n);

    // Measure execution time for function1
    auto start1 = std::chrono::steady_clock::now();
    trial1.empty();
    trial1.empty();
    trial1.empty();
    trial1.empty();
    trial1.empty();
    auto end1 = std::chrono::steady_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);
    std::cout <<  duration1.count() <<  std::endl;

    // Measure execution time for function2
    auto start2 = std::chrono::steady_clock::now();
    trial1.front();
    trial1.front();
    trial1.front();
    trial1.front();
    trial1.front();
    auto end2 = std::chrono::steady_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);
    std::cout <<  duration2.count() << std::endl;

    // Measure execution time for function2
    auto start21 = std::chrono::steady_clock::now();
    trial1.back();
    trial1.back();
    trial1.back();
    trial1.back();
    trial1.back();
    auto end21 = std::chrono::steady_clock::now();
    auto duration21 = std::chrono::duration_cast<std::chrono::nanoseconds>(end21 - start21);
    std::cout <<  duration21.count()  << std::endl;

//////////////////////////////////////
    auto start3 = std::chrono::steady_clock::now();
    reverse <List, List> (trial1, trial2);
    auto end3 = std::chrono::steady_clock::now();
    auto duration3 = std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - start3);
    std::cout << duration3.count()  << std::endl;

    auto start5 = std::chrono::steady_clock::now();
    find_in <List> (trial1, "apple");
    auto end5 = std::chrono::steady_clock::now();
    auto duration5 = std::chrono::duration_cast<std::chrono::nanoseconds>(end5 - start5);
    std::cout << duration5.count()  << std::endl;

    auto start6 = std::chrono::steady_clock::now();
    reverse <List, Vector> (trial1, trial3);
    auto end6 = std::chrono::steady_clock::now();
    auto duration6 = std::chrono::duration_cast<std::chrono::nanoseconds>(end6 - start6);
    std::cout << duration6.count()  << std::endl;


    // // Measure execution time for function2
    // auto start4 = std::chrono::steady_clock::now();
    
    // auto end4 = std::chrono::steady_clock::now();
    // auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4);
    // std::cout << "Execution time for remove front: " << duration4.count() << " microseconds" << std::endl;
    
    return 0;
}