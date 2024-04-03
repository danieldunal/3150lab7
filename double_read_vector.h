#ifndef _DOUBLE_READ_H_
#define _DOUBLE_READ_H_

#include <istream>
#include <vector>

using namespace std;

vector<double> doubles_read(istream & in_stream);
//vector<double> doubles_read(istream & in_stream, const string & terminal);
vector<double> doubles_read_one_line(istream & in_stream);

#endif