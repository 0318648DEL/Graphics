#include "pch.h"
#include <stdlib.h>
#include <gl/freeglut.h>
#include <gl/glut.h>

#define WIDTH 800
#define HEIGHT 600

GLUquadricObj *sph;
GLUquadricObj *light1;
GLUquadricObj *light2;

void SetupRC();
void DrawScene();
void Reshape(int w,int h);
void Keyboard(unsigned char key,int x,int y);
void TimerFunction(int value);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("31");

	SetupRC();

	glutDisplayFunc(DrawScene);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutTimerFunc(100, TimerFunction, 1);

	glutMainLoop();
}

void SetupRC()
{
	gluSphere(sph, 50.0, 20, 20);
	gluCylinder(light1, 10.0, 0.0, 10.0, 20, 8);
	gluCylinder(light2, 10.0, 0.0, 10.0, 20, 8);

	glEnable(GL_LIGHT0);
}