#include <stdarg.h>
#include "VectorND.hpp"
#include "matrix.hpp"
#include "geometry.hpp"
#include "bmp2matInt.hpp"

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
        MatrixSquare mesh;
        MatrixIntPlus cool;
        
    public:
        void initTela(string pic) {
            
            BoolMat p("K.txt");
            int M = p.M.height;
            int N = p.M.width;
            cool.initMatrixIntPlus(M, N);
            for (int i = 0; i < p.M.height; i++)
                for (int j = 0; j < p.M.width; j++)
                    cool.A[i][j] = p.M.getIJ(i, j);

            cout << p[0][0] << endl;
            double s = 0.2;
            this->m = p.M.height;
            this->n = p.M.width;
            this->mesh.initMatrixSquare(m, n);



            this->center.initVectorNDType2(3);
            this->center.updateVector3DP(center);
        
            for (int i = 0; i < 4; i++)
                aux[i].initVectorNDType2(3);
        
            double stepU = 0.01;
            double stepV = 0.01;
        
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++) {
                    double u1 = (double)i * stepU;
                    double v1 = (double)j * stepV;
        
                    double u2 = ((double)i * stepU) + stepU;
                    double v2 = (double)j * stepV;
        
                    double u3 = (double)i * stepU + stepU;
                    double v3 = (double)j * stepV + stepV;
        
                    double u4 = (double)i * stepU;
                    double v4 = (double)j * stepV + stepV;

                    if (i < m-1 && j < n-1) { 
                    
                    double height0, height1, height2, height3;
                    if (p.M.getIJ(i, j) == 0) height0 = 0.0;
                    if (p.M.getIJ(i, j) == 1) height0 = 0.02;
                    if (p.M.getIJ(i, j) == 2) height0 = 0.04;
                    if (p.M.getIJ(i, j) == 3) height0 = 0.06;
                    if (p.M.getIJ(i, j) == 4) height0 = 0.08;
                    if (p.M.getIJ(i, j) == 5) height0 = 0.1;
                    if (p.M.getIJ(i, j) == 6) height0 = 0.11;
                    if (p.M.getIJ(i, j) == 7) height0 = 0.12;
                    if (p.M.getIJ(i, j) == 8) height0 = 0.13;
                    if (p.M.getIJ(i, j) == 9) height0 = 0.14;
                    if (p.M.getIJ(i, j) == 10) height0 = 0.15;
                    if (p.M.getIJ(i, j) == 11) height0 = 0.16;

                    this->aux[0].updateVector3D(u1, v1,-height0);
                    if (p.M.getIJ(i+1, j) == 0) height1 = 0.0;
                    if (p.M.getIJ(i+1, j) == 1) height1 = 0.02;
                    if (p.M.getIJ(i+1, j) == 2) height1 = 0.04;
                    if (p.M.getIJ(i+1, j) == 3) height1 = 0.06;
                    if (p.M.getIJ(i+1, j) == 4) height1 = 0.08;
                    if (p.M.getIJ(i+1, j) == 5) height1 = 0.1;
                    if (p.M.getIJ(i+1, j) == 6) height1 = 0.11;
                    if (p.M.getIJ(i+1, j) == 7) height1 = 0.12;
                    if (p.M.getIJ(i+1, j) == 8) height1 = 0.13;
                    if (p.M.getIJ(i+1, j) == 9) height1 = 0.14;
                    if (p.M.getIJ(i+1, j) == 10) height1 = 0.15;
                    if (p.M.getIJ(i+1, j) == 11) height1 = 0.16;
                    this->aux[1].updateVector3D(u2, v2,-height1);
                    if (p.M.getIJ(i+1, j+1) == 0) height2 = 0.0;
                    if (p.M.getIJ(i+1, j+1) == 1) height2 = 0.02;
                    if (p.M.getIJ(i+1, j+1) == 2) height2 = 0.04;
                    if (p.M.getIJ(i+1, j+1) == 3) height2 = 0.06;
                    if (p.M.getIJ(i+1, j+1) == 4) height2 = 0.08;
                    if (p.M.getIJ(i+1, j+1) == 5) height2 = 0.1;
                    if (p.M.getIJ(i+1, j+1) == 6) height2 = 0.11;
                    if (p.M.getIJ(i+1, j+1) == 7) height2 = 0.12;
                    if (p.M.getIJ(i+1, j+1) == 8) height2 = 0.13;
                    if (p.M.getIJ(i+1, j+1) == 9) height2 = 0.14;
                    if (p.M.getIJ(i+1, j+1) == 10) height2 = 0.15;
                    if (p.M.getIJ(i+1, j+1) == 11) height2 = 0.16;

                    this->aux[2].updateVector3D(u3, v3,-height2);
                    if (p.M.getIJ(i, j+1) == 0) height3 = 0.0;
                    if (p.M.getIJ(i, j+1) == 1) height3 = 0.02;
                    if (p.M.getIJ(i, j+1) == 2) height3 = 0.04;
                    if (p.M.getIJ(i, j+1) == 3) height3 = 0.06;
                    if (p.M.getIJ(i, j+1) == 4) height3 = 0.08;
                    if (p.M.getIJ(i, j+1) == 5) height3 = 0.1;
                    if (p.M.getIJ(i, j+1) == 6) height3 = 0.11;
                    if (p.M.getIJ(i, j+1) == 7) height3 = 0.12;
                    if (p.M.getIJ(i, j+1) == 8) height3 = 0.13;
                    if (p.M.getIJ(i, j+1) == 9) height3 = 0.14;
                    if (p.M.getIJ(i, j+1) == 10) height3 = 0.15;
                    if (p.M.getIJ(i, j+1) == 11) height3 = 0.16;
                    this->aux[3].updateVector3D(u4, v4,-height3);

                    } else {
                        this->aux[0].updateVector3D(u1, v1, 0.0);
                        this->aux[1].updateVector3D(u2, v2, 0.0);
                        this->aux[2].updateVector3D(u3, v3, 0.0);
                        this->aux[3].updateVector3D(u4, v4, 0.0);
                    }
        
                    this->mesh.A[i][j].initSquare(this->aux[0], this->aux[1], this->aux[2], this->aux[3]);
            }

            cout << "\n\n-->debugger---\n\n";

        }

        void renderTela(int mod, RotationMats U) {
            
            for (int i = 0; i < this->mesh.m; i++)
                for (int j = 0; j < mod%cool.n; j++)
                    //if (cool.A[i][j] != 0)
                    if (cool.A[i][j] != 11)
                    this->mesh.A[i][j].renderSquare(cool.A[i][j] + mod, U);
        }
};



#endif