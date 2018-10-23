#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gl/freeglut.h>
#include <gl/glut.h>

#define WIDTH 800
#define HEIGHT 600

float angle_x = 0;
float angle_y = 0;
float angle_z = 0;
float camera_x = 0.0f;
float camera_y = 200.0f;
float camera_z = -300.0f;
double camera_angle_x = 0.0;
double camera_angle_y = 0.0;
double camera_angle_z = 0.0;
int shape_op = GLU_LINE;
GLUquadricObj *box1;
GLUquadricObj *box2;
GLUquadricObj *arm1;
GLUquadricObj *arm2;

void SetupRC();
void DrawScene();
void Reshape(int w, int h);
void Keyboard(unsigned char key, int x, int y);
void TimerFunction(int value);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Practice18");

	SetupRC();

	glutDisplayFunc(DrawScene);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutTimerFunc(100, TimerFunction, 1);

	glutMainLoop();
}

void SetupRC()
{
	glEnable(GL_DEPTH_TEST);  // 은면 제거
	glFrontFace(GL_CCW);   // 앞면 설정  
	//glEnable(GL_CULL_FACE);  // 내부는 잘라낸다  
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	box1 = gluNewQuadric();
	box2 = gluNewQuadric();
	arm1 = gluNewQuadric();
	arm2 = gluNewQuadric();
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

void DrawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camera_x, camera_y, camera_z, camera_x, camera_y - 200, camera_z + 300, 0.0, 0.0, 1.0);
	glRotatef(camera_angle_x, 1.0f, 0.0f, 0.0f);
	glRotatef(camera_angle_y, 0.0f, 1.0f, 0.0f);
	glRotatef(camera_angle_z, 0.0f, 0.0f, 1.0f);

	glPushMatrix();
	glRotatef(angle_x, 1.0f, 0.0f, 0.0f);
	glRotatef(angle_y, 0.0f, 1.0f, 0.0f);
	glRotatef(angle_z, 0.0f, 0.0f, 1.0f);
	glColor4f(0.0f, 0.8f, 0.8f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex3f(100.0f, -50.0f, 100.0f);
	glVertex3f(100.0f, -50.0f, -100.0f);
	glVertex3f(-100.0f, -50.0f, -100.0f);
	glVertex3f(-100.0f, -50.0f, 100.0f);
	glEnd();
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glLineWidth(2.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(100.0f, 0.0f, 0.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 100.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 100.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	{

	}

	glutSwapBuffers();
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		camera_y += 10.0f;
		break;
	case 'a':
		camera_x += 10.0f;
		break;
	case 's':
		camera_y -= 10.0f;
		break;
	case 'd':
		camera_x -= 10.0f;
		break;
	case '+':
		camera_z += 10.0f;
		break;
	case '-':
		camera_z -= 10.0f;
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
	glutPostRedisplay();

	glutTimerFunc(50, TimerFunction, 1);
}