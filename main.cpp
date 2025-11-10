#include <iostream>

#include "MyString.h"
using namespace std;
int main() {
    char oracion[50] = "hola como estas";
    char original[50];
    strcpy(original, oracion);
    strlwr(oracion);
    cout << oracion << endl;
    strupr(oracion);
    cout << oracion << endl;
    strwupr(oracion);
    cout << oracion << endl;

    return 0;
}
