
#include <iostream>
#include <cmath>

#include "double_vector.h"


using namespace std;


double square(const double & d){
    return d*d;
}

double dot_product(const double_vector & one, const double_vector & two) {
    double prod = 0;
    for (int i = 0; i < one.elements.size(); i++){
        prod += one.elements[i] * two.elements[i];
    }
    return prod;
}

double magnitude(const double_vector & my_vector) {
    double mag = 0;
    for (int i = 0; i < my_vector.elements.size(); i++){
        mag += square(my_vector.elements[i]);
    }
    return sqrt(mag);

};


double cosine_distance(const double_vector & one, const double_vector & two) {
    double dot_prod = dot_product(one,two);
    double one_magnitude = magnitude(one);
    double two_magnitude = magnitude(two);

    double d = dot_prod / (one_magnitude * two_magnitude);
    if (d > 1.0) 
        d = 1.0;
    if (d < -1.0)
        d = -1.0;

    return acos(d);
}



