#include <iostream>

#include "MyString.h"
using namespace std;
int main() {
    char oracion[5];
    char original[5];
    readline(oracion, 5);
    strcpy(original, oracion);
    strlwr(oracion);
    cout << oracion << endl;
    strupr(oracion);
    cout << oracion << endl;
    strwupr(oracion);
    cout << oracion << endl;

    return 0;
}
