#include <iostream>
#include <chrono>
#include <string>
#include "myvector.h"
#include "mylist.h"

using std::cout; 
using std:: string;

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



template <class C> void modify(C & v)
{

   for (int i=0; i<v.size(); i++)
   {
    
    if (!v[i].name .empty()) {
        v[i].name.erase(0, 1); // Erase the first character
    }
   
   }
    
}


int main() {

    List trial1;
    int n=100000;

    // Measure execution time for function1
    auto start1 = std::chrono::steady_clock::now();
    fill_back(trial1, n);
    auto end1 = std::chrono::steady_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
    std::cout << "Execution time for fill back: " << duration1.count() << " microseconds" << std::endl;

    // Measure execution time for function2
    auto start2 = std::chrono::steady_clock::now();
    remove_back(trial1);
    auto end2 = std::chrono::steady_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);
    std::cout << "Execution time for remove back: " << duration2.count() << " microseconds" << std::endl;

//////////////////////////////////////
    auto start3 = std::chrono::steady_clock::now();
    fill_front(trial1, n);
    auto end3 = std::chrono::steady_clock::now();
    auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3);
    std::cout << "Execution time for fill front: " << duration3.count() << " microseconds" << std::endl;


    auto start5 = std::chrono::steady_clock::now();
    modify(trial1);
    auto end5 = std::chrono::steady_clock::now();
    auto duration5 = std::chrono::duration_cast<std::chrono::microseconds>(end5 - start5);
    std::cout << "Execution time for modify: " << duration5.count() << " microseconds" << std::endl;

    // Measure execution time for function2
    auto start4 = std::chrono::steady_clock::now();
    remove_front(trial1);
    remove_front(trial1);
    remove_front(trial1);
    remove_front(trial1);
    remove_front(trial1);
    auto end4 = std::chrono::steady_clock::now();
    auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4);
    std::cout << "Execution time for remove front: " << duration4.count() << " microseconds" << std::endl;
    
    return 0;
}