#include <iostream>

#include "MyString.h"
#include "structs.h"
using namespace std;
int main() {
    // char oracion[1000];
    // char original[1000];
    // readline(oracion, 1000);
    // strcpy(original, oracion);
    // strlwr(oracion);
    // cout << oracion << endl;
    // strupr(oracion);
    // cout << oracion << endl;
    // strwupr(oracion);
    // cout << oracion << endl;
    int a = 0;
    safeReadInt(a, 1, 3, "Ingrese un numero: ", "Numero invalido. ");
    cout << "Numero ingresado: " << a << endl;
    return 0;
}
