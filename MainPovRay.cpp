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
#include "Tela.hpp"

using namespace std;

double PI = 3.1415926535897932384626;

VectorND center, I, J, K, minusI, minusJ, minusK, position, lightPosition;
VectorND joker, joker0;
double radius = 0.25;
double theta;
double phi;
double R, newR;
int red = 7;
int green = 8;
int blue = 9;
int white = 11;
int black = 12;
int yellow = 13;
int orange = 14;
int count = 0;

/*Rotation Matrix System*/
RotationMats U, V, W;

/*Arrow*/
Arrow flecha, flecha0, flecha1, flecha2;

/*Intro*/
Arrow baseI, baseJ, baseK;
ArrowTransform sbaseI, sbaseJ, sbaseK;

/*floor*/
Square fl, fl0, fl1, fl2, fl3, fl4;
VectorND floor0, floor1, floor2, floor3;

/*Cortina*/
Dodecahedron dodeca;
Cortina cortina;

/*Torus*/
Torus TT;

Tela tela;

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
          lightPosition.initVectorND(3, 0.0, 5.0, 0.0);

          
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
          V.initRotationMatsY(0.0);
          W.initRotationMatsY(0.0);

          ///////////////////
          /*Geometry       */
          ///////////////////

          VectorND a0, b0, c0;
          a0.initVectorND(3, 2.0, 0.0, 0.0);
          b0.initVectorND(3, 0.0, 2.0, 0.0);
          c0.initVectorND(3, 0.0, 0.0, 2.0);
          Facet ground;
          ground.initFacet(a0, b0, c0);


          ////////////////////
          /*Base for R3*/
          ////////////////////
          joker.updateVector3D(0.0, 1.0, 0.0);
          joker0.updateVector3D(0.0, 0.0, 0.0);
          flecha0.aristaSet(joker, joker0, 0.1);
          joker.updateVector3D(1.0, 0.0, 0.0);
          flecha1.aristaSet(joker, joker0, 0.1);
          joker.updateVector3D(0.0, 0.0, 1.0);
          flecha2.aristaSet(joker, joker0, 0.1);

          //TT.initTorus(5, 2.0, 1.0, center);
          tela.initTela("Go");
          joker.updateVector3D(0.0, 0.0,-3.5);
          dodeca.initDodecahedron(1, joker);
          //dodeca.initSmooth(2);

}

int main(void)
{ 
    setup();

    //Xstring title;
    //title = "topology";
    //title += to_string(0);
    //title += ".pov";
    
//    //POVRayWriter pov(title);
//    POVRayWriter pov;
//    pov.initPovRay(title);
//    pov.TILEFLOOR();
//   // pov.renderSquare(fl, U, 10);        //floor
//    pov.createLight(lightPosition);
//    //pov.renderArrow(flecha0, U, 6);     //Y-axis
//    //pov.renderArrow(flecha1, U, 6);     //X-axis
//    //pov.renderArrow(flecha2, U, 6);     //Z-axis
//    pov.eye(0.01 * PI, 0.0 * PI, 550);
//    //pov.renderTorus(TT, U, 0);
//    pov.renderTela(tela, U, 5);
//    pov.renderDodecahedron(dodeca, U);
//    pov.closePOVRayWriter();

    int count = 0;
    double rotSpeed = 0.0;
    double rotSpeedY = 0.0;
    double rotSpeedW = 0.0;
    int aux = 2;
    while (count < 1) {
      string title;
      title = "topologyTerminus0";
      title += to_string(count);
      title += ".pov";
      U.updateRotationMats(rotSpeed);
      POVRayWriter pov;
      pov.initPovRay(title);
      pov.TILEFLOOR();
      pov.createLight(lightPosition);
      //pov.renderArrow(flecha0, U, 6);     //Y-axis
      //pov.renderArrow(flecha1, U, 6);     //X-axis
      //pov.renderArrow(flecha2, U, 6);     //Z-axis
      pov.eye(0.01 * PI, 0.0 * PI, 550);
      pov.renderTela(tela, V, 5, aux);
      rotSpeed += 0.015;
      pov.renderDodecahedron(dodeca, U);
      pov.closePOVRayWriter();
      count += 1;
      cout << "\n --> i = " << count;
      rotSpeedW += 0.05;
      aux += 2;
    }


}

/*
for x in topology*.pov; do echo $x ; done
ffmpeg -r 36 -f image2 -s 500x500 -i topology%03d.png -vcodec libx264 -crf 25 -pix_fmt yuv420p test.mp4
*/

/*g++ Arrow.cpp ant.cpp dodecahedron.cpp geometry.cpp MainPovRay.cpp matrix.cpp PovRayWriter.cpp simplex.cpp Turtle.cpp VectorND.cpp -lm -lGL -lGLU -lglut*/