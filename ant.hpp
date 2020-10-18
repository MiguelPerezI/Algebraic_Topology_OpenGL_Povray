#include "matrix.hpp"
#include "VectorND.hpp"
#include "geometry.hpp"
#include "simplex.hpp"
#include "Arrow.hpp"


#ifndef ANT
#define ANT

#include <iostream>
#include <cstdlib>

using namespace std;

class Ant {
	public:
		public:
		int m;
		int n;
		VectorND base;
		VectorND head;
		double width;
		MatrixVectorND points;
		MatrixFacet mesh;
		MatrixVectorND legs;

		VectorND D;
		VectorND h0;
		VectorND h1;
		VectorND h2;
		VectorND h3;
		VectorND center;
		VectorND Z;
		VectorND minusZ;
		VectorND centerM;
		double longitud;
		int reflection;
		RotationMats Rz_phi1;
		RotationMats Ry_teta1;
		RotationMats Rz_phi2;
		RotationMats Ry_teta2;
		VectorND help;

		VectorND normal;
		//Facet ground;

		RotationMats U;

		void antGo(VectorND, VectorND, double, double, double, Facet, int, double rot);
		void antSet(VectorND, VectorND, double, double, double, Facet, int, double rot);
		void reflectAnt();

};

class MatrixAnt {
    public:
        int m, n;
        Ant * * A;

        void initMatrixAnt(int, int);
        void initA(int, int, VectorND, VectorND, double, double, double, Facet, int on, double rot);
        void updateA(int i, int j, VectorND a, VectorND b, double width);
};

class Cortina {
	public:
		SpaceCurve base, head;
		MatrixFacet tela;

		void initCortina(int n, double width);
		void moveCortina();
};

#endif