#include <stdarg.h>
#include "VectorND.hpp"
#include "matrix.hpp"
#include "geometry.hpp"
#include "bmp2matInt.hpp"
#include "simplex.hpp"

#ifndef TELA
#define TELA

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Tela {
    private:
        int m, n;
        double R;
        VectorND center;
        VectorND aux[4];
        Inversion inversion;
        MatrixSimplex colorComplex;
        RotationMats Xaxis;
        
    public:
            MatrixSquare mesh;
            MatrixIntPlus cool;

        void initTela(const char* pic) {
            
            BoolMat p(pic);
            int M = p.M.height;
            int N = p.M.width;
            cool.initMatrixIntPlus(M, N);
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                    cool.A[i][j] = p.M.getIJ(i, j);

            //cout << p[0][0] << endl;
            double s = 0.2;
            this->m = p.M.height;
            this->n = p.M.width;
            this->mesh.initMatrixSquare(m, n);

            inversion.initInversion(0.3, VectorND({0.0, 0.0, 0.0}));



            this->center.initVectorNDType2(3);
            this->center.updateVector3DP(center);
        
            for (int i = 0; i < 4; i++)
                aux[i].initVectorNDType2(3);
        
            double stepU = 0.0025;
            double stepV = 0.0025;

            double T1 = 1.0 * p.M.width * stepU;
            double T2 = 1.0 * p.M.height *stepV;


                cout << "\n--------<<<<<< H := " << T2;
                cout << "\n--------<<<<<< W := " << T1;
            T1 *= 0.5;
            T2 *= 0.5;
        
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++) {
                    double u1 = ((double)i) * stepU;
                    double v1 = ((double)j) * stepV;
        
                    double u2 = (((double)i) * stepU) + stepU;
                    double v2 = ((double)j )* stepV;
        
                    double u3 = ((double)i) * stepU + stepU;
                    double v3 = ((double)j) * stepV + stepV;
        
                    double u4 = ((double)i) * stepU;
                    double v4 = ((double)j) * stepV + stepV;

                    if (i < m-1 && j < n-1) { 
                    
                    double height0, height1, height2, height3;
                    
                    double ss = 2;
                    height0 = 0.1*(double)p.M.getIJ(i, j)/765.0;
                    height1 = 0.1*(double)p.M.getIJ(i+1, j)/765.0;
                    height2 = 0.1*(double)p.M.getIJ(i+1, j+1)/765.0;
                    height3 = 0.1*(double)p.M.getIJ(i, j+1)/765.0;

                    this->aux[0].updateVector3D(u1 - T2, v1 - T1,-height0);
                    //inversion.applyInversion(this->aux[0]);
                    //this->aux[0].updateVector3D(u1 - T1, height0, v1 - T2);

                    this->aux[1].updateVector3D(u2 - T2, v2 - T1,-height1);
                    //inversion.applyInversion(this->aux[1]);
                    //this->aux[1].updateVector3D(u2 - T1, height1, v2 - T2);

                    this->aux[2].updateVector3D(u3 - T2, v3 - T1,-height2);
                    //inversion.applyInversion(this->aux[2]);
                    //this->aux[2].updateVector3D(u3 - T1, height2, v3 - T2);

                    this->aux[3].updateVector3D(u4 - T2, v4 - T1,-height3);
                    //inversion.applyInversion(this->aux[3]);
                    //this->aux[3].updateVector3D(u4 - T1, height3, v4 - T2);
        
                    this->mesh.A[i][j].initSquare(this->aux[0], this->aux[1], this->aux[2], this->aux[3]);
            }

        }

        cout << "\n------------------------------->initTela Done\n";
    }


         void initTelaColorDepth(string pic) {
            
                BoolMat p("tree.txt");
                int M = p.M.height;
                int N = p.M.width;
                cool.initMatrixIntPlus(M, N);
                for (int i = 0; i < M; i++)
                    for (int j = 0; j < N; j++)
                        cool.A[i][j] = p.M.getIJ(i, j);
    
                //cout << p[0][0] << endl;
                double s = 0.2;
                this->m = p.M.height;
                this->n = p.M.width;
                this->mesh.initMatrixSquare(m, n);
    
                inversion.initInversion(2.8, VectorND({0.0, 0.0, 0.0}));
    
    
    
                this->center.initVectorNDType2(3);
                this->center.updateVector3DP(center);
            
                for (int i = 0; i < 4; i++)
                    aux[i].initVectorNDType2(3);
            
                double stepU = 0.1;
                double stepV = 0.1;
    
                double T1 = 1.0 * p.M.width * stepU;
                double T2 = 1.0 * p.M.height *stepV;
    
    
                    cout << "\n--------<<<<<< H := " << T2;
                    cout << "\n--------<<<<<< W := " << T1;
                T1 *= 0.5;
                T2 *= 0.5;
            
                for (int i = 0; i < m; i++)
                    for (int j = 0; j < n; j++) {
                        double u1 = ((double)i) * stepU;
                        double v1 = ((double)j) * stepV;
            
                        double u2 = (((double)i) * stepU) + stepU;
                        double v2 = ((double)j )* stepV;
            
                        double u3 = ((double)i) * stepU + stepU;
                        double v3 = ((double)j) * stepV + stepV;
            
                        double u4 = ((double)i) * stepU;
                        double v4 = ((double)j) * stepV + stepV;
    
                        if (i < m-1 && j < n-1) { 
                        
                        double height0, height1, height2, height3;
                        
                        double ss = 2;
                        height0 = 0.5*(double)p.M.getIJ(i, j)/765.0;
                        height1 = 0.5*(double)p.M.getIJ(i+1, j)/765.0;
                        height2 = 0.5*(double)p.M.getIJ(i+1, j+1)/765.0;
                        height3 = 0.5*(double)p.M.getIJ(i, j+1)/765.0;
    
                        this->aux[0].updateVector3D(u1 - T2, v1 - T1,-height0);
                        //inversion.applyInversion(this->aux[0]);
                        //this->aux[0].updateVector3D(u1 - T1, height0, v1 - T2);
    
                        this->aux[1].updateVector3D(u2 - T2, v2 - T1,-height1);
                        //inversion.applyInversion(this->aux[1]);
                        //this->aux[1].updateVector3D(u2 - T1, height1, v2 - T2);
    
                        this->aux[2].updateVector3D(u3 - T2, v3 - T1,-height2);
                        //inversion.applyInversion(this->aux[2]);
                        //this->aux[2].updateVector3D(u3 - T1, height2, v3 - T2);
    
                        this->aux[3].updateVector3D(u4 - T2, v4 - T1,-height3);
                        //inversion.applyInversion(this->aux[3]);
                        //this->aux[3].updateVector3D(u4 - T1, height3, v4 - T2);
            
                        this->mesh.A[i][j].initSquare(this->aux[0], this->aux[1], this->aux[2], this->aux[3]);
                }
    
            }
    
            cout << "\n------------------------------->initTela Done\n";
        }
    
            void renderTela(int mod, RotationMats U, int I, int J) {
    
                for (int i = 1; i < this->mesh.m-2; i++)
                    for (int j = 1; j < this->mesh.n-2; j++)
                        if (
                            cool.A[i][j] < 760 ||
                            cool.A[i][j-1] < 760 ||
                            cool.A[i][j+1] < 760 ||
                            cool.A[i+1][j] < 760 ||
                            cool.A[i+1][j-1] < 760 ||
                            cool.A[i+1][j+1] < 760 ||
                            cool.A[i-1][j] < 760 ||
                            cool.A[i-1][j-1] < 760 ||
                            cool.A[i-1][j+1] < 760
                            )
                        this->mesh.A[i][j].renderSquare(cool.A[i][j]+mod, U);
            }

};



#endif


//        void initTela(string pic) {
//            
//            BoolMat p("K.txt");
//            int M = p.M.height;
//            int N = p.M.width;
//            cool.initMatrixIntPlus(M, N);
//            for (int i = 0; i < p.M.height; i++)
//                for (int j = 0; j < p.M.width; j++)
//                    cool.A[i][j] = p.M.getIJ(i, j);
//
//            cout << p[0][0] << endl;
//            double s = 0.2;
//            this->m = p.M.height;
//            this->n = p.M.width;
//            this->mesh.initMatrixSquare(m, n);
//
//
//
//            this->center.initVectorNDType2(3);
//            this->center.updateVector3DP(center);
//        
//            for (int i = 0; i < 4; i++)
//                aux[i].initVectorNDType2(3);
//        
//            double stepU = 0.01;
//            double stepV = 0.01;
//        
//            for (int i = 0; i < m; i++)
//                for (int j = 0; j < n; j++) {
//                    double u1 = (double)i * stepU;
//                    double v1 = (double)j * stepV;
//        
//                    double u2 = ((double)i * stepU) + stepU;
//                    double v2 = (double)j * stepV;
//        
//                    double u3 = (double)i * stepU + stepU;
//                    double v3 = (double)j * stepV + stepV;
//        
//                    double u4 = (double)i * stepU;
//                    double v4 = (double)j * stepV + stepV;
//
//                    if (i < m-1 && j < n-1) { 
//                    
//                    double height0, height1, height2, height3;
//                    if (p.M.getIJ(i, j) == 0) height0 = 0.0;
//                    if (p.M.getIJ(i, j) == 1) height0 = 0.02;
//                    if (p.M.getIJ(i, j) == 2) height0 = 0.04;
//                    if (p.M.getIJ(i, j) == 3) height0 = 0.06;
//                    if (p.M.getIJ(i, j) == 4) height0 = 0.08;
//                    if (p.M.getIJ(i, j) == 5) height0 = 0.1;
//                    if (p.M.getIJ(i, j) == 6) height0 = 0.11;
//                    if (p.M.getIJ(i, j) == 7) height0 = 0.12;
//                    if (p.M.getIJ(i, j) == 8) height0 = 0.13;
//                    if (p.M.getIJ(i, j) == 9) height0 = 0.14;
//                    if (p.M.getIJ(i, j) == 10) height0 = 0.15;
//                    if (p.M.getIJ(i, j) == 11) height0 = 0.16;
//
//                    this->aux[0].updateVector3D(u1, v1,-height0);
//                    if (p.M.getIJ(i+1, j) == 0) height1 = 0.0;
//                    if (p.M.getIJ(i+1, j) == 1) height1 = 0.02;
//                    if (p.M.getIJ(i+1, j) == 2) height1 = 0.04;
//                    if (p.M.getIJ(i+1, j) == 3) height1 = 0.06;
//                    if (p.M.getIJ(i+1, j) == 4) height1 = 0.08;
//                    if (p.M.getIJ(i+1, j) == 5) height1 = 0.1;
//                    if (p.M.getIJ(i+1, j) == 6) height1 = 0.11;
//                    if (p.M.getIJ(i+1, j) == 7) height1 = 0.12;
//                    if (p.M.getIJ(i+1, j) == 8) height1 = 0.13;
//                    if (p.M.getIJ(i+1, j) == 9) height1 = 0.14;
//                    if (p.M.getIJ(i+1, j) == 10) height1 = 0.15;
//                    if (p.M.getIJ(i+1, j) == 11) height1 = 0.16;
//                    this->aux[1].updateVector3D(u2, v2,-height1);
//                    if (p.M.getIJ(i+1, j+1) == 0) height2 = 0.0;
//                    if (p.M.getIJ(i+1, j+1) == 1) height2 = 0.02;
//                    if (p.M.getIJ(i+1, j+1) == 2) height2 = 0.04;
//                    if (p.M.getIJ(i+1, j+1) == 3) height2 = 0.06;
//                    if (p.M.getIJ(i+1, j+1) == 4) height2 = 0.08;
//                    if (p.M.getIJ(i+1, j+1) == 5) height2 = 0.1;
//                    if (p.M.getIJ(i+1, j+1) == 6) height2 = 0.11;
//                    if (p.M.getIJ(i+1, j+1) == 7) height2 = 0.12;
//                    if (p.M.getIJ(i+1, j+1) == 8) height2 = 0.13;
//                    if (p.M.getIJ(i+1, j+1) == 9) height2 = 0.14;
//                    if (p.M.getIJ(i+1, j+1) == 10) height2 = 0.15;
//                    if (p.M.getIJ(i+1, j+1) == 11) height2 = 0.16;
//
//                    this->aux[2].updateVector3D(u3, v3,-height2);
//                    if (p.M.getIJ(i, j+1) == 0) height3 = 0.0;
//                    if (p.M.getIJ(i, j+1) == 1) height3 = 0.02;
//                    if (p.M.getIJ(i, j+1) == 2) height3 = 0.04;
//                    if (p.M.getIJ(i, j+1) == 3) height3 = 0.06;
//                    if (p.M.getIJ(i, j+1) == 4) height3 = 0.08;
//                    if (p.M.getIJ(i, j+1) == 5) height3 = 0.1;
//                    if (p.M.getIJ(i, j+1) == 6) height3 = 0.11;
//                    if (p.M.getIJ(i, j+1) == 7) height3 = 0.12;
//                    if (p.M.getIJ(i, j+1) == 8) height3 = 0.13;
//                    if (p.M.getIJ(i, j+1) == 9) height3 = 0.14;
//                    if (p.M.getIJ(i, j+1) == 10) height3 = 0.15;
//                    if (p.M.getIJ(i, j+1) == 11) height3 = 0.16;
//                    this->aux[3].updateVector3D(u4, v4,-height3);
//
//                    } else {
//                        this->aux[0].updateVector3D(u1, v1, 0.0);
//                        this->aux[1].updateVector3D(u2, v2, 0.0);
//                        this->aux[2].updateVector3D(u3, v3, 0.0);
//                        this->aux[3].updateVector3D(u4, v4, 0.0);
//                    }
//        
//                    this->mesh.A[i][j].initSquare(this->aux[0], this->aux[1], this->aux[2], this->aux[3]);
//            }
//
//            cout << "\n\n-->debugger---\n\n";
//
//        }