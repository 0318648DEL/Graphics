#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gl/freeglut.h>
#include <gl/glut.h>

#define WIDTH 800
#define HEIGHT 600

struct cam
{
	float x;
	float y;
	float z;
	float rx;
	float ry;
	float rz;
};

float sphere1_angle = 0.0f;
float sphere2_angle = 0.0f;
float sphere3_angle = 0.0f;

void SetupRC();
void DrawScene();
void Reshape(int w, int h);
//void Keyboard(unsigned char key, int x, int y);
void TimerFunction(int value);
cam cam_rotate = { 0, };

GLUquadricObj *sph1;
GLUquadricObj *sph2;
GLUquadricObj *sph3;
GLUquadricObj *sph4;
GLUquadricObj *ring1;
GLUquadricObj *ring2;
GLUquadricObj *ring3;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Practice16");

	SetupRC();

	sph1 = gluNewQuadric();
	sph2 = gluNewQuadric();
	sph3 = gluNewQuadric();
	sph4 = gluNewQuadric();
	ring1 = gluNewQuadric();
	ring2 = gluNewQuadric();
	ring3 = gluNewQuadric();
	glutDisplayFunc(DrawScene);
	glutReshapeFunc(Reshape);
	//glutKeyboardFunc(Keyboard);
	glutTimerFunc(100, TimerFunction, 1);

	glutMainLoop();
}

void SetupRC()
{

}

void DrawScene()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glColor4ub(150, 100, 50, 200);
	gluQuadricDrawStyle(sph1, GLU_FILL);
	gluQuadricNormals(sph1, GLU_SMOOTH);
	gluQuadricOrientation(sph1, GLU_OUTSIDE);
	gluSphere(sph1, 50, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(0, 0, 0, 256);
	gluQuadricDrawStyle(ring1, GLU_FILL);
	gluQuadricNormals(ring1, GLU_SMOOTH);
	gluQuadricOrientation(ring1, GLU_OUTSIDE);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluDisk(ring1, 78, 80, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(250, 200, 250, 200);
	gluQuadricDrawStyle(sph2, GLU_FILL);
	gluQuadricNormals(sph2, GLU_SMOOTH);
	gluQuadricOrientation(sph2, GLU_OUTSIDE);
	glRotatef(sphere1_angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(80.0f, 0.0f, 0.0f);
	gluSphere(sph2, 5, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(0, 0, 0, 256);
	gluQuadricDrawStyle(ring2, GLU_FILL);
	gluQuadricNormals(ring2, GLU_SMOOTH);
	gluQuadricOrientation(ring2, GLU_OUTSIDE);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	gluDisk(ring1, 78, 80, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(200, 200, 50, 200);
	gluQuadricDrawStyle(sph3, GLU_FILL);
	gluQuadricNormals(sph3, GLU_SMOOTH);
	gluQuadricOrientation(sph3, GLU_OUTSIDE);
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(sphere2_angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(80.0f, 0.0f, 0.0f);
	gluSphere(sph3, 5, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(0, 0, 0, 256);
	gluQuadricDrawStyle(ring3, GLU_FILL);
	gluQuadricNormals(ring3, GLU_SMOOTH);
	gluQuadricOrientation(ring3, GLU_OUTSIDE);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
	gluDisk(ring3, 78, 80, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(200, 100, 50, 200);
	gluQuadricDrawStyle(sph4, GLU_FILL);
	gluQuadricNormals(sph4, GLU_SMOOTH);
	gluQuadricOrientation(sph4, GLU_OUTSIDE);
	glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(sphere3_angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(80.0f, 0.0f, 0.0f);
	gluSphere(sph4, 5, 50, 50);
	glPopMatrix();

	glutSwapBuffers();
}

void Reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60.0, WIDTH / HEIGHT, 1.0, 1000.0);
	glTranslatef(0.0, 0.0, -300.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void TimerFunction(int value)
{
	sphere1_angle += 2.0f;
	sphere2_angle += 4.0f;
	sphere3_angle += 10.0f;

	glutPostRedisplay();

	glutTimerFunc(100, TimerFunction, 1);
}