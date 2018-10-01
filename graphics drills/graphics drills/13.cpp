#include "pch.h"
#include <gl/freeglut.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

GLvoid drawScene(GLvoid);
GLvoid reShape(int w, int h);
void keyBoard(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void Timer(int value);
void Triangle(GLfloat lx, GLfloat ly, GLfloat lz, GLfloat tx, GLfloat ty, GLfloat tz, GLfloat rx, GLfloat ry, GLfloat rz);
void Line();
void Init();

struct tri
{
	GLfloat leftX;
	GLfloat leftY;
	GLfloat leftZ;

	GLfloat topX;
	GLfloat topY;
	GLfloat topZ;

	GLfloat rightX;
	GLfloat rightY;
	GLfloat rightZ;
};

struct tri triangle1;
struct tri triangle2;
struct tri triangle3;
struct tri triangle4;
int state = -1;
int go = -1;
GLfloat scale = 1.0f;
GLfloat rotate = 0.0f;
GLfloat s_rotate = 0.0f;
GLfloat moved_x = 0.0f;
GLfloat moved_y1 = 0.0f;
GLfloat moved_y2 = 0.0f;
GLfloat moved_z = 0.0f;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Practice12");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(reShape);
	glutKeyboardFunc(keyBoard);
	glutMouseFunc(Mouse);
	glutTimerFunc(100, Timer, 1);
	glutMainLoop();
}

GLvoid drawScene()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	Line();
	switch (state)
	{
	case 1:
		glPushMatrix();
		rotate += 5.0f;
		glRotatef(rotate, 0.0f, 1.0f, 0.0f);
		glScalef(scale, scale, scale);
		Triangle(triangle1.leftX, triangle1.leftY, triangle1.leftZ, triangle1.topX, triangle1.topY, triangle1.topZ, triangle1.rightX, triangle1.rightY, triangle1.rightZ);
		Triangle(triangle2.leftX, triangle2.leftY, triangle2.leftZ, triangle2.topX, triangle2.topY, triangle2.topZ, triangle2.rightX, triangle2.rightY, triangle2.rightZ);
		glPushMatrix();
		glTranslatef(triangle1.leftX + moved_x, triangle1.leftY + moved_y1, 0.0f);
		glRotatef(s_rotate, 0.0f, 1.0f, 0.0f);
		Triangle(triangle3.leftX, triangle3.leftY, triangle3.leftZ, triangle3.topX, triangle3.topY, triangle3.topZ, triangle3.rightX, triangle3.rightY, triangle3.rightZ);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, triangle2.leftY + moved_y2, triangle2.leftZ + moved_z);
		glRotatef(s_rotate, 0.0f, 1.0f, 0.0f);
		Triangle(triangle4.leftX, triangle4.leftY, triangle4.leftZ, triangle4.topX, triangle4.topY, triangle4.topZ, triangle4.rightX, triangle4.rightY, triangle4.rightZ);
		glPopMatrix();
		glPopMatrix();
		state = 0;
		break;
	case 2:
		glPushMatrix();
		rotate -= 5.0f;
		glRotatef(rotate, 0.0f, 1.0f, 0.0f);
		glScalef(scale, scale, scale);
		Triangle(triangle1.leftX, triangle1.leftY, triangle1.leftZ, triangle1.topX, triangle1.topY, triangle1.topZ, triangle1.rightX, triangle1.rightY, triangle1.rightZ);
		Triangle(triangle2.leftX, triangle2.leftY, triangle2.leftZ, triangle2.topX, triangle2.topY, triangle2.topZ, triangle2.rightX, triangle2.rightY, triangle2.rightZ);
		glPushMatrix();
		glTranslatef(triangle1.leftX + moved_x, triangle1.leftY + moved_y1, 0.0f);
		glRotatef(s_rotate, 0.0f, 1.0f, 0.0f);
		Triangle(triangle3.leftX, triangle3.leftY, triangle3.leftZ, triangle3.topX, triangle3.topY, triangle3.topZ, triangle3.rightX, triangle3.rightY, triangle3.rightZ);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, triangle2.leftY + moved_y2, triangle2.leftZ + moved_z);
		glRotatef(s_rotate, 0.0f, 1.0f, 0.0f);
		Triangle(triangle4.leftX, triangle4.leftY, triangle4.leftZ, triangle4.topX, triangle4.topY, triangle4.topZ, triangle4.rightX, triangle4.rightY, triangle4.rightZ);
		glPopMatrix();
		glPopMatrix();
		state = 0;
		break;
	case 3:
		glPushMatrix();
		if (scale < 2.0)
		{
			scale += 0.1f;
		}
		glRotatef(rotate, 0.0f, 1.0f, 0.0f);
		glScalef(scale, scale, scale);
		Triangle(triangle1.leftX, triangle1.leftY, triangle1.leftZ, triangle1.topX, triangle1.topY, triangle1.topZ, triangle1.rightX, triangle1.rightY, triangle1.rightZ);
		Triangle(triangle2.leftX, triangle2.leftY, triangle2.leftZ, triangle2.topX, triangle2.topY, triangle2.topZ, triangle2.rightX, triangle2.rightY, triangle2.rightZ);
		glPushMatrix();
		glTranslatef(triangle1.leftX + moved_x, triangle1.leftY + moved_y1, 0.0f);
		glRotatef(s_rotate, 0.0f, 1.0f, 0.0f);
		Triangle(triangle3.leftX, triangle3.leftY, triangle3.leftZ, triangle3.topX, triangle3.topY, triangle3.topZ, triangle3.rightX, triangle3.rightY, triangle3.rightZ);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, triangle2.leftY + moved_y2, triangle2.leftZ + moved_z);
		glRotatef(s_rotate, 0.0f, 1.0f, 0.0f);
		Triangle(triangle4.leftX, triangle4.leftY, triangle4.leftZ, triangle4.topX, triangle4.topY, triangle4.topZ, triangle4.rightX, triangle4.rightY, triangle4.rightZ);
		glPopMatrix();
		glPopMatrix();
		state = 0;
		break;
	case 4:
		glPushMatrix();
		if (scale > 0.1)
		{
			scale -= 0.1f;
		}
		glRotatef(rotate, 0.0f, 1.0f, 0.0f);
		glScalef(scale, scale, scale);
		Triangle(triangle1.leftX, triangle1.leftY, triangle1.leftZ, triangle1.topX, triangle1.topY, triangle1.topZ, triangle1.rightX, triangle1.rightY, triangle1.rightZ);
		Triangle(triangle2.leftX, triangle2.leftY, triangle2.leftZ, triangle2.topX, triangle2.topY, triangle2.topZ, triangle2.rightX, triangle2.rightY, triangle2.rightZ);
		glPushMatrix();
		glTranslatef(triangle1.leftX + moved_x, triangle1.leftY + moved_y1, 0.0f);
		glRotatef(s_rotate, 0.0f, 1.0f, 0.0f);
		Triangle(triangle3.leftX, triangle3.leftY, triangle3.leftZ, triangle3.topX, triangle3.topY, triangle3.topZ, triangle3.rightX, triangle3.rightY, triangle3.rightZ);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, triangle2.leftY + moved_y2, triangle2.leftZ + moved_z);
		glRotatef(s_rotate, 0.0f, 1.0f, 0.0f);
		Triangle(triangle4.leftX, triangle4.leftY, triangle4.leftZ, triangle4.topX, triangle4.topY, triangle4.topZ, triangle4.rightX, triangle4.rightY, triangle4.rightZ);
		glPopMatrix();
		glPopMatrix();
		state = 0;
		break;
	case -1:
		Init();
		Triangle(triangle1.leftX, triangle1.leftY, triangle1.leftZ, triangle1.topX, triangle1.topY, triangle1.topZ, triangle1.rightX, triangle1.rightY, triangle1.rightZ);
		Triangle(triangle2.leftX, triangle2.leftY, triangle2.leftZ, triangle2.topX, triangle2.topY, triangle2.topZ, triangle2.rightX, triangle2.rightY, triangle2.rightZ);
		state = 0;
		break;
	case 0:
		glPushMatrix();
		glRotatef(rotate, 0.0f, 1.0f, 0.0f);
		glScalef(scale, scale, scale);
		Triangle(triangle1.leftX, triangle1.leftY, triangle1.leftZ, triangle1.topX, triangle1.topY, triangle1.topZ, triangle1.rightX, triangle1.rightY, triangle1.rightZ);
		Triangle(triangle2.leftX, triangle2.leftY, triangle2.leftZ, triangle2.topX, triangle2.topY, triangle2.topZ, triangle2.rightX, triangle2.rightY, triangle2.rightZ);
		glPushMatrix();
		glTranslatef(triangle1.leftX + moved_x, triangle1.leftY + moved_y1, 0.0f);
		glRotatef(s_rotate, 0.0f, 1.0f, 0.0f);
		Triangle(triangle3.leftX, triangle3.leftY, triangle3.leftZ, triangle3.topX, triangle3.topY, triangle3.topZ, triangle3.rightX, triangle3.rightY, triangle3.rightZ);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, triangle2.leftY + moved_y2, triangle2.leftZ + moved_z);
		glRotatef(s_rotate, 0.0f, 1.0f, 0.0f);
		Triangle(triangle4.leftX, triangle4.leftY, triangle4.leftZ, triangle4.topX, triangle4.topY, triangle4.topZ, triangle4.rightX, triangle4.rightY, triangle4.rightZ);
		glPopMatrix();
		glPopMatrix();
		break;
	}
	//glPushMatrix();
	////glRotatef(s_rotate, 0.0f, moved + (2 * moved), 0.0f);
	//glTranslatef(moved, 2 * moved, 0.0f);
	//Triangle(triangle3.leftX, triangle3.leftY, triangle3.leftZ, triangle3.topX, triangle3.topY, triangle3.topZ, triangle3.rightX, triangle3.rightY, triangle3.rightZ);
	//glPopMatrix();

	//glPushMatrix();
	////glRotatef(s_rotate, 0.0f, moved + (2 * moved), 0.0f);
	//glTranslatef(0.0f, 2 * moved, moved);
	//Triangle(triangle4.leftX, triangle4.leftY, triangle4.leftZ, triangle4.topX, triangle4.topY, triangle4.topZ, triangle4.rightX, triangle4.rightY, triangle4.rightZ);
	//glPopMatrix();

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
	case 'y':
		state = 1;
		drawScene();
		break;
	case 'Y':
		state = 2;
		drawScene();
		break;
	case 's':
		state = 3;
		drawScene();
		break;
	case 'S':
		state = 4;
		drawScene();
		break;
	}
}

void Mouse(int button, int state, int x, int y)
{

}

void Timer(int value)
{
	if (triangle1.leftX + moved_x <= triangle1.topX && go != 1)
	{
		moved_x += 3.0f;
		moved_y1 += 3.0f;
	}
	else if (moved_y1 >= triangle1.leftY)
	{
		moved_x += 3.0f;
		moved_y1 -= 3.0f;
		go = 1;
	}
	else if (go == 1)
	{
		if (moved_x <= triangle1.topX)
		{
			go = 0;
		}
		moved_x -= 3.0f;
	}

	if (triangle2.leftZ + moved_z <= triangle2.topZ&& go != 1)
	{
		moved_z += 3.0f;
		moved_y2 += 3.0f;
	}
	else if (moved_y2 >= triangle2.leftY)
	{
		moved_z += 3.0f;
		moved_y2 -= 3.0f;
		go = 1;
	}
	else if (go == 1)
	{
		if (moved_z <= triangle2.topZ)
		{
			go = 0;
		}
		moved_z -= 3.0f;
	}
	s_rotate += 10.0f;
	glutPostRedisplay();
	glutTimerFunc(100, Timer, 1);
}

void Line()
{
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(-400.0f, 0.0f, 0.0f);
	glVertex3f(400.0f, 0.0f, 0.0f);
	glEnd();

	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0f, -300.0f, 0.0f);
	glVertex3f(0.0f, 300.0f, 0.0f);
	glEnd();
}

void Triangle(GLfloat lx, GLfloat ly, GLfloat lz, GLfloat tx, GLfloat ty, GLfloat tz, GLfloat rx, GLfloat ry, GLfloat rz)
{
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_LINE_STRIP);
	glVertex3f(lx, ly, lz);
	glVertex3f(rx, ry, rz);
	glVertex3f(tx, ty, tz);
	glVertex3f(lx, ly, lz);
	glEnd();
	//glutSwapBuffers();

}

void Init()
{
	triangle1.leftX = -200.0f;
	triangle1.leftY = 0.0f;
	triangle1.leftZ = 0.0f;

	triangle1.rightX = 200.0f;
	triangle1.rightY = 0.0f;
	triangle1.rightZ = 0.0f;

	triangle1.topX = 0.0f;
	triangle1.topY = 200.0f;
	triangle1.topZ = 0.0f;

	triangle2.leftX = 0.0f;
	triangle2.leftY = 0.0f;
	triangle2.leftZ = -200.0f;

	triangle2.rightX = 0.0f;
	triangle2.rightY = 0.0f;
	triangle2.rightZ = 200.0f;

	triangle2.topX = 0.0f;
	triangle2.topY = 200.0f;
	triangle2.topZ = 0.0f;

	triangle3.leftX = -10.0f;
	triangle3.leftY = -10.0f;
	triangle3.leftZ = 0.0f;

	triangle3.rightX = 10.0f;
	triangle3.rightY = -10.0f;
	triangle3.rightZ = 0.0f;

	triangle3.topX = 0.0f;
	triangle3.topY = 10.0f;
	triangle3.topZ = 0.0f;

	triangle4.leftX = 0.0f;
	triangle4.leftY = -10.0f;
	triangle4.leftZ = -10.0f;

	triangle4.rightX = 0.0f;
	triangle4.rightY = -10.0f;
	triangle4.rightZ = 10.0f;

	triangle4.topX = 0.0f;
	triangle4.topY = 10.0f;
	triangle4.topZ = 0.0f;
}