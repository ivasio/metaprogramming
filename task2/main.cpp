#include <iostream>
#include "indexof.h"

using std::cout;
using std::endl;
using std::string;


typedef TypeList<int, TypeList<char, TypeList<double, NullType> > > IntCharDouble;
typedef int intAlias;



void printPosition(string typeName, int position) {
    cout << "Position of " << typeName << " in typelist [int, char, double] is " << position << endl;
}

int main() {

    printPosition("int", getIndexOf<IntCharDouble, int>());
    printPosition("char", getIndexOf<IntCharDouble, char>());
    printPosition("double", getIndexOf<IntCharDouble, double>());
    printPosition("void*", getIndexOf<IntCharDouble, void*>());
    printPosition("intAlias", getIndexOf<IntCharDouble, intAlias>());

    return 0;
}