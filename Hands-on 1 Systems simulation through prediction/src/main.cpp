#include "dataset.hpp"
#include "regresionlineal.hpp"

int main() {

    DataSet data;

    RegresionLineal modelo;

    modelo.calcularModelo(data);

    modelo.imprimirModelo();

    cout << "\n========== SIMULACION DE EXPERIMENTOS ==========" << endl;

    double resultado;

    resultado = modelo.predecir(4.5, 3.2);
    cout << "\nExperimento 1" << endl;
    cout << "x1 = 4.5 | x2 = 3.2" << endl;
    cout << "Yield = " << resultado << endl;

    resultado = modelo.predecir(7.0, 2.1);
    cout << "\nExperimento 2" << endl;
    cout << "x1 = 7.0 | x2 = 2.1" << endl;
    cout << "Yield = " << resultado << endl;

    resultado = modelo.predecir(10.5, 8.3);
    cout << "\nExperimento 3" << endl;
    cout << "x1 = 10.5 | x2 = 8.3" << endl;
    cout << "Yield = " << resultado << endl;

    resultado = modelo.predecir(13.0, 5.7);
    cout << "\nExperimento 4" << endl;
    cout << "x1 = 13.0 | x2 = 5.7" << endl;
    cout << "Yield = " << resultado << endl;

    resultado = modelo.predecir(15.2, 11.4);
    cout << "\nExperimento 5" << endl;
    cout << "x1 = 15.2 | x2 = 11.4" << endl;
    cout << "Yield = " << resultado << endl;

    system("pause");

    return 0;
}