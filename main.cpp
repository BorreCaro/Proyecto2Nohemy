#include <iostream>

#include "MyString.h"
#include "structs.h"
using namespace std;
int main() {
    char oracion[1000];
    char original[1000];
    readline(oracion, 1000);
    strcpy(original, oracion);
    strlwr(oracion);
    cout << oracion << endl;
    strupr(oracion);
    cout << oracion << endl;
    strwupr(oracion);
    cout << oracion << endl;

    return 0;
}
