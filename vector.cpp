#include "vector.h"

MyVector::MyVector(size_t size, ResizeStrategy,float coef){
    this->_size = size;
    this->_capacity = 1;
    this->_data = nullptr;
    this->_coef = coef;
}

MyVector::~MyVector(){

}

MyVector::MyVector(size_t size, ValueType value, ResizeStrategy, float coef){
    this->_size = size;
    this->_capacity = 1;
    this->_data = &value;
    this->_coef = coef;
}

MyVector::MyVector(const MyVector& copy){
    this->_size = copy._size;
    if (this->_size == 0) {
        this->_data = nullptr;
        return;
    }

    this->_data = copy._data;

}

size_t MyVector::capacity() const{
    return this->_capacity;
}

size_t MyVector::size() const{
    return  this->_size;
}


void MyVector::pushBack(const ValueType& value){
    if(this->_size == this->_capacity){
        reserve(this->_capacity * _coef);
    }
    ValueType* newData = new ValueType[this->_size + 1];
    memcpy(newData, this->_data, this->_size * sizeof(ValueType));
    this->_data = newData;
    delete[] newData;
}
void MyVector::insert(const size_t i, const ValueType& value){

}

void MyVector::reserve(const size_t capacity){


        if (capacity > this->_capacity) {
            this->_capacity = (this->_capacity == 0) ? 1 : this->_capacity;
            while (this->_capacity < capacity)
                this->_capacity ++;
            if (this->_data == 0)
                this->_data = new ValueType[this->_capacity];
            else {
                ValueType* newData = new ValueType[this->_capacity];
                memcpy(newData, this->_data, this->_size * sizeof(ValueType));
                this->_data = newData;
                delete[] newData;
            }
        }

}
