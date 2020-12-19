#ifndef BMP2MAT_HPP
#define BMP2MAT_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>

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
        int maxI, maxJ;

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
            M.escMatrixIntPlus();
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


                //cout << "  -->cycle := " << count << endl;
                cout << "  -->i := " << i << "    j := " << j << endl << endl;
                char Lex = this->file.get();

                if(Lex =='.'){
                    if (count == 0) M.push(0);
                    else {
                        j += 1;
                        M.push(0);
                    }
                }
                
                if(Lex ==','){
                    if (count == 0) M.push(1);
                    else {
                        j += 1;
                        M.push(1);
                    }
                }
                //cout << "  ------------------------------------------------> := " << 1 << endl;
                if(Lex =='^'){
                    if (count == 0) M.push(2);
                    else {
                        j += 1;
                        M.push(2);
                    }
                   // cout << "  ------------------------------------------------> := " << 2 << endl;
                }
                
                if(Lex =='~'){
                    if (count == 0) M.push(3);
                    else {
                        j += 1;
                        M.push(3);
                    }
                   // cout << "  ------------------------------------------------> := " << 3 << endl;
                }
                
                if(Lex =='+'){
                    if (count == 0) M.push(4);
                    else {
                        j += 1;
                        M.push(4);
                    }
                   // cout << "  ------------------------------------------------> := " << 4 << endl;
                }
                
                if(Lex =='*'){
                    if (count == 0) M.push(5);
                    else {
                        j += 1;
                        M.push(5);
                    }
                   // cout << "  ------------------------------------------------> := " << 5 << endl;
                }

                
                if(Lex =='-'){
                    if (count == 0) M.push(6);
                    else {
                        j += 1;
                        M.push(6);
                    }
                   // cout << "  ------------------------------------------------> := " << 6 << endl;
                }

                
                if(Lex =='i'){
                    if (count == 0) M.push(7);
                    else {
                        j += 1;
                        M.push(7);
                    }
                    //cout << "  ------------------------------------------------> := " << 7 << endl;
                }
                
                if(Lex =='{'){
                    if (count == 0) M.push(8);
                    else {
                        j += 1;
                        M.push(8);
                    }
                    //cout << "  ------------------------------------------------> := " << 8 << endl;
                }

                
                if(Lex =='L'){
                    if (count == 0) M.push(9);
                    else {
                        j += 1;
                        M.push(9);
                    }
                    ///cout << "  ------------------------------------------------> := " << 9 << endl;
                }
                
                if(Lex =='M'){
                    if (count == 0) M.push(10);
                    else {
                        j += 1;
                        M.push(10);
                    }
                    //cout << "  ------------------------------------------------> := " << 10 << endl;
                }
                
                if(Lex =='B'){
                    if (count == 0) M.push(11);
                    else {
                        j += 1;
                        M.push(11);
                    }
                   // cout << "  ------------------------------------------------> := " << 11 << endl;
                }

                
                if(Lex == '\n') {
                    i += 1;
                    if (i == 2) {
                        maxJ = j;
                        M.width = j;
                        cout << "\n\n---> maxJ = " << maxJ <<endl;
                    }
                    j = 0;
                    cout << "  --> i:= " << i << endl;
                    //if (i == 400) break;
                    
                }

                //cout << "  ------------------------------------------------> := " << 1000 << endl;

                if (Lex != ' ')
                    count += 1;
            }

            M.height = i-1;
        }



//                void scanMatrix(void){
//            this->file.clear();
//            this->file.seekg(0);
//            char line[2048];
//            int i = 1, j = 1;
//            int count = 0;
//            cout << "\n\n  -->In Scan Function\n";
//            while( this->file.peek() != EOF ){
//
//
//                //cout << "  -->cycle := " << count << endl;
//                cout << "  -->i := " << i << "    j := " << j << endl << endl;
//                char Lex = this->file.get();
//
//                if(Lex =='.'){
//                    if (count == 0) M.updateA(0, 0, 0);
//                    else {
//                        j += 1;
//                        if (i == 1) {
//                            
//                            M.updateMatrixIntPlusSize(i, j);
//                        }
//                        if (j-1 < maxJ)
//                        M.updateA(i-1, j-1, 0);
//                    }
//                cout << "  ------------------------------------------------> := " << 0 << endl;
//                }
//                
//                if(Lex ==','){
//                    if (count == 0) M.updateA(0, 0, 1);
//                    else {
//                        j += 1;
//                        if (i == 1) {
//                            
//                            M.updateMatrixIntPlusSize(i, j);
//                        }
//                        if (j-1 < maxJ)
//                        M.updateA(i-1, j-1, 1);
//                    }
//                }
//                cout << "  ------------------------------------------------> := " << 1 << endl;
//                if(Lex =='^'){
//                    if (count == 0) M.updateA(0, 0, 2);
//                    else {
//                        j += 1;
//                        if (i == 1) {
//                            
//                            M.updateMatrixIntPlusSize(i, j);
//                        }
//                        if (j-1 < maxJ)
//                        M.updateA(i-1, j-1, 2);
//                    }
//                    cout << "  ------------------------------------------------> := " << 2 << endl;
//                }
//                
//                if(Lex =='~'){
//                    if (count == 0) M.updateA(0, 0, 3);
//                    else {
//                        j += 1;
//                        if (i == 1) {
//                            
//                            M.updateMatrixIntPlusSize(i, j);
//                        }
//                        if (j-1 < maxJ)
//                        M.updateA(i-1, j-1, 3);
//                    }
//                    cout << "  ------------------------------------------------> := " << 3 << endl;
//                }
//                
//                if(Lex =='+'){
//                    if (count == 0) M.updateA(0, 0, 4);
//                    else {
//                        j += 1;
//                        if (i == 1) {
//                            
//                            M.updateMatrixIntPlusSize(i, j);
//                        }
//                        if (j-1 < maxJ)
//                        M.updateA(i-1, j-1, 4);
//                    }
//                    cout << "  ------------------------------------------------> := " << 4 << endl;
//                }
//                
//                if(Lex =='*'){
//                    if (count == 0) M.updateA(0, 0, 5);
//                    else {
//                        j += 1;
//                        if (i == 1) {
//                            
//                            M.updateMatrixIntPlusSize(i, j);
//                        }
//                        if (j-1 < maxJ)
//                        M.updateA(i-1, j-1, 5);
//                    }
//                    cout << "  ------------------------------------------------> := " << 5 << endl;
//                }
//
//                
//                if(Lex =='-'){
//                    if (count == 0) M.updateA(0, 0, 6);
//                    else {
//                        j += 1;
//                        if (i == 1) {
//                            
//                            M.updateMatrixIntPlusSize(i, j);
//                        }
//                        if (j-1 < maxJ)
//                        M.updateA(i-1, j-1, 6);
//                    }
//                    cout << "  ------------------------------------------------> := " << 6 << endl;
//                }
//
//                
//                if(Lex =='i'){
//                    if (count == 0) M.updateA(0, 0, 7);
//                    else {
//                        j += 1;
//                        if (i == 1) {
//                            
//                            M.updateMatrixIntPlusSize(i, j);
//                        }
//                        if (j-1 < maxJ)
//                        M.updateA(i-1, j-1, 7);
//                    }
//                    cout << "  ------------------------------------------------> := " << 7 << endl;
//                }
//                
//                if(Lex =='{'){
//                    if (count == 0) M.updateA(0, 0, 8);
//                    else {
//                        j += 1;
//                        if (i == 1) {
//                            
//                            M.updateMatrixIntPlusSize(i, j);
//                        }
//                        if (j-1 < maxJ)
//                        M.updateA(i-1, j-1, 8);
//                    }
//                    cout << "  ------------------------------------------------> := " << 8 << endl;
//                }
//
//                
//                if(Lex =='L'){
//                    if (count == 0) M.updateA(0, 0, 9);
//                    else {
//                        j += 1;
//                        if (i == 1) {
//                            
//                            M.updateMatrixIntPlusSize(i, j);
//                        }
//                        if (j-1 < maxJ)
//                        M.updateA(i-1, j-1, 9);
//                    }
//                    cout << "  ------------------------------------------------> := " << 9 << endl;
//                }
//                
//                if(Lex =='M'){
//                    if (count == 0) M.updateA(0, 0, 10);
//                    else {
//                        j += 1;
//                        if (i == 1) {
//                            
//                            M.updateMatrixIntPlusSize(i, j);
//                        }
//                        if (j-1 < maxJ)
//                        M.updateA(i-1, j-1, 10);
//                    }
//                    cout << "  ------------------------------------------------> := " << 10 << endl;
//                }
//                
//                if(Lex =='B'){
//                    if (count == 0) M.updateA(0, 0, 11);
//                    else {
//                        j += 1;
//                        if (i == 1) {
//                            
//                            M.updateMatrixIntPlusSize(i, j);
//                        }
//                        if (j-1 < maxJ)
//                        M.updateA(i-1, j-1, 11);
//                    }
//                    cout << "  ------------------------------------------------> := " << 11 << endl;
//                }
//
//                
//                if(Lex == '\n') {
//                    i += 1;
//                    if (i == 2) {
//                        maxJ = j;
//                        cout << "\n\n---> maxJ = " << maxJ <<endl;
//                    }
//
//                    M.updateMatrixIntPlusSize(i, maxJ);
//
//                    //if (i == 100) {
//                    //    cout << "\n\n---> maxJ = " << maxJ <<endl;
//                    //    break;
//                    //}
//
//                    j = 0;
//                    cout << "  --> i:= " << i << endl;
//                    if (i == 400) break;
//                    
//                }
//
//                cout << "  ------------------------------------------------> := " << 1000 << endl;
//
//                if (Lex != ' ')
//                    count += 1;
//            }
//
//            this->m = i;
//            this->n = maxJ;
//        }

//        void getDim(void){
//            char line[2048];
//            this->file.getline(line,2048,'\n');
//            this->n = (this->file.gcount() - 1) - int((this->file.gcount() - 1)/2);
//            while( this->file.peek()!=EOF ){
//                this->file.getline(line,2048,'\n');
//                ++this->m;
//            }
//            ++this->m;
//        }

//        void scanMatrix(void){
//            this->file.clear();
//            this->file.seekg(0);
//            char line[2048];
//            int i = 0, j = 0;
//            while( this->file.peek()!=EOF ){
//                char Lex = this->file.get();
//                if(Lex =='.'){
//                    M[i%this->m][j%this->n] = 0;
//                    //std::cout << "1 " << M[i%this->m][j%this->n] << "\n";
//                    ++j;
//                }
//                if(Lex ==','){
//                    M[i%this->m][j%this->n] = 1;
//                    ++j;
//                }
//                if(Lex =='^'){
//                    M[i%this->m][j%this->n] = 2;
//                    ++j;
//                }
//
//                if(Lex =='~'){
//                    M[i%this->m][j%this->n] = 3;
//                    ++j;
//                }
//                if(Lex =='+'){
//                    M[i%this->m][j%this->n] = 4;
//                    ++j;
//                }
//
//                if(Lex =='*'){
//                    M[i%this->m][j%this->n] = 5;
//                    ++j;
//                }
//                if(Lex =='-'){
//                    M[i%this->m][j%this->n] = 6;
//                    ++j;
//                }
//
//                if(Lex =='i'){
//                    M[i%this->m][j%this->n] = 7;
//                    ++j;
//                }
//
//                if(Lex =='{'){
//                    M[i%this->m][j%this->n] = 8;
//                    ++j;
//                }
//
//                if(Lex =='L'){
//                    M[i%this->m][j%this->n] = 9;
//                    ++j;
//                }
//
//                if(Lex =='M'){
//                    M[i%this->m][j%this->n] = 10;
//                    ++j;
//                }
//                if(Lex =='B'){
//                    M[i%this->m][j%this->n] = 11;
//                    ++j;
//                }
//                if(Lex =='\n')
//                    ++i;
//            }
//        }
//
        int* operator [] (int index) {  return M[index];  }
};

#endif
