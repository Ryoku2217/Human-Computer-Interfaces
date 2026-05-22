#ifndef __DATASET_HPP__
#define __DATASET_HPP__

#include <vector>

using namespace std;

class DataSet {

private:

    vector<double> x1;
    vector<double> x2;
    vector<double> y;

public:

    DataSet();

    vector<double> getX1() const;
    vector<double> getX2() const;
    vector<double> getY() const;
};

#endif // __DATASET_HPP__