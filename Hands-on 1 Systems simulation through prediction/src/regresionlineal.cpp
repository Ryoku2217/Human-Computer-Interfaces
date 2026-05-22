#include "regresionlineal.hpp"

RegresionLineal::RegresionLineal() : B0(0), B1(0), B2(0) {}

void RegresionLineal::calcularModelo(const DataSet& data) {

    vector<double> x1 = data.getX1();
    vector<double> x2 = data.getX2();
    vector<double> y = data.getY();

    int n = y.size();

    double sumX1 = 0;
    double sumX2 = 0;
    double sumY = 0;

    double sumX1X1 = 0;
    double sumX2X2 = 0;
    double sumX1X2 = 0;

    double sumX1Y = 0;
    double sumX2Y = 0;

    for(int i = 0; i < n; i++) {

        sumX1 += x1[i];
        sumX2 += x2[i];
        sumY += y[i];

        sumX1X1 += x1[i] * x1[i];
        sumX2X2 += x2[i] * x2[i];
        sumX1X2 += x1[i] * x2[i];

        sumX1Y += x1[i] * y[i];
        sumX2Y += x2[i] * y[i];
    }

    // Matriz aumentada 3x4

    double m[3][4] = {
        { (double)n, sumX1, sumX2, sumY },
        { sumX1, sumX1X1, sumX1X2, sumX1Y },
        { sumX2, sumX1X2, sumX2X2, sumX2Y }
    };

    // Eliminacion Gauss-Jordan

    for(int i = 0; i < 3; i++) {

        double pivote = m[i][i];

        for(int j = 0; j < 4; j++) {
            m[i][j] /= pivote;
        }

        for(int k = 0; k < 3; k++) {

            if(k != i) {

                double factor = m[k][i];

                for(int j = 0; j < 4; j++) {
                    m[k][j] -= factor * m[i][j];
                }
            }
        }
    }

    B0 = m[0][3];
    B1 = m[1][3];
    B2 = m[2][3];
}

double RegresionLineal::predecir(double x1, double x2) const {

    return B0 + (B1 * x1) + (B2 * x2);
}

void RegresionLineal::imprimirModelo() const {

    cout << fixed << setprecision(4);

    cout << "\n========== PARAMETROS ==========\n";

    cout << "B0 = " << B0 << endl;
    cout << "B1 = " << B1 << endl;
    cout << "B2 = " << B2 << endl;

    cout << "\n========== ECUACION DE REGRESION ==========" << endl;

    cout << "y = "
         << B0
         << " + ("
         << B1
         << " * x1) + ("
         << B2
         << " * x2)"
         << endl;
}