#include <iostream>
#include "payload.h"
#include "myvector.h"

using std:: cout;

Vector::Vector (){
    IdVec= VecCounter+1;
    Capacity=1;
    Objects = new Payload [Capacity];
    VecCounter=0;
    // ++VecCounter;
        } //Ask how they managed to write born function before declaring it in payload.h

    Vector:: ~ Vector (){ delete[] Objects;}

    void Vector:: push_back(const Payload &name) // The reason why an element dies right after the function ends its because this creates a payload object that is directly connected to the function, and you only copy the name to the new object array
    {
        if(Capacity<=VecCounter){
            Capacity= 2*Capacity;
            Payload* temp = new Payload[Capacity];
                for (int i = 0; i < VecCounter; ++i) {
                       temp[i] = Objects[i]; } 
                    // Deallocate the old array because you are not longer pointing at that place but that place still has memory, so you need to delete it
                    delete[] Objects;
                     Objects = temp; 
            }
            Objects[VecCounter] = name; //Correct Index because the VecCounter is later increased
            ++VecCounter;
     }

//Vector Pop Back
    void Vector::pop_back() {
    if (VecCounter <= 0) {
        cout << "Vector is empty. No objects to pop_back." << "\n";}
    else{
    Objects[VecCounter-1].~Payload();
    --VecCounter;
    }
}

// Vector push_front
    void Vector:: push_front(const Payload &name){

        if (Capacity<=VecCounter){
             Capacity= 2*Capacity;
             Payload* temp = new Payload[Capacity];
                for (int i = 0; i < VecCounter; ++i) {
                       temp[i] = Objects[i]; 
                       } 
                    // Deallocate the old array
                    delete[] Objects;
                    Objects = temp;
             } 
                for (int i=VecCounter; i>0; i--){
                Objects[i]=Objects[i-1];
                }    
                       Objects[0]= name;
        ++VecCounter;
    }


//Vector pop_front
    void Vector:: pop_front(){
        if (VecCounter <= 0) {
        cout << "Vector is empty. No objects to pop_front." << "\n";}
    else{
                for (int i=0; i < VecCounter - 1; i++){
                    Objects[i]=Objects[i+1];
                }
                --VecCounter;          
    }
    }

//Vector Operator overload
Payload& Vector::operator[](int i){
    return Objects[i];
}

//Vector Size
    int Vector::size () const { return VecCounter;};
//Vector Capacity
int Vector::capacity () const { return Capacity;}
//Vector Print -> calls print function
void Vector::print()const{
for(int i=0;i<VecCounter;i++){
    Objects[i].print();}
}
