#include <cstdio>
#include <iostream>
#include <sstream>
#include <cmath>
#include "PovRayWriter.hpp"
#include "VectorND.hpp"
#include "geometry.hpp"
#include "Turtle.hpp"
#include "dodecahedron.hpp"
#include "Arrow.hpp"
#include <string>
#include "simplex.hpp"

using namespace std;

double PI = 3.1415926535897932384626;

VectorND center, I, J, K, minusI, minusJ, minusK, position, lightPosition;
VectorND joker, joker0;
double radius = 0.25;
double theta;
double phi;
double R, newR;

/*Rotation Matrix System*/
RotationMats U;

/*Arrow*/
Arrow flecha, flecha0, flecha1, flecha2;

/*Ant*/
Ant ant;
MatrixAnt antPile;

double partition = 1;

/*floor*/
Square fl, fl0, fl1, fl2, fl3, fl4;
VectorND floor0, floor1, floor2, floor3;

/*Cortina*/
Cortina cortina;

void setup() {

	printf("\n\n<<<<<<<<<<<<>>>>> Terminus POV-Ray <<<<<>>>>>>>>>>>>>\n\n                  ---> Memory Setup ---> \n\n");

          ///////////////////
          /*  Base for R3  */
          ///////////////////
          center.zeroVectorND(3);
          I.initVectorND(3, 1.0, 0.0, 0.0);
          J.initVectorND(3, 0.0, 1.0, 0.0);
          K.initVectorND(3, 0.0, 0.0, 1.0);
          minusI.initVectorND(3,-1.0, 0.0, 0.0);
          minusJ.initVectorND(3, 0.0,-1.0, 0.0);
          minusK.initVectorND(3, 0.0, 0.0,-1.0);

          ///////////////////
          /*Camara position*/
          ///////////////////
          theta = 0.4 * PI; 
          phi = 0.75 * PI;
          R = 150;
          double X = R * sin(theta) * cos(phi);
          double Z = R * sin(theta) * sin(phi);
          double Y = R * cos(theta);
          position.initVectorND(3, X, Y, Z);

          ///////////////////
          /*Light position*/
          ///////////////////
          lightPosition.initVectorND(3,-4.0, 6.0, 3.0);

          
          joker.initVectorND(3, 2.0, 0.0, 0.0);
          joker0.initVectorND(3, 2.0, 0.0, 0.0);

          ///////////////////
          /*SkyBox         */
          ///////////////////
          double far = 15.0;
          double wid = 20.0;
          floor0.initVectorND(3, wid, -2.0, wid);
          floor1.initVectorND(3,-wid, -2.0, wid);
          floor2.initVectorND(3,-wid, -2.0,-wid);
          floor3.initVectorND(3, wid, -2.0,-wid);
          fl.initSquare(floor0, floor1, floor2, floor3);
          printf("-->Floor setup succesful\n");

          ///////////////////
          /*Rotation Matrix*/
          ///////////////////
          U.initRotationMats(0.0);

          ///////////////////
          /*Geometry       */
          ///////////////////

          VectorND a0, b0, c0;
          a0.initVectorND(3, 2.0, 0.0, 0.0);
          b0.initVectorND(3, 0.0, 2.0, 0.0);
          c0.initVectorND(3, 0.0, 0.0, 2.0);
          Facet ground;
          ground.initFacet(a0, b0, c0);


          joker.updateVector3D(0.0, 2.0, 0.0);
          joker0.updateVector3D(1.0, 0.0, 1.0);
          //ant.antSet(joker, joker0, 0.3, 0.0*PI, 0.0*PI, ground, 0);
          antPile.initMatrixAnt(1, 77 + 25 + 49 + 25 + 42);
          cortina.initCortina(100, 0.1);
          printf("-->Curve animation setup succesful\n");


          ////////////////////
          /*Vector Animation*/
          ////////////////////
          int count = 0;
          double teta1 = 0;
          double teta2 = 0;
          double move = 1.5;
          double move0 = 0.0;
          double step = 0.025;

          while (count < 77) {

            if (count < 25)
              antPile.initA(0, count, 
              midPoint(cortina.base.curve.getArista(0, count).getTail(), cortina.head.curve.getArista(0, count).getTail()), 
              midPoint(cortina.base.curve.getArista(0, count).getHead(), cortina.head.curve.getArista(0, count).getHead()), 
              0.3, 
              0.65*teta1, 
              3.0*teta1,
              cortina.tela.getFacet(0, count), 1, 0.0);

            if (25 <= count && count < 50)
              antPile.initA(0, count, 
              midPoint(cortina.base.curve.getArista(0, count).getTail(), cortina.head.curve.getArista(0, count).getTail()), 
              midPoint(cortina.base.curve.getArista(0, count).getHead(), cortina.head.curve.getArista(0, count).getHead()),
              0.3, 
              0.65*teta1, 
              3.0*teta1,
              cortina.tela.getFacet(0, count), 0, 0.0);

            if (50 <= count && count < 75)
              antPile.initA(0, count, 
              midPoint(cortina.base.curve.getArista(0, count).getTail(), cortina.head.curve.getArista(0, count).getTail()), 
              midPoint(cortina.base.curve.getArista(0, count).getHead(), cortina.head.curve.getArista(0, count).getHead()),
              0.3, 
              0.65*teta1, 
              3.0*teta1,
              cortina.tela.getFacet(0, count), 0, 0.0);

            if (75 <= count && count < 100)
              antPile.initA(0, count, 
              midPoint(cortina.base.curve.getArista(0, count).getTail(), cortina.head.curve.getArista(0, count).getTail()), 
              midPoint(cortina.base.curve.getArista(0, count).getHead(), cortina.head.curve.getArista(0, count).getHead()),
              0.3, 
              0.65*teta1, 
              3.0*teta1,
              cortina.tela.getFacet(0, count), 1, 0.0);

            if (count < 10) teta1 += step;
            if (10 <= count && count < 20) teta1 -= step;
            if (20 <= count && count < 30) teta1 -= step;
            if (30 <= count && count < 40) teta1 += step;
            if (40 <= count && count < 50) teta1 += step;
            if (50 <= count && count < 60) teta1 -= step;
            if (60 <= count && count < 70) teta1 -= step;
            if (70 <= count && count < 80) teta1 += step;
            if (80 <= count && count < 90) teta1 += step;
            if (90 <= count && count < 100) teta1 -= step;
            count += 1;
          }

          int i0m = count;
          int i0n = 0;
          while (i0m < count + 25) {

            antPile.initA(0, i0m, 
              midPoint(cortina.base.curve.getArista(0, count).getTail(), cortina.head.curve.getArista(0, count).getTail()), 
              midPoint(cortina.base.curve.getArista(0, count).getHead(), cortina.head.curve.getArista(0, count).getHead()),
              0.3, 
              0.65*teta1, 
              2.0*teta1,
              cortina.tela.getFacet(0, count), 1, -0.04 * (double)i0n);

            i0m += 1;
            i0n += 1;
          }

          while (28 < count) {

            if (75 <= count && count < 100)
              antPile.initA(0, i0m, 
              midPoint(cortina.base.curve.getArista(0, count).getTail(), cortina.head.curve.getArista(0, count).getTail()), 
              midPoint(cortina.base.curve.getArista(0, count).getHead(), cortina.head.curve.getArista(0, count).getHead()),
              0.3, 
              0.65*teta1, 
              3.0*teta1,
              cortina.tela.getFacet(0, count), 1,-0.04*25.0);


            if (50 <= count && count < 75)
              antPile.initA(0, i0m, 
              midPoint(cortina.base.curve.getArista(0, count).getTail(), cortina.head.curve.getArista(0, count).getTail()), 
              midPoint(cortina.base.curve.getArista(0, count).getHead(), cortina.head.curve.getArista(0, count).getHead()),
              0.3, 
              0.65*teta1, 
              3.0*teta1,
              cortina.tela.getFacet(0, count), 0,-0.04*25.0);

            if (25 <= count && count < 50)
              antPile.initA(0, i0m, 
              midPoint(cortina.base.curve.getArista(0, count).getTail(), cortina.head.curve.getArista(0, count).getTail()), 
              midPoint(cortina.base.curve.getArista(0, count).getHead(), cortina.head.curve.getArista(0, count).getHead()),
              0.3, 
              0.65*teta1, 
              3.0*teta1,
              cortina.tela.getFacet(0, count), 0,-0.04*25.0);

            if (count < 10) teta1 += step;
            if (10 <= count && count < 20) teta1 -= step;
            if (20 <= count && count < 30) teta1 -= step;
            if (30 <= count && count < 40) teta1 += step;
            if (40 <= count && count < 50) teta1 += step;
            if (50 <= count && count < 60) teta1 -= step;
            if (60 <= count && count < 70) teta1 -= step;
            if (70 <= count && count < 80) teta1 += step;
            if (80 <= count && count < 90) teta1 += step;
            if (90 <= count && count < 100) teta1 -= step;
            count -= 1;
            i0m += 1;
          }

          int i1m = i0m;
          i0n = 0;
          while (i1m < i0m + 25) {

            antPile.initA(0, i1m, 
              midPoint(cortina.base.curve.getArista(0, count).getTail(), cortina.head.curve.getArista(0, count).getTail()), 
              midPoint(cortina.base.curve.getArista(0, count).getHead(), cortina.head.curve.getArista(0, count).getHead()),
              0.3, 
              0.65*teta1, 
              2.0*teta1,
              cortina.tela.getFacet(0, count), 0, (-0.04 * 25.0) + (-0.04*(double)i0n));

            i1m += 1;
            i0n += 1;
          }





          while (count < 70) {

//            if (75 <= count && count < 100)
//              antPile.initA(0, i0m, 
//              midPoint(cortina.base.curve.getArista(0, count).getTail(), cortina.head.curve.getArista(0, count).getTail()), 
//              midPoint(cortina.base.curve.getArista(0, count).getHead(), cortina.head.curve.getArista(0, count).getHead()),
//              0.3, 
//              0.65*teta1, 
//              3.0*teta1,
//              cortina.tela.getFacet(0, count), 1, 0.0);


            if (50 <= count && count < 75)
              antPile.initA(0, i1m, 
              midPoint(cortina.base.curve.getArista(0, count).getTail(), cortina.head.curve.getArista(0, count).getTail()), 
              midPoint(cortina.base.curve.getArista(0, count).getHead(), cortina.head.curve.getArista(0, count).getHead()),
              0.3, 
              0.65*teta1, 
              3.0*teta1,
              cortina.tela.getFacet(0, count), 0, 0.0);

            if (25 <= count && count < 50)
              antPile.initA(0, i1m, 
              midPoint(cortina.base.curve.getArista(0, count).getTail(), cortina.head.curve.getArista(0, count).getTail()), 
              midPoint(cortina.base.curve.getArista(0, count).getHead(), cortina.head.curve.getArista(0, count).getHead()),
              0.3, 
              0.65*teta1, 
              3.0*teta1,
              cortina.tela.getFacet(0, count), 0, 0.0);

            if (count < 10) teta1 += step;
            if (10 <= count && count < 20) teta1 -= step;
            if (20 <= count && count < 30) teta1 -= step;
            if (30 <= count && count < 40) teta1 += step;
            if (40 <= count && count < 50) teta1 += step;
            if (50 <= count && count < 60) teta1 -= step;
            if (60 <= count && count < 70) teta1 -= step;
            if (70 <= count && count < 80) teta1 += step;
            if (80 <= count && count < 90) teta1 += step;
            if (90 <= count && count < 100) teta1 -= step;
            count += 1;
            i1m += 1;
          }






          printf("-->Animation setup succesful\n");

          joker.updateVector3D(0.0, 3.0, 0.0);
          joker0.updateVector3D(0.0,-3.0, 0.0);
          flecha0.aristaSet(joker, joker0, 0.1);
          joker.updateVector3D(3.0, 0.0, 0.0);
          joker0.updateVector3D(-3.0, 0.0, 0.0);
          flecha1.aristaSet(joker, joker0, 0.1);
          joker.updateVector3D(0.0, 0.0, 3.0);
          joker0.updateVector3D(0.0, 0.0,-3.0);
          flecha2.aristaSet(joker, joker0, 0.1);

          //cortina.moveCortina();
}

int main(void)
{	
  	setup();
  	POVRayWriter pov("topology.pov");

    pov.eye(0.35 * PI, 1.25 * PI, 250);

    pov.renderSquare(fl, U, 10);        //floor
  	pov.createLight(lightPosition);
    pov.renderArrow(flecha0, U, 6);     //Y-axis
    pov.renderArrow(flecha1, U, 6);     //X-axis
    pov.renderArrow(flecha2, U, 6);     //Z-axis
    
    string str, strAux0, strAux1, strAux2, strAux3;

    //pov.renderAnt(ant, U, 6);
    //pov.renderSpaceCurve(cortina.base, U, 7);
//    pov.renderSpaceCurve(cortina.head, U, 7);

    for (int i = 0; i < 2*100; i++)
      pov.renderFacetPOVRay(cortina.tela.getFacet(0, i), 6, U);

    joker.updateVector3D(
      cortina.base.curve.getArista(0, 0).getHead().access(0),
      cortina.base.curve.getArista(0, 0).getHead().access(1) + 0.25,
      cortina.base.curve.getArista(0, 0).getHead().access(2));

    pov.text("-13", 0.2, joker, 90, "Red");

    joker.updateVector3D(
      cortina.base.curve.getArista(0, 7).getHead().access(0),
      cortina.base.curve.getArista(0, 7).getHead().access(1) + 0.17,
      cortina.base.curve.getArista(0, 7).getHead().access(2));

    pov.text("-12", 0.2, joker, 90, "Red");

    joker.updateVector3D(
      cortina.base.curve.getArista(0, 14).getHead().access(0),
      cortina.base.curve.getArista(0, 14).getHead().access(1) + 0.17,
      cortina.base.curve.getArista(0, 14).getHead().access(2));

    pov.text("-11", 0.2, joker, 90, "Red");

    joker.updateVector3D(
      cortina.base.curve.getArista(0, 21).getHead().access(0),
      cortina.base.curve.getArista(0, 21).getHead().access(1) + 0.17,
      cortina.base.curve.getArista(0, 21).getHead().access(2));

    pov.text("-10", 0.2, joker, 90, "Red");

    joker.updateVector3D(
      cortina.base.curve.getArista(0, 28).getHead().access(0),
      cortina.base.curve.getArista(0, 28).getHead().access(1) + 0.17,
      cortina.base.curve.getArista(0, 28).getHead().access(2));

    pov.text("-9", 0.2, joker, 90, "Red");

    joker.updateVector3D(
      cortina.base.curve.getArista(0, 35).getHead().access(0),
      cortina.base.curve.getArista(0, 35).getHead().access(1) + 0.17,
      cortina.base.curve.getArista(0, 35).getHead().access(2));

    pov.text("-8", 0.2, joker, 90, "Red");

    joker.updateVector3D(
      cortina.base.curve.getArista(0, 42).getHead().access(0),
      cortina.base.curve.getArista(0, 42).getHead().access(1) + 0.17,
      cortina.base.curve.getArista(0, 42).getHead().access(2));

    pov.text("-7", 0.2, joker, 90, "Red");

    joker.updateVector3D(
      cortina.base.curve.getArista(0, 49).getHead().access(0),
      cortina.base.curve.getArista(0, 49).getHead().access(1) + 0.17,
      cortina.base.curve.getArista(0, 49).getHead().access(2));

    pov.text("-6", 0.2, joker, 90, "Red");

    joker.updateVector3D(
      cortina.base.curve.getArista(0, 56).getHead().access(0),
      cortina.base.curve.getArista(0, 56).getHead().access(1) + 0.17,
      cortina.base.curve.getArista(0, 56).getHead().access(2));

    pov.text("-5", 0.2, joker, 90, "Red");

    joker.updateVector3D(
      cortina.base.curve.getArista(0, 63).getHead().access(0),
      cortina.base.curve.getArista(0, 63).getHead().access(1) + 0.17,
      cortina.base.curve.getArista(0, 63).getHead().access(2));

    pov.text("-4", 0.2, joker, 90, "Red");

    joker.updateVector3D(
      cortina.base.curve.getArista(0, 70).getHead().access(0),
      cortina.base.curve.getArista(0, 70).getHead().access(1) + 0.17,
      cortina.base.curve.getArista(0, 70).getHead().access(2));

    pov.text("-3", 0.2, joker, 90, "Red");

    joker.updateVector3D(
      cortina.base.curve.getArista(0, 77).getHead().access(0),
      cortina.base.curve.getArista(0, 77).getHead().access(1) + 0.17,
      cortina.base.curve.getArista(0, 77).getHead().access(2));

    pov.text("-2", 0.2, joker, 90, "Red");

    joker.updateVector3D(
      cortina.base.curve.getArista(0, 84).getHead().access(0),
      cortina.base.curve.getArista(0, 84).getHead().access(1) + 0.17,
      cortina.base.curve.getArista(0, 84).getHead().access(2));

    pov.text("-1", 0.2, joker, 90, "Red");

    joker.updateVector3D(
      cortina.base.curve.getArista(0, 91).getHead().access(0),
      cortina.base.curve.getArista(0, 91).getHead().access(1) + 0.17,
      cortina.base.curve.getArista(0, 91).getHead().access(2));

    pov.text("0", 0.2, joker, 90, "Red");

    for (int i = 0; i < 102; i++) {
        str = "   #if ((";
        strAux0 = to_string(i);
        strAux1 = "*0.003267941) + 0*0.33333 <= clock & clock <= (";
        strAux2 = to_string(i+1);
        strAux3 = "*0.003267941) + 0*0.33333)";
  
        str += strAux0;
        str += strAux1;
        str += strAux2;
        str += strAux3;
  
        pov.writer << str << endl;
        //pov.renderMatrixArista(cortina.base.curveList.A[i], U, 0.05, 7);
        pov.renderAnt(antPile.A[0][i], U, 6);
        pov.writer << "   #end" << endl;
      }


      for (int i = 0; i < 49 + 25; i++) {
        str = "   #if ((";
        strAux0 = to_string(i);
        strAux1 = "*0.0045) + 1*0.33333 <= clock & clock <= (";
        strAux2 = to_string(i+1);
        strAux3 = "*0.0045) + 1*0.33333)";
  
        str += strAux0;
        str += strAux1;
        str += strAux2;
        str += strAux3;
  
        pov.writer << str << endl;
        //pov.text("v", 0.7, joker, 0.0, "White");
        pov.renderAnt(antPile.A[0][102 + i], U, 6);
        pov.writer << "   #end" << endl;
      }

      for (int i = 0; i < 42; i++) {
        str = "   #if ((";
        strAux0 = to_string(i);
        strAux1 = "*0.007936429) + 2*0.33333 <= clock & clock <= (";
        strAux2 = to_string(i+1);
        strAux3 = "*0.007936429) + 2*0.33333)";
  
        str += strAux0;
        str += strAux1;
        str += strAux2;
        str += strAux3;
  
        pov.writer << str << endl;
        //pov.text("v", 0.7, joker, 0.0, "White");
        pov.renderAnt(antPile.A[0][176 + i], U, 6);
        pov.writer << "   #end" << endl;
      }


    pov.closePOVRayWriter();
  	cout << "\n\n\n";
}