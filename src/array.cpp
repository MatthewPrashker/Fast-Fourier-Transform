#include "array.hpp"
#include <iostream>

Array::Array() {
    this->_data = nullptr;
    this->_size = 0;
}

Array::Array(const Array& other) {
    this->_size = other._size;
    this->_data = new double[this->_size];
    for(int i = 0; i < this->_size; i++) {
        this->_data[i] = other._data[i];
    }
}

void Array::resize(unsigned new_size, bool prsv) {
    double* new_data = new double[new_size];
    if(prsv) {
        for(int i = 0; i < std::min(new_size, this->_size); i++) {
            new_data[i] = this->_data[i];
        }
        for(int i = std::min(new_size, this->_size); i < new_size; i++) {
            new_data[i] = double(0);
        }
    } else {
        for(int i = 0; i < new_size; i++) {
            new_data[i] = 0;
        }
    }
    this->~Array();
    this->_data = new_data;
    this->_size = new_size;
}

Array::Array (unsigned int n, double v) {
    this->_size = n;
    this->_data = new double[n];
    for(int i = 0; i < n; i++) {
        this->_data[i] = v;
    }
}

//Arithmetic Functions
Array Array::add_util(const Array &rhs, bool sub) const {
    unsigned int max_length = std::max(this->_size, rhs._size);
    unsigned int min_length = std::min(this->_size, rhs._size);
    bool right_bigger = (rhs._size > this->_size);
    double* new_data = new double[max_length];
    for(int i = 0; i < min_length; i++) {
        if(! sub) {
            new_data[i] = (*this)[i] + rhs[i];
        } else {
            new_data[i] = (*this)[i] - rhs[i];
        }
    }
    if(right_bigger) {
        for(int i = min_length; i < max_length; i++) {
            new_data[i] = rhs[i];
        }
    } else {
        for(int i = min_length; i < max_length; i++) {
            new_data[i] = (*this)[i];
        }
    }
    Array rv;
    rv._size = max_length;
    rv._data = new_data;
    return rv;
}

Array Array::add(const Array &rhs) const {
    return this->add_util(rhs);
}
Array Array::operator+(const Array& rhs) const {
    return this->add(rhs);
}

Array Array::sub(const Array &rhs) const {
    return this->add_util(rhs, true);
}
Array Array::operator-(const Array& rhs) const {
    return this->sub(rhs);
}

//End Arithmetic Functions


Array& Array::operator=(const Array&rhs) {
    if(this == &rhs) {return *this;} //check for self-assignment
    this->resize(rhs._size, false); //no need to preserve values
    this->_size = rhs._size;
    for(int i = 0; i < rhs._size; i++) {this->_data[i] = rhs._data[i];}
    return *this;
}


void Array::copy(const Array &rhs) {
    if(this->_size != rhs._size) {(*this).resize(rhs._size, false);} 
    for(int i = 0; i < this->_size; i++) {(*this)[i] = rhs[i];}
}

void Array::print() const {
    for(int i = 0; i < this->_size; i++) {
        std::cout << this->_data[i] << "\n";
    }
}

std::ostream& operator<<(std::ostream& os, const Array& A) {
    for(int i = 0; i < A._size; i++) {
        os << A._data[i] << " ";
    }
    os << "\n";
    return os;
}




