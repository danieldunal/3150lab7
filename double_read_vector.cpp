#include <istream>
#include <sstream>
#include <vector>

#include "double_read_vector.h"

using namespace std;


vector<double> doubles_read(istream & in_stream) {
    vector<double> res;
    for(int i; in_stream >> i; ) {
        res.push_back(i);
    }

    return res;
}


vector<double> doubles_read_one_line(istream & in_stream) {
    vector<double> res;
    string line;
    
    getline(in_stream, line);
    istringstream is(line);
    string next;
    while (is >> next) {
        res.push_back(stod(next));
    }

    return res;
};


