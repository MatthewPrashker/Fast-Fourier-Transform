#ifndef _ARRAY_HPP
#define _ARRAY_HPP
#include <algorithm>

class Array {
 
 public:
  
  Array();
  ~Array() {delete[] this->_data;}
  Array(const Array &other); //copy constructor
  explicit Array(unsigned int n, double v = 0.0);
  
  unsigned int size() const { return this->_size; }

  double *data() {return _data; }  // get the data pointer of array

  const double *data() const {return _data;}   // get read-only pointer of array

  void copy(const Array &rhs);
  void print() const;
  

  Array add_util(const Array &rhs, bool sub = false) const;
  Array add(const Array &rhs) const;
  Array sub(const Array &rhs) const;
  Array operator+(const Array &rhs) const;
  Array operator-(const Array &rhs) const;
  
  // reference entry "index" of the data
  double &at(unsigned index) { return this->_data[index]; }
  // read-only reference entry "index" of the data
  const double &at(unsigned index) const {return this->_data[index];}

  
  void resize(unsigned new_size, bool prsv = true);

  // some math functions
  // L-2 norm, sum, maximum/minimum, and dot (inner) products
  //double norm() const;                  // l2 norm
  //double sum() const;                   // sum
  //double max() const;                   // maximum value
  //double min() const;                   // minimum value
  //double dot(const Array &rhs) const {  // inner
    // for this one, compute the dot product (or inner product)
    // between this and rhs. The region is the min(this->_size and rhs.size())
  //}
  
 
  double &operator[](const unsigned index) { return this->at(index); }
  const double &operator[](const unsigned index) const {return this->at(index);}

  Array& operator=(const Array &rhs); //Assignment Operator
  //The reason the assignment operator must return a value is to support operator chaining

  // assignment, hint call resize if other and "this" have difference sizes
  //Array &operator=(const Array &other) {
    // it is not a constant memory function
    // so we can call resize
    //resize(other.size());
    // copy the value correspondingly
    //return *this;  // do not forget this
  //}

 private:
  double *_data;   ///< data pointer
  unsigned _size;  ///< length of the array
};


#endif //_ARRAY_HPP
