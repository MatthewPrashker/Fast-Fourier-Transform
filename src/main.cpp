#include <iostream>
#include "array.hpp"

int main() {
    //Array v(100);
    Array w(10);
    //w.print();
    w[1] = 4;
    //w.print();
    w.resize(20, true);
    Array v(20000, 5);
    //(v - w).print();
    Array q;
    q = v - w + w - v + v;
    q.print(); //should be all zeros
    //(w + v).print();
    //w.resize(100);
    // we know v should have length 100, with initialized value of zero
    // v = {0, 0, 0, ..., 0}
    // for (unsigned i = 0; i < v.size(); ++i) {
    //     v[i] = i;
    //     v.at(i) = i;
    // }
    //w.copy(v);
    // std::cout << w[4] << "\n";
    //Array v2(v);  // make a "copy"
    //Array v3;     // default
    // the size of v3 should be 0
    //v3 = v;
}
