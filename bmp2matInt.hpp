#ifndef BMP2MAT_HPP
#define BMP2MAT_HPP

#include <iostream>
#include <fstream>
#include <sstream> 
#include <cstdlib>
#include "simplex.hpp"

//string convertToString(char* a, int size) 
//{ 
//    string s = ""; 
//    for (int i = 0; i < size; i++) { 
//        s = s + a[i]; 
//    } 
//    return s; 
//}

class MatrixIntPlus {
    public:
        int m, n;
        int height, width;
        int * * A;

        void initMatrixIntPlus(int m, int n) {

            this->m = m;
            this->n = n;
            this->A = (int **) malloc (m * sizeof(int*));
            for (int i = 0; i < m; i++)
                this->A[i] = (int *) malloc (n * sizeof(int));
        }

        int* operator [] (int index)
        {  return this->A[index%this->n];  }

        void zeroMatrixIntPlus(int m, int n) {
        
            this->initMatrixIntPlus(m, n);
            for (int i = 0; i < this->m; ++i)
                for (int j = 0; j < this->n; ++j)
                    this->A[i][j] = 0;
        }

        void escMatrixIntPlus() {

            for (int i = 0; i < this->m; i++) {
                for (int j = 0; j < this->n; j++)
                    printf("%d ", this->getA(i, j));
                printf("\n\n");
            }
        }

        int getA(int i, int j) {
            return this->A[i][j];
        }
        
        void updateA(int i, int j, int x) {
            this->A[i][j] = x;
        }

        void updateMatrixIntPlusSize(int newM, int newN) {
    
            this->m = newM;
            this->n = newN;
            this->A = (int **) realloc (this->A, sizeof(int*) * newM);
            for (int i = 0; i < m; i++)
                this->A[i] = (int *) realloc (this->A[i], sizeof(int) * newN);
        }

        void push(int newM) {
            this->A[0] = (int *) realloc (this->A[0], sizeof(int) * (this->n+1));
            this->A[0][this->n] = newM;
            this->n += 1;
        }

        int getIJ(int j, int i){

            return A[0][i + j*width];
        }

};

class BoolMat{
    private:
        std::ifstream file;
        const char * File;
        int m = 0 ,n = 0;
        int maxI, maxJ = 0;
        MatrixSimplexColor colors;

    public:
        MatrixIntPlus M;
        
//        BoolMat(const char * file_name){
//            this->file = std::ifstream(file_name);
//            this->File = file_name;
//            this->getDim();
//            this->M.initMatrixIntPlus(this->m, this->n);
//            this->scanMatrix();
//            for(int i=0; i<this->m; ++i){
//                for(int j=0; j<this->n; ++j)
//                    std::cout << M[i][j] << " ";
//                std::cout << '\n';
//            }
//        }

        BoolMat(const char * file_name){
            this->file = std::ifstream(file_name);
            this->File = file_name;
            this->M.initMatrixIntPlus(1, 1);

            cout << "\n-->About to scan\n";
            this->scanMatrix();
            cout << "\n-->Done to scanning\n";
            //M.escMatrixIntPlus();
            cout << "\n--->Dimensions     height := " << M.height << "   width := " << M.width << endl; 
            cout << "\n\n i,j ---------->>>>>>>> " << M.getIJ(M.height-1, M.width-1) << "\n\n";
        }
        
        void scanMatrix(void){
                            
            this->file.clear();
            this->file.seekg(0);
            char line[2048];
            int i = 1, j = 1;
            int count = 0;
            cout << "\n\n  -->In Scan Function\n";
            while( this->file.peek() != EOF ){


                    int count00 = 0;
                    char c0;
                    char c1;
                    char c2;
                    
                    while (count00 < 3) {
                    
                        char lex = file.get();
                    
                        if (lex != ' '  && lex != '\n') {
                            if (count00 == 0) c0 = lex;
                            else {
                                if (count00 == 1) c1 = lex;
                                else c2 = lex;
                            }
                        } else {

                            if(lex == '\n') {
                                i += 1;
                                //cout << "  --> i:= " << i << endl;
                            }

                            break;
                        }
                    
                                            
                        count00 += 1;
                    }

                    if (count00 > 0) {

                        char array[count00];
                        if (count00 == 1) {
                            //cout << c0 << "\n";
                            array[0] = c0;
                        }
                        if (count00 == 2) {
                            //cout << c0 << c1 << "\n";
                            array[0] = c0;
                            array[1] = c1;
                        }
                        if (count00 == 3) {
                            //cout << c0 << c1 << c2 << "\n";
                            array[0] = c0;
                            array[1] = c1;
                            array[2] = c2;
                        }
                        //string s = convertToString(array, count00);

                        string s = ""; 
                        for (int i = 0; i < count00; i++) { 
                            s = s + array[i]; 
                        }  

                        stringstream geek(s); 
                        int x = 0; 
                        geek >> x;
                        //cout << maxJ << "  --  " << x << " " << endl;
                        M.push(x);
                        if (i == 1) maxJ += 1;
                    }


                    //if (i == 3) {
                    //    cout << "-......>>>>>> maxJ = " << maxJ << endl;
                    //    break;   
                    //}


            }
            M.width = maxJ;
            M.height = i-1;


        }



        void scanColorMatrix(void){
                            
            this->file.clear();
            this->file.seekg(0);
            char line[2048];
            int i = 1, j = 1;
            int count = 0;
            cout << "\n\n  -->In Scan Function\n";
            while( this->file.peek() != EOF ){


                    int count00 = 0;
                    char c0;
                    char c1;
                    char c2;
                    
                    while (count00 < 3) {
                    
                        char lex = file.get();
                    
                        if (lex != ' '  && lex != '\n') {
                            if (count00 == 0) c0 = lex;
                            else {
                                if (count00 == 1) c1 = lex;
                                else c2 = lex;
                            }
                        } else {

                            if(lex == '\n') {
                                i += 1;
                                //cout << "  --> i:= " << i << endl;
                            }

                            break;
                        }
                    
                                            
                        count00 += 1;
                    }

                    if (count00 > 0) {

                        char array[count00];
                        if (count00 == 1) {
                            //cout << c0 << "\n";
                            array[0] = c0;
                        }
                        if (count00 == 2) {
                            //cout << c0 << c1 << "\n";
                            array[0] = c0;
                            array[1] = c1;
                        }
                        if (count00 == 3) {
                            //cout << c0 << c1 << c2 << "\n";
                            array[0] = c0;
                            array[1] = c1;
                            array[2] = c2;
                        }
                        //string s = convertToString(array, count00);

                        string s = ""; 
                        for (int i = 0; i < count00; i++) { 
                            s = s + array[i]; 
                        }  

                        stringstream geek(s); 
                        int x = 0; 
                        geek >> x;
                        //cout << maxJ << "  --  " << x << " " << endl;
                        M.push(x);
                        if (i == 1) maxJ += 1;
                    }


                    //if (i == 3) {
                    //    cout << "-......>>>>>> maxJ = " << maxJ << endl;
                    //    break;   
                    //}


            }
            M.width = maxJ;
            M.height = i-1;


        }

        int* operator [] (int index) {  return M[index];  }
};

#endif
