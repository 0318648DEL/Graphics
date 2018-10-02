#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gl/freeglut.h>

#define WIDTH 800
#define HEIGHT 600

GLvoid drawScene(GLvoid);
GLvoid reShape(int w, int h);
void Timer(int value);

struct number
{
	
};
int hour = 0;
int minute = 0;
int second = 0;

int main(int argc, char **argv)
{
	srand((unsigned)time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Practice14");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(reShape);
	glutTimerFunc(100, Timer, 1);
	glutMainLoop();
}

GLvoid drawScene()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
}

GLvoid reShape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(-400.0f, 400.0f, -300.0f, 300.0f, -400.0f, 400.0f);
}

void get_time()
{
	time_t timer;
	struct tm *t;

	timer = time(NULL);

	t = localtime(&timer);

	hour = t->tm_hour;
	minute = t->tm_min;
	second = t->tm_sec;
}

void Timer(int value)
{
	get_time();
}