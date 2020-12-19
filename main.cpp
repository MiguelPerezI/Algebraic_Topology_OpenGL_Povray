#include <iostream>
#include <cstdlib>
#include "matrix.hpp"
#include <math.h>
#include "bmp2matInt.hpp"

using namespace std;

int main() {
	cout << "Matrix Class\n\n\n";

	/*Primero necesitamos un espacio en la memoria que almacene una matriz.*/
	BoolMat("frac.txt");
	
	cout << "\n\n\n";
	return 0;
}