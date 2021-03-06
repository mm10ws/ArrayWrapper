#include <cstdlib>
#include <iostream>
#include "ArrayWrapper.h"
using namespace std;

int main()
{   
    int a[15];
    for(int i=0; i<15; i++)
            a[i] = i;
    int b[5];
    for(int i=0; i<5; i++)
            b[i] = 5-i;
    ArrayWrapper wa(a,15,25);
    cout<<"Dynamic array a created\n";
    cout<<wa<<endl;
    wa[0] = wa[14];
    cout<<"Dynamic array a, after copying "
    <<wa.getSize()<<"th element to the first index\n";
    cout<<wa<<endl;
    // Adds a new element, since enough capacity no need to expand
    int ss=wa.getSize();
    wa[ss] = 20;
    cout<<"Dynamic array a, after adding a new element to the end (at index "<<ss<<")\n";
    cout<<wa<<endl;    
    ArrayWrapper wb(b,5);
    cout<<"Dynamic array b created\n";
    cout<<wb<<endl;
    ss=wb.getSize();
    for(int i=0; i<ss; i++)
            wb[i+ss] = 2*i;
    cout<<"Dynamic array b, after adding 5 more elements\n";
    cout<<wb<<endl;      
    system("PAUSE");
    return 0;//EXIT_SUCCESS;
}

ArrayWrapper::ArrayWrapper(){//default constructor
        size = 0;
        capacity = 10;
        _array = new int[10];
}

ArrayWrapper::ArrayWrapper(int *array, int size, int capacity) {//constructor
        this->size = size;
        this->capacity = capacity;
        if(size > capacity){
             cout<<"Error: size is greater than capacity"<<endl;             
        }
        else{
             _array = new int[capacity];
             for(int i = 0; i < size; i++){
                     _array[i] = array[i];
             }
        }
}

ArrayWrapper::ArrayWrapper(const ArrayWrapper &other){//copy constructor
        size = other.size;
        capacity = other.capacity;
        _array = new int[other.capacity];
        for(int i = 0; i < other.size; i++){
                     _array[i] = other._array[i];
        }
} 
                        
int ArrayWrapper::getSize() const{//return size of dynamic array
        return this->size;                
}

int ArrayWrapper::getCapacity() const{//return capacity of dynamic array
        return this->capacity;
}

void ArrayWrapper::changeCapacity(int newCapacity){//change the capacity of dynamic array
        if(newCapacity <= 0){//error condition
              cout<<"Error: new capacity must be greater than zero"<<endl;
        }
        else{
              this->capacity = newCapacity;
              int temp[newCapacity];
              if(newCapacity < this->size){//shrinking array
                  this->size = newCapacity;           
                  for(int i = 0; i < newCapacity; i++){
                       temp[i] = this->_array[i];
                  }
              }
              else{
                  for(int i = 0; i < this->size; i++){
                       temp[i] = this->_array[i];
                  }
              }
              delete this->_array;
              this->_array = new int[newCapacity];
              for(int i = 0; i < newCapacity; i++){
                  this->_array[i] = temp[i];
              }                 
        }                                   
}                                                        

int ArrayWrapper::operator[] (int position) const{//overloaded operator to return element at position
        if(position < 0 || position >= this->size){//error condition
            cout<<"Error: invalid position"<<endl;
            return -1;
        }        
        else{
            return this->_array[position];
        }
}

int& ArrayWrapper::operator [] (int position){//overloaded operator to return reference of element at position
        if((position > this->capacity)||position < 0){//error condition
            cout<<"Error: invalid position"<<endl;                                    
        }
        else if((position == this->size)&&(position == this->capacity)){//increase the capacity if size == capacity
             this->changeCapacity(this->capacity +10);
             this->size++;             
        }
        else if(position == this->size && position < this->capacity){//increment size when adding element to array at position >= size
             this->size++;
        }        
        return _array[position];
}

ArrayWrapper::~ArrayWrapper(){//destructor
        delete _array;
}           
           
ostream& operator << (std::ostream &o, const ArrayWrapper &other){//overloaded operator to print info about dynamic arrays
        o<<"size: "<<other.getSize()<<endl;
        o<<"capacity: "<< other.getCapacity()<<endl;
        for(int i = 0; i < other.getSize(); i++){
             o<<other[i]<<endl;
        }   
        return o;
}

ArrayWrapper& ArrayWrapper::operator=(const ArrayWrapper &ob){//overload operator for =
        if(this == &ob){
              cout<<"Error: cannot copy object onto itself"<<endl;
        }
        else{
             delete this->_array;
             this->_array = new int[ob.getCapacity()];
             for(int i = 0; i < ob.getSize(); i++){
                  this->_array[i] = ob[i];
             }
             this->size = ob.getSize();
             this->capacity = ob.getCapacity();
        }
        return (*this);                      
}
                      


























