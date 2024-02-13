#include <iostream>
#include "myvector.h"
#include "mylist.h"

using std::cout;
using std::string;

template <class C> void show(const C & v)
{
cout << "size/cap: " << v.size() << '/'
<< v.capacity() << ": "; v.print(); cout
<< '\n';
}

// Filling a container with push_back() with n elements
template <class C>
void fill_back(C & mycontainer, int n) {
    for (int i = 0; i < n; ++i) {
        string name = "Element " + std::to_string(i);
        mycontainer.push_back(Payload(name));
    }
}

// Filling a container with push_front() with n elements
template <class C>
void fill_front(C & mycontainer, int n) {
    for (int i = 0; i < n; ++i) {
        string name = "Element " + std::to_string(i);
        mycontainer.push_front(Payload(name));
    }
}

// Removing all elements from the container with pop_back()
template <class C>
void remove_back(C & mycontainer) {
    while (mycontainer.size() > 0) {
        mycontainer.pop_back();
    }
}

// Removing all elements from the container with pop_front()
template <class C>
void remove_front(C & mycontainer) {
    while (mycontainer.size() > 0) {
        mycontainer.pop_front();
    }
}

// Removing the first character of the name of each element
template <class C>
void modify(C & mycontainer) {
    for (int i = 0; i < mycontainer.size(); ++i) {
        Payload &payload = mycontainer[i];
        payload.name = payload.name.substr(1); // Remove first character
    }
}

// Printing the size followed by all elements in the container without using the print() method in Payload
template <class C>
void print(C & mycontainer) {
    cout << "Size: " << mycontainer.size() << '\n';
    for (int i = 0; i < mycontainer.size(); ++i) {
        cout << mycontainer[i].name << '\n';
    }
}

// Sample run function
template <class Container>
void run(string message, int n) {
    cout << message << '\n';
    Container c;
    fill_back(c, n); show(c);
    modify(c); show(c);
    modify(c); show(c);
    modify(c); show(c);
    remove_back(c);
    show(c);
    fill_front(c, n); show(c);
    print(c);
    remove_front(c); show(c);
    cout << '\n';
}

int main() {
    run<Vector>("Vector", 10);
    run<List>("List", 10);
    return 0;
}
