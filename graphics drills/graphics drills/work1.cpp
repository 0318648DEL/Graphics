#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gl/freeglut.h>
#include <gl/glut.h>

#define WIDTH 800
#define HEIGHT 600

void SetupRC();
void DrawScene();
void Reshape(int w, int h);
void Mouse(int button, int state, int x, int y);
void TimerFunction(int value);

/*
���� �ʿ��Ѱ� �ﰢ���̶� �簢��
�ﰢ���� ������ �� 10�� ����??
�簢���� ���簢�� Ȥ�� ������ �����ؼ� �̱�
�ﰢ���� �迭�� ���� �̴´� ġ��
������ ��ǥ�� ���? �̰� ȸ���� �ؾ��ϴµ�
�ƴ� ȸ���� �ʿ�� ����
ȸ�� �� �ϴ� �ﰢ�� 10�� + �簢���̴��� ��������� �ϴ°� �ϳ�+ �� �����= �� �� �ֳ� �̰� 3�� ���Ҵµ�
������ �Ұ� �̰� �ϳ��� �ִ°� �ƴϴ�
��;���̤���

*/


struct triangles
{
	float x1;
	float x2;
	float x3;
	float y1;
	float y2;
	float y3;
	float z1;
	float z2;
	float z3;
};

struct square
{
	int mode;
	float x1;
	float x2;
	float x3;
	float x4;
	float y1;
	float y2;
	float y3;
	float y4;
	float z1;
	float z2;
	float z3;
	float z4;
};

triangles tri[10];
square sqr;
int start;

float start_point;
float end_point;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("WORK");

	SetupRC();

	glutDisplayFunc(DrawScene);
	glutReshapeFunc(Reshape);
	glutMouseFunc(Mouse);
	glutTimerFunc(100, TimerFunction, 1);

	glutMainLoop();
}

void DrawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void SetupRC()
{
	glEnable(GL_DEPTH_TEST);  // ���� ����
	glFrontFace(GL_CCW);   // �ո� ����  
	//glEnable(GL_CULL_FACE);  // ���δ� �߶󳽴�  
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void Reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//gluPerspective(60.0, WIDTH / HEIGHT, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

	}
}

void TimerFunction(int value)
{

}