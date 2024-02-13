#include <iostream>
#include <chrono>
#include "myvector.h"
#include "mylist.h"

using std::cout;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::string;

// Function prototypes
template <class C>
void fill_back(C & mycontainer, int n);

template <class C>
void fill_front(C & mycontainer, int n);

template <class C>
void remove_back(C & mycontainer);

template <class C>
void remove_front(C & mycontainer);

template <class C>
void modify(C & mycontainer);

// Function to measure the time taken for a function to run
template <class C>
double measure_time(C & container, int n, void (*func)(C&, int));

int main() {
    for (int n = 10; n <= 100000; n *= 10) {
        cout << "n = " << n << '\n';

        // Measure time for vector
        Vector vector;
        double time_fill_back_vector = measure_time(vector, n, fill_back<Vector>);
        double time_fill_front_vector = measure_time(vector, n, fill_front<Vector>);
        double time_remove_back_vector = measure_time(vector, n, remove_back<Vector>);
        double time_remove_front_vector = measure_time(vector, n, remove_front<Vector>);
        double time_modify_vector = measure_time(vector, n, modify<Vector>);

        // Measure time for list
        List list;
        double time_fill_back_list = measure_time(list, n, fill_back<List>);
        double time_fill_front_list = measure_time(list, n, fill_front<List>);
        double time_remove_back_list = measure_time(list, n, remove_back<List>);
        double time_remove_front_list = measure_time(list, n, remove_front<List>);
        double time_modify_list = measure_time(list, n, modify<List>);

        cout << "Vector:\n";
        cout << "Fill back: " << time_fill_back_vector << " microseconds\n";
        cout << "Fill front: " << time_fill_front_vector << " microseconds\n";
        cout << "Remove back: " << time_remove_back_vector << " microseconds\n";
        cout << "Remove front: " << time_remove_front_vector << " microseconds\n";
        cout << "Modify: " << time_modify_vector << " microseconds\n";

        cout << "List:\n";
        cout << "Fill back: " << time_fill_back_list << " microseconds\n";
        cout << "Fill front: " << time_fill_front_list << " microseconds\n";
        cout << "Remove back: " << time_remove_back_list << " microseconds\n";
        cout << "Remove front: " << time_remove_front_list << " microseconds\n";
        cout << "Modify: " << time_modify_list << " microseconds\n\n";
    }

    return 0;
}

template <class C>
void fill_back(C & mycontainer, int n) {
    for (int i = 0; i < n; ++i) {
        string name = "Element " + std::to_string(i);
        mycontainer.push_back(Payload(name));
    }
}

template <class C>
void fill_front(C & mycontainer, int n) {
    for (int i = 0; i < n; ++i) {
        string name = "Element " + std::to_string(i);
        mycontainer.push_front(Payload(name));
    }
}

template <class C>
void remove_back(C & mycontainer) {
    while (mycontainer.size() > 0) {
        mycontainer.pop_back();
    }
}

template <class C>
void remove_front(C & mycontainer) {
    while (mycontainer.size() > 0) {
        mycontainer.pop_front();
    }
}

template <class C>
void modify(C & mycontainer) {
    for (int i = 0; i < mycontainer.size(); ++i) {
        Payload &payload = mycontainer[i];
        payload.name = payload.name.substr(1); // Remove first character
    }
}

template <class C>
double measure_time(C & container, int n, void (*func)(C&, int)) {
    auto start = high_resolution_clock::now();
    func(container, n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return static_cast<double>(duration.count());
}
