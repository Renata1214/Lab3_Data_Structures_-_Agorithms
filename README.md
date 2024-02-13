# Lab3_Data_Structures_-_Agorithms

## TASKS
1. Write global template functions1
 (in the user space, no modifications to the containers
allowed):

a. Filling a container with push_back() with 10 elements
b. Filling a container with push_front() with 10 elements
c. Removing all elements from the container with pop_back()
d. Removing all elements from the container with pop_front()
e. Removing the first character of the name of each element2
f. Printing the size followed by all elements in the container without using
the print() method in Payload3

Make sure that you are passing the containers to the functions by reference, not values; because there is not a copy constructor defined in them. There should be exactly 6 generic functions: e.g.

```
template <class C> void fill_back(C & mycontainer, int n); 
```

2. Change the push functions so that they also take an argument int n – the size to be filled.

3. Use STL chrono to measure the time that takes each function (a) to (e) except the printing one to run (f) for n=10,100,1000,10000,100000,etc. for the 2 different containers: vector & list. [Note: if the function is too fast for small n and you do not get a non-zero value for the time (because it’s too small), you can run the same function several times, then divide the time by the number of runs to get the time result for one run.]

Remember: In order to get better results and start noticing the pattern of the different time complexities across different functions for vectors VS. lists, you want to run the
tests on greater values of n. For smaller values, the differences across functions will not be visible.

4. Make a table that summarizes the results, comparing them to the theoretical results, and write a short summary of why the results are so different for some cases.