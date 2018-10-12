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

int shape_option = 1;
int axis_x_rotation = 0;
int axis_y_rotation = 0;
int axis_z_rotation = 0;
float angle_x = 0;
float angle_y = 0;
float angle_z = 0;
float shape1_angle_y = 0;
float shape2_angle_y = 0;

void SetupRC();
void DrawScene();
void Reshape(int w, int h);
void Keyboard(unsigned char key, int x, int y);
void TimerFunction(int value);
cam cam_rotate = { 0, };

//GLUquadricObj *qobj;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Practice16");

	SetupRC();

	glutDisplayFunc(DrawScene);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
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
	
	switch (shape_option)
	{
	case 1:
		glPushMatrix();
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		glRotatef(shape1_angle_y, 0.0f, 1.0f, 0.0f);
		glRotatef(angle_x, 1.0f, 0.0f, 0.0f);
		glRotatef(angle_y, 0.0f, 1.0f, 0.0f);
		glRotatef(angle_z, 0.0f, 0.0f, 1.0f);
		glTranslatef(-100.0f, 0.0f, 0.0f);
		glutSolidSphere(50.0, 20, 20);
		glPopMatrix();

		glPushMatrix();
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		glRotatef(shape2_angle_y, 0.0f, 1.0f, 0.0f);
		glRotatef(angle_x, 1.0f, 0.0f, 0.0f);
		glRotatef(angle_y, 0.0f, 1.0f, 0.0f);
		glRotatef(angle_z, 0.0f, 0.0f, 1.0f);
		glTranslatef(100.0f, 0.0f, 0.0f);
		glutWireSphere(50.0, 20, 20);
		glPopMatrix();
		break;
	}

	glPushMatrix();
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(angle_x, 1.0f, 0.0f, 0.0f);
	glRotatef(angle_y, 0.0f, 1.0f, 0.0f);
	glRotatef(angle_z, 0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glPointSize(2.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(100.0f, 0.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	glRotatef(angle_x, 1.0f, 0.0f, 0.0f);
	glRotatef(angle_y, 0.0f, 1.0f, 0.0f);
	glRotatef(angle_z, 0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glPointSize(2.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 100.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	glRotatef(angle_x, 1.0f, 0.0f, 0.0f);
	glRotatef(angle_y, 0.0f, 1.0f, 0.0f);
	glRotatef(angle_z, 0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glPointSize(2.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 100.0f);
	glEnd();
	glPopMatrix();

	glutSwapBuffers();
}

void Reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60.0, WIDTH/HEIGHT, 1.0, 1000.0);
	glTranslatef(0.0, 0.0, -300.0);
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '1':
		shape_option = 1;
		break;
	case '2':
		shape_option = 2;
		break;
	case '3':
		shape_option = 3;
		break;
	case '4':
		shape_option = 4;
		break;
	case 'X':
		angle_x += 10.0f;
		break;
	case 'Y':
		angle_y += 10.0f;
		break;
	case 'Z':
		angle_z += 10.0f;
		break;
	case 'L':
		shape1_angle_y += 10.0f;
		break;
	case 'K':
		shape2_angle_y += 10.0f;
		break;
	}
	glutPostRedisplay();
}

void TimerFunction(int value)
{
	glutPostRedisplay();
	
	glutTimerFunc(100, TimerFunction, 1);
}