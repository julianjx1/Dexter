#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include<vector>
#define PI 3.1416
using namespace std;
static float	pa[5];
static float	pb[5];
static float	dx	=  -15.0;
static float	dy	=  -15.0;
static float  moveEnemyX[5];
static float  moveEnemyY[5];
static int countPower = 0;
static bool specialPower = false;
static float extraPower = 35.0f;
static float extraPowerUp = 35.0f;

/* GLUT callback Handlers */

void circle(float radius_x, float radius_y,int circleSize)
{
	int i = 0;
	float angle = 30.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < circleSize; i++)
		{

			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

	glEnd();
}
void  circleMaker(float ra,float ta, float tb, float ca, float cb, float cc, float cra, float crb ,float angle)
{
    glPushMatrix();
    glRotatef(ra,0.0f,0.0f,1.0f);
    glTranslatef(ta,tb,0.0f);
   glColor3f(ca,cb,cc);
    circle(cra, crb, angle);
    glPopMatrix();
}

void eye()
{

    circleMaker(180.0f, -4.5f, -4.5f, 0.0f, 0.0f, 0.0f, 3.0f, 4.0f, 50.0f);     //Outer Right Black eye
    circleMaker(180.0f, 0.5f, -4.5f, 0.0f, 0.0f, 0.0f, 3.0f, 4.0f, 50.0f);    //Outer Left Black eye
    circleMaker(180.0f, 0.6f, -4.0f, 0.484f, 0.781f, 0.914f, 2.5f, 3.0f, 50.0f);   //Inner Right Light Sky eye
    circleMaker(180.0f, -4.6f, -4.0f, 0.484f, 0.781f, 0.914f, 2.5f, 3.0f, 50.0f);  //Inner Left Light Sky eye
    circleMaker(180.0f, 0.5f, -4.5f, 0.0f, 0.0f, 0.0f, 1.5f, 1.5f, 50.0f);       //Inner Right Black eye
    circleMaker(180.0f, -4.5f, -4.5f, 0.0f, 0.0f, 0.0f, 1.5f, 1.5f, 50.0f);      //Inner Left Black eye

}

void quadMaker(float ta, float tb, float ca, float cb, float cc, float ba, float bb )
{
     glPushMatrix();
        glTranslatef(ta,tb,0.0f);
        glBegin(GL_QUADS);
             glColor3f(ca,cb,cc);
            glVertex2f(ba, bb);
            glVertex2f(ba, -bb);
            glVertex2f(-ba, -bb);
            glVertex2f(-ba, bb);
        glEnd();
    glPopMatrix();
}
void dexter()
{
    //shirt
     quadMaker(0.0f, -4.0f, 0.0f, 0.0f, 0.0f, 4.5f, 3.5f);  //black
    quadMaker(0.0f, -4.0f, 1.0f, 1.0f, 1.0f, 4.0f, 3.0f);   //white
    quadMaker(2.5f, -4.0f, 0.0f, 0.0f, 0.0f, 0.1f, 3.0f);   //line
    circleMaker(0.0f, 2.0f, -5.0f, 0.0f, 0.0f, 0.0f, 0.25f, 0.8f, 100.0f);  //circle


    //circleMaker(-16.0f, 5.0f, 0.0f, 0.992f, 0.886f, 0.852f, -5.0f, -4.0f, 30.0f);
//hand

    //left arm
    glPushMatrix();
        glTranslatef(-4.5f,-1.0f,0.0f);
        glBegin(GL_POLYGON);
           //glColor3f(0.52f,0.12f,0.484f);
            glColor3f(0.0f, 0.0f, 0.0f);

            glVertex2f(0.0f, -0.5f);
             glVertex2f(0.2f, -0.5f);
             glVertex2f(-.3f, -3.0f);
             glVertex2f(-.5f, -3.0f);



        glEnd();
    glPopMatrix();
//right arm
    glPushMatrix();
        glTranslatef(4.5f,-1.0f,0.0f);
        glBegin(GL_POLYGON);
           //glColor3f(0.52f,0.12f,0.484f);
            glColor3f(0.0f, 0.0f, 0.0f);

             glVertex2f(0.0f, -0.5f);
             glVertex2f(-0.2f, -0.5f);
             glVertex2f(.3f, -3.0f);
             glVertex2f(.5f, -3.0f);



        glEnd();
    glPopMatrix();
//left black fingure
     glPushMatrix();
        glTranslatef(-4.5f,-4.0f,0.0f);
        glBegin(GL_POLYGON);
           glColor3f(0.0f,0.0f,0.0f);
           // glColor3f(1.0f, 0.0f, 0.0f);

            glVertex2f(0.0f, 0.0f);
            glVertex2f(-2.0f, 0.0f);
            glVertex2f(0.0f, -.4f);
            glVertex2f(-2.3f, -.5f);
            glVertex2f(0.0f, -.6f);
            glVertex2f(-2.3f, -1.5f);
            glVertex2f(0.0f, -1.0f);
            glVertex2f(-2.0f, -2.5f);
            glVertex2f(0.0f, -1.5f);


        glEnd();
    glPopMatrix();
//left voilet fingure

     glPushMatrix();
        glTranslatef(-4.5f,-4.0f,0.0f);
        glBegin(GL_POLYGON);
           glColor3f(0.52f,0.12f,0.484f);
           // glColor3f(1.0f, 0.0f, 0.0f);

            glVertex2f(0.0f, -0.2f);
             glVertex2f(-1.5f, -0.05f);

            glVertex2f(0.0f, -.4f);
            glVertex2f(-1.7f, -.45f);
            glVertex2f(0.0f, -.6f);
            glVertex2f(-2.0f, -1.3f);
            glVertex2f(0.0f, -1.0f);
            glVertex2f(-1.5f, -2.1f);
            glVertex2f(0.0f, -1.3f);


        glEnd();
    glPopMatrix();

//right black fingure

     glPushMatrix();
        glTranslatef(4.5f,-4.0f,0.0f);
        glBegin(GL_POLYGON);
           glColor3f(0.0f,0.0f,0.0f);
           // glColor3f(1.0f, 0.0f, 0.0f);

            glVertex2f(0.0f, 0.0f);
            glVertex2f(2.0f, 0.0f);
            glVertex2f(0.0f, -.4f);
            glVertex2f(2.3f, -.5f);
            glVertex2f(0.0f, -.6f);
            glVertex2f(2.3f, -1.5f);
            glVertex2f(0.0f, -1.0f);
            glVertex2f(2.0f, -2.5f);
            glVertex2f(0.0f, -1.5f);


        glEnd();
    glPopMatrix();

//right voilet fingure
     glPushMatrix();
        glTranslatef(4.5f,-4.0f,0.0f);
        glBegin(GL_POLYGON);
           glColor3f(0.52f,0.12f,0.484f);
           // glColor3f(1.0f, 0.0f, 0.0f);

            glVertex2f(0.0f, -0.2f);
             glVertex2f(1.5f, -0.05f);

            glVertex2f(0.0f, -.4f);
            glVertex2f(1.7f, -.45f);
            glVertex2f(0.0f, -.6f);
            glVertex2f(2.0f, -1.3f);
            glVertex2f(0.0f, -1.0f);
            glVertex2f(1.5f, -2.1f);
            glVertex2f(0.0f, -1.3f);


        glEnd();
    glPopMatrix();



    //face
    quadMaker(0.5f, 4.0f, 0.992f, 0.886f, 0.852f, 5.0f, 3.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-4.85f,0.0f);
    glVertex2f(-4.85f,1.0f);
    glVertex2f(5.5f,1.5f);
    glVertex2f(0.5f,-3.9f);
    glEnd();

    circleMaker(15.0f, .6f, 0.0f, 0.992f, 0.886f, 0.852f, 5.0f, -4.0f, 30.0f);
    //head
    circleMaker(0.0f, 1.0f, 8.0f, 0.0f, 0.0f, 0.0f, -6.0f, 3.0f, 100);
    circleMaker(0.0f, 1.0f, 8.0f, 0.91f, 0.453f, 0.0898f, -5.5f, 2.5f, 100);

    //eye
    eye();

    //sunglass handle
    glBegin(GL_POLYGON);

    glVertex2f(-3.0f,3.0f);
    glVertex2f(-3.0f,4.0f);
    glVertex2f(-5.5f,1.0f);
    glVertex2f(-5.5f,1.5f);
    glEnd();


//ear
  //  circleMaker(0.0f, 5.0f, 1.0f, 0.992f, 0.886f, 0.852f, .5f, 1.0f, 100);
    circleMaker(0.0f, -4.8f, 1.0f, 0.992f, 0.886f, 0.852f, .5f, 1.0f, 100);



//nose

//outer black
       glPushMatrix();
        glTranslatef(0.5f,0.0f,0.0f);
        glBegin(GL_POLYGON);

            //glColor3f(1.0f, 1.0f, 1.0f);
            glColor3f(0.0f, 0.0f, 0.0f);

            glVertex2f(1.0f, -.2f);
            glVertex2f(0.9f, -1.0f);
            glVertex2f(0.1f, -0.1f);
            glVertex2f(0.1f, 0.6f);
            glVertex2f(1.8f, 1.3f);

        glEnd();
    glPopMatrix();

//inner skin color
    glPushMatrix();
        glTranslatef(0.5f,0.0f,0.0f);
        glBegin(GL_POLYGON);
           glColor3f(0.992f,0.886f,0.852f);
           // glColor3f(1.0f, 0.0f, 0.0f);

            glVertex2f(0.8f, 0.0f);
            glVertex2f(0.8f, -0.8f);
            glVertex2f(0.0f, 0.0f);
            glVertex2f(0.2f, 0.5f);
            glVertex2f(1.5f, 1.0f);

        glEnd();
    glPopMatrix();

//leg
     glPushMatrix();
        glTranslatef(0.0f,-7.0f,0.0f);
        glBegin(GL_POLYGON);
           glColor3f(0.0f,0.0f,0.0f);
           // glColor3f(1.0f, 0.0f, 0.0f);

            glVertex2f(-3.0f, 0.0f);
            glVertex2f(-5.0f, -5.0f);
            glVertex2f(-1.0f, -3.0f);
            glVertex2f(-2.2f, -5.0f);
            glVertex2f(0.0f, -4.0f);
            glVertex2f(0.0f, 0.0f);

             glVertex2f(3.0f, 0.0f);
            glVertex2f(5.0f, -5.0f);
            glVertex2f(2.0f, -3.0f);
            glVertex2f(2.2f, -5.0f);
            glVertex2f(0.0f, -4.0f);
            glVertex2f(0.0f, 0.0f);

        glEnd();
    glPopMatrix();


}
void enemy(){

   //hand
   //left side sholder
    glPushMatrix();
    glTranslatef(-3.8f, -3.0f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(0.691f, 0.546f, 0.05f);
            glVertex2f(2.0f,-1.0f);
            glVertex2f(0.0f,-1.0f);
            glVertex2f(0.0f,-0.0f);
            glVertex2f(2.0f,-0.0f);
        glEnd();
    glPopMatrix();
  //left hand
      glPushMatrix();
    glTranslatef(-3.8f, -9.0f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(0.691f, 0.546f, 0.05f);
            glVertex2f(0.0f, 5.0f);
            glVertex2f(0.0f, -4.0f);
            glVertex2f(0.3f, -3.0f);
            glVertex2f(0.5f, -4.0f);
            glVertex2f(0.8f, -3.0f);
            glVertex2f(1.1f, -4.0f);
            glVertex2f(1.4f, -3.0f);
            glVertex2f(1.7f, -4.0f);
            glVertex2f(1.7f, 5.0f);
        glEnd();
    glPopMatrix();
//right sholder
     glPushMatrix();
    glTranslatef(2.8f, -3.0f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(0.691f, 0.546f, 0.05f);
            glVertex2f(2.0f,-1.0f);
            glVertex2f(0.0f,-1.0f);
            glVertex2f(0.0f,-0.0f);
            glVertex2f(2.0f,-0.0f);
        glEnd();
    glPopMatrix();
//right hand
     glPushMatrix();
    glTranslatef(3.1f, -9.0f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(0.691f, 0.546f, 0.05f);
            glVertex2f(0.0f, 5.0f);
            glVertex2f(0.0f, -4.0f);
            glVertex2f(0.3f, -3.0f);
            glVertex2f(0.5f, -4.0f);
            glVertex2f(0.8f, -3.0f);
            glVertex2f(1.1f, -4.0f);
            glVertex2f(1.4f, -3.0f);
            glVertex2f(1.7f, -4.0f);
            glVertex2f(1.7f, 5.0f);
        glEnd();
    glPopMatrix();
 //neck
    quadMaker(0.5f, -3.0f, 0.0f, 0.0f, 0.0f, 0.3f, 0.3f);
    quadMaker(0.5f, -3.0f, 0.691f, 0.546f, 0.05f, 0.2f, 0.2f);
//face
    glPushMatrix();
        glBegin(GL_POLYGON);
            glColor3f(0.691f, 0.546f, 0.05f);

            glVertex2f(2.8f, -1.5f);
            glVertex2f(2.8f, -0.5f);
            glVertex2f(2.8f, -0.5f);
            glVertex2f(-1.8f, 0.0f);
            glVertex2f(0.0f, -2.8f);


        glEnd();
    glPopMatrix();
    quadMaker(0.5f, 1.0f, 0.691f, 0.546f, 0.05f, 2.3f, 1.5f);
    circleMaker(180.0f, 0.0f, 0.0f, 0.691f, 0.546f, 0.05f, 1.8f, 2.8f, 30.0f);
    circleMaker(-100.0f, 1.0f, 0.2f, 0.691f, 0.546f, 0.05f, 1.8f, 2.8f, 30.0f);
//head
    glPushMatrix();
    glTranslatef(-1.8f, 2.5f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(0.691f, 0.546f, 0.05f);

            glVertex2f(0.0f, 0.0f);
            glVertex2f(0.5f, 1.0f);
            glVertex2f(1.0f, 0.0f);
            glVertex2f(1.5f, 1.0f);
            glVertex2f(2.0f, 0.0f);
            glVertex2f(2.5f, 1.0f);
            glVertex2f(3.0f, 0.0f);
            glVertex2f(3.5f, 1.0f);
            glVertex2f(4.0f, 0.0f);
            glVertex2f(4.5f, 1.0f);
            glVertex2f(4.6f, 0.0f);
        glEnd();
    glPopMatrix();

//eye
     circleMaker(0.0f, -0.8f, 1.0f, 1.0f, 1.0f, 1.0f, 0.3f, 0.2f, 100.0f);
     circleMaker(0.0f, 0.8f, 1.0f, 1.0f, 1.0f, 1.0f, 0.3f, 0.2f, 100.0f);
     circleMaker(0.0f,-0.8f, 1.0f, 0.0f, 0.0f, 0.0f, 0.1f, 0.1f, 100.0f);
     circleMaker(0.0f, 0.8f, 1.0f, 0.0f, 0.0f, 0.0f, 0.1f, 0.1f, 100.0f);
//mouth
     circleMaker(180.0f, -.2f, 1.0f, 0.0f, 0.0f, 0.0f, 1.5f, 1.5f, 50.0f);
     circleMaker(0.0f, .2f, -2.1f, 1.0f, 0.31f, 0.31f, 1.0f, 0.2f, 100.0f);

 //body
    glPushMatrix();
    glTranslatef(-2.0f, -3.0f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(0.0f, 0.4f, 1.0f);

            glVertex2f(0.0f, 0.0f);
            glVertex2f(5.0f, 0.0f);
            glVertex2f(5.0f, -10.0f);
            glVertex2f(0.0f, -10.0f);

        glEnd();
    glPopMatrix();
//leg
//left leg
    glPushMatrix();
    glTranslatef(-2.0f, -13.0f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(1.0f, 0.2f, 0.0f);
            glVertex2f(0.0f, -8.0f);
            glVertex2f(0.0f, 0.0f);
            glVertex2f(3.0f, 0.0f);
            glVertex2f(1.0f, -10.0f);
            glVertex2f(-2.0f, -10.0f);
            glVertex2f(-1.0f, -8.0f);
        glEnd();
    glPopMatrix();
// right leg
    glPushMatrix();
    glTranslatef(2.0f, -13.0f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(1.0f, 0.2f, 0.0f);
            glVertex2f(0.0f, -8.0f);
            glVertex2f(-3.0f, 0.0f);
            glVertex2f(1.0f, 0.0f);
            glVertex2f(1.0f, -10.0f);
            glVertex2f(-2.0f, -10.0f);
            glVertex2f(-1.0f, -8.0f);
        glEnd();
    glPopMatrix();
}
void building(float ca, float cb, float cc)
{
    //full building
    quadMaker(0.0f, 0.0f, ca, cb, cc, 2.0, 6.0f);
    //window
    quadMaker(1.0f, 5.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(-1.0f, 5.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(-1.0f, 3.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(1.0f, 3.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(-1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(-1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(1.0f, -3.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(-1.0f, -3.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(1.0f, -5.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(-1.0f, -5.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
}
void buildingBuild(float angle, float ra, float rb, float ta, float tb, float sa, float sb)
{
    float ca1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float cb1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float cc1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    glPushMatrix();

    glTranslatef(ta, tb, 0.0f);
    glRotatef(angle, ra, rb, 0.0f);
    glScalef(sa, sb, 0.0f);
    building(ca1, cb1, cc1);
    glPopMatrix();
}

void viewBuilding()
{
    buildingBuild(0.0f, 0.0f, 0.0f, -18.0f, 10.0f, 1.0f, 1.0f);
    buildingBuild(0.0f, 0.0f, 0.0f, -13.8f, 13.0f, 0.8f, 1.5f);
    buildingBuild(40.0f, 0.0f, 1.0f, -10.0f, 10.0f, 1.0f, 1.0f);
    buildingBuild(40.0f, 1.0f, 0.0f, -6.0f, 8.55f, 1.0f, 1.0f);
    buildingBuild(0.0f, 0.0f, 0.0f, -1.5f, 11.2f, 1.0f, 1.2f);
    buildingBuild(0.0f, 0.0f, 0.0f, 3.0f, 10.0f, 1.0f, 1.0f);
    buildingBuild(40.0f, 1.0f, 0.0f, 7.5f, 8.55f, 1.0f, 1.0f);
    buildingBuild(40.0f, 0.0f, 1.0f, 11.5f, 10.0f, 1.0f, 1.0f);
    buildingBuild(40.0f, 0.0f, 1.0f, 15.0f, 10.0f, 1.0f, 1.0f);
    buildingBuild(0.0f, 0.0f, 0.0f, 18.5f, 11.8f, 0.7f, 1.3f);
}

void road(){
    //gray color road
    quadMaker(0.0f, 1.5f, 0.41f, 0.41f, 0.41f, 20.0f, 5.0f);
    //white strap
    quadMaker(-19.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(-16.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(-13.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(-10.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(-7.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(-4.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(-1.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(2.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(5.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(8.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(11.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(14.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(17.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(20.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
}
void superPower()
{
    for(int i = 0; i < 5; i++)
    {
        pa[i] = 25.0f;
        pb[i] = 0.0f;
        moveEnemyX[i] = 25.0f;
        moveEnemyY[i] =  ((float)rand() / RAND_MAX) * 25 -10;
        cout << moveEnemyY[i] << endl;
    }
    extraPower = 35.0f;
    extraPowerUp = 35.0f;
    specialPower = false;
    glutPostRedisplay();
}
static void display(void)
{

    for(int i = 0; i < 5; i++)
    {
        if(pa[i] <=25.0f && pa[i] >= -20.0f)
    {
        for(int j = 0; j < 5; j++)
        {
            if(pa[i] >= moveEnemyX[j] && pb[i] <= moveEnemyY[j] && pb[i] >= (moveEnemyY[j]-7))
            {
                cout <<"yes" <<  endl;
                moveEnemyX[j] = 22.0f;
                pa[i] = 25.0f;
                countPower++;
                break;
            }
        }
        glutPostRedisplay();
        pa[i]+=0.01f;

      //  cout << pa << "" << moveEnemyX <<  endl;
    }
    }
    for(int i = 0; i < 5; i++)
    if(moveEnemyX[i] <= -20.00f)
            moveEnemyX[i] = 20.00f;
    else
        moveEnemyX[i]-=0.001f;
    glutPostRedisplay();
    glClear(GL_COLOR_BUFFER_BIT);

    //night sky
    quadMaker(0.0f, 0.0f,0.0f, 0.0f, 0.0f,20.0f, 20.0f);
    //moon
    circleMaker(0.0f, 15.0f, 18.0f, 1.0f, 1.0f,1.0f, 0.5f, 1.0f, 100.0f);

    glPushMatrix();
    glTranslatef(0.0f, 5.0f, 0.0f);
    glScalef(1.0f, 0.5f, 0.0f);
    viewBuilding();
    glPopMatrix();
    road();
    //Ground
    quadMaker(0.0f, -11.8f,0.54f, 0.50f, 0.298f, 20.0f, 8.3f);

    glPushMatrix();
    glTranslatef(dx, dy, 0.0f);
    glScalef(0.3f, .3f, 0.0f);  //small dexter
    dexter();
    glPopMatrix();
    for(int i = 0; i < 5; i++)
    {
        glPushMatrix();
    glTranslatef(moveEnemyX[i], moveEnemyY[i], 0.0f);
    glScalef(0.3f, .3f, 0.0f);
    enemy();
    glPopMatrix();
    }
    for(int i = 0; i < 5; i++)
    circleMaker(0.0f, pa[i], pb[i], 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 100.0f);
/*
   if(specialPower == true)
    {
        glPushMatrix();
        glBegin(GL_POLYGON);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2f(extraPower, 8.0f);
            glVertex2f(extraPower, -20.0f);
            glVertex2f(extraPowerUp, -20.0f);
            glVertex2f(extraPowerUp, 8.0f);
        glEnd();
    glPopMatrix();
    extraPowerUp+=.0001f;
    cout << extraPowerUp << endl;
    if(extraPowerUp > 20.0f)
        superPower();
    glutPostRedisplay();
    }*/
    glFlush();
}



void spe_key(int key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_LEFT:
                if(dx >= -17.0f)
				{dx -=1.0f;
				glutPostRedisplay();
				}
				break;

		case GLUT_KEY_RIGHT:
                if(dx <= 17.0f)
				{dx +=1.0f;
				glutPostRedisplay();}
				break;

        case GLUT_KEY_DOWN:
                if(dy >= -15.0f)
				{dy -=1.0f;
				glutPostRedisplay();
				}
				cout << dy << endl;
				break;

		case GLUT_KEY_UP:
                if(dy <= 8.0f)
				{dy +=1.0f;
				glutPostRedisplay();}
				break;
	  default:
			break;
	}
}

void my_keyboard(unsigned char key, int x, int y)
{

    switch (key)
    {

    case 'e':
        for(int i = 0; i < 5 ; i++)
        {
            if(pa[i] > 20.0f)
            {pa[i] = dx;
             pb[i] = dy;
             break;
            }
        }
        break;

    case 's':
        if(countPower >= 5)
        {
            specialPower = true;
            extraPower = dx;
            countPower = 0;
        }
        break;

    default:
        break;
    }
}

void init(void)
{
	glClearColor (1.0f, 1.0f, 1.0f, 1.0f);
	//glOrtho(-50.0, 50.0, -50.0, 50.0, -10.0, 10.0);
	glOrtho(-20.0, 20.0, -20.0, 20.0, -10.0, 10.0);
	superPower();
}

int main(int argc, char *argv[])
{
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1200, 900);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Like a Boss");
	init();
	glutDisplayFunc(display);
	glutSpecialFunc(spe_key);//up,down,left,right
	glutKeyboardFunc(my_keyboard);
	glutMainLoop();
	return 0;
}
