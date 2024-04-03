#ifndef _DOUBLE_VECTOR_H_
#define _DOUBLE_VECTOR_H_

#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

struct double_vector {
    int id;
    vector<double> elements;
    
    double_vector(const double_vector & dv) : elements(dv.elements), id(dv.id) {
    };
    
    double_vector() : id(0.0) {};
    double_vector(vector<double> & elements, int id) :  elements(elements), id(id) {};
};




/**/
double square(const double & d);
double dot_product(const double_vector & one, const double_vector & two) ;
double magnitude(const double_vector & my_vector);
double cosine_distance(const double_vector & one, const double_vector & two);




#endif
