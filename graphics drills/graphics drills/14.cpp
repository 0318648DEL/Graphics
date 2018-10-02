#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gl/freeglut.h>

#define WIDTH 800
#define HEIGHT 600

GLvoid drawScene(GLvoid);
GLvoid reShape(int w, int h);
void keyBoard(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void Timer(int value);

int state = 1;
int start_num = 0;
int last_num = 20;
int trigger[20] = { 0, };
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
	srand((unsigned)time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Practice14");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(reShape);
	glutMouseFunc(Mouse);
	glutKeyboardFunc(keyBoard);
	glutTimerFunc(100, Timer, 1);
	glutMainLoop();
}

GLvoid drawScene(GLvoid)
{
	int draw = 0;
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	for (int x = 19; x>=0; --x)
	{
		if (trigger[x] == 1)
		{
			glPushMatrix();
			glColor4ub(color1[x], color2[x], color3[x], 1.0);
			glTranslatef(trans_coordinate_x[x], trans_coordinate_y[x], 0.0f);
			glRotatef(rotation[x], axis_x[x], axis_y[x], axis_z[x]);
			glScalef(scale[x], scale[x], scale[x]);
			switch (shape_num[x])
			{
			case 1:
				glutWireCone(coordinate[x], coordinate[x], 8, 8);
				break;
			case 2:
				glutWireCube(coordinate[x]);
				break;
			case 3:
				glutWireSphere(coordinate[x] / 2, 10, 10);
				break;
			case 4:
				glutWireTorus(coordinate[x] / 5, coordinate[x] / 2, 10, 10);
				break;
			case 5:
				glutWireTeapot(coordinate[x]);
				break;
			}
			glPopMatrix();
		}
		
	}
	glutSwapBuffers();
}

GLvoid reShape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(-400.0f, 400.0f, -300.0f, 300.0f, -400.0f, 400.0f);
}

void keyBoard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		glutLeaveMainLoop();
		break;
	case 'r':
		state *= -1;
		break;
	}
}

void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (start_num<last_num)
		{
			trigger[start_num] = 1;
			trans_coordinate_x[start_num] = x-400;
			trans_coordinate_y[start_num] = y-300;
			coordinate[start_num] = (rand()%20)+5;
			shape_num[start_num] = (rand() % 5) + 1;
			scale[start_num] = 20;
			color1[start_num] = (rand() % 255) + 1;
			color2[start_num] = (rand() % 255) + 1;
			color3[start_num] = (rand() % 255) + 1;
			rotate_axis[start_num] = rand() % 3;
			switch (rotate_axis[start_num])
			{
			case 0:
				axis_x[start_num] = 1;
				axis_y[start_num] = 0;
				axis_z[start_num] = 0;
				break;
			case 1:
				axis_x[start_num] = 0;
				axis_y[start_num] = 1;
				axis_z[start_num] = 0;
				break;
			case 2:
				axis_x[start_num] = 0;
				axis_y[start_num] = 0;
				axis_z[start_num] = 1;
				break;
			}
			++start_num;
			start_num = start_num % last_num;
		}
	}
}

void Timer(int value)
{
	int temp = 19;
	while (temp >= 0)
	{
			if (scale[temp] <= 0&&trigger[temp]==1)
			{
				trigger[temp] = 0;
				/*shape_num[temp] = 0;
				scale[temp] = 0;
				color1[temp] =0;
				color2[temp] =0;
				color3[temp] =0;
				rotate_axis[temp] = 0;
				axis_x[temp] = 0;
				axis_y[temp] = 0;
				axis_z[temp] = 0;
				rotation[temp] = 0;
				coordinate[temp] = 0;
				trans_coordinate_x[temp] = 0;
				trans_coordinate_y[temp] = 0;*/
			}
			else if(trigger[temp]==1)
			{
				--scale[temp];
				switch (rotate_axis[temp])
				{
				case 0:
					rotation[temp] += state*axis_x[temp] * 20;
					break;
				case 1:
					rotation[temp] += state*axis_y[temp] * 20;
					break;
				case 2:
					rotation[temp] += state*axis_z[temp] * 20;
					break;
				}
			}
			--temp;
	}
	glutPostRedisplay();
	glutTimerFunc(100, Timer, 1);

}