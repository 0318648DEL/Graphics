#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
//#include <iostream>
#include <time.h>
#include <gl/freeglut.h>
#include <gl/glut.h>

#define WIDTH 800
#define HEIGHT 600

void SetupRC();
void DrawScene();
void Reshape(int w, int h);
void Mouse(int button, int state, int x, int y);
void Motion(int x, int y);
void Check(int x, int y);
void Cutting();
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
	float x;
	float y;
	float angle;
	/*float z1;
	float z2;
	float z3;*/
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
	//float z1;
	//float z2;
	//float z3;
	//float z4;
};

struct lines
{
	float x1;
	float x2;
	float y1;
	float y2;
};

triangles cut_tri[2];
triangles up_tri[10];
float grid_points_l[28][2];
float grid_points_r[28][2];


square sqr;
lines cut_line;

bool left_button = false;
int check = 0;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("WORK");
	srand((unsigned)time(NULL));

	SetupRC();

	glutDisplayFunc(DrawScene);
	glutReshapeFunc(Reshape);
	glutMouseFunc(Mouse);
	glutMotionFunc(Motion);
	glutPassiveMotionFunc(Check);
	glutTimerFunc(100, TimerFunction, 1);

	glutMainLoop();
}

void DrawScene()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	/*glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/

	glBegin(GL_LINES);
	{
		glColor3ub(255, 0, 0);
		glVertex2f(cut_line.x1, cut_line.y1);
		glVertex2f(cut_line.x2, cut_line.y2);
	}
	glEnd();

	glBegin(GL_POLYGON);
	{
		glColor3ub(255, 255, 255);
		glVertex2f(sqr.x1, sqr.y1);
		glVertex2f(sqr.x2, sqr.y2);
		glVertex2f(sqr.x3, sqr.y3);
		glVertex2f(sqr.x4, sqr.y4);

	}
	glEnd();

	{
		glBegin(GL_LINE_LOOP);
		{
			glVertex2f(grid_points_l[0][0], grid_points_l[0][1]);
			glVertex2f(grid_points_l[6][0], grid_points_l[6][1]);
			glVertex2f(grid_points_l[13][0], grid_points_l[13][1]);
			glVertex2f(grid_points_l[7][0], grid_points_l[7][1]);
		}
		glEnd();
		glBegin(GL_LINE_LOOP);
		{
			glVertex2f(grid_points_l[7][0], grid_points_l[7][1]);
			glVertex2f(grid_points_l[13][0], grid_points_l[13][1]);
			glVertex2f(grid_points_l[20][0], grid_points_l[20][1]);
			glVertex2f(grid_points_l[14][0], grid_points_l[14][1]);
		}
		glEnd();
		glBegin(GL_LINE_LOOP);
		{
			glVertex2f(grid_points_l[14][0], grid_points_l[14][1]);
			glVertex2f(grid_points_l[20][0], grid_points_l[20][1]);
			glVertex2f(grid_points_l[27][0], grid_points_l[27][1]);
			glVertex2f(grid_points_l[21][0], grid_points_l[21][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		{
			glVertex2f(grid_points_l[1][0], grid_points_l[1][1]);
			glVertex2f(grid_points_l[22][0], grid_points_l[22][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		{
			glVertex2f(grid_points_l[2][0], grid_points_l[2][1]);
			glVertex2f(grid_points_l[23][0], grid_points_l[23][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		{
			glVertex2f(grid_points_l[3][0], grid_points_l[3][1]);
			glVertex2f(grid_points_l[24][0], grid_points_l[24][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		{
			glVertex2f(grid_points_l[4][0], grid_points_l[4][1]);
			glVertex2f(grid_points_l[25][0], grid_points_l[25][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		{
			glVertex2f(grid_points_l[5][0], grid_points_l[5][1]);
			glVertex2f(grid_points_l[26][0], grid_points_l[26][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		{
			glVertex2f(grid_points_l[6][0], grid_points_l[6][1]);
			glVertex2f(grid_points_l[27][0], grid_points_l[27][1]);
		}
		glEnd();
	}

	{
		glBegin(GL_LINE_LOOP);
		{
			glVertex2f(grid_points_r[0][0], grid_points_r[0][1]);
			glVertex2f(grid_points_r[6][0], grid_points_r[6][1]);
			glVertex2f(grid_points_r[13][0], grid_points_r[13][1]);
			glVertex2f(grid_points_r[7][0], grid_points_r[7][1]);
		}
		glEnd();
		glBegin(GL_LINE_LOOP);
		{
			glVertex2f(grid_points_r[7][0], grid_points_r[7][1]);
			glVertex2f(grid_points_r[13][0], grid_points_r[13][1]);
			glVertex2f(grid_points_r[20][0], grid_points_r[20][1]);
			glVertex2f(grid_points_r[14][0], grid_points_r[14][1]);
		}
		glEnd();
		glBegin(GL_LINE_LOOP);
		{
			glVertex2f(grid_points_r[14][0], grid_points_r[14][1]);
			glVertex2f(grid_points_r[20][0], grid_points_r[20][1]);
			glVertex2f(grid_points_r[27][0], grid_points_r[27][1]);
			glVertex2f(grid_points_r[21][0], grid_points_r[21][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		{
			glVertex2f(grid_points_r[1][0], grid_points_r[1][1]);
			glVertex2f(grid_points_r[22][0], grid_points_r[22][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		{
			glVertex2f(grid_points_r[2][0], grid_points_r[2][1]);
			glVertex2f(grid_points_r[23][0], grid_points_r[23][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		{
			glVertex2f(grid_points_r[3][0], grid_points_r[3][1]);
			glVertex2f(grid_points_r[24][0], grid_points_r[24][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		{
			glVertex2f(grid_points_r[4][0], grid_points_r[4][1]);
			glVertex2f(grid_points_r[25][0], grid_points_r[25][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		{
			glVertex2f(grid_points_r[5][0], grid_points_r[5][1]);
			glVertex2f(grid_points_r[26][0], grid_points_r[26][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		{
			glVertex2f(grid_points_r[6][0], grid_points_r[6][1]);
			glVertex2f(grid_points_r[27][0], grid_points_r[27][1]);
		}
		glEnd();
	}

	glBegin(GL_LINES);
	{
		glColor3ub(255, 255, 255);
		glVertex2f(-400, 200);
		glVertex2f(400, 200);
	}
	glEnd();

	for (int yeet = 0; yeet < 10; ++yeet)
	{
		glPushMatrix();
		glTranslatef(up_tri[yeet].x, up_tri[yeet].y, 0.0f);
		glRotatef(up_tri[yeet].angle, 0.0, 0.0, 1.0);
		glColor3ub(255, 255, 255);
		glBegin(GL_TRIANGLES);
		{
			glVertex2f(-25, -25);
			glVertex2f(25, -25);
			glVertex2f(0, 25);

		}
		glEnd();
		glPopMatrix();
	}


	glutSwapBuffers();
}

void SetupRC()
{
	//glEnable(GL_DEPTH_TEST);  // 은면 제거
	//glFrontFace(GL_CCW);   // 앞면 설정  
	//glEnable(GL_CULL_FACE);  // 내부는 잘라낸다  
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	int grid_x = -400;
	int grid_y = -300;
	int up_tri_init_x = -380;
	int up_tri_init_y = 260;
	sqr.mode = rand() % 2;
	if (sqr.mode == 0)
	{
		sqr.x1 = -25.0f;
		sqr.x2 = -25.0f;
		sqr.x3 = 25.0f;
		sqr.x4 = 25.0f;
		sqr.y1 = -300.0f;
		sqr.y2 = -350.0f;
		sqr.y3 = -350.0f;
		sqr.y4 = -300.0f;
	}
	else if (sqr.mode == 1)
	{
		sqr.x1 = 0.0f;
		sqr.x2 = -25.0f;
		sqr.x3 = 0.0f;
		sqr.x4 = 25.0f;
		sqr.y1 = -300.0f;
		sqr.y2 = -325.0f;
		sqr.y3 = -350.0f;
		sqr.y4 = -325.0f;
	}

	for (int i = 0; i < 28; ++i)
	{
		if (i % 7 == 0)
		{
			grid_x = -400;
			grid_y += 50;
		}
		grid_points_l[i][0] = grid_x;
		grid_points_l[i][1] = grid_y;
		grid_x += 50;
	}

	grid_y = -300;

	for (int i = 0; i < 28; ++i)
	{
		if (i % 7 == 0)
		{
			grid_x = 400;
			grid_y += 50;
		}
		grid_points_r[i][0] = grid_x;
		grid_points_r[i][1] = grid_y;
		grid_x -= 50;
	}

	for (int i = 0; i < 10; ++i)
	{
		up_tri[i].x = up_tri_init_x;
		up_tri[i].y = up_tri_init_y;
		up_tri[i].angle = rand() % 300;

		up_tri_init_x += 80;
	}
}

void Reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	glOrtho(-400.0f, 400.0f, -300.0f, 300.0f, -1.0f, 1.0f);

	//glOrtho(0.0, 800.0, 0.0, 600.0, -400.0, 400.0);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();

	//gluPerspective(60.0, WIDTH / HEIGHT, 1.0, 1000.0);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
}

void Cutting()
{
	cut_line
}

void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		cut_line.x1 = x - (WIDTH / 2);
		cut_line.y1 = -(y - (HEIGHT / 2));
		cut_line.x2 = x - (WIDTH / 2);
		cut_line.y2 = -(y - (HEIGHT / 2));
		printf("x1 : %f  y1 : %f", cut_line.x1, cut_line.y1);
		left_button = true;
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		//자르는 함수 넣기
		cut_line.x1 = 0;
		cut_line.y1 = 0;
		cut_line.x2 = 0;
		cut_line.y2 = 0;
		left_button = false;
		printf("x2 : %f  y2 : %f", cut_line.x2, cut_line.y2);
		printf("\n");

	}
	glutPostRedisplay();
}

void Motion(int x, int y)
{
	if (left_button == true)
	{
		cut_line.x2 = x - (WIDTH / 2);
		cut_line.y2 = -(y - (HEIGHT / 2));
		//printf("x2 : %f  y2 : %f", cut_line.x2, cut_line.y2);

	}
	glutPostRedisplay();

}

void Check(int x, int y)
{

}

void TimerFunction(int value)
{
	if (sqr.y3 > HEIGHT / 2)
	{
		sqr.mode = rand() % 2;
		if (sqr.mode == 0)
		{
			sqr.x1 = -25.0f;
			sqr.x2 = -25.0f;
			sqr.x3 = 25.0f;
			sqr.x4 = 25.0f;
			sqr.y1 = -300.0f;
			sqr.y2 = -350.0f;
			sqr.y3 = -350.0f;
			sqr.y4 = -300.0f;
		}
		else if (sqr.mode == 1)
		{
			sqr.x1 = 0.0f;
			sqr.x2 = -25.0f;
			sqr.x3 = 0.0f;
			sqr.x4 = 25.0f;
			sqr.y1 = -300.0f;
			sqr.y2 = -325.0f;
			sqr.y3 = -350.0f;
			sqr.y4 = -325.0f;
		}
	}
	for (int x = 0; x < 10; ++x)
	{
		if (up_tri[x].x > 420)
		{
			up_tri[x].x = -380;
			up_tri[x].angle = rand()%200;
		}
		else
		{
			up_tri[x].x += 5;
			up_tri[x].angle += 10.0f;

		}
	}
	sqr.y1 += 5.0f;
	sqr.y2 += 5.0f;
	sqr.y3 += 5.0f;
	sqr.y4 += 5.0f;
	glutPostRedisplay();
	glutTimerFunc(100, TimerFunction, 1);
}