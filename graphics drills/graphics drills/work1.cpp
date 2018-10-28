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
지금 필요한거 삼각형이랑 사각형
삼각형은 여러게 한 10개 정도??
사각형은 정사각형 혹은 마름모 선택해서 뽑기
삼각형은 배열로 만들어서 뽑는다 치면
각각의 좌표는 어떻게? 이거 회전도 해야하는데
아니 회전할 필요는 없네
회전 안 하는 삼각형 10개 + 사각형이던지 마름모던지 하는거 하나+ 별 만들기= 할 수 있나 이거 3일 남았는데
문제는 할게 이거 하나만 있는게 아니다
ㅁ;ㄴ이ㅏ러

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
	glEnable(GL_DEPTH_TEST);  // 은면 제거
	glFrontFace(GL_CCW);   // 앞면 설정  
	//glEnable(GL_CULL_FACE);  // 내부는 잘라낸다  
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