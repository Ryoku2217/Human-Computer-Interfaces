#ifndef __REGRESIONLINEAL_HPP__
#define __REGRESIONLINEAL_HPP__

#include "dataset.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

class RegresionLineal {

private:

    double B0;
    double B1;
    double B2;

public:

    RegresionLineal();

    void calcularModelo(const DataSet& data);

    double predecir(double x1, double x2) const;

    void imprimirModelo() const;
};

#endif // __REGRESIONLINEAL_HPP__