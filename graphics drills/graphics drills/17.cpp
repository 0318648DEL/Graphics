#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <gl/freeglut.h>
#include <gl/glut.h>

#define WIDTH 800
#define HEIGHT 600
#define PI 3.1415926

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
float sphere4_angle = 0.0f;
float sphere5_angle = 0.0f;
float sphere6_angle = 0.0f;

float camera_x = 0.0f;
float camera_y = 200.0f;
float camera_z = -300.0f;
double camera_angle_x = 0.0;
double camera_angle_y = 0.0;
double camera_angle_z = 0.0;
float theta;
float phi;
double radius = sqrt(pow(camera_y, 2.0) + pow(camera_z, 2.0));

int draw_mode = GLU_FILL;

void SetupRC();
void DrawScene();
void Reshape(int w, int h);
void Keyboard(unsigned char key, int x, int y);
void TimerFunction(int value);
cam cam_rotate = { 0, };

GLUquadricObj *sph1;
GLUquadricObj *sph2;
GLUquadricObj *sph3;
GLUquadricObj *sph4;
GLUquadricObj *sph5;
GLUquadricObj *sph6;
GLUquadricObj *sph7;
GLUquadricObj *ring1;
GLUquadricObj *ring2;
GLUquadricObj *ring3;
GLUquadricObj *ring4;
GLUquadricObj *ring5;
GLUquadricObj *ring6;

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
	sph5 = gluNewQuadric();
	sph6 = gluNewQuadric();
	sph7 = gluNewQuadric();
	ring1 = gluNewQuadric();
	ring2 = gluNewQuadric();
	ring3 = gluNewQuadric();
	ring4 = gluNewQuadric();
	ring5 = gluNewQuadric();
	ring6 = gluNewQuadric();
	glutDisplayFunc(DrawScene);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutTimerFunc(10, TimerFunction, 1);

	glutMainLoop();
}

void SetupRC()
{
	glEnable(GL_DEPTH_TEST);  // 은면 제거
	glFrontFace(GL_CCW);   // 앞면 설정  
	//glEnable(GL_CULL_FACE);  // 내부는 잘라낸다  
	glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
}

void DrawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camera_x, camera_y, camera_z, camera_x, camera_y-200, camera_z+300, 0.0, 0.0, 1.0);
	glRotatef(camera_angle_x, 1.0f, 0.0f, 0.0f);
	glRotatef(camera_angle_y, 0.0f, 1.0f, 0.0f);
	glRotatef(camera_angle_z, 0.0f, 0.0f, 1.0f);

	glPushMatrix();
	glColor4ub(150, 100, 50, 200);
	gluQuadricDrawStyle(sph1, draw_mode);
	gluQuadricNormals(sph1, GLU_SMOOTH);
	gluQuadricOrientation(sph1, GLU_OUTSIDE);
	gluSphere(sph1, 80, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(0, 0, 0, 256);
	gluQuadricDrawStyle(ring1, GLU_FILL);
	gluQuadricNormals(ring1, GLU_SMOOTH);
	gluQuadricOrientation(ring1, GLU_OUTSIDE);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluDisk(ring1, 128, 130, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(250, 200, 250, 200);
	gluQuadricDrawStyle(sph2, draw_mode);
	gluQuadricNormals(sph2, GLU_SMOOTH);
	gluQuadricOrientation(sph2, GLU_OUTSIDE);
	glRotatef(sphere1_angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(129.0f, 0.0f, 0.0f);
	gluSphere(sph2, 25, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(0, 0, 0, 256);
	gluQuadricDrawStyle(ring2, GLU_FILL);
	gluQuadricNormals(ring2, GLU_SMOOTH);
	gluQuadricOrientation(ring2, GLU_OUTSIDE);
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluDisk(ring2, 128, 130, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(200, 200, 50, 200);
	gluQuadricDrawStyle(sph3, draw_mode);
	gluQuadricNormals(sph3, GLU_SMOOTH);
	gluQuadricOrientation(sph3, GLU_OUTSIDE);
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(sphere2_angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(129.0f, 0.0f, 0.0f);
	gluSphere(sph3, 25, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(0, 0, 0, 256);
	gluQuadricDrawStyle(ring3, GLU_FILL);
	gluQuadricNormals(ring3, GLU_SMOOTH);
	gluQuadricOrientation(ring3, GLU_OUTSIDE);
	glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluDisk(ring3, 128, 130, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(200, 100, 50, 200);
	gluQuadricDrawStyle(sph4, draw_mode);
	gluQuadricNormals(sph4, GLU_SMOOTH);
	gluQuadricOrientation(sph4, GLU_OUTSIDE);
	glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(sphere3_angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(129.0f, 0.0f, 0.0f);
	gluSphere(sph4, 25, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(250, 100, 50, 200);
	gluQuadricDrawStyle(sph5, draw_mode);
	gluQuadricNormals(sph5, GLU_SMOOTH);
	gluQuadricOrientation(sph5, GLU_OUTSIDE);
	glRotatef(sphere1_angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(129.0f, 0.0f, 0.0f);
	glRotatef(sphere4_angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(40.0f, 0.0f, 0.0f);
	gluSphere(sph5, 10, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(0, 0, 0, 256);
	gluQuadricDrawStyle(ring4, GLU_FILL);
	gluQuadricNormals(ring4, GLU_SMOOTH);
	gluQuadricOrientation(ring4, GLU_OUTSIDE);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(sphere1_angle, 0.0f, 0.0f, -1.0f);
	glTranslatef(129.0f, 0.0f, 0.0f);
	gluDisk(ring4, 40, 42, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(250, 190, 50, 200);
	gluQuadricDrawStyle(sph6, draw_mode);
	gluQuadricNormals(sph6, GLU_SMOOTH);
	gluQuadricOrientation(sph6, GLU_OUTSIDE);
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(sphere2_angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(129.0f, 0.0f, 0.0f);
	glRotatef(sphere2_angle, 0.0f, -1.0f, 0.0f);
	glRotatef(45.0f, 0.0f, 0.0f, -1.0f);
	glRotatef(sphere5_angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(40.0f, 0.0f, 0.0f);
	gluSphere(sph6, 10, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(0, 0, 0, 256);
	gluQuadricDrawStyle(ring5, GLU_FILL);
	gluQuadricNormals(ring5, GLU_SMOOTH);
	gluQuadricOrientation(ring5, GLU_OUTSIDE);
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(sphere2_angle, 0.0f, 0.0f, -1.0f);
	glTranslatef(129.0f, 0.0f, 0.0f);
	glRotatef(sphere2_angle, 0.0f, 0.0f, 1.0f);
	glRotatef(45.0f, 0.0f, -1.0f, 0.0f);
	gluDisk(ring5, 40, 42, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(250, 190, 50, 200);
	gluQuadricDrawStyle(sph7, draw_mode);
	gluQuadricNormals(sph7, GLU_SMOOTH);
	gluQuadricOrientation(sph7, GLU_OUTSIDE);
	glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(sphere3_angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(129.0f, 0.0f, 0.0f);
	glRotatef(sphere3_angle, 0.0f, -1.0f, 0.0f);
	glRotatef(-45.0f, 0.0f, 0.0f, -1.0f);
	glRotatef(sphere6_angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(40.0f, 0.0f, 0.0f);
	gluSphere(sph7, 10, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(0, 0, 0, 256);
	gluQuadricDrawStyle(ring6, GLU_FILL);
	gluQuadricNormals(ring6, GLU_SMOOTH);
	gluQuadricOrientation(ring6, GLU_OUTSIDE);
	glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(sphere3_angle, 0.0f, 0.0f, -1.0f);
	glTranslatef(129.0f, 0.0f, 0.0f);
	glRotatef(sphere3_angle, 0.0f, 0.0f, 1.0f);
	glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
	gluDisk(ring6, 40, 42, 50, 50);
	glPopMatrix();

	glutSwapBuffers();
}

void Reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60.0, WIDTH / HEIGHT, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'c':
		if (draw_mode == GLU_FILL)
		{
			draw_mode = GLU_LINE;
		}
		else
			draw_mode = GLU_FILL;
		break;
	case 'w':
		camera_y += 1.0f;
		break;
	case 'a':
		camera_x += 1.0f;
		break;
	case 's':
		camera_y -= 1.0f;
		break;
	case 'd':
		camera_x -= 1.0f;
		break;
	case '+':
		camera_z += 1.0f;
		break;
	case '-':
		camera_z -= 1.0f;
		break;
	case 'x':
		camera_angle_x += 1.0f;
		break;
	case 'X':
		camera_angle_x -= 1.0f;
		break;
	case 'y':
		camera_angle_y += 1.0f;
		break;
	case 'Y':
		camera_angle_y -= 1.0f;
		break;
	case 'z':
		camera_angle_z += 1.0f;
		break;
	case 'Z':
		camera_angle_z -= 1.0f;
		break;
	case 'i':
		camera_x = 0.0f;
		camera_y = 200.0f;
		camera_z = -300.0f;
		camera_angle_x = 0.0f;
		camera_angle_y = 0.0f;
		camera_angle_z = 0.0f;
		break;
	}

	glutPostRedisplay();
}

void TimerFunction(int value)
{
	sphere1_angle += 10.0f;
	sphere2_angle += 2.0f;
	sphere3_angle += 5.0f;
	sphere4_angle += 15.0f;
	sphere5_angle += 8.0f;
	sphere6_angle += 11.0f;

	glutPostRedisplay();

	glutTimerFunc(50, TimerFunction, 1);
}