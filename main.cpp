#include <iostream>
using namespace std;
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>
#include<mmsystem.h>

bool rainday = false;
bool night = false;
float _rain = 0.0f;
float _nt = 0.0;
GLfloat positionrocket = 0.0f;
GLfloat speedrocket = 0.12;
GLfloat positionplane = 0.0f;
GLfloat speedplane = 0.07;
GLfloat position = 0.0f;
GLfloat speed = 0.033f;

GLfloat positionsun = 0.0f;
GLfloat speedsun = 0.003f;
GLfloat positionmoon = 0.0f;
GLfloat speedmoon = 0.003f;

GLfloat position1 = 0.08f;
GLfloat speed1 = 0.1f;
GLfloat positioncloud1 = 0.0f;
GLfloat speedcloud1 = 0.008;
GLfloat positioncloud2 = 0.0f;
GLfloat speedcloud2 = 0.008;
GLfloat positioncloud3 = 0.0f;
GLfloat speedcloud3 = 0.008;
GLfloat positioncar1 = 0.0f;
GLfloat speedcar1 = 0.03;
GLfloat positionbus1 = 0.0f;
GLfloat speedbus1 = 0.01f;
GLfloat positioncar2 = 0.0f;
GLfloat speedcar2 = 0.03f;
GLfloat positiontrack=0.0f;
GLfloat speedtrack = 0.03f;
GLfloat positioncar3=0.0f;
GLfloat speedcar3 = 0.03f;


void DrawTriangle(GLfloat ax,GLfloat ay,GLfloat bx,GLfloat by,GLfloat cx,GLfloat cy,GLfloat cr,GLfloat cg,GLfloat cb,GLfloat ca=1.0)
{
    glBegin(GL_TRIANGLES);
   glColor4f(cr,cg,cb,ca);
   glVertex2f(ax,ay);
   glVertex2f(bx,by);
   glVertex2f(cx, cy);
   glEnd();
}
void DrawQuad(GLfloat ax,GLfloat ay,GLfloat bx,GLfloat by,GLfloat cx,GLfloat cy,GLfloat dx,GLfloat dy,GLfloat cr,GLfloat cg,GLfloat cb,GLfloat ca=1.0)
{
   glBegin(GL_QUADS);
    glColor4f(cr,cg,cb,ca);
   glVertex2f(ax,ay);
   glVertex2f(bx,by);
   glVertex2f(cx, cy);
   glVertex2f(dx, dy);
   glEnd();
}
void DrawCircle(float x, float y, float radius, int triangleAmount)
{
    float twicePi=2.0f*3.1415926f;
   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

}

void drawrain()
{

 for (float j=0;j<=1;j+=.05)
 {


    for(float i=0.0;i<=1;i+=.05)
    {

        glBegin(GL_LINES);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(-j, i);
        glVertex2f(-j-.01, i+.01);
        glEnd();
        glBegin(GL_LINES);
         glColor3f(1.0,1.0,1.0);
        glVertex2f(j, i);
        glVertex2f(j-.01, i+.01);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(-j, -i);
        glVertex2f(-j+.01, -i-.01);
        glEnd();
        glBegin(GL_LINES);
         glColor3f(1.0,1.0,1.0);
        glVertex2f(j, -i);
        glVertex2f(j+.01, -i-.01);
        glEnd();

    }
    }
}
void drawSky()
{
/////////////////////////////////////////////Maruf Start
//sky
////sky day color
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 1.0f, .8f);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(0.9999f, 0.0f);
    glVertex2f(0.9999f, 0.9999f);
    glVertex2f(-1.0f, 0.9999f);
	glEnd();
////sky plane
    glPushMatrix();
    glTranslated(positionplane,.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.2f);
	glVertex2f(-0.13f, 0.7f);
	glVertex2f(0.30f, 0.7f);
    glVertex2f(0.25f, 0.8f);
    glVertex2f(-0.00f, 0.8f);
	glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.9f, 0.2f);
	glVertex2f(0.05f, 0.72f);
	glVertex2f(0.08f, 0.72f);
    glVertex2f(0.02f, 0.60f);
	glEnd();
	glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.9f, 0.2f);
	glVertex2f(0.03f, 0.78f);
	glVertex2f(0.05f, 0.80f);
    glVertex2f(0.00f, 0.85f);
	glEnd();
	glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.9f, 0.2f);
	glVertex2f(-0.10f, 0.72f);
	glVertex2f(-0.05f, 0.76f);
    glVertex2f(-0.12f, 0.80f);
	glEnd();
	glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.17f, 0.74f);
	glVertex2f(0.23f, 0.74f);
    glVertex2f(0.23f, 0.76f);
    glVertex2f(0.17f, 0.76f);
	glEnd();
	glPopMatrix();

////sky cloudg
glPushMatrix();
glPushMatrix();
glTranslated(positioncloud1,.0f,0.0f);
glColor3f(1.0f,1.0f,1.0f);
DrawCircle(0.85,0.80,.05,200);
DrawCircle(0.80,0.85,.05,200);
DrawCircle(0.75,0.77,.05,200);
DrawCircle(0.80,0.76,.05,200);
glPopMatrix();
glPushMatrix();
glTranslated(positioncloud2,.0f,0.0f);
DrawCircle(0.20,0.80,.05,200);
DrawCircle(0.15,0.85,.05,200);
DrawCircle(0.10,0.77,.05,200);
DrawCircle(0.20,0.76,.05,200);
DrawCircle(0.22,0.82,.05,200);
DrawCircle(0.12,0.82,.05,200);
DrawCircle(0.15,0.80,.05,200);
glPopMatrix();
glPushMatrix();
glTranslated(positioncloud3,.0f,0.0f);
DrawCircle(-0.92,0.65,.05,200);
DrawCircle(-0.91,0.70,.05,200);
DrawCircle(-0.90,0.80,.05,200);
DrawCircle(-0.85,0.75,.05,200);
DrawCircle(-0.85,0.70,.05,200);
DrawCircle(-0.85,0.84,.05,200);
DrawCircle(-0.80,0.80,.05,200);
glPopMatrix();
glPopMatrix();

////sky rocket

////////////////////////////////////////////Maruf End
}
void drawstar()
{
    ////sky star
glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.10f, 0.80);
    glVertex2f(0.12f, 0.78f);
    glVertex2f(0.11f, 0.82f);
    glVertex2f(0.13f, 0.84f);
	glVertex2f(0.11f, 0.84);
    glVertex2f(0.10f, 0.87f);
    glVertex2f(0.09f, 0.84f);
    glVertex2f(0.07f, 0.84);
    glVertex2f(0.09f, 0.82f);
    glVertex2f(0.08f, 0.78f);
    glVertex2f(0.10f, 0.80);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.30f, 0.70);
    glVertex2f(0.32f, 0.68f);
    glVertex2f(0.31f, 0.72f);
    glVertex2f(0.33f, 0.74f);
	glVertex2f(0.31f, 0.74);
    glVertex2f(0.30f, 0.77f);
    glVertex2f(0.29f, 0.74f);
    glVertex2f(0.27f, 0.74);
    glVertex2f(0.29f, 0.72f);
    glVertex2f(0.28f, 0.68f);
    glVertex2f(0.30f, 0.70);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.40f, 0.80);
    glVertex2f(0.42f, 0.78f);
    glVertex2f(0.41f, 0.82f);
    glVertex2f(0.43f, 0.84f);
	glVertex2f(0.41f, 0.84);
    glVertex2f(0.40f, 0.87f);
    glVertex2f(0.39f, 0.84f);
    glVertex2f(0.37f, 0.84);
    glVertex2f(0.39f, 0.82f);
    glVertex2f(0.38f, 0.78f);
    glVertex2f(0.40f, 0.80);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.40f, 0.50);
    glVertex2f(0.42f, 0.48f);
    glVertex2f(0.41f, 0.52f);
    glVertex2f(0.43f, 0.54f);
	glVertex2f(0.41f, 0.54);
    glVertex2f(0.40f, 0.57f);
    glVertex2f(0.39f, 0.54f);
    glVertex2f(0.37f, 0.54);
    glVertex2f(0.39f, 0.52f);
    glVertex2f(0.38f, 0.48f);
    glVertex2f(0.40f, 0.50);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.20f, 0.50);
    glVertex2f(0.22f, 0.48f);
    glVertex2f(0.21f, 0.52f);
    glVertex2f(0.23f, 0.54f);
	glVertex2f(0.21f, 0.54);
    glVertex2f(0.20f, 0.57f);
    glVertex2f(0.19f, 0.54f);
    glVertex2f(0.17f, 0.54);
    glVertex2f(0.19f, 0.52f);
    glVertex2f(0.18f, 0.48f);
    glVertex2f(0.20f, 0.50);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.90f, 0.50);
    glVertex2f(0.92f, 0.48f);
    glVertex2f(0.91f, 0.52f);
    glVertex2f(0.93f, 0.54f);
	glVertex2f(0.91f, 0.54);
    glVertex2f(0.90f, 0.57f);
    glVertex2f(0.89f, 0.54f);
    glVertex2f(0.87f, 0.54);
    glVertex2f(0.89f, 0.52f);
    glVertex2f(0.88f, 0.48f);
    glVertex2f(0.90f, 0.50);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.70f, 0.50);
    glVertex2f(0.72f, 0.48f);
    glVertex2f(0.71f, 0.52f);
    glVertex2f(0.73f, 0.54f);
	glVertex2f(0.71f, 0.54);
    glVertex2f(0.70f, 0.57f);
    glVertex2f(0.69f, 0.54f);
    glVertex2f(0.67f, 0.54);
    glVertex2f(0.69f, 0.52f);
    glVertex2f(0.68f, 0.48f);
    glVertex2f(0.70f, 0.50);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.50f, 0.70);
    glVertex2f(0.52f, 0.68f);
    glVertex2f(0.51f, 0.72f);
    glVertex2f(0.53f, 0.74f);
	glVertex2f(0.51f, 0.74);
    glVertex2f(0.50f, 0.77f);
    glVertex2f(0.49f, 0.74f);
    glVertex2f(0.47f, 0.74);
    glVertex2f(0.49f, 0.72f);
    glVertex2f(0.48f, 0.68f);
    glVertex2f(0.50f, 0.70);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.63f, 0.70);
    glVertex2f(0.65f, 0.68f);
    glVertex2f(0.64f, 0.72f);
    glVertex2f(0.66f, 0.74f);
	glVertex2f(0.64f, 0.74);
    glVertex2f(0.63f, 0.77f);
    glVertex2f(0.62f, 0.74f);
    glVertex2f(0.60f, 0.74);
    glVertex2f(0.62f, 0.72f);
    glVertex2f(0.61f, 0.68f);
    glVertex2f(0.63f, 0.70);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.70f, 0.80);
    glVertex2f(0.72f, 0.78f);
    glVertex2f(0.71f, 0.82f);
    glVertex2f(0.73f, 0.84f);
	glVertex2f(0.71f, 0.84);
    glVertex2f(0.70f, 0.87f);
    glVertex2f(0.69f, 0.84f);
    glVertex2f(0.67f, 0.84);
    glVertex2f(0.69f, 0.82f);
    glVertex2f(0.68f, 0.78f);
    glVertex2f(0.70f, 0.80);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.80f, 0.70);
    glVertex2f(0.82f, 0.68f);
    glVertex2f(0.81f, 0.72f);
    glVertex2f(0.83f, 0.74f);
	glVertex2f(0.81f, 0.74);
    glVertex2f(0.80f, 0.77f);
    glVertex2f(0.79f, 0.74f);
    glVertex2f(0.77f, 0.74);
    glVertex2f(0.79f, 0.72f);
    glVertex2f(0.78f, 0.68f);
    glVertex2f(0.80f, 0.70);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.30f, 0.70);
    glVertex2f(-0.32f, 0.68f);
    glVertex2f(-0.31f, 0.72f);
    glVertex2f(-0.33f, 0.74f);
	glVertex2f(-0.31f, 0.74);
    glVertex2f(-0.30f, 0.77f);
    glVertex2f(-0.29f, 0.74f);
    glVertex2f(-0.27f, 0.74);
    glVertex2f(-0.29f, 0.72f);
    glVertex2f(-0.28f, 0.68f);
    glVertex2f(-0.30f, 0.70);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.70f, 0.80);
    glVertex2f(-0.72f, 0.78f);
    glVertex2f(-0.71f, 0.82f);
    glVertex2f(-0.73f, 0.84f);
	glVertex2f(-0.71f, 0.84);
    glVertex2f(-0.70f, 0.87f);
    glVertex2f(-0.69f, 0.84f);
    glVertex2f(-0.67f, 0.84);
    glVertex2f(-0.69f, 0.82f);
    glVertex2f(-0.68f, 0.78f);
    glVertex2f(-0.70f, 0.80);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.10f, 0.85);
    glVertex2f(-0.12f, 0.83f);
    glVertex2f(-0.11f, 0.87f);
    glVertex2f(-0.13f, 0.89f);
	glVertex2f(-0.11f, 0.89);
    glVertex2f(-0.10f, 0.92f);
    glVertex2f(-0.09f, 0.89f);
    glVertex2f(-0.07f, 0.89);
    glVertex2f(-0.09f, 0.87f);
    glVertex2f(-0.08f, 0.83f);
    glVertex2f(-0.10f, 0.85);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.10f, 0.85);
    glVertex2f(-0.12f, 0.83f);
    glVertex2f(-0.11f, 0.87f);
    glVertex2f(-0.13f, 0.89f);
	glVertex2f(-0.11f, 0.89);
    glVertex2f(-0.10f, 0.92f);
    glVertex2f(-0.09f, 0.89f);
    glVertex2f(-0.07f, 0.89);
    glVertex2f(-0.09f, 0.87f);
    glVertex2f(-0.08f, 0.83f);
    glVertex2f(-0.10f, 0.85);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.50f, 0.85);
    glVertex2f(-0.52f, 0.83f);
    glVertex2f(-0.51f, 0.87f);
    glVertex2f(-0.53f, 0.89f);
	glVertex2f(-0.51f, 0.89);
    glVertex2f(-0.50f, 0.92f);
    glVertex2f(-0.49f, 0.89f);
    glVertex2f(-0.47f, 0.89);
    glVertex2f(-0.49f, 0.87f);
    glVertex2f(-0.48f, 0.83f);
    glVertex2f(-0.50f, 0.85);
	glEnd();
	glPushMatrix();
}
void drawskynight()
{
    glPushMatrix();
    ////sky night
////sky color
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(0.9999f, 0.0f);
    glVertex2f(0.9999f, 0.9999f);
    glVertex2f(-1.0f, 0.9999f);
	glEnd();


	////sky rocket
    glPushMatrix();
    glTranslated(positionrocket,.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.9f, 1.0f);
	glVertex2f(-0.13f, 0.7f);
	glVertex2f(0.20f, 0.7f);
    glVertex2f(0.20f, 0.8f);
    glVertex2f(-0.13f, 0.8f);
	glEnd();
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.8f, 0.8f);
	glVertex2f(-0.15f, 0.72f);
	glVertex2f(-0.13f, 0.72f);
    glVertex2f(-0.13f, 0.78f);
    glVertex2f(-0.15f, 0.78f);
	glEnd();
	glBegin(GL_QUADS);
    glColor3f(0.8f, 0.0f, 0.8f);
	glVertex2f(-0.17f, 0.73f);
	glVertex2f(-0.15f, 0.73f);
    glVertex2f(-0.15f, 0.77f);
    glVertex2f(-0.17f, 0.77f);
	glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.0f, 0.8f);
	glVertex2f(0.05f, 0.72f);
	glVertex2f(0.08f, 0.72f);
    glVertex2f(0.02f, 0.60f);
	glEnd();
	glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.0f, 0.8f);
	glVertex2f(0.03f, 0.78f);
	glVertex2f(0.05f, 0.80f);
    glVertex2f(0.00f, 0.85f);
	glEnd();
	glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.0f, 0.8f);
	glVertex2f(0.20f, 0.7f);
    glVertex2f(0.20f, 0.8f);
    glVertex2f(0.30f, 0.75f);
	glEnd();
	glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.12f, 0.74f);
	glVertex2f(0.16f, 0.74f);
    glVertex2f(0.16f, 0.76f);
    glVertex2f(0.12f, 0.76f);
	glEnd();
	glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.06f, 0.74f);
	glVertex2f(0.10f, 0.74f);
    glVertex2f(0.10f, 0.76f);
    glVertex2f(0.06f, 0.76f);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.00f, 0.74f);
	glVertex2f(0.04f, 0.74f);
    glVertex2f(0.04f, 0.76f);
    glVertex2f(0.00f, 0.76f);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.06f, 0.74f);
	glVertex2f(-0.02f, 0.74f);
    glVertex2f(-0.02f, 0.76f);
    glVertex2f(-0.06f, 0.76f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.6f, .0f);
	glVertex2f(-0.17f, 0.73f);
	glVertex2f(-0.24f, 0.68f);
    glVertex2f(-0.23f, 0.72f);
    glVertex2f(-0.25f, 0.75f);
    glVertex2f(-0.23f, 0.77f);
    glVertex2f(-0.24f, 0.81f);
    glVertex2f(-0.17f, 0.77f);
	glEnd();
	glPopMatrix();
}

void drawsun()
{
    ////sky sun
glPushMatrix();
glTranslated(.0f,positionsun,.0f);
glColor3f(1.0f,0.6f,0.0f);
DrawCircle(0.60,0.0,.08,200);
glColor3f(1.0f,1.0f,0.2f);
DrawCircle(0.60,0.0,.05,200);
glPopMatrix();
}
void drawmoon()
{
    ////sky moon
glPushMatrix();
glTranslated(.0f,positionmoon,.0f);
glColor3f(1.0f,1.0f,1.0f);
DrawCircle(0.60,0.0,.06,200);
glColor3f(1.0f,1.0f,0.8f);
DrawCircle(0.60,0.0,.04,200);
glPopMatrix();
}
void drawBuilding()
{
     //glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//glClear(GL_COLOR_BUFFER_BIT);
	//glLoadIdentity(); //Reset the drawing perspective
	//glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
//drawSky();

    //glBegin(GL_LINES);
    //glColor3f(0.0f, 0.0f, 0.0f);
    //glVertex2f(-1.0f, 0.0f);
    //glVertex2f(1.0f, 0.0f);
    //lEnd();
    ///////////////////////////////////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.8f, 0.0f);
    glVertex2f(0.97f, 0.0f);
    glVertex2f(0.97f, 0.3f);
    glVertex2f(0.8f, 0.3f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.77f, 0.0f);
    glVertex2f(0.8f, 0.0f);
    glVertex2f(0.8f, 0.3f);
    glVertex2f(0.77f, 0.28f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(0.82f, 0.02f);
    glVertex2f(0.875f, 0.02f);
    glVertex2f(0.875f, 0.12f);
    glVertex2f(0.82f, 0.12f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(0.82f, 0.16f);
    glVertex2f(0.875f, 0.16f);
    glVertex2f(0.875f, 0.28f);
    glVertex2f(0.82f, 0.28f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(0.895f, 0.02f);
    glVertex2f(0.95f, 0.02f);
    glVertex2f(0.95f, 0.12f);
    glVertex2f(0.895f, 0.12f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(0.895f, 0.16f);
    glVertex2f(0.95f, 0.16f);
    glVertex2f(0.95f, 0.28f);
    glVertex2f(0.895f, 0.28f);
	glEnd();
	//////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.1f, .3f);
    glVertex2f(0.62f, 0.0f);
    glVertex2f(0.75f, 0.0f);
    glVertex2f(0.75f, 0.4f);
    glVertex2f(0.62f, 0.4f);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.1f, .3f);
    glVertex2f(0.60f, 0.0f);
    glVertex2f(0.62f, 0.0f);
    glVertex2f(0.62f, 0.4f);
    glVertex2f(0.60f, 0.38f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(0.64f, 0.04f);
    glVertex2f(0.73f, 0.04f);
    glVertex2f(0.73f, 0.14f);
    glVertex2f(0.64f, 0.14f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(0.64, 0.16f);
    glVertex2f(0.73f, 0.16f);
    glVertex2f(0.73f, 0.26f);
    glVertex2f(0.64f, 0.26f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(0.64f, 0.28f);
    glVertex2f(0.73f, 0.28f);
    glVertex2f(0.73f, 0.38f);
    glVertex2f(0.64f, 0.38f);
	glEnd();
	/////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.58f, 0.0f);
    glVertex2f(0.58f, 0.24f);
    glVertex2f(0.4f, 0.24f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.38f, 0.0f);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.4f, 0.24f);
    glVertex2f(0.38f, 0.21f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(0.42f, 0.02f);
    glVertex2f(0.48f, 0.02f);
    glVertex2f(0.48f, 0.11f);
    glVertex2f(0.42f, 0.11f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(0.50f, 0.13f);
    glVertex2f(0.56f, 0.13f);
    glVertex2f(0.56f, 0.22f);
    glVertex2f(0.50f, 0.22f);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(0.50f, 0.02f);
    glVertex2f(0.56f, 0.02f);
    glVertex2f(0.56f, 0.11f);
    glVertex2f(0.50f, 0.11f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(0.42f, 0.13f);
    glVertex2f(0.48f, 0.13f);
    glVertex2f(0.48f, 0.22f);
    glVertex2f(0.42f, 0.22f);
	glEnd();
	//////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(0.22f, 0.0f);
    glVertex2f(0.36f, 0.0f);
    glVertex2f(0.36f, 0.35f);
    glVertex2f(0.22f, 0.35f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(0.20f, 0.0f);
    glVertex2f(0.22f, 0.0f);
    glVertex2f(0.22f, 0.35f);
    glVertex2f(0.20f, 0.33f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(.0f, .7f, .8f);
    glVertex2f(0.24f, 0.02f);
    glVertex2f(0.34f, 0.02f);
    glVertex2f(0.34f, 0.11f);
    glVertex2f(0.24f, 0.11f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(0.24f, 0.13f);
    glVertex2f(0.34f, 0.13f);
    glVertex2f(0.34f, 0.22f);
    glVertex2f(0.24f, 0.22f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(0.24f, 0.24f);
    glVertex2f(0.34f, 0.24f);
    glVertex2f(0.34f, 0.33f);
    glVertex2f(0.24f, 0.33f);
	glEnd();
	///////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(0.15f, 0.0f);
    glVertex2f(0.18f, 0.0f);
    glVertex2f(0.18f, 0.37f);
    glVertex2f(0.15f, 0.4f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(0.15f, 0.0f);
    glVertex2f(0.15f, 0.4f);
    glVertex2f(-0.1f, 0.4f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(-0.08f, 0.02f);
    glVertex2f(0.01f, 0.02f);
    glVertex2f(0.01f, 0.19f);
    glVertex2f(-0.08f, 0.19f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(0.03f, 0.02f);
    glVertex2f(0.13f, 0.02f);
    glVertex2f(0.13f, 0.19f);
    glVertex2f(0.03f, 0.19f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(-0.08f, 0.21f);
    glVertex2f(0.01f, 0.21f);
    glVertex2f(0.01f, 0.38f);
    glVertex2f(-0.08f, 0.38f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(0.03f, 0.21f);
    glVertex2f(0.13f, 0.21f);
    glVertex2f(0.13f, 0.38f);
    glVertex2f(0.03f, 0.38f);
	glEnd();
	////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.24f, 0.0f);
    glVertex2f(-0.12f, 0.0f);
    glVertex2f(-0.12f, 0.45f);
    glVertex2f(-0.24f, 0.45f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.26f, 0.0f);
    glVertex2f(-0.24f, 0.0f);
    glVertex2f(-0.24f, 0.45f);
    glVertex2f(-0.26f, 0.43f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(-0.22f, 0.03f);
    glVertex2f(-0.14f, 0.03f);
    glVertex2f(-0.14f, 0.15f);
    glVertex2f(-0.22f, 0.15f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(-0.22f, 0.17f);
    glVertex2f(-0.14f, 0.17f);
    glVertex2f(-0.14f, 0.29f);
    glVertex2f(-0.22f, 0.29f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(-0.22f, 0.31f);
    glVertex2f(-0.14f, 0.31f);
    glVertex2f(-0.14f, 0.43f);
    glVertex2f(-0.22f, 0.43f);
	glEnd();
	////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.48f, 0.0f);
    glVertex2f(-0.31f, 0.0f);
    glVertex2f(-0.31f, 0.37f);
    glVertex2f(-0.48f, 0.37f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.31f, 0.0f);
    glVertex2f(-0.28f, 0.0f);
    glVertex2f(-0.28f, 0.34f);
    glVertex2f(-0.31f, 0.37f);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(-0.46f, 0.02f);
    glVertex2f(-0.41f, 0.02f);
    glVertex2f(-0.41f, 0.12f);
    glVertex2f(-0.46f, 0.12f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(-0.46f, 0.14f);
    glVertex2f(-0.41f, 0.14f);
    glVertex2f(-0.41f, 0.24f);
    glVertex2f(-0.46f, 0.24f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(-0.46f, 0.26f);
    glVertex2f(-0.41f, 0.26f);
    glVertex2f(-0.41f, 0.36f);
    glVertex2f(-0.46f, 0.36f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(-0.38f, 0.02f);
    glVertex2f(-0.33f, 0.02f);
    glVertex2f(-0.33f, 0.12f);
    glVertex2f(-0.38f, 0.12f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(-0.38f, 0.14f);
    glVertex2f(-0.33f, 0.14f);
    glVertex2f(-0.33f, 0.24f);
    glVertex2f(-0.38f, 0.24f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, .7f, .8f);
    glVertex2f(-0.38f, 0.26f);
    glVertex2f(-0.33f, 0.26f);
    glVertex2f(-0.33f, 0.36f);
    glVertex2f(-0.38f, 0.36f);
	glEnd();
	///////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.7f, .8f);
    glVertex2f(-0.52f, 0.0f);
    glVertex2f(-0.50f, 0.0f);
    glVertex2f(-0.50f, 0.48f);
    glVertex2f(-0.52f, 0.5f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.7f,.8f);
    glVertex2f(-0.66f, 0.0f);
    glVertex2f(-0.52f, 0.0f);
    glVertex2f(-0.52f, 0.5f);
    glVertex2f(-0.66f, 0.5f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.f, .7f, .8f);
    glVertex2f(-0.64f, 0.02f);
    glVertex2f(-0.54f, 0.02f);
    glVertex2f(-0.54f, 0.12f);
    glVertex2f(-0.64f, 0.12f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.f, .7f, .8f);
    glVertex2f(-0.64f, 0.14f);
    glVertex2f(-0.54f, 0.14f);
    glVertex2f(-0.54f, 0.24f);
    glVertex2f(-0.64f, 0.24f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.f, .7f, .8f);
    glVertex2f(-0.64f, 0.26f);
    glVertex2f(-0.54f, 0.26f);
    glVertex2f(-0.54f, 0.36f);
    glVertex2f(-0.64f, 0.36f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.f, .7f, .8f);
    glVertex2f(-0.64f, 0.38f);
    glVertex2f(-0.54f, 0.38f);
    glVertex2f(-0.54f, 0.48f);
    glVertex2f(-0.64f, 0.48f);
	glEnd();
	////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.7f, 0.0f);
    glVertex2f(-0.68f, 0.0f);
    glVertex2f(-0.68f, 0.18f);
    glVertex2f(-0.7f, 0.2f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.83f, 0.0f);
    glVertex2f(-0.7f, 0.0f);
    glVertex2f(-0.7f, 0.2f);
    glVertex2f(-0.83f, 0.2f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.f, .7f, .8f);
    glVertex2f(-0.81f, 0.02f);
    glVertex2f(-0.775f, 0.02f);
    glVertex2f(-0.775f, 0.09f);
    glVertex2f(-0.81f, 0.09f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.f, .7f, .8f);
    glVertex2f(-0.755f, 0.02f);
    glVertex2f(-0.72f, 0.02f);
    glVertex2f(-0.72f, 0.09f);
    glVertex2f(-0.755f, 0.09f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.f, .7f, .8f);
    glVertex2f(-0.81f, 0.11f);
    glVertex2f(-0.775f, 0.11f);
    glVertex2f(-0.775f, 0.18f);
    glVertex2f(-0.81f, 0.18f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.f, .7f, .8f);
    glVertex2f(-0.755f, 0.11f);
    glVertex2f(-0.72f, 0.11f);
    glVertex2f(-0.72f, 0.18f);
    glVertex2f(-0.755f, 0.18f);
	glEnd();
	//////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.1f, 0.0f);
    glVertex2f(-0.87f, 0.0f);
    glVertex2f(-0.85f, 0.0f);
    glVertex2f(-0.85f, 0.23f);
    glVertex2f(-0.87f, 0.25f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.1f, 0.0f);
    glVertex2f(-0.97f, 0.0f);
    glVertex2f(-0.87f, 0.0f);
    glVertex2f(-0.87f, 0.25f);
    glVertex2f(-0.97f, 0.25f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.f, .7f, .8f);
    glVertex2f(-0.95f, 0.03f);
    glVertex2f(-0.89f, 0.03f);
    glVertex2f(-0.89f, 0.12f);
    glVertex2f(-0.95f, 0.12f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.f, .7f, .8f);
    glVertex2f(-0.95f, 0.14f);
    glVertex2f(-0.89f, 0.14f);
    glVertex2f(-0.89f, 0.23f);
    glVertex2f(-0.95f, 0.23f);
	glEnd();

    glPopMatrix();

	//glutSwapBuffers();
}

void drawbuildingnight()
{

     //glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//glClear(GL_COLOR_BUFFER_BIT);
	//glLoadIdentity(); //Reset the drawing perspective
	//glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
//drawSky();

    //glBegin(GL_LINES);
    //glColor3f(0.0f, 0.0f, 0.0f);
    //glVertex2f(-1.0f, 0.0f);
    //glVertex2f(1.0f, 0.0f);
    //lEnd();
    ///////////////////////////////////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.8f, 0.0f);
    glVertex2f(0.97f, 0.0f);
    glVertex2f(0.97f, 0.3f);
    glVertex2f(0.8f, 0.3f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.77f, 0.0f);
    glVertex2f(0.8f, 0.0f);
    glVertex2f(0.8f, 0.3f);
    glVertex2f(0.77f, 0.28f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(0.82f, 0.02f);
    glVertex2f(0.875f, 0.02f);
    glVertex2f(0.875f, 0.12f);
    glVertex2f(0.82f, 0.12f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(0.82f, 0.16f);
    glVertex2f(0.875f, 0.16f);
    glVertex2f(0.875f, 0.28f);
    glVertex2f(0.82f, 0.28f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(0.895f, 0.02f);
    glVertex2f(0.95f, 0.02f);
    glVertex2f(0.95f, 0.12f);
    glVertex2f(0.895f, 0.12f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(0.895f, 0.16f);
    glVertex2f(0.95f, 0.16f);
    glVertex2f(0.95f, 0.28f);
    glVertex2f(0.895f, 0.28f);
	glEnd();
	//////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.1f, .3f);
    glVertex2f(0.62f, 0.0f);
    glVertex2f(0.75f, 0.0f);
    glVertex2f(0.75f, 0.4f);
    glVertex2f(0.62f, 0.4f);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.1f, .3f);
    glVertex2f(0.60f, 0.0f);
    glVertex2f(0.62f, 0.0f);
    glVertex2f(0.62f, 0.4f);
    glVertex2f(0.60f, 0.38f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(0.64f, 0.04f);
    glVertex2f(0.73f, 0.04f);
    glVertex2f(0.73f, 0.14f);
    glVertex2f(0.64f, 0.14f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(0.64, 0.16f);
    glVertex2f(0.73f, 0.16f);
    glVertex2f(0.73f, 0.26f);
    glVertex2f(0.64f, 0.26f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(0.64f, 0.28f);
    glVertex2f(0.73f, 0.28f);
    glVertex2f(0.73f, 0.38f);
    glVertex2f(0.64f, 0.38f);
	glEnd();
	/////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.58f, 0.0f);
    glVertex2f(0.58f, 0.24f);
    glVertex2f(0.4f, 0.24f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.38f, 0.0f);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.4f, 0.24f);
    glVertex2f(0.38f, 0.21f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(0.42f, 0.02f);
    glVertex2f(0.48f, 0.02f);
    glVertex2f(0.48f, 0.11f);
    glVertex2f(0.42f, 0.11f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(0.50f, 0.13f);
    glVertex2f(0.56f, 0.13f);
    glVertex2f(0.56f, 0.22f);
    glVertex2f(0.50f, 0.22f);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(0.50f, 0.02f);
    glVertex2f(0.56f, 0.02f);
    glVertex2f(0.56f, 0.11f);
    glVertex2f(0.50f, 0.11f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(0.42f, 0.13f);
    glVertex2f(0.48f, 0.13f);
    glVertex2f(0.48f, 0.22f);
    glVertex2f(0.42f, 0.22f);
	glEnd();
	//////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(0.22f, 0.0f);
    glVertex2f(0.36f, 0.0f);
    glVertex2f(0.36f, 0.35f);
    glVertex2f(0.22f, 0.35f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(0.20f, 0.0f);
    glVertex2f(0.22f, 0.0f);
    glVertex2f(0.22f, 0.35f);
    glVertex2f(0.20f, 0.33f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(0.24f, 0.02f);
    glVertex2f(0.34f, 0.02f);
    glVertex2f(0.34f, 0.11f);
    glVertex2f(0.24f, 0.11f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(0.24f, 0.13f);
    glVertex2f(0.34f, 0.13f);
    glVertex2f(0.34f, 0.22f);
    glVertex2f(0.24f, 0.22f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(0.24f, 0.24f);
    glVertex2f(0.34f, 0.24f);
    glVertex2f(0.34f, 0.33f);
    glVertex2f(0.24f, 0.33f);
	glEnd();
	///////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(0.15f, 0.0f);
    glVertex2f(0.18f, 0.0f);
    glVertex2f(0.18f, 0.37f);
    glVertex2f(0.15f, 0.4f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(0.15f, 0.0f);
    glVertex2f(0.15f, 0.4f);
    glVertex2f(-0.1f, 0.4f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.08f, 0.02f);
    glVertex2f(0.01f, 0.02f);
    glVertex2f(0.01f, 0.19f);
    glVertex2f(-0.08f, 0.19f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(0.03f, 0.02f);
    glVertex2f(0.13f, 0.02f);
    glVertex2f(0.13f, 0.19f);
    glVertex2f(0.03f, 0.19f);
	glEnd();
	glBegin(GL_POLYGON);
   glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.08f, 0.21f);
    glVertex2f(0.01f, 0.21f);
    glVertex2f(0.01f, 0.38f);
    glVertex2f(-0.08f, 0.38f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(0.03f, 0.21f);
    glVertex2f(0.13f, 0.21f);
    glVertex2f(0.13f, 0.38f);
    glVertex2f(0.03f, 0.38f);
	glEnd();
	////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.24f, 0.0f);
    glVertex2f(-0.12f, 0.0f);
    glVertex2f(-0.12f, 0.45f);
    glVertex2f(-0.24f, 0.45f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.26f, 0.0f);
    glVertex2f(-0.24f, 0.0f);
    glVertex2f(-0.24f, 0.45f);
    glVertex2f(-0.26f, 0.43f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.22f, 0.03f);
    glVertex2f(-0.14f, 0.03f);
    glVertex2f(-0.14f, 0.15f);
    glVertex2f(-0.22f, 0.15f);
	glEnd();
	glBegin(GL_POLYGON);
   glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.22f, 0.17f);
    glVertex2f(-0.14f, 0.17f);
    glVertex2f(-0.14f, 0.29f);
    glVertex2f(-0.22f, 0.29f);
	glEnd();
	glBegin(GL_POLYGON);
   glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.22f, 0.31f);
    glVertex2f(-0.14f, 0.31f);
    glVertex2f(-0.14f, 0.43f);
    glVertex2f(-0.22f, 0.43f);
	glEnd();
	////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.48f, 0.0f);
    glVertex2f(-0.31f, 0.0f);
    glVertex2f(-0.31f, 0.37f);
    glVertex2f(-0.48f, 0.37f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.31f, 0.0f);
    glVertex2f(-0.28f, 0.0f);
    glVertex2f(-0.28f, 0.34f);
    glVertex2f(-0.31f, 0.37f);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.46f, 0.02f);
    glVertex2f(-0.41f, 0.02f);
    glVertex2f(-0.41f, 0.12f);
    glVertex2f(-0.46f, 0.12f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.46f, 0.14f);
    glVertex2f(-0.41f, 0.14f);
    glVertex2f(-0.41f, 0.24f);
    glVertex2f(-0.46f, 0.24f);
	glEnd();
	glBegin(GL_POLYGON);
  glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.46f, 0.26f);
    glVertex2f(-0.41f, 0.26f);
    glVertex2f(-0.41f, 0.36f);
    glVertex2f(-0.46f, 0.36f);
	glEnd();
	glBegin(GL_POLYGON);
   glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.38f, 0.02f);
    glVertex2f(-0.33f, 0.02f);
    glVertex2f(-0.33f, 0.12f);
    glVertex2f(-0.38f, 0.12f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.38f, 0.14f);
    glVertex2f(-0.33f, 0.14f);
    glVertex2f(-0.33f, 0.24f);
    glVertex2f(-0.38f, 0.24f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.38f, 0.26f);
    glVertex2f(-0.33f, 0.26f);
    glVertex2f(-0.33f, 0.36f);
    glVertex2f(-0.38f, 0.36f);
	glEnd();
	///////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.7f, .8f);
    glVertex2f(-0.52f, 0.0f);
    glVertex2f(-0.50f, 0.0f);
    glVertex2f(-0.50f, 0.48f);
    glVertex2f(-0.52f, 0.5f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.7f, .8f);
    glVertex2f(-0.66f, 0.0f);
    glVertex2f(-0.52f, 0.0f);
    glVertex2f(-0.52f, 0.5f);
    glVertex2f(-0.66f, 0.5f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.64f, 0.02f);
    glVertex2f(-0.54f, 0.02f);
    glVertex2f(-0.54f, 0.12f);
    glVertex2f(-0.64f, 0.12f);
	glEnd();
	glBegin(GL_POLYGON);
   glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.64f, 0.14f);
    glVertex2f(-0.54f, 0.14f);
    glVertex2f(-0.54f, 0.24f);
    glVertex2f(-0.64f, 0.24f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.64f, 0.26f);
    glVertex2f(-0.54f, 0.26f);
    glVertex2f(-0.54f, 0.36f);
    glVertex2f(-0.64f, 0.36f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.64f, 0.38f);
    glVertex2f(-0.54f, 0.38f);
    glVertex2f(-0.54f, 0.48f);
    glVertex2f(-0.64f, 0.48f);
	glEnd();
	////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.7f, 0.0f);
    glVertex2f(-0.68f, 0.0f);
    glVertex2f(-0.68f, 0.18f);
    glVertex2f(-0.7f, 0.2f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.83f, 0.0f);
    glVertex2f(-0.7f, 0.0f);
    glVertex2f(-0.7f, 0.2f);
    glVertex2f(-0.83f, 0.2f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.81f, 0.02f);
    glVertex2f(-0.775f, 0.02f);
    glVertex2f(-0.775f, 0.09f);
    glVertex2f(-0.81f, 0.09f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.755f, 0.02f);
    glVertex2f(-0.72f, 0.02f);
    glVertex2f(-0.72f, 0.09f);
    glVertex2f(-0.755f, 0.09f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.81f, 0.11f);
    glVertex2f(-0.775f, 0.11f);
    glVertex2f(-0.775f, 0.18f);
    glVertex2f(-0.81f, 0.18f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.755f, 0.11f);
    glVertex2f(-0.72f, 0.11f);
    glVertex2f(-0.72f, 0.18f);
    glVertex2f(-0.755f, 0.18f);
	glEnd();
	//////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.1f, 0.0f);
    glVertex2f(-0.87f, 0.0f);
    glVertex2f(-0.85f, 0.0f);
    glVertex2f(-0.85f, 0.23f);
    glVertex2f(-0.87f, 0.25f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.1f, 0.0f);
    glVertex2f(-0.97f, 0.0f);
    glVertex2f(-0.87f, 0.0f);
    glVertex2f(-0.87f, 0.25f);
    glVertex2f(-0.97f, 0.25f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.95f, 0.03f);
    glVertex2f(-0.89f, 0.03f);
    glVertex2f(-0.89f, 0.12f);
    glVertex2f(-0.95f, 0.12f);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.9f, 1.0f, .1f);
    glVertex2f(-0.95f, 0.14f);
    glVertex2f(-0.89f, 0.14f);
    glVertex2f(-0.89f, 0.23f);
    glVertex2f(-0.95f, 0.23f);
	glEnd();

    glPopMatrix();

}
void Drawvhiclesday()
{

glPushMatrix();

//car1 left to right:
glPushMatrix();
glTranslated(positioncar1,.0f,0.0f);
glBegin(GL_POLYGON);

    glColor3f(0.0f,.75f,.50f);
    glVertex2f(-.75,-.09);
    glVertex2f(-.80,-.09);
    glVertex2f(-.80,-0.15);
    glVertex2f(-.50,-0.15);
    glVertex2f(-.50,-.11);
    glVertex2f(-.60,-.09);
    glVertex2f(-.65,-.04);
glEnd();
glColor3f(1.0f,1.f,1.0f);
DrawCircle(-.72,-.15,.03,200);
DrawCircle(-.60,-.15,.03,200);
glPopMatrix();


//car1 end:

//car2 left to right:

glPushMatrix();
glTranslated(positioncar2,.0f,0.0f);
glBegin(GL_POLYGON);
    glColor3f(0.50f,.0f,.75f);
    glVertex2f(.50,-.09);
    glVertex2f(.45,-.09);
    glVertex2f(.45,-0.15);
    glVertex2f(.75,-0.15);
    glVertex2f(.75,-.11);
    glVertex2f(.65,-.09);
    glVertex2f(.55,-.04);
glEnd();
glColor3f(1.0f,1.f,1.0f);
DrawCircle(.52,-.15,.03,200);
DrawCircle(.65,-.15,.03,200);
glPopMatrix();
//car2 end
//bus left to right:


glPushMatrix();
glTranslated(positionbus1,.0f,0.0f);
DrawQuad(-.35f,-.04f,-.35f,-.18f,.10f,-.18f,.10f,-.04f,1.0f,0.0f,0.0f);
DrawQuad(-.30f,-.11f,-.30f,-.06f,-.33f,-.06f,-.33f,-.11f,0.75f,0.50f,0.35f);
DrawQuad(-.27f,-.11f,-.27f,-.06f,-.24f,-.06f,-.24f,-.11f,0.75f,0.50f,0.35f);
DrawQuad(-.21f,-.11f,-.21f,-.06f,-.18f,-.06f,-.18f,-.11f,0.75f,0.50f,0.35f);
DrawQuad(-.15f,-.11f,-.15f,-.06f,-.12f,-.06f,-.12f,-.11f,0.75f,0.50f,0.35f);
DrawQuad(-.09f,-.11f,-.09f,-.06f,-.06f,-.06f,-.06f,-.11f,0.75f,0.50f,0.35f);
DrawQuad(-.03f,-.11f,-.03f,-.06f,-0.0f,-.06f,-0.0f,-.11f,0.75f,0.50f,0.35f);
DrawQuad(.03f,-.11f,.03f,-.06f,.06f,-.06f,.06f,-.11f,0.75f,0.50f,0.35f);
glColor3f(1.0f,1.f,1.0f);
DrawCircle(-.20,-.18,.03,200);
DrawCircle(0.0,-.18,.03,200);
//bus end
glPopMatrix();




glPopMatrix();
glPopMatrix();
glPushMatrix();

glPushMatrix();
glTranslated(positiontrack,.0f,0.0f);
//track right to left"
DrawQuad(.15f,-.33f,.15f,-.45f,.18f,-.45f,.18f,-.33f,1.0,0.0,0.0);
DrawQuad(.18f,-.36f,.18f,-.45f,.30f,-.45f,.30f,-.36f,1.0,0.0,0.0);
glColor3f(1.0f,1.f,1.0f);
DrawCircle(.18,-.45,.02,200);
DrawCircle(.25,-.45,.02,200);
glPopMatrix();


//end track
//car right to left:
glPushMatrix();
glTranslated(positioncar3,.0f,0.0f);
glBegin(GL_POLYGON);
glColor3f(1.0f,.50f,.0f);
      glVertex2f(-.60,-.35);
    glVertex2f(-.65,-.35);
    glVertex2f(-.70,-0.42);
    glVertex2f(-.40,-0.42);
    glVertex2f(-.40,-.35);
    glVertex2f(-.45,-.35);
    glVertex2f(-.50,-.31);
glEnd();
glColor3f(1.0f,1.f,1.0f);
DrawCircle(-.60,-.42,.03,200);
DrawCircle(-.45,-.42,.03,200);

glPopMatrix();
glPopMatrix();
}
void Drawvhiclesnight()
{

glPushMatrix();

//car1 left to right:
glPushMatrix();
glTranslated(positioncar1,.0f,0.0f);
DrawTriangle(-.50,-.12,-.40,-.07,-.40,-.13,1,1,.3);
DrawTriangle(-.50,-.13,-.40,-.12,-.40,-.16,1,1,.3);
//DrawTriangle(-0.50,-0.12,-0.40,-0.05,-0.40,-0.10,1.0.1.0,0.3);
glBegin(GL_POLYGON);

    glColor3f(0.0f,.75f,.50f);
    glVertex2f(-.75,-.09);
    glVertex2f(-.80,-.09);
    glVertex2f(-.80,-0.15);
    glVertex2f(-.50,-0.15);
    glVertex2f(-.50,-.11);
    glVertex2f(-.60,-.09);
    glVertex2f(-.65,-.04);
glEnd();
glColor3f(1.0f,1.f,1.0f);
DrawCircle(-.72,-.15,.03,200);
DrawCircle(-.60,-.15,.03,200);
glPopMatrix();


//car1 end:

//car2 left to right:

glPushMatrix();
glTranslated(positioncar2,.0f,0.0f);
DrawTriangle(.75,-.12,.85,-.07,.85,-.13,1,1,.3);
DrawTriangle(.75,-.13,.85,-.12,.85,-.16,1,1,.3);
glBegin(GL_POLYGON);
    glColor3f(0.50f,.0f,.75f);
    glVertex2f(.50,-.09);
    glVertex2f(.45,-.09);
    glVertex2f(.45,-0.15);
    glVertex2f(.75,-0.15);
    glVertex2f(.75,-.11);
    glVertex2f(.65,-.09);
    glVertex2f(.55,-.04);
glEnd();
glColor3f(1.0f,1.f,1.0f);
DrawCircle(.52,-.15,.03,200);
DrawCircle(.65,-.15,.03,200);
glPopMatrix();
//car2 end
//bus left to right:


glPushMatrix();
glTranslated(positionbus1,.0f,0.0f);
DrawTriangle(.10,-.14,.20,-.09,.20,-.15,1,1,.3);
DrawTriangle(.10,-.16,.20,-.14,.20,-.20,1,1,.3);
DrawQuad(-.35f,-.04f,-.35f,-.18f,.10f,-.18f,.10f,-.04f,1.0f,0.0f,0.0f);
DrawQuad(-.30f,-.11f,-.30f,-.06f,-.33f,-.06f,-.33f,-.11f,0.75f,0.50f,0.35f);
DrawQuad(-.27f,-.11f,-.27f,-.06f,-.24f,-.06f,-.24f,-.11f,0.75f,0.50f,0.35f);
DrawQuad(-.21f,-.11f,-.21f,-.06f,-.18f,-.06f,-.18f,-.11f,0.75f,0.50f,0.35f);
DrawQuad(-.15f,-.11f,-.15f,-.06f,-.12f,-.06f,-.12f,-.11f,0.75f,0.50f,0.35f);
DrawQuad(-.09f,-.11f,-.09f,-.06f,-.06f,-.06f,-.06f,-.11f,0.75f,0.50f,0.35f);
DrawQuad(-.03f,-.11f,-.03f,-.06f,-0.0f,-.06f,-0.0f,-.11f,0.75f,0.50f,0.35f);
DrawQuad(.03f,-.11f,.03f,-.06f,.06f,-.06f,.06f,-.11f,0.75f,0.50f,0.35f);
glColor3f(1.0f,1.f,1.0f);
DrawCircle(-.20,-.18,.03,200);
DrawCircle(0.0,-.18,.03,200);
//bus end
glPopMatrix();




glPopMatrix();
glPopMatrix();
glPushMatrix();

glPushMatrix();
glTranslated(positiontrack,.0f,0.0f);
DrawTriangle(.15,-.42,.05,-.47,.05,-.44,1,1,.3);
DrawTriangle(.15,-.40,.05,-.45,.05,-.42,1,1,.3);
//track right to left"
DrawQuad(.15f,-.33f,.15f,-.45f,.18f,-.45f,.18f,-.33f,1.0,0.0,0.0);
DrawQuad(.18f,-.36f,.18f,-.45f,.30f,-.45f,.30f,-.36f,1.0,0.0,0.0);
glColor3f(1.0f,1.f,1.0f);
DrawCircle(.18,-.45,.02,200);
DrawCircle(.25,-.45,.02,200);
glPopMatrix();


//end track
//car right to left:
glPushMatrix();
glTranslated(positioncar3,.0f,0.0f);
DrawTriangle(-.68,-.40,-.78,-.37,-.78,-.41,1,1,.3);
DrawTriangle(-.68,-.41,-.78,-.45,-.78,-.37,1,1,.3);
glBegin(GL_POLYGON);
glColor3f(1.0f,.50f,.0f);
      glVertex2f(-.60,-.35);
    glVertex2f(-.65,-.35);
    glVertex2f(-.70,-0.42);
    glVertex2f(-.40,-0.42);
    glVertex2f(-.40,-.35);
    glVertex2f(-.45,-.35);
    glVertex2f(-.50,-.31);
glEnd();
glColor3f(1.0f,1.f,1.0f);
DrawCircle(-.60,-.42,.03,200);
DrawCircle(-.45,-.42,.03,200);

glPopMatrix();
glPopMatrix();
//DrawQuad(-1.2,1.2,-1.2,-1.2,1.2,-1.2,1.2,1.2,0,0,0,.5);
}
void drawroadlampnight()
{

    DrawTriangle(-.87,.19,-.92,-.04,-.82,-.04,1,1,.9,.5);
    DrawTriangle(-.67,.19,-.72,-.04,-.62,-.04,1,1,.9,.5);
    DrawTriangle(-.47,.19,-.52,-.04,-.42,-.04,1,1,.9,.5);
    DrawTriangle(-.27,.19,-.32,-.04,-.22,-.04,1,1,.9,.5);
    DrawTriangle(-.07,.19,-.12,-.04,-.02,-.04,1,1,.9,.5);
    DrawTriangle(.07,.19,.12,-.04,.02,-.04,1,1,.9,.5);
    DrawTriangle(.27,.19,.32,-.04,.22,-.04,1,1,.9,.5);
    DrawTriangle(.47,.19,.52,-.04,.42,-.04,1,1,.9,.5);
    DrawTriangle(.67,.19,.72,-.04,.62,-.04,1,1,.9,.5);
    DrawTriangle(.87,.19,.92,-.04,.82,-.04,1,1,.9,.5);

     DrawTriangle(-.87,-.32,-.92,-.50,-.82,-.50,1,1,.9,.5);
    DrawTriangle(-.67,-.32,-.72,-.50,-.62,-.50,1,1,.9,.5);
    DrawTriangle(-.47,-.32,-.52,-.50,-.42,-.50,1,1,.9,.5);
    DrawTriangle(-.27,-.32,-.32,-.50,-.22,-.50,1,1,.9,.5);
    DrawTriangle(-.07,-.32,-.12,-.50,-.02,-.50,1,1,.9,.5);
    DrawTriangle(.07,-.32,.12,-.50,.02,-.50,1,1,.9,.5);
    DrawTriangle(.27,-.32,.32,-.50,.22,-.50,1,1,.9,.5);
    DrawTriangle(.47,-.32,.52,-.50,.42,-.50,1,1,.9,.5);
    DrawTriangle(.67,-.32,.72,-.50,.62,-.50,1,1,.9,.5);
    DrawTriangle(.87,-.32,.92,-.50,.82,-.50,1,1,.9,.5);
}
void Drawtrain()
{
    glPushMatrix();
glTranslatef(position,0.0f, 0.0f);

glBegin(GL_QUAD_STRIP);
      glColor3f(0.7f,0.4f,0.0f);
      glVertex2f(-0.8f, -0.76f);
      glVertex2f(0.02f, -0.76f);
      glVertex2f(-0.8f, -0.74f);
      glVertex2f(0.02f, -0.74f);
glEnd();

glBegin(GL_QUAD_STRIP);
      glColor3f(0.0f,0.3f,0.0f);
      glVertex2f(-0.88f, -0.86f);
      glVertex2f(-0.88f, -0.55f);

      glVertex2f(-0.68f, -0.86f);
      glVertex2f(-0.68f, -0.55f);

glEnd();

glBegin(GL_QUAD_STRIP);
      glColor3f(0.0f,0.3f,0.1f);
      glVertex2f(-0.58f, -0.86f);
      glVertex2f(-0.58f, -0.55f);

      glVertex2f(-0.38f, -0.86f);
      glVertex2f(-0.38f, -0.55f);

glEnd();
glBegin(GL_QUAD_STRIP);
      glColor3f(0.0f,0.3f,0.1f);
      glVertex2f(-0.28f, -0.86f);
      glVertex2f(-0.28f, -0.55f);

      glVertex2f(-0.08f, -0.86f);
      glVertex2f(-0.08f, -0.55f);

glEnd();

glBegin(GL_QUAD_STRIP);
      glColor3f(0.0f,0.3f,0.0f);

     glVertex2f(0.02f, -0.86f);
     glVertex2f(0.02f, -0.55f);

     glVertex2f(0.27f, -0.86f);
    glVertex2f(0.27f, -0.55f);

glEnd();

glBegin(GL_TRIANGLES);
      glColor3f(0.0f,0.3f,0.0f);

     glVertex2f(0.37f, -0.76f);
     glVertex2f(0.27f, -0.76f);
    glVertex2f(0.27f, -0.55f);

glEnd();
glBegin(GL_TRIANGLES);
      glColor3f(0.0f,0.4f,0.1f);

     glVertex2f(0.37f, -0.76f);
     glVertex2f(0.27f, -0.76f);
    glVertex2f(0.27f, -0.86f);

glEnd();
glBegin(GL_QUAD_STRIP);
      glColor3f(0.7f,1.0f,0.5f);

     glVertex2f(0.07f, -0.65f);
     glVertex2f(0.07f, -0.74f);

     glVertex2f(0.12f, -0.65f);
     glVertex2f(0.12f, -0.74f);

glEnd();

glBegin(GL_QUAD_STRIP);
      glColor3f(0.7f,1.0f,0.5f);

     glVertex2f(0.14f, -0.65f);
     glVertex2f(0.14f, -0.74f);

     glVertex2f(0.19f, -0.65f);
     glVertex2f(0.19f, -0.74f);

glEnd();

glBegin(GL_QUAD_STRIP);
      glColor3f(0.7f,1.0f,0.5f);

     glVertex2f(-0.11f, -0.65f);
     glVertex2f(-0.11f, -0.74f);

     glVertex2f(-0.17f, -0.65f);
     glVertex2f(-0.17f, -0.74f);

glEnd();

glBegin(GL_QUAD_STRIP);
      glColor3f(0.7f,1.0f,0.5f);

     glVertex2f(-0.22f, -0.65f);
     glVertex2f(-0.22f, -0.74f);

     glVertex2f(-0.26f, -0.65f);
     glVertex2f(-0.26f, -0.74f);

glEnd();

glBegin(GL_QUAD_STRIP);
      glColor3f(0.7f,1.0f,0.5f);

     glVertex2f(-0.41f, -0.65f);
     glVertex2f(-0.41f, -0.74f);

     glVertex2f(-0.47f, -0.65f);
     glVertex2f(-0.47f, -0.74f);

glEnd();


glBegin(GL_QUAD_STRIP);
      glColor3f(0.7f,1.0f,0.5f);

     glVertex2f(-0.52f, -0.65f);
     glVertex2f(-0.52f, -0.74f);

     glVertex2f(-0.56f, -0.65f);
     glVertex2f(-0.56f, -0.74f);

glEnd();

glBegin(GL_QUAD_STRIP);
      glColor3f(0.7f,1.0f,0.5f);

     glVertex2f(-0.71f, -0.65f);
     glVertex2f(-0.71f, -0.74f);

     glVertex2f(-0.77f, -0.65f);
     glVertex2f(-0.77f, -0.74f);
glEnd();
glBegin(GL_QUAD_STRIP);
      glColor3f(0.7f,1.0f,0.5f);

     glVertex2f(-0.82f, -0.65f);
     glVertex2f(-0.82f, -0.74f);

     glVertex2f(-0.86f, -0.65f);
     glVertex2f(-0.86f, -0.74f);
glEnd();
//////////////////////////

////////////////


DrawCircle(0.07f, -0.86f,0.03,45);
DrawCircle(0.18f, -0.86f,0.03,45);
DrawCircle(-0.14f, -0.86f,0.03,45);
DrawCircle(-0.234f, -0.86f,0.03,45);
DrawCircle(-0.535f, -0.86f,0.03,45);
DrawCircle(-0.435f, -0.86f,0.03,45);
DrawCircle(-0.838f, -0.86f,0.03,45);
DrawCircle(-0.738f, -0.86f,0.03,45);
/////////////
DrawCircle(0.283f, -0.65f, 0.02,5);

//DrawQuad(0.01,-0.55,0.01,-0.33,0.17,-0.55,0.17,-0.33,0.33,0.34,0.45);
glPopMatrix();

}
void display() {

   glClear(GL_COLOR_BUFFER_BIT);
   //glClearColor(0.8f, 1.0f, 0.9f, 1.0f);
   glLoadIdentity();

if (!night)
    {
        drawSky();
        drawsun();

   drawBuilding();
}
else{

        if (!rainday){
            drawskynight();

            drawstar();
            drawmoon();
            drawbuildingnight();

        }
        else {
        drawskynight();
        }


}

   glPushMatrix();

   glPopMatrix();
   //highway
 glPushMatrix();
 DrawQuad(-.89,0.0,-.90,0.0,-.90,.20,-.89,.20,.5,0.0,.0);
 DrawQuad(-.90,0.20,-.90,0.21,-.87,.21,-.87,.20,.5,0.0,.0);
 DrawTriangle(-.87,.20,-.88,.19,-.86,.19,1,1,.9);

  DrawQuad(-.69,0.0,-.70,0.0,-.70,.20,-.69,.20,.5,0.0,.0);
 DrawQuad(-.70,0.20,-.70,0.21,-.67,.21,-.67,.20,.5,0.0,.0);
 DrawTriangle(-.67,.20,-.68,.19,-.66,.19,1,1,.9);

  DrawQuad(-.49,0.0,-.50,0.0,-.50,.20,-.49,.20,.5,0.0,.0);
 DrawQuad(-.50,0.20,-.50,0.21,-.47,.21,-.47,.20,.5,0.0,.0);
 DrawTriangle(-.47,.20,-.48,.19,-.46,.19,1,1,.9);

  DrawQuad(-.29,0.0,-.30,0.0,-.30,.20,-.29,.20,.5,0.0,.0);
 DrawQuad(-.30,0.20,-.30,0.21,-.27,.21,-.27,.20,.5,0.0,.0);
 DrawTriangle(-.27,.20,-.28,.19,-.26,.19,1,1,.9);

 DrawQuad(-.09,0.0,-.10,0.0,-.10,.20,-.09,.20,.5,0.0,.0);
 DrawQuad(-.10,0.20,-.10,0.21,-.07,.21,-.07,.20,.5,0.0,.0);
 DrawTriangle(-.07,.20,-.08,.19,-.06,.19,1,1,.9);

 DrawQuad(.09,0.0,.10,0.0,.10,.20,.09,.20,.5,0.0,.0);
 DrawQuad(.10,0.20,.10,0.21,.07,.21,.07,.20,.5,0.0,.0);
 DrawTriangle(.07,.20,.08,.19,.06,.19,1,1,.9);

 DrawQuad(.29,0.0,.30,0.0,.30,.20,.29,.20,.5,0.0,.0);
 DrawQuad(.30,0.20,.30,0.21,.27,.21,.27,.20,.5,0.0,.0);
 DrawTriangle(.27,.20,.28,.19,.26,.19,1,1,.9);

 DrawQuad(-.29,0.0,-.30,0.0,-.30,.20,-.29,.20,.5,0.0,.0);
 DrawQuad(-.30,0.20,-.30,0.21,-.27,.21,-.27,.20,.5,0.0,.0);
 DrawTriangle(-.27,.20,-.28,.19,-.26,.19,1,1,.9);

  DrawQuad(.49,0.0,.50,0.0,.50,.20,.49,.20,.5,0.0,.0);
 DrawQuad(.50,0.20,.50,0.21,.47,.21,.47,.20,.5,0.0,.0);
 DrawTriangle(.47,.20,.48,.19,.46,.19,1,1,.9);

  DrawQuad(.69,0.0,.70,0.0,.70,.20,.69,.20,.5,0.0,.0);
 DrawQuad(.70,0.20,.70,0.21,.67,.21,.67,.20,.5,0.0,.0);
 DrawTriangle(.67,.20,.68,.19,.66,.19,1,1,.9);

 DrawQuad(.89,0.0,.90,0.0,.90,.20,.89,.20,.5,0.0,.0);
 DrawQuad(.90,0.20,.90,0.21,.87,.21,.87,.20,.5,0.0,.0);
 DrawTriangle(.87,.20,.88,.19,.86,.19,1,1,.9);
//roadlamp end
DrawQuad(-1.2f,0.0f,1.2f,0.0f,1.2f,-0.50f,-1.2f,-0.50,0.169f,0.169f,0.169f);
DrawQuad(-1.05f,-0.23f,-0.95f,-0.23f,-0.95f,-0.28f,-1.05f,-0.28f,1.0f,1.0f,1.0f);
DrawQuad(-.85f,-0.23f,-0.75f,-0.23f,-0.75f,-0.28f,-0.85f,-0.28,1.0f,1.0f,1.0f);
DrawQuad(-.65f,-0.23f,-0.55f,-0.23f,-0.55f,-0.28f,-0.65f,-0.28,1.0f,1.0f,1.0f);
DrawQuad(-.45f,-0.23f,-0.35f,-0.23f,-0.35f,-0.28f,-0.45f,-0.28,1.0f,1.0f,1.0f);
DrawQuad(-.25f,-0.23f,-0.15f,-0.23f,-0.15f,-0.28f,-0.25f,-0.28,1.0f,1.0f,1.0f);
DrawQuad(-.05f,-0.23f,0.05f,-0.23f,0.05f,-0.28f,-0.05f,-0.28,1.0f,1.0f,1.0f);
DrawQuad(.15f,-0.23f,0.25f,-0.23f,0.25f,-0.28f,0.15f,-0.28,1.0f,1.0f,1.0f);
DrawQuad(.35f,-0.23f,0.45f,-0.23f,0.45f,-0.28f,0.35f,-0.28,1.0f,1.0f,1.0f);
DrawQuad(.55f,-0.23f,0.65f,-0.23f,0.65f,-0.28f,0.55f,-0.28,1.0f,1.0f,1.0f);
DrawQuad(.75f,-0.23f,0.85f,-0.23f,0.85f,-0.28f,0.75f,-0.28,1.0f,1.0f,1.0f);
DrawQuad(-1.0f,0.0,-1.0f,0.05f,-.90f, .05f,-.90f, 0.0f,1.0f,1.0f,1.0f);
DrawQuad(-.90f,0.0,-.90f,0.05f,-.80f, .05f,-.80f, 0.0f,1.0f,1.0f,0.0f);
DrawQuad(-.80f,0.0,-.80f,0.05f,-.70f, .05f,-.70f, 0.0f,1.0f,1.0f,1.0f);
DrawQuad(-.70f,0.0,-.70f,0.05f,-.60f, .05f,-.60f, 0.0f,1.0f,1.0f,0.0f);
DrawQuad(-.60f,0.0,-.60f,0.05f,-.50f, .05f,-.50f, 0.0f,1.0f,1.0f,1.0f);
DrawQuad(-.50f,0.0,-.50f,0.05f,-.40f, .05f,-.40f, 0.0f,1.0f,1.0f,0.0f);
DrawQuad(-.40f,0.0,-.40f,0.05f,-.30f, .05f,-.30f, 0.0f,1.0f,1.0f,1.0f);
DrawQuad(-.30f,0.0,-.30f,0.05f,-.20f, .05f,-.20f, 0.0f,1.0f,1.0f,0.0f);
DrawQuad(-.20f,0.0,-.20f,0.05f,-.10f, .05f,-.10f, 0.0f,1.0f,1.0f,1.0f);
DrawQuad(-.10f,0.0,-.10f,0.05f,.00f, .05f,0.0f, 0.0f,1.0f,1.0f,0.0f);
DrawQuad(0.00f,0.0,.00f,0.05f,.10f, .05f,.10f, 0.0f,1.0f,1.0f,1.0f);
DrawQuad(.10f,0.0,.10f,0.05f,.20f, .05f,.20f, 0.0f,1.0f,1.0f,0.0f);
DrawQuad(.20f,0.0,.20f,0.05f,.30f, .05f,.30f, 0.0f,1.0f,1.0f,1.0f);
DrawQuad(.30f,0.0,.30f,0.05f,.40f, .05f,.40f, 0.0f,1.0f,1.0f,0.0f);
DrawQuad(.40f,0.0,.40f,0.05f,.50f, .05f,.50f, 0.0f,1.0f,1.0f,1.0f);
DrawQuad(.50f,0.0,.50f,0.05f,.60f, .05f,.60f, 0.0f,1.0f,1.0f,0.0f);
DrawQuad(.60f,0.0,.60f,0.05f,.70f, .05f,.70f, 0.0f,1.0f,1.0f,1.0f);
DrawQuad(.70f,0.0,.70f,0.05f,.80f, .05f,.80f, 0.0f,1.0f,1.0f,0.0f);
DrawQuad(.80f,0.0,.80f,0.05f,.90f, .05f,.90f, 0.0f,1.0f,1.0f,1.0f);
DrawQuad(.90f,0.0,.90f,0.05f,1.00f, .05f,1.0f, 0.0f,1.0f,1.0f,0.0f);


DrawQuad(-1.0f,-0.50,-1.0f,-0.55f,-.90f, -.55f,-.90f, -0.50f,1.0f,1.0f,1.0f);
DrawQuad(-.90f,-0.50,-.90f,-0.55f,-.80f, -.55f,-.80f,- 0.50f,1.0f,1.0f,0.0f);
DrawQuad(-.80f,-0.50,-.80f,-0.55f,-.70f, -0.55f,-.70f, -0.50f,1.0f,1.0f,1.0f);
DrawQuad(-.70f,-0.50,-.70f,-0.55f,-.60f, -0.55f,-.60f, -0.50f,1.0f,1.0f,0.0f);
DrawQuad(-.60f,-0.50,-.60f,-0.55f,-.50f, -0.55f,-.50f,-0.50f,1.0f,1.0f,1.0f);
DrawQuad(-.50f,-0.50,-.50f,-0.55f,-.40f, -0.55f,-.40f,-0.50f,1.0f,1.0f,0.0f);
DrawQuad(-.40f,-0.50,-.40f,-0.55f,-.30f, -0.55f,-.30f,-0.50f,1.0f,1.0f,1.0f);
DrawQuad(-.30f,-0.50,-.30f,-0.55f,-.20f, -0.55f,-.20f, -0.50f,1.0f,1.0f,0.0f);
DrawQuad(-.20f,-0.50,-.20f,-0.55f,-.10f, -0.55f,-.10f,-0.50f,1.0f,1.0f,1.0f);
DrawQuad(-.10f,-0.50,-.10f,-0.55f,.00f, -0.55f,0.0f, -0.50f,1.0f,1.0f,0.0f);
DrawQuad(0.00f,-0.50,.00f,-0.55f,.10f, -0.55f,.10f, -0.50,1.0f,1.0f,1.0f);
DrawQuad(.10f,-0.50,.10f,-0.55f,.20f, -0.55f,.20f,-0.50,1.0f,1.0f,0.0f);
DrawQuad(.20f,-0.50,.20f,-0.55f,.30f, -0.55f,.30f,-0.50,1.0f,1.0f,1.0f);
DrawQuad(.30f,-0.50,.30f,-0.55f,.40f, -0.55f,.40f,-0.50,1.0f,1.0f,0.0f);
DrawQuad(.40f,-0.50,.40f,-0.55f,.50f, -0.55f,.50f, -0.50,1.0f,1.0f,1.0f);
DrawQuad(.50f,-0.50,.50f,-0.55f,.60f, -0.55f,.60f,-0.50,1.0f,1.0f,0.0f);
DrawQuad(.60f,-0.50,.60f,-0.55f,.70f,-0.55f,.70f, -0.50,1.0f,1.0f,1.0f);
DrawQuad(.70f,-0.50,.70f,-0.55f,.80f, -0.55f,.80f, -0.50,1.0f,1.0f,0.0f);
DrawQuad(.80f,-0.50,.80f,-0.55f,.90f, -0.55f,.90f, -0.50,1.0f,1.0f,1.0f);
DrawQuad(.90f,-0.50,.90f,-0.55f,1.00f,-0.55f,1.0f, -0.50,1.0f,1.0f,0.0f);

glPopMatrix();

if (!night)
{

    Drawvhiclesday();
}
else
{

Drawvhiclesnight();
drawroadlampnight();
 //drawskynight();
}
glPushMatrix();

 DrawQuad(-.89,-0.55,-.90,-0.55,-.90,-.30,-.89,-.30,.5,0.0,.0);
 DrawQuad(-.90,-0.30,-.90,-0.31,-.87,-.31,-.87,-.30,.5,0.0,.0);
 DrawTriangle(-.87,-.31,-.88,-.32,-.86,-.32,1,1,.9);

  DrawQuad(-.69,-0.55,-.70,-0.55,-.70,-.30,-.69,-.30,.5,0.0,.0);
 DrawQuad(-.70,-.30,-.70,-0.31,-.67,-.31,-.67,-.30,.5,0.0,.0);
 DrawTriangle(-.67,-.31,-.68,-.32,-.66,-.32,1,1,.9);

  DrawQuad(-.49,-0.55,-.50,-0.55,-.50,-.30,-.49,-.30,.5,0.0,.0);
 DrawQuad(-.50,-.30,-.50,-.31,-.47,-.31,-.47,-.30,.5,0.0,.0);
 DrawTriangle(-.47,-.31,-.48,-.32,-.46,-.32,1,1,.9);

  DrawQuad(-.29,-0.55,-.30,-0.55,-.30,-.30,-.29,-.30,.5,0.0,.0);
 DrawQuad(-.30,-0.30,-.30,-0.31,-.27,-.31,-.27,-.30,.5,0.0,.0);
 DrawTriangle(-.27,-.31,-.28,-.32,-.26,-.32,1,1,.9);

 DrawQuad(-.09,-0.55,-.10,-0.55,-.10,-.30,-.09,-.30,.5,0.0,.0);
 DrawQuad(-.10,-.30,-.10,-0.31,-.07,-.31,-.07,-.30,.5,0.0,.0);
 DrawTriangle(-.07,-.31,-.08,-.32,-.06,-.32,1,1,.9);


DrawQuad(.09,-0.55,.10,-0.55,.10,-.30,.09,-.30,.5,0.0,.0);
 DrawQuad(.10,-0.30,.10,-0.31,.07,-.31,.07,-.30,.5,0.0,.0);
 DrawTriangle(.07,-.31,.08,-.32,.06,-.32,1,1,.9);

 DrawQuad(.29,-0.55,.30,-0.55,.30,-.30,.29,-.30,.5,0.0,.0);
 DrawQuad(.30,-.30,.30,-.31,.27,-.31,.27,-.30,.5,0.0,.0);
 DrawTriangle(.27,-.31,.28,-.32,.26,-.32,1,1,.9);

  DrawQuad(.49,-0.55,.50,-0.55,.50,-.30,.49,-.30,.5,0.0,.0);
 DrawQuad(.50,-.30,.50,-.31,.47,-.31,.47,-.30,.5,0.0,.0);
 DrawTriangle(.47,-.31,.48,-.32,.46,-.32,1,1,.9);

  DrawQuad(.69,-0.55,.70,-0.55,.70,-.30,.69,-.30,.5,0.0,.0);
 DrawQuad(.70,-.30,.70,-.31,.67,-.31,.67,-.30,.5,0.0,.0);
 DrawTriangle(.67,-.31,.68,-.32,.66,-.32,1,1,.9);

 DrawQuad(.89,-0.55,.90,-0.55,.90,-.30,.89,-.30,.5,0.0,.0);
 DrawQuad(.90,-.30,.90,-.31,.87,-.31,.87,-.30,.5,0.0,.0);
 DrawTriangle(.87,-.31,.88,-.32,.86,-.32,1,1,.9);
//roadlamp end

glPopMatrix();
glPushMatrix();
glBegin(GL_LINE_STRIP);
      glColor3f(1.0f,1.0f,0.9f);
      glVertex2f(-1.0f, -0.5f);
      glVertex2f(1.0f, -0.5f);
glEnd();

glBegin(GL_LINES);
for(float i=-0.9f;i<1.0f;i=i+0.1f)
{

      glColor3f(1.0f,1.0f,0.9f);
      glVertex2f(i , -0.76f);
      glVertex2f(i, -0.95f);

}
glEnd();
///////////////////////




glBegin(GL_QUAD_STRIP);
      glColor3f(1.0f,1.0f,0.9f);
      glVertex2f(-1.0f, -0.95f);
      glVertex2f(1.0f, -0.95f);
      glVertex2f(-1.0f, -0.91f);
      glVertex2f(1.0f, -0.91f);
glEnd();

glBegin(GL_QUAD_STRIP);
      glColor3f(1.0f,1.0f,0.9f);
      glVertex2f(-1.0f, -0.76f);
      glVertex2f(1.0f, -0.76f);

      glVertex2f(-1.0f, -0.72f);
      glVertex2f(1.0f, -0.72f);
glEnd();







////////////

glBegin(GL_LINES);
      glColor3f(1.0f,1.0f,0.9f);
    //  glVertex2f(-1.0f, -0.86f);
 //     glVertex2f(1.0f, -0.86f);
glEnd();
///////
glPopMatrix();
Drawtrain();
if (night)
{
    DrawQuad(-1.2,1.2,-1.2,-1.2,1.2,-1.2,1.2,1.2,0,0,0,.3);
}

if (rainday)
 {

     if (night){
     drawskynight();
     drawbuildingnight();
      Drawvhiclesnight();
     drawroadlampnight();


     drawrain();
     DrawQuad(-1.2,1.2,-1.2,-1.2,1.2,-1.2,1.2,1.2,0,0,0,.3);
     }
     else {
    drawSky();
    drawBuilding();
    Drawvhiclesnight();
//drawroadlampnight();
     drawrain();
     DrawQuad(-1.2,1.2,-1.2,-1.2,1.2,-1.2,1.2,1.2,0,0,0,.3);
     }
 }


   glFlush();

}

void upsun(int x)
{
    if(positionsun >= .75)
    {
         positionsun = positionsun;
    }
 else {
    positionsun+= speedsun;
 }

 glutPostRedisplay();
 glutTimerFunc(100, upsun, 0);

}
void downsun(int x)
{
    if(positionsun <=.0)
    {
         positionsun = -2.0;
    }
 else {
    positionsun-= speedsun;
 }

 glutPostRedisplay();
 glutTimerFunc(100, downsun, 0);

}

void upmoon(int x)
{
    if(positionmoon >= .85)
    {
         positionmoon = positionmoon;
    }
 else {
    positionmoon+= speedmoon;
 }

 glutPostRedisplay();
 glutTimerFunc(100, upmoon, 0);

}
void downmoon(int x)
{
    if(positionmoon <=.0)
    {
         positionmoon = -2.0;
    }
 else {
    positionmoon-= speedmoon;
 }

 glutPostRedisplay();
 glutTimerFunc(100, downmoon, 0);

}


void updatecar1()
{
    if(positioncar1 >= 2)
        positioncar1 = -1.5f;
    positioncar1 += speedcar1;

}
void updatecar3()
{
    if(positioncar3<= -1.5)
        positioncar3 = 1.5f;
    positioncar3 -= speedcar3;

}
void updattrack()
{
    if(positiontrack<= -1.5)
        positiontrack = 1.5f;
    positiontrack -= speedtrack;

}
void updaterocket()
{
    if(positionrocket >= 2)
        positionrocket = -1.5f;
    positionrocket += speedrocket;

}
void updateplane()
{
    if(positionplane >= 2)
        positionplane = -1.5f;
    positionplane += speedplane;

}
void updaterocket(int value) {
 updaterocket();
 updateplane();
 glutPostRedisplay();
 glutTimerFunc(100, updaterocket, 0);
}
void updatcar2()
{
    if(positioncar2>=1.5)
        positioncar2=-1.7f;
    positioncar2 += speedcar2;
}
void updatbus(){
   if(positionbus1>=2)
        positionbus1=-1.7f;
    positionbus1 += speedbus1;
}


void updatecar(int value) {
 updatecar1();
 updatcar2();
 updatbus();
 updatecar3();
updattrack();
	glutPostRedisplay();
glutTimerFunc(50, updatecar, 0);
}
void update(int value) {

    if(position > 2.0)
        position = -1.2f;

    position += speed;
    //if(position== -0.08f)
    //{
    //    position = 0.0f;
    //}
	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}
void update1(int value) {

    if(position1 > 1.0)
        position1 = -0.08f;

    position1 += speed1;
    /*if(position1==0.08f)
    {
        position = 0.0f;
    }*/
	glutPostRedisplay();


	glutTimerFunc(100, update1, 0);
}
void updatecloud1()
{
    if(positioncloud1>= 1.5)
        positioncloud1 = -1.2f;
    positioncloud1+= speedcloud1;

}
void updatecloud2()
{
    if(positioncloud2>= 1.5)
        positioncloud2 = -1.2f;
    positioncloud2+= speedcloud2;

}
void updatecloud3()
{
    if(positioncloud3>= 1.5)
        positioncloud3 = -1.2f;
    positioncloud3+= speedcloud3;

}
void movecloud(int x)
{
    updatecloud1();
    updatecloud2();
    updatecloud3();
    glutPostRedisplay();


	glutTimerFunc(100, movecloud, 0);

}
void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
}



void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {
	    case 'r':
        rainday = true;

       // Rain(_rain);
        //sndPlaySound("rain.wav",SND_ASYNC|SND_LOOP);
        //sndPlaySound("River.wav",SND_MEMORY|SND_ASYNC);
        break;

    case 'e':
        rainday = false;
        if (!night){
          //sndPlaySound("cars.wav",SND_ASYNC|SND_LOOP);
        }
		else {
             //sndPlaySound("night.wav",SND_ASYNC|SND_LOOP);
		}
        break;

    case 'n':
        night = true;
        //downsun(0);
        upmoon(0);
        positionsun=0;
         if(!rainday){
        //sndPlaySound("night.wav",SND_ASYNC|SND_LOOP);
        }else {
        //sndPlaySound("rain.wav",SND_ASYNC|SND_LOOP);
        }

        //sndPlaySound("cars.wav",SND_ASYNC|SND_LOOP);
        break;
case 'd':
        night = false;
        upsun(0);
        positionmoon=0;
        if(!rainday){
        //sndPlaySound("cars.wav",SND_ASYNC|SND_LOOP);
        }else {
        //sndPlaySound("rain.wav",SND_ASYNC|SND_LOOP);
        }
        //sndPlaySound("train.wav",SND_ASYNC|SND_LOOP);
        break;
case 'w':
    speed -= 0.01f;
    break;
case 'a':
    speed += 0.01f;
    break;
    case 's':
    speed = 0.0f;
    break;


glutPostRedisplay();


	}
}


int main(int argc, char** argv) {
    cout <<"press d for day mode "<<endl;
    cout<<"press n for night mode "<<endl;
    cout<<"press r for rain mode"<<endl;
    cout<<"press e for exit rain mode"<<endl;
    cout <<"press a to speed up the train"<<endl;
    cout<<"press w to speed down the train"<<endl;
    cout<<"press s to stop the train"<<endl;
   glutInit(&argc, argv);
   glutInitWindowSize(1200, 600);
   glutInitWindowPosition(50, 50);
   glutCreateWindow(" City & Highway Scenarios ");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   //glutMouseFunc(handleMouse);
   glutTimerFunc(100, updatecar, 0);
    glutTimerFunc(100, movecloud, 0);
    glutTimerFunc(1000, update, 0);
   glutTimerFunc(1000, update1, 0);
   glutTimerFunc(100, updaterocket, 0);
   glutTimerFunc(100, upsun, 0);
   //sndPlaySound("cars.wav",SND_ASYNC|SND_LOOP);
   //sndPlaySound("train.wav",SND_ASYNC|SND_LOOP);
  //glutTimerFunc(100, Rain, 0);
   glutMainLoop();
   return 0;
}

