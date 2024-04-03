#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cmath>

#include "double_vector.h"
#include "my_distance.h"
#include "double_read_vector.h"

using namespace std;


int main() {

    vector<double_vector> my_double_vector;
    vector<my_distance> all_pairs_distances;

    vector<double> v1;
    vector<double> v2;
    v1.push_back(1.0);
    v1.push_back(1.0);
    v1.push_back(1.0);
    v2.push_back(1.0);
    v2.push_back(1.0);
    v2.push_back(0.0);

    double_vector dv1 = double_vector(v1, 10);
    double_vector dv2 = double_vector(v2, 11);

    double dp = dot_product(dv1, dv2);
    double m1 = magnitude(dv1);
    double m2 = magnitude(dv2);
    cout << "dp: " << dp << " m1: "<< m1 <<" m2: "<< m2 << " cos: " << acos(dp/(m1*m2)) << endl;



    ifstream in_file;
    in_file.open("vectors_2D.txt");

    int id = 0;
    vector<double> vector_data;
    while (!in_file.eof()) {
        vector_data = doubles_read_one_line(in_file);
        double_vector d_vector = double_vector(vector_data, id++);
        my_double_vector.push_back(d_vector);
    }



    int size = my_double_vector.size();

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if(i != j){
                my_distance my_distance1(i, j, cosine_distance(my_double_vector[i], my_double_vector[j]));
                all_pairs_distances.push_back(my_distance1);
            }
        }
    }
    
    sort(   all_pairs_distances.begin(),
            all_pairs_distances.end(),
            [](const my_distance & left, const my_distance & right) -> bool {
                return left.cos_distance > right.cos_distance;
            }

    );

    for ( auto dist : all_pairs_distances) {
        cout << " id 1: "<< dist.id_1 << " id 2: "<< dist.id_2 << " cos_distance: " << dist.cos_distance << endl;
    }
    in_file.close();

    return 0;
}

