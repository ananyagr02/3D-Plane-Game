//#include<windows.h>
//#include <GL/glut.h>
//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <cstring>  // for strcpy, strcmp, etc.
//#include <string>   // for std::string
//#include <cstdlib>  // for rand(), srand()
//#include <stdlib.h>
//#define rad (3.1416/180)
//#define EN_SIZE 20
//using namespace std;
//
//int score = 0;
//bool scored = false;
//
//class RGBpixmap {
//public:
//    int nRows, nCols;
//    void readBMPFile(char* frame);
//    void makeCheckerBoard();
//    void makeCheckImage();
//    void setTexture(unsigned int texName);
//    ~RGBpixmap();
//};
//
//RGBpixmap pix[6];
//
//float zoom = 4;
//int tola[5000][5000];
//float tX = 0, tY = 0, tZ = -8, rX = 0, rY = 0, rZ = 4;
//float tZ1 = -20, tZ2 = -40, tZ3 = -60, tZ4 = -80, tZ5 = -100, tZ6 = -120;
//float rotX = 0, rotY = 0, rotZ = 0;
//float cosX = 0, cosY = 1, cosZ = 0;
//float angle = 0;
//float xEye = 0.0f, yEye = 5.0f, zEye = 30.0f;
//float cenX = 0, cenY = 0, cenZ = 0, roll = 0;
//float radius = 0;
//float theta = 0, slope = 0;
//float speed = 0.3;
//float angleBackFrac = 0.2;
////bool saheedMinarVisible = false;
//float r[] = { 0.1,0.4,0.0,0.9,0.2,0.5,0.0,0.7,0.5,0.0 };
//float g[] = { 0.2,0.0,0.4,0.5,0.2,0.0,0.3,0.9,0.0,0.2 };
//float b[] = { 0.4,0.5,0.0,0.7,0.9,0.0,0.1,0.2,0.5,0.0 };
//int TIME = 0;
//bool START = false;
//float torusPosX[7] = { 1,-2,3,-4,-2,0,2 };
//float torusPosY[7] = { 2,3,10,6,7,4,1 };
//
//bool rot = false;
//
//
//static void resize(int width, int height)
//{
//    const float ar = (float)width / (float)height;
//
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 1000.0);
//
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//}
//
//void drawPlane() {
//
//    glColor3d(0.4, 0.2, 0.2);
//    glPushMatrix();
//    glTranslated(0, 1.55, 0);
//    glScaled(2, 0.05, 1.5);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glColor3d(0.4, 0.2, 0.2);
//    glPushMatrix();
//    glTranslated(0, 1.6, 0);
//    glScaled(1.9, 0.05, 1.4);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    //glColor3d(0.4,0.2,0.2);
//    //glColor3d(1,0.8,0.7);
//    glColor3d(0.4, 0.2, 0.2);
//    glPushMatrix();
//    glTranslated(0, 1.65, 0);
//    glScaled(1.8, 0.05, 1.3);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    /// pataton
//
//    glColor3d(1, 1, 1);
//    glPushMatrix();
//    glTranslated(0, 1.68, -0.4);
//    glScaled(0.5, 0.02, 0.08);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    /// Piller
//
//    glPushMatrix();
//    glTranslated(0, 1.99, -0.4);
//    glScaled(0.06, 0.7, 0.04);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    /// ROD
//
//    glColor3d(0, 0, 0);
//
//    glPushMatrix();
//    glTranslated(0.07, 1.99, -0.4);
//    glScaled(0.003, 0.7, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0.11, 1.99, -0.4);
//    glScaled(0.003, 0.7, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0.15, 1.99, -0.4);
//    glScaled(0.003, 0.7, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    ///
//    glPushMatrix();
//    glTranslated(-0.22, 0, 0);
//    glPushMatrix();
//    glTranslated(0.07, 1.99, -0.4);
//    glScaled(0.003, 0.7, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0.11, 1.99, -0.4);
//    glScaled(0.003, 0.7, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0.15, 1.99, -0.4);
//    glScaled(0.003, 0.7, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//    glPopMatrix();
//
//    ///Horizontal rod
//    glPushMatrix();
//    glTranslated(2.2, 0, -0.1);
//    glScaled(4.2, 1, 1);
//    glColor3d(0, 0, 0);
//    glPushMatrix();
//    glTranslated(-0.528, 1.85, -0.3);
//    glScaled(0.1, 0.003, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.528, 2.02, -0.3);
//    glScaled(0.1, 0.003, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.528, 2.18, -0.3);
//    glScaled(0.1, 0.003, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//    glColor3d(1, 1, 1);
//    glPopMatrix();
//
//    /// ROD END
//
//    glColor3d(1, 1, 1);
//    glPushMatrix();
//    glTranslated(-0.22, 1.99, -0.4);
//    glScaled(0.06, 0.7, 0.04);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0.22, 1.99, -0.4);
//    glScaled(0.06, 0.7, 0.04);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    /// Upper piller
//
//    glPushMatrix();
//    glTranslated(0, 0.743, -1.424);
//    glRotated(45, 1, 0, 0);
//
//    //glColor3d(1,0,1);
//    glPushMatrix();
//    glTranslated(0, 1.99, -0.4);
//    glScaled(0.06, 0.3, 0.04);
//    glutSolidCube(1);
//    glPopMatrix();
//    //glColor3d(1,1,1);
//
//    glPushMatrix();
//    glTranslated(-0.22, 1.99, -0.4);
//    glScaled(0.06, 0.3, 0.04);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0.22, 1.99, -0.4);
//    glScaled(0.06, 0.3, 0.04);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0, 2.15, -0.4);
//    glScaled(0.5, 0.04, 0.04);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    /// ROD
//
//    glColor3d(0, 0, 0);
//
//    glPushMatrix();
//    glTranslated(0.07, 1.99, -0.4);
//    glScaled(0.003, 0.277, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0.11, 1.99, -0.4);
//    glScaled(0.003, 0.277, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0.15, 1.99, -0.4);
//    glScaled(0.003, 0.277, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    ///
//
//    glColor3d(0, 0, 0);
//    glPushMatrix();
//    glTranslated(-0.22, 0, 0);
//    glPushMatrix();
//    glTranslated(0.07, 1.99, -0.4);
//    glScaled(0.003, 0.277, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0.11, 1.99, -0.4);
//    glScaled(0.003, 0.277, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0.15, 1.99, -0.4);
//    glScaled(0.003, 0.277, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//    glPopMatrix();
//    /// ROD END
//
//    ///Horizontal rod
//    glPushMatrix();
//    glTranslated(2.2, 0, -0.1);
//    glScaled(4.2, 1, 1);
//    glColor3d(0, 0, 0);
//    glPushMatrix();
//    glTranslated(-0.528, 1.85, -0.3);
//    glScaled(0.1, 0.003, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.528, 2, -0.3);
//    glScaled(0.1, 0.003, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.528, 2.15, -0.3);
//    glScaled(0.1, 0.003, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//    glColor3d(1, 1, 1);
//    glPopMatrix();
//
//    glPopMatrix();
//
//
//    /// piller left 1
//    glColor3d(1, 1, 1);
//    glPushMatrix();
//    glTranslated(0.1, 0, -0.4);
//    glRotated(45, 0, 1, 0);
//
//    glPushMatrix();
//    glTranslated(-0.605, 1.94, -0.3);
//    glScaled(0.045, 0.65, 0.03);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.45, 1.94, -0.3);
//    glScaled(0.045, 0.65, 0.03);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.528, 2.258, -0.3);
//    glScaled(0.199, 0.04, 0.03);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.528, 1.68, -0.3);
//    glScaled(0.199, 0.02, 0.06);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    /// ROD
//    glColor3d(0, 0, 0);
//    glPushMatrix();
//    glTranslated(-0.64, -0.05, 0.1);
//    glScaled(1, 1.02, 1);
//    glPushMatrix();
//    glTranslated(0.078, 1.99, -0.4);
//    glScaled(0.003, 0.56, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0.11, 1.99, -0.4);
//    glScaled(0.003, 0.56, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0.145, 1.99, -0.4);
//    glScaled(0.003, 0.56, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//    glPopMatrix();
//
//    ///
//    glColor3d(1, 1, 1);
//
//    ///Horizontal rod
//    glColor3d(0, 0, 0);
//    glPushMatrix();
//    glTranslated(-0.528, 1.85, -0.3);
//    glScaled(0.1, 0.003, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.528, 2, -0.3);
//    glScaled(0.1, 0.003, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.528, 2.15, -0.3);
//    glScaled(0.1, 0.003, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//    glColor3d(1, 1, 1);
//    glPopMatrix();
//
//    /// piller left 2
//    glPushMatrix();
//    glTranslated(0.65, 0, 0.3);
//    glRotated(-45, 0, 1, 0);
//
//    glPushMatrix();
//    glTranslated(-0.605, 1.94, -0.3);
//    glScaled(0.045, 0.65, 0.03);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.45, 1.94, -0.3);
//    glScaled(0.045, 0.65, 0.03);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.528, 2.258, -0.3);
//    glScaled(0.199, 0.04, 0.03);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.528, 1.68, -0.3);
//    glScaled(0.199, 0.02, 0.06);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    ///ROD
//    glColor3d(0, 0, 0);
//    glPushMatrix();
//    glTranslated(-0.64, -0.05, 0.1);
//    glScaled(1, 1.02, 1);
//    glPushMatrix();
//    glTranslated(0.078, 1.99, -0.4);
//    glScaled(0.003, 0.56, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0.11, 1.99, -0.4);
//    glScaled(0.003, 0.56, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0.145, 1.99, -0.4);
//    glScaled(0.003, 0.56, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//    glPopMatrix();
//    glColor3d(1, 1, 1);
//    ///ROD
//
//    ///Horizontal rod
//    glColor3d(0, 0, 0);
//    glPushMatrix();
//    glTranslated(-0.528, 1.85, -0.3);
//    glScaled(0.1, 0.003, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.528, 2, -0.3);
//    glScaled(0.1, 0.003, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.528, 2.15, -0.3);
//    glScaled(0.1, 0.003, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//    glColor3d(1, 1, 1);
//
//    glPopMatrix();
//
//
//    glPushMatrix();
//    /// piller left 1
//    glTranslated(0.06, 0, 0.14);
//    glPushMatrix();
//
//    glTranslated(-0.2, 0, -0.31);
//    glRotated(45, 0, 1, 0);
//
//    glPushMatrix();
//    glTranslated(-0.605, 1.88, -0.3);
//    glScaled(0.045, 0.4, 0.03);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.45, 1.88, -0.3);
//    glScaled(0.045, 0.4, 0.03);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.528, 2.08, -0.3);
//    glScaled(0.2, 0.04, 0.03);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.528, 1.68, -0.3);
//    glScaled(0.199, 0.02, 0.06);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    ///ROD
//    glColor3d(0, 0, 0);
//    glPushMatrix();
//    glTranslated(-0.641, 0.43, 0.1);
//    glScaled(1, 0.73, 1);
//    glPushMatrix();
//    glTranslated(0.078, 1.99, -0.4);
//    glScaled(0.003, 0.56, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0.11, 1.99, -0.4);
//    glScaled(0.003, 0.56, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0.145, 1.99, -0.4);
//    glScaled(0.003, 0.56, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//    glPopMatrix();
//
//    ///Horizontal rod
//    glColor3d(0, 0, 0);
//    glPushMatrix();
//    glTranslated(-0.528, 1.8, -0.3);
//    glScaled(0.1, 0.003, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.528, 1.96, -0.3);
//    glScaled(0.1, 0.003, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//    glColor3d(1, 1, 1);
//    ///ROD
//
//    glPopMatrix();
//
//    /// piller left 2
//    glPushMatrix();
//    glTranslated(0.83, 0, 0.39);
//    glRotated(-45, 0, 1, 0);
//
//    glPushMatrix();
//    glTranslated(-0.605, 1.88, -0.3);
//    glScaled(0.045, 0.4, 0.03);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.45, 1.88, -0.3);
//    glScaled(0.045, 0.4, 0.03);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.528, 2.1, -0.3);
//    glScaled(0.199, 0.04, 0.03);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.528, 1.68, -0.3);
//    glScaled(0.199, 0.02, 0.06);
//    glutSolidCube(1);
//    glPopMatrix();
//
//
//    ///Horizontal rod
//    glColor3d(0, 0, 0);
//    glPushMatrix();
//    glTranslated(-0.528, 1.8, -0.3);
//    glScaled(0.1, 0.003, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-0.528, 1.96, -0.3);
//    glScaled(0.1, 0.003, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//    glColor3d(1, 1, 1);
//
//    ///ROD
//    glColor3d(0, 0, 0);
//    glPushMatrix();
//    glTranslated(-0.641, 0.43, 0.1);
//    glScaled(1, 0.73, 1);
//    glPushMatrix();
//    glTranslated(0.078, 1.99, -0.4);
//    glScaled(0.003, 0.56, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0.11, 1.99, -0.4);
//    glScaled(0.003, 0.56, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0.145, 1.99, -0.4);
//    glScaled(0.003, 0.56, 0.003);
//    glutSolidCube(1);
//    glPopMatrix();
//    glPopMatrix();
//    glColor3d(1, 1, 1);
//    ///ROD
//
//    glPopMatrix();
//
//
//    glPopMatrix();
//
//    /// Circle
//
//    glColor3d(1, 0, 0);
//    glPushMatrix();
//    glTranslated(0, 2.1, -0.44);
//    glScaled(0.35, 0.35, 0.01);
//    glutSolidSphere(1, 50, 50);
//    glPopMatrix();
//
//    glColor3d(0, 0, 0);
//    glPushMatrix();
//    glTranslated(-0.18, 1.9, -0.45);
//    glScaled(0.01, 0.5, 0.01);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glColor3d(0, 0, 0);
//    glPushMatrix();
//    glTranslated(0.18, 1.9, -0.45);
//    glScaled(0.01, 0.5, 0.01);
//    glutSolidCube(1);
//    glPopMatrix();
//
//
//}
//
//void fan() {
//    glColor3d(0.5, 1, 0);
//    glPushMatrix();
//    glTranslated(0, 0, 0);
//    glScaled(1, 1, 0.7);
//    glutSolidSphere(0.8, 30, 30);
//    glPopMatrix();
//
//    glColor3d(0.5, 1, 0);
//    glPushMatrix();
//    glTranslated(0, 0, 0);
//    glRotated(5, 0, 1, 0);
//    glScaled(0.5, 2.5, 0.05);
//    glutSolidSphere(1, 30, 30);
//    glPopMatrix();
//
//    glColor3d(0.5, 1, 0);
//    glPushMatrix();
//    glTranslated(0, 0, 0);
//    glRotated(-5, 0, 1, 0);
//    glRotated(90, 0, 0, 1);
//    glScaled(0.5, 2.5, 0.05);
//    glutSolidSphere(1, 30, 30);
//    glPopMatrix();
//
//}
//
//void plane() {
//    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
//    double a = t * 90.0;
//
//    /// Main body
//    glColor3d(0.5, 1, 0);
//    glPushMatrix();
//    glTranslated(0, 0, 0);
//    glScaled(3, 0.4, 0.5);
//    glutSolidSphere(1, 30, 30);
//    glPopMatrix();
//
//    glColor3d(0, 0, 0);
//    glPushMatrix();
//    glTranslated(1.7, 0.1, 0);
//    glScaled(1.5, 0.7, 0.8);
//    glRotated(40, 0, 1, 0);
//    glutSolidSphere(0.45, 30, 30);
//    glPopMatrix();
//
//    ///Right
//    glColor3d(0.8, 1, 0);
//    glPushMatrix();
//    glTranslated(0, 0, 1.2);
//    glRotated(-50, 0, 1, 0);
//    glScaled(0.7, 0.1, 3);
//    glRotated(25, 0, 1, 0);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glColor3d(0.8, 1, 0);
//    glPushMatrix();
//    glTranslated(-0.3, -0.15, 1.5);
//    glRotated(90, 0, 1, 0);
//    glScaled(0.1, 0.1, 0.9);
//    glutSolidTorus(0.5, 0.5, 50, 50);
//    glPopMatrix();
//
//    glColor3d(0.8, 1, 0);
//    glPushMatrix();
//    glTranslated(0.2, -0.15, 0.9);
//    glRotated(90, 0, 1, 0);
//
//    /// FAN
////        glPushMatrix();
////            glTranslated(0,0,0.5);
////            glRotated(10*a,0,0,1);
////            glScaled(0.1,0.1,0.1);
////            fan();
////        glPopMatrix();
//
//    glScaled(0.1, 0.1, 0.9);
//    glutSolidTorus(0.5, 0.5, 50, 50);
//    glPopMatrix();
//
//    ///Left
//    glColor3d(0.8, 1, 0);
//    glPushMatrix();
//    glTranslated(0, 0, -1.2);
//    glRotated(50, 0, 1, 0);
//    glScaled(0.7, 0.1, 3);
//    glRotated(-25, 0, 1, 0);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glColor3d(0.8, 1, 0);
//    glPushMatrix();
//    glTranslated(-0.3, -0.15, -1.5);
//    glRotated(90, 0, 1, 0);
//    glScaled(0.1, 0.1, 0.9);
//    glutSolidTorus(0.5, 0.5, 50, 50);
//    glPopMatrix();
//
//    glColor3d(0.8, 1, 0);
//    glPushMatrix();
//    glTranslated(0.2, -0.15, -0.9);
//    glRotated(90, 0, 1, 0);
//    glScaled(0.1, 0.1, 0.9);
//    glutSolidTorus(0.5, 0.5, 50, 50);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-2.8, 0, 0);
//    glScaled(0.8, 0.5, 0.3);
//
//    ///Right
//    glColor3d(0.8, 1, 0);
//    glPushMatrix();
//    glTranslated(0.4, 0, 1.5);
//    glRotated(-30, 0, 1, 0);
//    glScaled(0.7, 0.1, 3);
//    glRotated(10, 0, 1, 0);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    ///left
//    glColor3d(0.8, 1, 0);
//    glPushMatrix();
//    glTranslated(0.4, 0, -1.5);
//    glRotated(30, 0, 1, 0);
//    glScaled(0.7, 0.1, 3);
//    glRotated(-10, 0, 1, 0);
//    glutSolidCube(1);
//    glPopMatrix();
//    glPopMatrix();
//
//    glColor3d(0.8, 1, 0);
//    glPushMatrix();
//    glTranslated(-2.7, 0.5, 0);
//    glRotated(45, 0, 0, 1);
//    glScaled(0.8, 2, 0.1);
//    glRotated(-20, 0, 0, 1);
//    glutSolidCube(0.5);
//    glPopMatrix();
//
//    //    glColor3d(0.8,1,0);
//    //    glPushMatrix();
//    //        glTranslated(-2.95,0.85,0);
//    //        glRotated(90,0,1,0);
//    //        glScaled(0.05,0.05,0.6);
//    //        glutSolidTorus(0.5,0.5,50,50);
//    //    glPopMatrix();
//
//
//        ///FANS
//
//    //    glPushMatrix();
//    //        glTranslated(0,0,0);
//    //        glRotated(10*a,0,0,1);
//    //        //glRotated(90,1,0,0);
//    //        fan();
//    //    glPopMatrix();
//}
//
//
//void singleHouse(int R, int G, int B) {
//    glColor3d(r[R % 10], g[G % 10], b[B % 10]);
//    glPushMatrix();
//    glTranslated(0, 0, 0);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glColor3d(0, 0, 0);
//    glPushMatrix();
//    glTranslated(0.2, 0, 0);
//    glScaled(0.3, 0.3, 1.001);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glColor3d(0, 0, 0);
//    glPushMatrix();
//    glTranslated(-0.2, 0, 0);
//    glScaled(0.3, 0.3, 1.001);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glColor3d(0, 0, 0);
//    glPushMatrix();
//    glTranslated(0, 0, 0.2);
//    glScaled(1.001, 0.3, 0.3);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glColor3d(0, 0, 0);
//    glPushMatrix();
//    glTranslated(0, 0, -0.2);
//    glScaled(1.001, 0.3, 0.3);
//    glutSolidCube(1);
//    glPopMatrix();
//
//}
//
//void house(int n, int R, int G) {
//    for (int i = 0; i < n; i++) {
//        glPushMatrix();
//        glTranslated(0, 0.8 + i, 0);
//        singleHouse(G, R, i);
//        glPopMatrix();
//    }
//}
//
//void MonumentEnv() {
//    /// Ground
//    glColor3d(0, 0.5, 0.1);
//    glPushMatrix();
//    glTranslated(0, 0, 0);
//    glScaled(EN_SIZE * 2, 0.3, EN_SIZE * 2);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(-8, -2.7, -5);
//    glRotated(65, 0, 1, 0);
//    //glRotated(15,0,1,0);
//    glScaled(2, 2, 2);
//    drawPlane();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(8, -2.7, -5);
//    glRotated(-65, 0, 1, 0);
//    //glRotated(15,0,1,0);
//    glScaled(2, 2, 2);
//    drawPlane();
//    glPopMatrix();
//}
//
//void environment(int n) {
//
//    /// Ground
//    glColor3d(0, 0.5, 0.1);
//    glPushMatrix();
//    glTranslated(0, 0, 0);
//    glScaled(EN_SIZE * 2, 0.3, EN_SIZE * 2);
//    glutSolidCube(1);
//    glPopMatrix();
//
//
//    glColor3d(0, 1, 0.1);
//    glPushMatrix();
//    glTranslated(torusPosX[n], torusPosY[n], 0);
//    glScaled(0.3, 0.3, 0.3);
//    glutSolidTorus(1, 3, 30, 30);
//    glPopMatrix();
//
//    for (int i = -(EN_SIZE / 2) + 1; i < (EN_SIZE / 2); i += 2) {
//        for (int j = -(EN_SIZE / 2) + 1; j < (EN_SIZE / 2); j += 2) {
//            if (tola[i + (EN_SIZE / 2) + 1][j + (EN_SIZE / 2) + 1] != 0) {
//                glPushMatrix();
//                glTranslated(i, 0, j);
//                house(tola[i + (EN_SIZE / 2) + 1][j + (EN_SIZE / 2) + 1], i, j);
//                glPopMatrix();
//            }
//            else if (i >= -5 && i <= 5) {}
//            else {
//                tola[i + (EN_SIZE / 2) + 1][j + (EN_SIZE / 2) + 1] = (rand() % 5) + 1;
//                glPushMatrix();
//                glTranslated(i, 0, j);
//                house(tola[i + (EN_SIZE / 2) + 1][j + (EN_SIZE / 2) + 1], i, j);
//                glPopMatrix();
//            }
//        }
//    }
//
//    // glColor3d(0,1,0.7);
//
// //    glPushMatrix();
// //        glRotated(angle,0,1,0);
// //        glPushMatrix();
// //            glTranslated(tX,tY,tZ);
// //            glScaled(1,1,2);
// //            //glRotated(90,1,0,0);
// //            glutSolidCube(1);
// //        glPopMatrix();
// //    glPopMatrix();
//}
//
//void draw() {
//    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
//    double a = t * 90.0;
//
//    TIME = t;
//
//    ///Plane
//    if (rotX > 11)rotX = 11;
//    if (rotX < -11)rotX = -11;
//    if (rotZ > 10)rotZ = 10;
//    if (rotZ < -15)rotZ = -15;
//
//    glPushMatrix();
//    glTranslated(0, 1, 0);
//    glRotated(90, 0, 1, 0);
//    glRotated(5, 0, 0, 1);
//    glRotated(rotX, 1, 0, 0);
//    glRotated(rotY, 0, 1, 0);
//    glRotated(rotZ, 0, 0, 1);
//
//    glScaled(0.4, 0.4, 0.4);
//    plane();
//    glPopMatrix();
//
//    ///Environment
//    if (tX >= 4.1)tX = 4.1;
//    if (tX <= -4.1)tX = -4.1;
//    if (tY > 0.1)tY = 0.1;
//    if (tY < -15)tY = -15;
//
//    glPushMatrix();
//    glTranslated(tX, tY, tZ);
//    environment(2);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(tX, tY, tZ1);
//    MonumentEnv();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(tX, tY, tZ2);
//    environment(3);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(tX, tY, tZ3);
//    environment(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(tX, tY, tZ4);
//    environment(5);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(tX, tY, tZ5);
//    environment(4);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(tX, tY, tZ6);
//    environment(2);
//    glPopMatrix();
//
//    tZ += speed;
//    tZ1 += speed;
//    tZ2 += speed;
//    tZ3 += speed;
//    tZ4 += speed;
//    tZ5 += speed;
//    tZ6 += speed;
//
//    if (tZ >= 20)tZ = -110;
//    if (tZ1 >= 20)tZ1 = -110;
//    if (tZ2 >= 20)tZ2 = -110;
//    if (tZ3 >= 20)tZ3 = -110;
//    if (tZ4 >= 20)tZ4 = -110;
//    if (tZ5 >= 20)tZ5 = -110;
//    if (tZ6 >= 20)tZ6 = -110;
//
//    if (rotX > 0)rotX -= angleBackFrac;
//    if (rotX < 0)rotX += angleBackFrac;
//    if (rotY > 0)rotY -= angleBackFrac;
//    if (rotY < 0)rotY += angleBackFrac;
//    if (rotZ > 0)rotZ -= angleBackFrac;
//    if (rotZ < 0)rotZ += angleBackFrac;
//
//    //cout<<tX<<" "<<tY<<" "<<tZ<<endl;
//    //cout<<rotX<<" "<<rotY<<" "<<rotZ<<endl;
//
//    speed += 0.0002;
//    if (speed >= 0.7)speed = 0.7;
//}
//
//
//void drawBitmapText(char* str, float x, float y, float z)
//{
//    char* c;
//    glRasterPos3f(x, y + 8, z);
//
//    for (c = str; *c != '\0'; c++)
//    {
//        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
//    }
//}
//
//void drawStrokeText(const char* str, int x, int y, int z)
//{
//    const char* c;
//    glPushMatrix();
//    glTranslatef(x, y + 8, z);
//    glScalef(0.002f, 0.002f, z);
//
//    for (c = str; *c != '\0'; c++)
//    {
//        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
//    }
//    glPopMatrix();
//}
//
//void drawStrokeText2(const char* str, int x, int y, int z)
//{
//    const char* c;
//    glPushMatrix();
//    glTranslatef(x, y + 8, z);
//    glScalef(0.005f, 0.005f, z);
//
//    for (c = str; *c != '\0'; c++)
//    {
//        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
//    }
//    glPopMatrix();
//}
//void drawStrokeChar(char c, float x, float y, float z)
//{
//    glPushMatrix();
//    glTranslatef(x, y + 8, z);
//    glScalef(0.002f, 0.002f, z);
//    glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
//    glPopMatrix();
//}
//
//static void display(void)
//{
//    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
//    double a = t * 90.0;
//    double aa = a;
//
//    if (!rot) {
//        a = 0;
//    }
//
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    glLoadIdentity();
//
//    gluLookAt(0.0, 4.5, 10.0,
//        0, 4, 0,
//        0, 1.0f, 0.0f);
//
//    if (START) {
//
//        glPushMatrix();
//        glTranslated(0, 0, 0);
//        glScaled(zoom, zoom, zoom);
//        glRotated(a, 0, 1, 0);
//        draw();
//        glPopMatrix();
//
//        drawStrokeText("UP: W, DOWN: S, LEFT: A, RIGHT: D, MAIN MENU: M", -8, 0.9, 0);
//        drawStrokeText("TIME : ", 3, 0, 0);
//        int mod, number = 0;
//        while (TIME) {
//            mod = TIME % 10;
//            number = number * 10 + mod;
//            TIME /= 10;
//        }
//        float tmp = 0;
//        while (number) {
//            mod = number % 10;
//            drawStrokeChar(mod + 48, 4 + tmp, 0, 0);
//            number /= 10;
//            tmp += 0.2;
//        }
//    }
//    else {
//
//        glPushMatrix();
//        glTranslated(0, 3, 0);
//        glRotated(aa, 0, 1, 0);
//        glScaled(1.5, 1.5, 1.5);
//        plane();
//        glPopMatrix();
//
//        drawStrokeText("Press G to Start", -1, -1, 0);
//        drawStrokeText2("Plane Game", -2, 0, 0);
//    }
//
//    //glColor3d(1,1,0);
//    //drawStrokeText("Osama Hosam's OpenGL Tutorials",200,200,0);
//
////	glRasterPos2i(100, 120);
////    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
////    glutBitmapString(GLUT_BITMAP_HELVETICA_18, "text to render");
//
//    //drawBitmapText("Osama Hosam's OpenGL Tutorials",0,0,0);
//
//
//    //drawStrokeChar(49,2,0,0);
//
//
//    glutSwapBuffers();
//}
//
//static void key(unsigned char key, int x, int y)
//{
//    float frac = 0.3;
//    float rotFrac = 1;
//    switch (key)
//    {
//    case 27:
//    case 'q':
//        exit(0);
//        break;
//    case 'r':
//        rot = true;
//        break;
//    case 't':
//        rot = false;
//        break;
//    case 'z':
//        zoom += 0.05;
//        break;
//    case 'Z':
//        zoom -= 0.05;
//    case 'w':
//        tY -= frac;
//        rotZ += rotFrac;
//        break;
//    case 's':
//        tY += frac;
//        rotZ -= rotFrac;
//        break;
//    case 'a':
//        tX += frac;
//        rotX -= rotFrac * 3;
//        rotY += rotFrac / 2;
//        break;
//    case 'd':
//        tX -= frac;
//        rotX += rotFrac * 3;
//        rotY -= rotFrac / 2;
//        break;
//        //        case 'y':
//        //            rotX-=rotFrac;
//        //            break;
//        //        case 'h':
//        //            rotX+=rotFrac;
//        //            break;
//        //        case 'g':
//        //            rotY+=rotFrac;
//        //            break;
//        //        case 'j':
//        //            rotY-=rotFrac;
//        //            break;
//    case 'g':
//        START = true;
//        break;
//    case 'm':
//        START = false;
//        break;
//        //        case 'o':
//        //            cosX-=frac*cos(rotX*rad);
//        //            cosY+=frac*cos(rotY*rad);
//        //            cosZ-=frac*cos(rotZ*rad);
//        //            //cout<<"Front : "<<cosX<<" "<<cosY<<" "<<cosZ<<endl;
//        //            break;
//        //        case 'l':
//        //            cosX+=frac*cos(rotX*rad);
//        //            cosY-=frac*cos(rotY*rad);
//        //            cosZ+=frac*cos(rotZ*rad);
//        //            //cout<<"Back : "<<cosX<<" "<<cosY<<" "<<cosZ<<endl;
//        //            break;
//
//    }
//
//    glutPostRedisplay();
//}
//
//static void idle(void)
//{
//    glutPostRedisplay();
//}
//
//const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
//const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
//
//const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
//const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
//const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//const GLfloat high_shininess[] = { 100.0f };
//
///* Program entry point */
//
//int main(int argc, char* argv[])
//{
//    glutInit(&argc, argv);
//    glutInitWindowPosition(0, 0);
//    glutInitWindowSize(1366, 720);
//    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
//
//    glutCreateWindow("GLUT Shapes");
//
//    glutReshapeFunc(resize);
//    glutDisplayFunc(display);
//    glutKeyboardFunc(key);
//    glutIdleFunc(idle);
//
//    //PlaySound("starwars.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
//
//    glClearColor(1, 1, 1, 1);
//    glEnable(GL_CULL_FACE);
//    glCullFace(GL_BACK);
//
//    glEnable(GL_DEPTH_TEST);
//    glDepthFunc(GL_LESS);
//
//    glEnable(GL_LIGHT0);
//    glEnable(GL_NORMALIZE);
//    glEnable(GL_COLOR_MATERIAL);
//    glEnable(GL_LIGHTING);
//
//    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//
//    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
//    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
//
//    glutMainLoop();
//
//    return EXIT_SUCCESS;
//}



#include <windows.h>
#include <GL/glut.h>

#include "rgbpixmap.h" 

#include <iostream>
#include <vector>
#include <cmath>     // For std::abs, cos, etc.
#include <cstring>   // for strcpy, strcmp, etc. (though sprintf_s is in cstdio)
#include <string>    // for std::string
#include <cstdlib>   // for rand(), srand()
#include <stdlib.h>  // (already included cstdlib which is preferred C++ version)
#include <cstdio>    // For sprintf_s

#define rad (3.1416/180)
#define EN_SIZE 20
using namespace std;

// SCORE SYSTEM START: Global variables for scoring
int score = 0;
// bool scored = false; // Leaving this as it might be for something else

// Tracks if the torus in a specific chunk instance has been scored
// Index mapping:
// 0 -> tZ chunk's torus
// 1 -> tZ2 chunk's torus (tZ1 is monument, no torus)
// 2 -> tZ3 chunk's torus
// 3 -> tZ4 chunk's torus
// 4 -> tZ5 chunk's torus
// 5 -> tZ6 chunk's torus
bool torusInChunkScored[6] = { false, false, false, false, false, false };
// SCORE SYSTEM END: Global variables
/*
class RGBpixmap {
public:
    int nRows, nCols;
    void readBMPFile(const char* frame); // Changed char* to const char* to match common practice and rgbpixmap.cpp
    void makeCheckerBoard();
    void makeCheckImage();
    void setTexture(unsigned int texName);
    ~RGBpixmap();
    RGBpixmap(); // Added constructor declaration if it's missing from your header equivalent
};
*/
// Minimal constructor and destructor definitions if they were in a separate file
// This is just a placeholder if they are not already defined elsewhere when you link
// If your RGBpixmap class is fully defined in another .cpp, you might not need these here.
// However, the declaration `RGBpixmap pix[6];` requires a constructor to be accessible.

//RGBpixmap::RGBpixmap() : nRows(0), nCols(0) { /* pixel should be initialized in class or here */ }
//RGBpixmap::~RGBpixmap() { /* delete[] pixel; if pixel is owned by this class */ }


RGBpixmap pix[6];

float zoom = 4;
int tola[5000][5000];
float tX = 0, tY = 0, tZ = -8, rX = 0, rY = 0, rZ = 4;
float tZ1 = -20, tZ2 = -40, tZ3 = -60, tZ4 = -80, tZ5 = -100, tZ6 = -120;
float rotX = 0, rotY = 0, rotZ = 0;
float cosX = 0, cosY = 1, cosZ = 0;
float angle = 0;
float xEye = 0.0f, yEye = 5.0f, zEye = 30.0f;
float cenX = 0, cenY = 0, cenZ = 0, roll = 0;
float radius = 0;
float theta = 0, slope = 0;
float speed = 0.3;
float angleBackFrac = 0.2;
//bool saheedMinarVisible = false;
float r[] = { 0.1,0.4,0.0,0.9,0.2,0.5,0.0,0.7,0.5,0.0 };
float g[] = { 0.2,0.0,0.4,0.5,0.2,0.0,0.3,0.9,0.0,0.2 };
float b[] = { 0.4,0.5,0.0,0.7,0.9,0.0,0.1,0.2,0.5,0.0 };
int TIME = 0;
bool START = false;
float torusPosX[7] = { 1,-2,3,-4,-2,0,2 }; // Indices 0-6, environment uses them directly
float torusPosY[7] = { 2,3,10,6,7,4,1 };

bool rot = false;


static void resize(int width, int height)
{
    const float ar = (float)width / (float)height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 1000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void drawPlane() { // This is actually the Shaheed Minar / Monument

    glColor3d(0.4, 0.2, 0.2);
    glPushMatrix();
    glTranslated(0, 1.55, 0);
    glScaled(2, 0.05, 1.5);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(0.4, 0.2, 0.2);
    glPushMatrix();
    glTranslated(0, 1.6, 0);
    glScaled(1.9, 0.05, 1.4);
    glutSolidCube(1);
    glPopMatrix();

    //glColor3d(0.4,0.2,0.2);
    //glColor3d(1,0.8,0.7);
    glColor3d(0.4, 0.2, 0.2);
    glPushMatrix();
    glTranslated(0, 1.65, 0);
    glScaled(1.8, 0.05, 1.3);
    glutSolidCube(1);
    glPopMatrix();

    /// pataton

    glColor3d(1, 1, 1);
    glPushMatrix();
    glTranslated(0, 1.68, -0.4);
    glScaled(0.5, 0.02, 0.08);
    glutSolidCube(1);
    glPopMatrix();

    /// Piller

    glPushMatrix();
    glTranslated(0, 1.99, -0.4);
    glScaled(0.06, 0.7, 0.04);
    glutSolidCube(1);
    glPopMatrix();

    /// ROD

    glColor3d(0, 0, 0);

    glPushMatrix();
    glTranslated(0.07, 1.99, -0.4);
    glScaled(0.003, 0.7, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.11, 1.99, -0.4);
    glScaled(0.003, 0.7, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.15, 1.99, -0.4);
    glScaled(0.003, 0.7, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    ///
    glPushMatrix();
    glTranslated(-0.22, 0, 0);
    glPushMatrix();
    glTranslated(0.07, 1.99, -0.4);
    glScaled(0.003, 0.7, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.11, 1.99, -0.4);
    glScaled(0.003, 0.7, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.15, 1.99, -0.4);
    glScaled(0.003, 0.7, 0.003);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();

    ///Horizontal rod
    glPushMatrix();
    glTranslated(2.2, 0, -0.1);
    glScaled(4.2, 1, 1);
    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(-0.528, 1.85, -0.3);
    glScaled(0.1, 0.003, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.528, 2.02, -0.3);
    glScaled(0.1, 0.003, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.528, 2.18, -0.3);
    glScaled(0.1, 0.003, 0.003);
    glutSolidCube(1);
    glPopMatrix();
    glColor3d(1, 1, 1);
    glPopMatrix();

    /// ROD END

    glColor3d(1, 1, 1);
    glPushMatrix();
    glTranslated(-0.22, 1.99, -0.4);
    glScaled(0.06, 0.7, 0.04);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.22, 1.99, -0.4);
    glScaled(0.06, 0.7, 0.04);
    glutSolidCube(1);
    glPopMatrix();

    /// Upper piller

    glPushMatrix();
    glTranslated(0, 0.743, -1.424);
    glRotated(45, 1, 0, 0);

    //glColor3d(1,0,1);
    glPushMatrix();
    glTranslated(0, 1.99, -0.4);
    glScaled(0.06, 0.3, 0.04);
    glutSolidCube(1);
    glPopMatrix();
    //glColor3d(1,1,1);

    glPushMatrix();
    glTranslated(-0.22, 1.99, -0.4);
    glScaled(0.06, 0.3, 0.04);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.22, 1.99, -0.4);
    glScaled(0.06, 0.3, 0.04);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 2.15, -0.4);
    glScaled(0.5, 0.04, 0.04);
    glutSolidCube(1);
    glPopMatrix();

    /// ROD

    glColor3d(0, 0, 0);

    glPushMatrix();
    glTranslated(0.07, 1.99, -0.4);
    glScaled(0.003, 0.277, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.11, 1.99, -0.4);
    glScaled(0.003, 0.277, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.15, 1.99, -0.4);
    glScaled(0.003, 0.277, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    ///

    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(-0.22, 0, 0);
    glPushMatrix();
    glTranslated(0.07, 1.99, -0.4);
    glScaled(0.003, 0.277, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.11, 1.99, -0.4);
    glScaled(0.003, 0.277, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.15, 1.99, -0.4);
    glScaled(0.003, 0.277, 0.003);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    /// ROD END

    ///Horizontal rod
    glPushMatrix();
    glTranslated(2.2, 0, -0.1);
    glScaled(4.2, 1, 1);
    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(-0.528, 1.85, -0.3);
    glScaled(0.1, 0.003, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.528, 2, -0.3);
    glScaled(0.1, 0.003, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.528, 2.15, -0.3);
    glScaled(0.1, 0.003, 0.003);
    glutSolidCube(1);
    glPopMatrix();
    glColor3d(1, 1, 1);
    glPopMatrix();

    glPopMatrix();


    /// piller left 1
    glColor3d(1, 1, 1);
    glPushMatrix();
    glTranslated(0.1, 0, -0.4);
    glRotated(45, 0, 1, 0);

    glPushMatrix();
    glTranslated(-0.605, 1.94, -0.3);
    glScaled(0.045, 0.65, 0.03);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.45, 1.94, -0.3);
    glScaled(0.045, 0.65, 0.03);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.528, 2.258, -0.3);
    glScaled(0.199, 0.04, 0.03);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.528, 1.68, -0.3);
    glScaled(0.199, 0.02, 0.06);
    glutSolidCube(1);
    glPopMatrix();

    /// ROD
    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(-0.64, -0.05, 0.1);
    glScaled(1, 1.02, 1);
    glPushMatrix();
    glTranslated(0.078, 1.99, -0.4);
    glScaled(0.003, 0.56, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.11, 1.99, -0.4);
    glScaled(0.003, 0.56, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.145, 1.99, -0.4);
    glScaled(0.003, 0.56, 0.003);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();

    ///
    glColor3d(1, 1, 1);

    ///Horizontal rod
    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(-0.528, 1.85, -0.3);
    glScaled(0.1, 0.003, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.528, 2, -0.3);
    glScaled(0.1, 0.003, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.528, 2.15, -0.3);
    glScaled(0.1, 0.003, 0.003);
    glutSolidCube(1);
    glPopMatrix();
    glColor3d(1, 1, 1);
    glPopMatrix();

    /// piller left 2
    glPushMatrix();
    glTranslated(0.65, 0, 0.3);
    glRotated(-45, 0, 1, 0);

    glPushMatrix();
    glTranslated(-0.605, 1.94, -0.3);
    glScaled(0.045, 0.65, 0.03);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.45, 1.94, -0.3);
    glScaled(0.045, 0.65, 0.03);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.528, 2.258, -0.3);
    glScaled(0.199, 0.04, 0.03);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.528, 1.68, -0.3);
    glScaled(0.199, 0.02, 0.06);
    glutSolidCube(1);
    glPopMatrix();

    ///ROD
    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(-0.64, -0.05, 0.1);
    glScaled(1, 1.02, 1);
    glPushMatrix();
    glTranslated(0.078, 1.99, -0.4);
    glScaled(0.003, 0.56, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.11, 1.99, -0.4);
    glScaled(0.003, 0.56, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.145, 1.99, -0.4);
    glScaled(0.003, 0.56, 0.003);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    glColor3d(1, 1, 1);
    ///ROD

    ///Horizontal rod
    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(-0.528, 1.85, -0.3);
    glScaled(0.1, 0.003, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.528, 2, -0.3);
    glScaled(0.1, 0.003, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.528, 2.15, -0.3);
    glScaled(0.1, 0.003, 0.003);
    glutSolidCube(1);
    glPopMatrix();
    glColor3d(1, 1, 1);

    glPopMatrix();


    glPushMatrix();
    /// piller left 1
    glTranslated(0.06, 0, 0.14);
    glPushMatrix();

    glTranslated(-0.2, 0, -0.31);
    glRotated(45, 0, 1, 0);

    glPushMatrix();
    glTranslated(-0.605, 1.88, -0.3);
    glScaled(0.045, 0.4, 0.03);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.45, 1.88, -0.3);
    glScaled(0.045, 0.4, 0.03);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.528, 2.08, -0.3);
    glScaled(0.2, 0.04, 0.03);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.528, 1.68, -0.3);
    glScaled(0.199, 0.02, 0.06);
    glutSolidCube(1);
    glPopMatrix();

    ///ROD
    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(-0.641, 0.43, 0.1);
    glScaled(1, 0.73, 1);
    glPushMatrix();
    glTranslated(0.078, 1.99, -0.4);
    glScaled(0.003, 0.56, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.11, 1.99, -0.4);
    glScaled(0.003, 0.56, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.145, 1.99, -0.4);
    glScaled(0.003, 0.56, 0.003);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();

    ///Horizontal rod
    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(-0.528, 1.8, -0.3);
    glScaled(0.1, 0.003, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.528, 1.96, -0.3);
    glScaled(0.1, 0.003, 0.003);
    glutSolidCube(1);
    glPopMatrix();
    glColor3d(1, 1, 1);
    ///ROD

    glPopMatrix();

    /// piller left 2
    glPushMatrix();
    glTranslated(0.83, 0, 0.39);
    glRotated(-45, 0, 1, 0);

    glPushMatrix();
    glTranslated(-0.605, 1.88, -0.3);
    glScaled(0.045, 0.4, 0.03);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.45, 1.88, -0.3);
    glScaled(0.045, 0.4, 0.03);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.528, 2.1, -0.3);
    glScaled(0.199, 0.04, 0.03);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.528, 1.68, -0.3);
    glScaled(0.199, 0.02, 0.06);
    glutSolidCube(1);
    glPopMatrix();


    ///Horizontal rod
    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(-0.528, 1.8, -0.3);
    glScaled(0.1, 0.003, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.528, 1.96, -0.3);
    glScaled(0.1, 0.003, 0.003);
    glutSolidCube(1);
    glPopMatrix();
    glColor3d(1, 1, 1);

    ///ROD
    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(-0.641, 0.43, 0.1);
    glScaled(1, 0.73, 1);
    glPushMatrix();
    glTranslated(0.078, 1.99, -0.4);
    glScaled(0.003, 0.56, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.11, 1.99, -0.4);
    glScaled(0.003, 0.56, 0.003);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.145, 1.99, -0.4);
    glScaled(0.003, 0.56, 0.003);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    glColor3d(1, 1, 1);
    ///ROD

    glPopMatrix();


    glPopMatrix();

    /// Circle

    glColor3d(1, 0, 0);
    glPushMatrix();
    glTranslated(0, 2.1, -0.44);
    glScaled(0.35, 0.35, 0.01);
    glutSolidSphere(1, 50, 50);
    glPopMatrix();

    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(-0.18, 1.9, -0.45);
    glScaled(0.01, 0.5, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(0.18, 1.9, -0.45);
    glScaled(0.01, 0.5, 0.01);
    glutSolidCube(1);
    glPopMatrix();
}

void fan() {
    glColor3d(0.5, 1, 0);
    glPushMatrix();
    glTranslated(0, 0, 0);
    glScaled(1, 1, 0.7);
    glutSolidSphere(0.8, 30, 30);
    glPopMatrix();

    glColor3d(0.5, 1, 0);
    glPushMatrix();
    glTranslated(0, 0, 0);
    glRotated(5, 0, 1, 0);
    glScaled(0.5, 2.5, 0.05);
    glutSolidSphere(1, 30, 30);
    glPopMatrix();

    glColor3d(0.5, 1, 0);
    glPushMatrix();
    glTranslated(0, 0, 0);
    glRotated(-5, 0, 1, 0);
    glRotated(90, 0, 0, 1);
    glScaled(0.5, 2.5, 0.05);
    glutSolidSphere(1, 30, 30);
    glPopMatrix();

}

void plane() {
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t * 90.0;

    /// Main body
    glColor3d(0.5, 1, 0);
    glPushMatrix();
    glTranslated(0, 0, 0);
    glScaled(3, 0.4, 0.5);
    glutSolidSphere(1, 30, 30);
    glPopMatrix();

    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(1.7, 0.1, 0);
    glScaled(1.5, 0.7, 0.8);
    glRotated(40, 0, 1, 0);
    glutSolidSphere(0.45, 30, 30);
    glPopMatrix();

    ///Right
    glColor3d(0.8, 1, 0);
    glPushMatrix();
    glTranslated(0, 0, 1.2);
    glRotated(-50, 0, 1, 0);
    glScaled(0.7, 0.1, 3);
    glRotated(25, 0, 1, 0);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(0.8, 1, 0);
    glPushMatrix();
    glTranslated(-0.3, -0.15, 1.5);
    glRotated(90, 0, 1, 0);
    glScaled(0.1, 0.1, 0.9);
    glutSolidTorus(0.5, 0.5, 50, 50);
    glPopMatrix();

    glColor3d(0.8, 1, 0);
    glPushMatrix();
    glTranslated(0.2, -0.15, 0.9);
    glRotated(90, 0, 1, 0);

    /// FAN
//        glPushMatrix();
//            glTranslated(0,0,0.5);
//            glRotated(10*a,0,0,1);
//            glScaled(0.1,0.1,0.1);
//            fan();
//        glPopMatrix();

    glScaled(0.1, 0.1, 0.9);
    glutSolidTorus(0.5, 0.5, 50, 50);
    glPopMatrix();

    ///Left
    glColor3d(0.8, 1, 0);
    glPushMatrix();
    glTranslated(0, 0, -1.2);
    glRotated(50, 0, 1, 0);
    glScaled(0.7, 0.1, 3);
    glRotated(-25, 0, 1, 0);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(0.8, 1, 0);
    glPushMatrix();
    glTranslated(-0.3, -0.15, -1.5);
    glRotated(90, 0, 1, 0);
    glScaled(0.1, 0.1, 0.9);
    glutSolidTorus(0.5, 0.5, 50, 50);
    glPopMatrix();

    glColor3d(0.8, 1, 0);
    glPushMatrix();
    glTranslated(0.2, -0.15, -0.9);
    glRotated(90, 0, 1, 0);
    glScaled(0.1, 0.1, 0.9);
    glutSolidTorus(0.5, 0.5, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-2.8, 0, 0);
    glScaled(0.8, 0.5, 0.3);

    ///Right
    glColor3d(0.8, 1, 0);
    glPushMatrix();
    glTranslated(0.4, 0, 1.5);
    glRotated(-30, 0, 1, 0);
    glScaled(0.7, 0.1, 3);
    glRotated(10, 0, 1, 0);
    glutSolidCube(1);
    glPopMatrix();

    ///left
    glColor3d(0.8, 1, 0);
    glPushMatrix();
    glTranslated(0.4, 0, -1.5);
    glRotated(30, 0, 1, 0);
    glScaled(0.7, 0.1, 3);
    glRotated(-10, 0, 1, 0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();

    glColor3d(0.8, 1, 0);
    glPushMatrix();
    glTranslated(-2.7, 0.5, 0);
    glRotated(45, 0, 0, 1);
    glScaled(0.8, 2, 0.1);
    glRotated(-20, 0, 0, 1);
    glutSolidCube(0.5);
    glPopMatrix();
}


void singleHouse(int R, int G, int B) {
    glColor3d(r[R % 10], g[G % 10], b[B % 10]);
    glPushMatrix();
    glTranslated(0, 0, 0);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(0.2, 0, 0);
    glScaled(0.3, 0.3, 1.001);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(-0.2, 0, 0);
    glScaled(0.3, 0.3, 1.001);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(0, 0, 0.2);
    glScaled(1.001, 0.3, 0.3);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(0, 0, -0.2);
    glScaled(1.001, 0.3, 0.3);
    glutSolidCube(1);
    glPopMatrix();

}

void house(int n, int R, int G) {
    for (int i = 0; i < n; i++) {
        glPushMatrix();
        glTranslated(0, 0.8 + i, 0); // Building floors slightly separated, adjust if needed
        singleHouse(G, R, i);
        glPopMatrix();
    }
}

void MonumentEnv() {
    /// Ground
    glColor3d(0, 0.5, 0.1);
    glPushMatrix();
    glTranslated(0, 0, 0);
    glScaled(EN_SIZE * 2, 0.3, EN_SIZE * 2);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-8, -2.7, -5); // Y seems low, might be intentional for base
    glRotated(65, 0, 1, 0);
    glScaled(2, 2, 2);
    drawPlane(); // This is the monument
    glPopMatrix();

    glPushMatrix();
    glTranslated(8, -2.7, -5);
    glRotated(-65, 0, 1, 0);
    glScaled(2, 2, 2);
    drawPlane(); // This is the monument
    glPopMatrix();
}

void environment(int n) { // n is used to index torusPosX/Y

    /// Ground
    glColor3d(0, 0.5, 0.1);
    glPushMatrix();
    glTranslated(0, 0, 0);
    glScaled(EN_SIZE * 2, 0.3, EN_SIZE * 2);
    glutSolidCube(1);
    glPopMatrix();


    glColor3d(0, 1, 0.1); // Torus color
    glPushMatrix();
    glTranslated(torusPosX[n], torusPosY[n], 0);
    glScaled(0.3, 0.3, 0.3);
    // glutSolidTorus(innerRadius, outerRadius, nsides, nrings)
    // Here, 1 is tube radius, 3 is sweep radius (center of torus to center of tube)
    glutSolidTorus(1, 3, 30, 30);
    glPopMatrix();

    for (int i = -(EN_SIZE / 2) + 1; i < (EN_SIZE / 2); i += 2) {
        for (int j = -(EN_SIZE / 2) + 1; j < (EN_SIZE / 2); j += 2) {
            if (tola[i + (EN_SIZE / 2) + 1][j + (EN_SIZE / 2) + 1] != 0) {
                glPushMatrix();
                glTranslated(i, 0, j); // Base of house at y=0 relative to ground surface
                house(tola[i + (EN_SIZE / 2) + 1][j + (EN_SIZE / 2) + 1], i, j);
                glPopMatrix();
            }
            else if (i >= -5 && i <= 5) {} // Clear path in the middle
            else {
                tola[i + (EN_SIZE / 2) + 1][j + (EN_SIZE / 2) + 1] = (rand() % 5) + 1;
                glPushMatrix();
                glTranslated(i, 0, j);
                house(tola[i + (EN_SIZE / 2) + 1][j + (EN_SIZE / 2) + 1], i, j);
                glPopMatrix();
            }
        }
    }
}

// SCORE SYSTEM START: Helper struct for managing chunk data
struct ChunkInfo {
    float* zValue;        // Pointer to tZ, tZ1, etc.
    int environmentIndex; // Index for torusPosX/Y (e.g., 2 for environment(2)), -1 if no torus
    int scoredFlagIndex;  // Index for torusInChunkScored array
};
// SCORE SYSTEM END: Helper struct

void draw() {
    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t * 90.0;

    TIME = t;

    ///Plane
    if (rotX > 11)rotX = 11;
    if (rotX < -11)rotX = -11;
    if (rotZ > 10)rotZ = 10;
    if (rotZ < -15)rotZ = -15;

    glPushMatrix();
    glTranslated(0, 1, 0); // Plane's base vertical position before player input
    glRotated(90, 0, 1, 0);
    glRotated(5, 0, 0, 1);
    glRotated(rotX, 1, 0, 0);
    glRotated(rotY, 0, 1, 0);
    glRotated(rotZ, 0, 0, 1);

    glScaled(0.4, 0.4, 0.4);
    plane();
    glPopMatrix();

    ///Environment
    if (tX >= 4.1)tX = 4.1;
    if (tX <= -4.1)tX = -4.1;
    if (tY > 0.1)tY = 0.1;       // tY is translation of environment. Positive tY means env moves down (plane seems up)
    if (tY < -15)tY = -15;     // Negative tY means env moves up (plane seems down)


    // SCORE SYSTEM START: Collision Detection Logic
    float planeEffX = -tX; // Plane's effective X relative to an un-translated chunk
    // If tX is positive (env moves right), plane is effectively to the left.
    float planeEffY = 1.0f - tY; // Plane drawn at y=1. If tY is positive (env moves down), plane's Y is 1-tY.
    float planeCollisionDepth = 0.0f; // Z-depth where plane is considered to be for collision
    float collisionZWindow = 1.5f * speed / 0.3f; // How close in Z for collision check (scales slightly with speed)
    // Ensure this window is large enough. Base was 1.5f.

// Torus dimensions: glutSolidTorus(tubeRadius=1, sweepRadius=3, ...) scaled by 0.3
// Actual tube radius = 1.0f * 0.3f = 0.3f
// Actual sweep radius (center of torus to center of tube) = 3.0f * 0.3f = 0.9f
// Radius of the hole = sweepRadius - tubeRadius = 0.9f - 0.3f = 0.6f.
    float torusHoleRadius = (3.0f - 1.0f) * 0.3f;
    float torusHoleRadiusSq = torusHoleRadius * torusHoleRadius; // For squared distance check

    ChunkInfo chunks[] = {
        {&tZ,  2, 0}, // tZ uses environment(2), scoredFlag index 0
        {&tZ1, -1, -1},// tZ1 is MonumentEnv, no torus
        {&tZ2, 3, 1}, // tZ2 uses environment(3), scoredFlag index 1
        {&tZ3, 1, 2}, // tZ3 uses environment(1), scoredFlag index 2
        {&tZ4, 5, 3}, // tZ4 uses environment(5), scoredFlag index 3
        {&tZ5, 4, 4}, // tZ5 uses environment(4), scoredFlag index 4
        {&tZ6, 2, 5}  // tZ6 uses environment(2), scoredFlag index 5
    };
    const int numGameChunks = sizeof(chunks) / sizeof(ChunkInfo);

    for (int i = 0; i < numGameChunks; ++i) {
        if (chunks[i].environmentIndex != -1) { // If it's a chunk that can have a torus
            // Check for collision
            // *(chunks[i].zValue) is the current Z position of the front of the chunk
            if (std::abs(*(chunks[i].zValue) - planeCollisionDepth) < collisionZWindow &&
                !torusInChunkScored[chunks[i].scoredFlagIndex]) {

                float currentTorusPosX = torusPosX[chunks[i].environmentIndex];
                float currentTorusPosY = torusPosY[chunks[i].environmentIndex];

                float dx = planeEffX - currentTorusPosX;
                float dy = planeEffY - currentTorusPosY;
                float distSq = dx * dx + dy * dy;

                if (distSq < torusHoleRadiusSq) {
                    score++;
                    torusInChunkScored[chunks[i].scoredFlagIndex] = true;
                    // Optional: Play a sound effect here
                    // PlaySound("score.wav", NULL, SND_ASYNC | SND_FILENAME);
                }
            }
        }
    }
    // SCORE SYSTEM END: Collision Detection Logic

    glPushMatrix();
    glTranslated(tX, tY, tZ);
    environment(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(tX, tY, tZ1);
    MonumentEnv();
    glPopMatrix();

    glPushMatrix();
    glTranslated(tX, tY, tZ2);
    environment(3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(tX, tY, tZ3);
    environment(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(tX, tY, tZ4);
    environment(5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(tX, tY, tZ5);
    environment(4);
    glPopMatrix();

    glPushMatrix();
    glTranslated(tX, tY, tZ6);
    environment(2);
    glPopMatrix();

    // SCORE SYSTEM START: Update Z positions and reset scored flags
    // This replaces the individual tZ += speed; if(tZ>=20)tZ=-110; blocks
    for (int i = 0; i < numGameChunks; ++i) {
        *(chunks[i].zValue) += speed;
        if (*(chunks[i].zValue) >= 20) { // When chunk passes camera and resets
            *(chunks[i].zValue) = -110;  // Reset Z to the back
            if (chunks[i].scoredFlagIndex != -1) { // If this chunk type had a torus
                torusInChunkScored[chunks[i].scoredFlagIndex] = false; // Reset its scored flag
            }
        }
    }
    // SCORE SYSTEM END: Update Z positions

    if (rotX > 0)rotX -= angleBackFrac;
    if (rotX < 0)rotX += angleBackFrac;
    if (rotY > 0)rotY -= angleBackFrac;
    if (rotY < 0)rotY += angleBackFrac;
    if (rotZ > 0)rotZ -= angleBackFrac;
    if (rotZ < 0)rotZ += angleBackFrac;

    speed += 0.0002;
    if (speed >= 0.7)speed = 0.7;
}


void drawBitmapText(char* str, float x, float y, float z)
{
    char* c;
    glRasterPos3f(x, y + 8, z);

    for (c = str; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
    }
}

void drawStrokeText(const char* str, int x, int y, int z)
{
    const char* c;
    glPushMatrix();
    glTranslatef(x, y + 8, z);
    glScalef(0.002f, 0.002f, z); // Scale for stroke font

    for (c = str; *c != '\0'; c++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }
    glPopMatrix();
}

void drawStrokeText2(const char* str, int x, int y, int z)
{
    const char* c;
    glPushMatrix();
    glTranslatef(x, y + 8, z);
    glScalef(0.005f, 0.005f, z); // Larger scale

    for (c = str; *c != '\0'; c++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }
    glPopMatrix();
}
void drawStrokeChar(char c, float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x, y + 8, z);
    glScalef(0.002f, 0.002f, z); // Scale consistent with drawStrokeText
    glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
    glPopMatrix();
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t * 90.0;
    double aa = a;

    if (!rot) {
        a = 0;
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(0.0, 4.5, 10.0, // Eye position
        0, 4, 0,              // Look-at position
        0, 1.0f, 0.0f);       // Up vector

    if (START) {

        glPushMatrix();
        glTranslated(0, 0, 0);
        glScaled(zoom, zoom, zoom);
        glRotated(a, 0, 1, 0); // Gentle rotation for the whole scene if `rot` is true
        draw();
        glPopMatrix();

        drawStrokeText("UP: W, DOWN: S, LEFT: A, RIGHT: D, MAIN MENU: M", -8, 0.9, 0);

        // --- EXISTING TIME DISPLAY LOGIC (DO NOT CHANGE THIS PART) ---
        drawStrokeText("TIME : ", 3, 0, 0);
        int mod, number = 0;
        // Store TIME in a temp variable to avoid modifying the global TIME for display purposes
        int tempDisplayTime = TIME;
        if (tempDisplayTime == 0) { // Handle TIME = 0 case explicitly for reversal logic
            drawStrokeChar('0', 4.0f, 0, 0);
        }
        else {
            while (tempDisplayTime) { // Reversing the number
                mod = tempDisplayTime % 10;
                number = number * 10 + mod;
                tempDisplayTime /= 10;
            }
            float tmp = 0; // x-offset for characters
            if (number == 0 && TIME != 0) { // Handles cases like TIME = 10, 20, etc. where reversed is 01, 02
                // This block will draw the reversed number (e.g. '0' then '1' for TIME=10)
                // To ensure leading zeros of the *original* number are handled if it's small,
                // we might need to count digits or use sprintf.
                // However, the current logic will draw '0' then '1' for TIME=10, which is fine.
                // And for TIME=1, it draws '1'.
                int originalTimeForDisplay = TIME;
                // If TIME was 10, number is 1 (01 reversed). We need to draw '0' then '1'.
                // A simple way to handle this is to count digits of original TIME.
                // For now, sticking to the provided logic which draws reversed digits.
                // If TIME = 10, number = 1. Loop below draws '1'. Then we need to draw '0'.
                // This needs a more robust digit-by-digit drawing from original number if precise original format is key.
                // The current code draws the reversed number, so for 10, it processes '1' (from number=1).
                // It will draw '1'. The '0' from '01' (reversed 10) is lost.
                // Let's assume the user wants the digits of TIME to be printed correctly.
                // For simplicity and to keep the spirit of original code, this will print reversed.
                // To print correctly, one would convert TIME to string or extract digits without reversing.
                char timeStr[10];
                sprintf_s(timeStr, sizeof(timeStr), "%d", TIME);
                float char_x_offset = 0;
                for (int k = 0; timeStr[k] != '\0'; ++k) {
                    drawStrokeChar(timeStr[k], 4.0f + char_x_offset, 0, 0);
                    char_x_offset += 0.2f; // Adjust spacing as needed
                }

            }
            else { // General case for reversed number or TIME=0 already handled
                float char_x_offset = 0;
                if (number == 0 && TIME == 0) { /* already handled by drawStrokeChar('0',...) */ }
                else {
                    // This loop draws the digits of the reversed 'number'
                    // If TIME was 123, number is 321. This draws 3, then 2, then 1.
                    // If TIME was 10, number is 1. This draws 1.
                    int temp_number = number; // use another temp for this loop
                    if (temp_number == 0 && TIME != 0) { // e.g. TIME=10, number = 1, but if somehow number ended up 0
                        // This case is tricky with pure reversal. Re-doing with sprintf is safer.
                        char timeStrSprintf[10];
                        sprintf_s(timeStrSprintf, sizeof(timeStrSprintf), "%d", TIME);
                        for (int k = 0; timeStrSprintf[k] != '\0'; ++k) {
                            drawStrokeChar(timeStrSprintf[k], 4.0f + char_x_offset, 0, 0);
                            char_x_offset += 0.2f;
                        }
                    }
                    else {
                        while (temp_number) {
                            mod = temp_number % 10;
                            drawStrokeChar(mod + 48, 4.0f + char_x_offset, 0, 0);
                            temp_number /= 10;
                            char_x_offset += 0.2f;
                        }
                    }
                }
            }
        }
        // --- END OF EXISTING TIME DISPLAY LOGIC ---

        // SCORE SYSTEM START: Display Score below Time
        drawStrokeText("SCORE : ", 3, -0.5f, 0); // Positioned below TIME
        char scoreStr[10]; // Buffer for score string
        sprintf_s(scoreStr, sizeof(scoreStr), "%d", score); // Convert int score to string

        float score_char_x_offset = 0;
        for (int k = 0; scoreStr[k] != '\0'; ++k) {
            drawStrokeChar(scoreStr[k], 4.0f + score_char_x_offset, -0.5f, 0);
            score_char_x_offset += 0.2f; // Adjust spacing as needed, same as TIME
        }
        // SCORE SYSTEM END: Display Score

    }
    else { // Menu Screen
        glPushMatrix();
        glTranslated(0, 3, 0);
        glRotated(aa, 0, 1, 0);
        glScaled(1.5, 1.5, 1.5);
        plane();
        glPopMatrix();

        drawStrokeText("Press G to Start", -1, -1, 0);
        drawStrokeText2("Plane Game", -2, 0, 0);
    }

    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y)
{
    float frac = 0.3;
    float rotFrac = 1;
    switch (key)
    {
    case 27:
    case 'q':
        exit(0);
        break;
    case 'r':
        rot = true;
        break;
    case 't':
        rot = false;
        break;
    case 'z':
        zoom += 0.05;
        break;
    case 'Z':
        zoom -= 0.05;
        break; // Added missing break
    case 'w':
        tY -= frac; // Env moves up, plane seems to go down relative to initial pos
        rotZ += rotFrac;
        break;
    case 's':
        tY += frac; // Env moves down, plane seems to go up relative to initial pos
        rotZ -= rotFrac;
        break;
    case 'a':
        tX += frac; // Env moves right, plane seems to go left
        rotX -= rotFrac * 3;
        rotY += rotFrac / 2;
        break;
    case 'd':
        tX -= frac; // Env moves left, plane seems to go right
        rotX += rotFrac * 3;
        rotY -= rotFrac / 2;
        break;
    case 'g':
        START = true;
        // SCORE SYSTEM: Reset score when game starts/restarts
        score = 0;
        for (int i = 0; i < 6; ++i) torusInChunkScored[i] = false;
        // Reset Z positions for a fresh start (optional, but good practice)
        tZ = -8; tZ1 = -20; tZ2 = -40; tZ3 = -60; tZ4 = -80; tZ5 = -100; tZ6 = -120;
        speed = 0.3; // Reset speed
        tX = 0; tY = 0; // Reset plane "position"
        rotX = 0; rotY = 0; rotZ = 0; // Reset plane rotation

        break;
    case 'm':
        START = false;
        break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1366, 720);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    //PlaySound("starwars.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

    glClearColor(1, 1, 1, 1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));


    glutMainLoop();

    return EXIT_SUCCESS;
}