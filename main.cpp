#include <iostream>
#include <cstdlib>
#include "matrix.hpp"
#include <math.h>
#include "bmp2matInt.hpp"
#include <string>
#include <sstream> 
#include <cstring>

using namespace std;

//string convertToString(char* a, int size) 
//{ 
//    string s = ""; 
//    for (int i = 0; i < size; i++) { 
//        s = s + a[i]; 
//    } 
//    return s; 
//}

int main() {
	cout << "Matrix Class\n\n\n";

	/*Primero necesitamos un espacio en la memoria que almacene una matriz.*/
	BoolMat("V.txt");
//	std::ifstream file;
//	file = std::ifstream("test.txt");
//
//	const char * File;
//	File = "test.txt";
//
//	while (file.peek() != EOF) {
//
//		int count = 0;
//		char c0;
//		char c1;
//		char c2;
//
//		while (count < 3) {
//
//				char lex = file.get();
//
//					if (lex != ' '  && lex != '\n') {
//						if (count == 0) c0 = lex;
//						else {
//							if (count == 1) c1 = lex;
//							else c2 = lex;
//						}
//					} else 
//						break;
//
//						
//			count += 1;
//		}
//
//		char array[count];
//		if (count == 1) {
//			//cout << c0 << "\n";
//			array[0] = c0;
//		}
//		if (count == 2) {
//			//cout << c0 << c1 << "\n";
//			array[0] = c0;
//			array[1] = c1;
//		}
//		if (count == 3) {
//			//cout << c0 << c1 << c2 << "\n";
//			array[0] = c0;
//			array[1] = c1;
//			array[2] = c2;
//		}
//
//		if (count > 0) {
//			//cout << " count := " << count << "    ";
//			 //int ret = atoi(array);
//			//for (int i = 0; i < count; i++)
//			//	cout << array[i];
//			string s = convertToString(array, count);
//			stringstream geek(s); 
//			int x = 0; 
//    		geek >> x;
//			//cout << x << "\n";
//		}
//
//	}
//	
	cout << "\n\n\n";
	return 0;
}