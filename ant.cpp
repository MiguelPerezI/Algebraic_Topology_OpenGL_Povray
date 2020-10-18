#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include "matrix.hpp"
#include "VectorND.hpp"
#include "geometry.hpp"
#include "simplex.hpp"
#include "Arrow.hpp"
#include "ant.hpp"

int equalDouble0(double a, double b) {

	double epsilon = 0.00000000000001;
	double cc = (a - b) * (a - b);
	if (sqrt(cc) < epsilon)
		return 1;
	else
		return 0;
}

void Ant::antGo(VectorND a, VectorND b, double width, double teta1, double teta2, Facet ground, int on, double rot) {

	//printf("\n\n-->Arrow Constructor\n");
	this->head.initVectorND(3, a.access(0), a.access(1), a.access(2));// = VectorND({a[0], a[1], a[2]});
	this->base.initVectorND(3, b.access(0), b.access(1), b.access(2));// = VectorND({b[0], b[1], b[2]});
	this->D.initVectorND(3, 0.0, 0.0, 0.0);// = VectorND({0, 0, 0});
	this->center.initVectorND(3, 0.0, 0.0, 0.0);
	this->centerM.initVectorND(3, 0.0, 0.0, 0.0);
	this->centerM.SumVectorND(a, b);
	this->centerM.scaleND(0.5);
	this->normal.initVectorND(3, 0.0, 1.0, 0.0);
	this->help.initVectorND(3, 0.0, 1.0, 0.0);

	//printf("-->Restamos a y b\n");
	this->D.subVectorND(a, b);

	//printf("-->Definimos los h0, ..., h3\n");
	this->h0.initVectorND(3, this->D.access(0), this->D.access(1), 		0.0);// = VectorND({this->D[0], this->D[1], 		  0});
	this->h1.initVectorND(3, this->D.access(0), this->D.access(1), this->D.access(2));// = VectorND({this->D[0], this->D[1], this->D[2]});
	this->h2.initVectorND(3, 		0.0, 		0.0, this->D.access(2));// = VectorND({		  0, 		  0, this->D[2]});
	this->h3.initVectorND(3,
		(0.5 * this->D.access(0)) + this->base.access(0),
		(0.5 * this->D.access(1)) + this->base.access(1),
		(0.5 * this->D.access(2)) + this->base.access(2));

	//printf("-->Definimos la longitud de Flecha\n");
	this->longitud = 0.5 * this->D.norm();
	//printf("-->longitud es %lg\n", this->longitud);
	double size = 0.5;
	this->Z.initVectorND(3, 0.0, 0.0, 1.0*size);
	this->minusZ.initVectorND(3, 0.0, 0.0,-1.0*size);

	//printf("-->Inicializando Puntos Vectoriales del Mesh\n");
	this->m = 20;
	this->n = 40;
	this->points.initMatrixVectorND(this->m, this->n + 1);
	int nlegs = 15;
	double legLength = 0.19*size;
	double subLegLength = 0.15*size;
	this->legs.initMatrixVectorND(1, nlegs);

	double R = 0.01;
	double * pR = &R;

	double r = width;

	//legs
	//double teta1 =-0.0*M_PI;
	//double teta2 =-0.34*M_PI;
	double initteta = -0.5*M_PI;
	teta1 *= M_PI;
	teta2 *= M_PI;
	this->legs.A[0][0].initVectorND(3, 0.0, 0.0, 0.01);
	this->legs.A[0][1].initVectorND(3, 0.16, legLength * sin(1.0*teta1 + initteta), legLength * cos(1.0*teta1 + initteta));
	this->legs.A[0][2].initVectorND(3,-0.16, legLength * sin(-1.0*teta1 + initteta), legLength * cos(-1.0*teta1 + initteta));

	this->legs.A[0][3].initVectorND(3, 
		this->legs.A[0][1].access(0), 
		(subLegLength * sin(1.0*teta2 + initteta)) + this->legs.A[0][1].access(1), 
		(subLegLength * cos(1.0*teta2 + initteta)) + this->legs.A[0][1].access(2));

	this->legs.A[0][4].initVectorND(3, 
		this->legs.A[0][2].access(0), 
		(subLegLength * sin(-1.0*teta2 + initteta)) + this->legs.A[0][2].access(1), 
		(subLegLength * cos(-1.0*teta2 + initteta)) + this->legs.A[0][2].access(2));

	this->legs.A[0][5].initVectorND(3, 0.16, legLength * sin(1.0*teta1 + initteta), legLength * cos(1.0*teta1 + initteta) + 0.2);
	this->legs.A[0][6].initVectorND(3,-0.16, legLength * sin(-1.0*teta1 + initteta), legLength * cos(-1.0*teta1 + initteta) + 0.2);

	this->legs.A[0][7].initVectorND(3, 0.0, 0.0, 0.2);

	this->legs.A[0][8].initVectorND(3, 
		this->legs.A[0][5].access(0), 
		(subLegLength * sin(1.0*teta2 + initteta)) + this->legs.A[0][5].access(1), 
		(subLegLength * cos(1.0*teta2 + initteta)) + this->legs.A[0][5].access(2));

	this->legs.A[0][9].initVectorND(3, 
		this->legs.A[0][6].access(0), 
		(subLegLength * sin(-1.0*teta2 + initteta)) + this->legs.A[0][6].access(1), 
		(subLegLength * cos(-1.0*teta2 + initteta)) + this->legs.A[0][6].access(2));


	this->legs.A[0][10].initVectorND(3, 0.0, 0.0, 0.3);


	this->legs.A[0][11].initVectorND(3, 0.16, legLength * sin(1.0*teta1 + initteta), legLength * cos(1.0*teta1 + initteta) + 0.3);
	this->legs.A[0][12].initVectorND(3,-0.16, legLength * sin(-1.0*teta1 + initteta), legLength * cos(-1.0*teta1 + initteta) + 0.3);

	this->legs.A[0][13].initVectorND(3, 
		this->legs.A[0][11].access(0), 
		(subLegLength * sin(1.0*teta2 + initteta)) + this->legs.A[0][11].access(1), 
		(subLegLength * cos(1.0*teta2 + initteta)) + this->legs.A[0][11].access(2));

	this->legs.A[0][14].initVectorND(3, 
		this->legs.A[0][12].access(0), 
		(subLegLength * sin(-1.0*teta2 + initteta)) + this->legs.A[0][12].access(1), 
		(subLegLength * cos(-1.0*teta2 + initteta)) + this->legs.A[0][12].access(2));

	//Body
	VectorND cen0, cen1;
	cen0.initVectorND(3, 0.0, 0.0, 0.9 * Z.access(2));
	cen1.initVectorND(3, 0.0, 0.0, 0.7 * Z.access(2));
	for (int j = 0; j < this->n + 1; j++) {

		//--> Ring 0
		this->points.A[0][j].initVectorND(3, 
			0.01 * r * size * cos(j * (2 * M_PI) / this->n) + Z.access(0), 
			0.01 * r * size * sin(j * (2 * M_PI) / this->n) + Z.access(1), 
			Z.access(2));

		//--> Ring 1
		this->points.A[1][j].initVectorND(3,
			0.4*r * size * cos(j * (2 * M_PI) / this->n), 
			0.4*r * size * sin(j * (2 * M_PI) / this->n), 
			0.9 * Z.access(2));

		if (4 < j && j < 16)
			this->points.A[1][j].dilate(this->points.A[1][j], cen0, 0.66);

		//--> Ring 1
		this->points.A[2][j].initVectorND(3,
			0.2*r * size * cos(j * (2 * M_PI) / this->n), 
			0.2*r * size * sin(j * (2 * M_PI) / this->n), 
			0.8 * Z.access(2));


		//--> Ring 2
		this->points.A[1+2][j].initVectorND(3,
			0.6 * r * size * cos(j * (2 * M_PI) / this->n), 
			0.6 * r * size * sin(j * (2 * M_PI) / this->n), 
			0.7 * Z.access(2));


		if (7 < j && j < 13)
			this->points.A[1+2][j].dilate(this->points.A[1+2][j], cen1, 0.66);


		//--> Ring 3
		this->points.A[1+3][j].initVectorND(3,
			0.4 * r * size * cos(j * (2 * M_PI) / this->n), 
			0.4 * r * size * sin(j * (2 * M_PI) / this->n), 
			0.5 * Z.access(2));

		//--> Ring 4
		this->points.A[1+4][j].initVectorND(3,
			0.6 * r * size * cos(j * (2 * M_PI) / this->n), 
			0.6 * r * size * sin(j * (2 * M_PI) / this->n), 
			0.4 * Z.access(2));

		//--> Ring 5
		this->points.A[1+5][j].initVectorND(3,
			0.75 * r * size * cos(j * (2 * M_PI) / this->n), 
			0.75 * r * size * sin(j * (2 * M_PI) / this->n), 
			0.3 * Z.access(2));

		//--> Ring 6
		this->points.A[1+6][j].initVectorND(3,
			0.81 * r * size * cos(j * (2 * M_PI) / this->n), 
			0.81 * r * size * sin(j * (2 * M_PI) / this->n), 
			0.2 * Z.access(2));

		//--> Ring 7
		this->points.A[1+7][j].initVectorND(3,
			0.7 * r * size * cos(j * (2 * M_PI) / this->n), 
			0.7 * r * size * sin(j * (2 * M_PI) / this->n), 
			0.1 * Z.access(2));

		//--> Ring 8
		this->points.A[1+8][j].initVectorND(3,
			0.4 * r * size * cos(j * (2 * M_PI) / this->n), 
			0.4 * r * size * sin(j * (2 * M_PI) / this->n), 
			0.0 * Z.access(2));

		//--> Ring 9
		this->points.A[1+9][j].initVectorND(3,
			0.7 * r * size * 0.6* cos(j * (2 * M_PI) / this->n), 
			0.7 * r * size * 0.6* sin(j * (2 * M_PI) / this->n), 
			0.1*minusZ.access(2));

		//--> Ring 10
		this->points.A[1+10][j].initVectorND(3,
			0.9 * r * size * 0.6* cos(j * (2 * M_PI) / this->n), 
			0.9 * r * size * 0.6* sin(j * (2 * M_PI) / this->n), 
			0.2*minusZ.access(2));

		//--> Ring 11
		this->points.A[1+11][j].initVectorND(3,
			0.95 * r * size * 0.6* cos(j * (2 * M_PI) / this->n), 
			0.95 * r * size * 0.6* sin(j * (2 * M_PI) / this->n), 
			0.3*minusZ.access(2));

		//--> Ring 12
		this->points.A[1+12][j].initVectorND(3,
			1.0 * r * size * 0.6* cos(j * (2 * M_PI) / this->n), 
			1.0 * r * size * 0.6* sin(j * (2 * M_PI) / this->n), 
			0.4*minusZ.access(2));

		//--> Ring 13
		this->points.A[1+13][j].initVectorND(3,
			1.0 * r * size * 0.6* cos(j * (2 * M_PI) / this->n), 
			1.0 * r * size * 0.6* sin(j * (2 * M_PI) / this->n), 
			0.5*minusZ.access(2));

		//--> Ring 14
		this->points.A[1+14][j].initVectorND(3,
			0.95 * r * size * 0.6* cos(j * (2 * M_PI) / this->n), 
			0.95 * r * size * 0.6* sin(j * (2 * M_PI) / this->n), 
			0.6*minusZ.access(2));

		//--> Ring 15
		this->points.A[1+15][j].initVectorND(3,
			0.9 * r * size * 0.6* cos(j * (2 * M_PI) / this->n), 
			0.9 * r * size * 0.6* sin(j * (2 * M_PI) / this->n), 
			0.7*minusZ.access(2));

		//--> Ring 16
		this->points.A[1+16][j].initVectorND(3,
			0.8 * r * size * 0.6* cos(j * (2 * M_PI) / this->n), 
			0.8 * r * size * 0.6* sin(j * (2 * M_PI) / this->n), 
			0.8*minusZ.access(2));

		//--> Ring 17
		this->points.A[1+17][j].initVectorND(3,
			0.5 * r * size * 0.6* cos(j * (2 * M_PI) / this->n), 
			0.5 * r * size * 0.6* sin(j * (2 * M_PI) / this->n), 
			0.9*minusZ.access(2));

		//--> Ring 18
		this->points.A[1+18][j].initVectorND(3,
			0.01 * r * size * 0.6* cos(j * (2 * M_PI) / this->n) + minusZ.access(0), 
			0.01 * r * size * 0.6* sin(j * (2 * M_PI) / this->n) + minusZ.access(1), 
			minusZ.access(2));
	}
	
	//printf("-->Calculando Angulo Phi\n");
	double P_pro_p_k = this->h0.access(0);
	double abs_pro_p = this->h0.norm();
	double phi = acos(P_pro_p_k / abs_pro_p);
	//printf("-->phi := %lg\n", phi);

	double P_p_k;
	int k;

	if (this->h1[2] > 0.0)
		P_p_k = this->h1.access(2);
	else
		P_p_k = -this->h1.access(2);
	//printf("-->Calculando Angulo Teta\n");
	double abs_p = this->h1.norm();
	double teta = acos(P_p_k / abs_p);
	//printf("-->teta := %lg\n", teta);

	//printf("-->Inicializando Matrices de Rotacion\n");
	this->Rz_phi1.initRotationMats(phi);
	this->Rz_phi2.initRotationMats(-phi);
	this->Ry_teta2.initRotationMatsY(-teta);
	this->Ry_teta1.initRotationMatsY(teta);


	if (equalDouble0(teta, 0) == 1) {

		//Move Body
					//printf("-->Here\n");
					for (int j = 0; j < this->n + 1; j++) {
						for (int i = 0; i < this->m; i++) 
						this->points.A[i][j].SumVectorND(this->points.A[i][j], this->h3);
					}
		//Move Legs
					for (int i = 0; i < nlegs; i++)
						this->legs.A[0][i].SumVectorND(this->legs.A[0][i], this->h3);

					this->center.SumVectorND(this->center, this->h3);
					this->help.SumVectorND(this->help, this->h3);
	}
	else {
		if (this->D.access(1) > 0.0) {
			//Rotate Body
					for (int j = 0; j < this->n + 1; j++) {
						for (int i = 0; i < this->m; i++) {
							this->Ry_teta1.rot3D(this->points.A[i][j]);
							this->points.A[i][j].updateVector3DP(this->Ry_teta1.getAux());
							this->Rz_phi2.rot3D(this->points.A[i][j]);
							this->points.A[i][j].updateVector3DP(this->Rz_phi2.getAux());	
						}
					}
			//Rotate Legs
						for (int i = 0; i < nlegs; i++) {
							this->Ry_teta1.rot3D(this->legs.A[0][i]);
							this->legs.A[0][i].updateVector3DP(this->Ry_teta1.getAux());
							this->Rz_phi2.rot3D(this->legs.A[0][i]);
							this->legs.A[0][i].updateVector3DP(this->Rz_phi2.getAux());	
						}

						this->Ry_teta1.rot3D(this->normal);
						this->normal.updateVector3DP(this->Ry_teta1.getAux());
						this->Rz_phi2.rot3D(this->normal);
						this->normal.updateVector3DP(this->Rz_phi2.getAux());

						this->Ry_teta1.rot3D(this->center);
						this->center.updateVector3DP(this->Ry_teta1.getAux());
						this->Rz_phi2.rot3D(this->center);
						this->center.updateVector3DP(this->Rz_phi2.getAux());

						this->Ry_teta1.rot3D(this->help);
						this->help.updateVector3DP(this->Ry_teta1.getAux());
						this->Rz_phi2.rot3D(this->help);
						this->help.updateVector3DP(this->Rz_phi2.getAux());
		} else {
			//Move Body
			for (int j = 0; j < this->n + 1; j++) {
				for (int i = 0; i < this->m; i++) {
					this->Ry_teta1.rot3D(this->points.A[i][j]);
					this->points.A[i][j].updateVector3DP(this->Ry_teta1.getAux());
					this->Rz_phi1.rot3D(this->points.A[i][j]);
					this->points.A[i][j].updateVector3DP(this->Rz_phi1.getAux());
				}
			}

			//Move Legs
			for (int i = 0; i < nlegs; i++) {
					this->Ry_teta1.rot3D(this->legs.A[0][i]);
					this->legs.A[0][i].updateVector3DP(this->Ry_teta1.getAux());
					this->Rz_phi1.rot3D(this->legs.A[0][i]);
					this->legs.A[0][i].updateVector3DP(this->Rz_phi1.getAux());
				}

			this->Ry_teta1.rot3D(this->normal);
			this->normal.updateVector3DP(this->Ry_teta1.getAux());
			this->Rz_phi1.rot3D(this->normal);
			this->normal.updateVector3DP(this->Rz_phi1.getAux());	

			this->Ry_teta1.rot3D(this->center);
			this->center.updateVector3DP(this->Ry_teta1.getAux());
			this->Rz_phi1.rot3D(this->center);
			this->center.updateVector3DP(this->Rz_phi1.getAux());

			this->Ry_teta1.rot3D(this->help);
			this->help.updateVector3DP(this->Ry_teta1.getAux());
			this->Rz_phi1.rot3D(this->help);
			this->help.updateVector3DP(this->Rz_phi1.getAux());			
		}

		for (int j = 0; j < this->n + 1; j++) {
			for (int i = 0; i < this->m; i++) 
				this->points.A[i][j].SumVectorND(this->points.A[i][j], this->h3);
		}

		for (int i = 0; i < nlegs; i++) 
			this->legs.A[0][i].SumVectorND(this->legs.A[0][i], this->h3);

		this->center.SumVectorND(this->center, this->h3);
		this->help.SumVectorND(this->help, this->h3);
	}

	double top, bottom;
	VectorND auxUp;
	auxUp.initVectorND(3, ground.normalK()[0], ground.normalK()[1], ground.normalK()[2]);
	auxUp.scaleND(1.5);
	top = this->normal.dotProd(ground.normalK());
	bottom = (this->normal.norm()) * (ground.normalK().norm());

	double rotAngle = acos(top/bottom);
	if (on == 0)
		this->U.initAxeRotation(a, b, rotAngle);
	else 
		this->U.initAxeRotation(a, b,-rotAngle);

	for (int j = 0; j < this->n + 1; j++)
		for (int i = 0; i < this->m; i++)
			U.rot3DAxe(this->points.A[i][j]);

	for (int i = 0; i < nlegs; i++) 
		U.rot3DAxe(this->legs.A[0][i]);

	U.rot3DAxe(this->normal);
	U.rot3DAxe(this->center);
	U.rot3DAxe(this->help);


	this->normal.SumVectorND(this->normal, this->h3);

	U.updateAxeRotation(this->help, this->center, rot*3.1415);

	for (int j = 0; j < this->n + 1; j++)
		for (int i = 0; i < this->m; i++)
			U.rot3DAxe(this->points.A[i][j]);

	for (int i = 0; i < nlegs; i++) 
		U.rot3DAxe(this->legs.A[0][i]);

	U.rot3DAxe(this->normal);


	//printf("-->Rellenando Matriz Mesh\n");
	this->mesh.initMatrixFacet(2 * this->m, this->n);
	for (int j = 0; j < this->n; j++) {
		for (int i = 0; i < this->m-1; i++) {
			this->mesh.inputFacet(2*i, j,   this->points.A[i][j],   this->points.A[i][j+1],   this->points.A[i+1][j]);
			this->mesh.inputFacet(2*i + 1, j, this->points.A[i][j+1], this->points.A[i+1][j+1], this->points.A[i+1][j]);	
		}
	}
	//printf("\n\n\n");
}

void Ant::reflectAnt() {
	
	for (int j = 0; j < this->n + 1; j++) {
		for (int i = 0; i < this->m; i++) {
			this->points.A[i][j].dilate(this->points.A[i][j], this->centerM, -1);	
		}
	}	

	for (int j = 0; j < this->n; j++) {
		for (int i = 0; i < this->m-1; i++) {
			this->mesh.updateFacet(2*i, j,   this->points.A[i][j],   this->points.A[i][j+1],   this->points.A[i+1][j]);
			this->mesh.updateFacet(2*i + 1, j, this->points.A[i][j+1], this->points.A[i+1][j+1], this->points.A[i+1][j]);	
		}
	}
}

void Ant::antSet(VectorND a, VectorND b, double width, double teta1, double teta2, Facet ground, int on, double rot) {

	this->help.initVectorND(3);
	this->help.subVectorND(a, b);
	if (this->help.access(2) < 0.0) {
		this->antGo(a, b, width, teta1, teta2, ground, on, rot);
		this->reflectAnt();
		this->reflection = 111;
	}
	else {
		this->antGo(b, a, width, teta1, teta2, ground, on, rot);
		this->reflection = 110;
	}
}

void MatrixAnt::initMatrixAnt(int m, int n) {
	
	this->m = m;
	this->n = n;

	this->A = (Ant * *) malloc (m * sizeof(Ant*));
    for (int i = 0; i < m; i++)
        this->A[i] = (Ant *) malloc (n * sizeof(Ant));
}

void MatrixAnt::initA(int i, int j, VectorND a, VectorND b, double width, double teta1, double teta2, Facet ground, int on, double rot) {

	this->A[i][j].antSet(a, b, width, teta1, teta2, ground, on, rot);
}

void Cortina::initCortina(int n, double width) {

	this->base.initCortinaBase(n, width);
	this->head.initCortinaHead(n, width);
	this->base.initCurveList();
	this->head.initCurveList();

	this->tela.initMatrixFacet(1, 2*n);
	int count = 0;
	for (int i = 0; i < n; i++) {
		this->tela.inputFacet(0, count, 
			this->base.curve.getArista(0, i).getTail(),
			this->head.curve.getArista(0, i).getTail(),
			this->head.curve.getArista(0, i).getHead());

		count += 1;
		this->tela.inputFacet(0, count, 
			this->head.curve.getArista(0, i).getHead(),
			this->base.curve.getArista(0, i).getHead(),
			this->base.curve.getArista(0, i).getTail());
		count += 1;
	}

}
