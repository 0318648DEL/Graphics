#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <gl/freeglut.h>

#define WIDTH 800
#define HEIGHT 600

GLvoid drawScene(GLvoid);
GLvoid reShape(int w, int h);
void keyBoard(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void Timer(int value);

int num = 0;
int trigger[20] = 0;
int shape_num[20] = { 0, };
GLfloat coordinate[20] = { 0, };
int rotate_axis[20] = { 0, };
int axis_x[20] = { 0, };
int axis_y[20] = { 0, };
int axis_z[20] = { 0, };
GLfloat rotation[20] = { 0, };
GLfloat trans_coordinate_x[20] = { 0, };
GLfloat trans_coordinate_y[20] = { 0, };
int scale[20] = { 0, };
int color1[20] = { 0, };
int color2[20] = { 0, };
int color3[20] = { 0, };

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Practice13");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(reShape);
	glutMouseFunc(Mouse);
	glutTimerFunc(100, Timer, 1);
	glutMainLoop();
}

GLvoid drawScene(GLvoid)
{
	int draw = 0;
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

}

GLvoid reShape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(-400.0f, 400.0f, -300.0f, 300.0f, -400.0f, 400.0f);
}

void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (num < 20)
		{
			trigger[num] = 1;
			trans_coordinate_x[num] = x;
			trans_coordinate_y[num] = y;
			coordinate[num] = 20.0f;
			shape_num[num] = (rand() % 5) + 1;
			scale[num] = (rand() % 10) + 5;
			color1[num] = (rand() % 255) + 1;
			color2[num] = (rand() % 255) + 1;
			color3[num] = (rand() % 255) + 1;
			rotate_axis[num] = rand() % 3;
			switch (rotate_axis[num])
			{
			case 0:
				axis_x[num] = 1;
				axis_y[num] = 0;
				axis_z[num] = 0;
				break;
			case 1:
				axis_x[num] = 0;
				axis_y[num] = 1;
				axis_z[num] = 0;
				break;
			case 2:
				axis_x[num] = 0;
				axis_y[num] = 0;
				axis_z[num] = 1;
				break;
			}
			++num;
		}
	}
}

void Timer(int value)
{
	int temp = 0;
	while (temp < 20)
	{
			if (scale[temp] <= 0&&trigger[temp]==1)
			{
				for (int i = temp; i < 19; ++i)
				{
					trigger[temp] = trigger[temp + 1];
					shape_num[temp] = shape_num[temp+1];
					scale[temp] = shape_num[temp+1];
					color1[temp] = shape_num[temp + 1];
					color2[temp] = shape_num[temp + 1];
					color3[temp] = shape_num[temp + 1];
					rotate_axis[temp] = rotate_axis[temp + 1];
					axis_x[temp] = axis_x[temp + 1];
					axis_y[temp] = axis_y[temp + 1];
					axis_z[temp] = axis_z[temp + 1];
					rotation[temp] = rotation[temp + 1];
					coordinate[temp] = coordinate[temp + 1];
					trans_coordinate_x[temp] = trans_coordinate_x[temp + 1];
					trans_coordinate_y[temp] = trans_coordinate_y[temp + 1];
				}
				num = 19;
				trigger[num] = 0;
			}
			else
			{
				--scale[temp];
				switch (rotate_axis[temp])
				{
				case 0:
					rotation[temp] += axis_x[temp] * 20;
					break;
				case 1:
					rotation[temp] += axis_y[temp] * 20;
					break;
				case 2:
					rotation[temp] += axis_z[temp] * 20;
					break;
				}
			}
	}
	
}