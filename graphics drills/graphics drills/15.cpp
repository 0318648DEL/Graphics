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
void keyBoard(unsigned char key, int x, int y);

int hour = 0;
int minute = 0;
int second = 0;
GLfloat rotation = 0;

int main(int argc, char **argv)
{
	srand((unsigned)time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Practice15");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(reShape);
	glutKeyboardFunc(keyBoard);
	glutTimerFunc(100, Timer, 1);
	glutMainLoop();
}

GLvoid drawScene()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	switch (hour / 10)
	{
	case 0:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-350.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-300.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-350.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-300.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-325.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-325.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-325.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 1:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-350.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-300.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//glPushMatrix();
		//glColor4ub(160, 100, 0, 1);
		//glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		//glTranslatef(-350.0f, 40.0f, 0.0f);
		//glScalef(5.0f, 10.0f, 1.0f);
		//glutSolidCube(5.0f);
		//glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-300.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();
		break;
	case 2:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-350.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-300.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-350.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-300.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-325.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-325.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-325.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();
		
		//가로 3개
		break;
	}
	switch (hour % 10)
	{
	case 0:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-270.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-220.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-270.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-220.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 1:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-350.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-220.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//glPushMatrix();
		//glColor4ub(160, 100, 0, 1);
		//glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		//glTranslatef(-350.0f, 40.0f, 0.0f);
		//glScalef(5.0f, 10.0f, 1.0f);
		//glutSolidCube(5.0f);
		//glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-220.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();
		break;
	case 2:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-270.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-300.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-350.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-220.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 3:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-270.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-220.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-270.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-220.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 4:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-270.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-220.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-270.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-220.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		//가로 3개
		break;
	}
	glPushMatrix();
	glColor4ub(160, 100, 0, 1);
	glRotatef(rotation, 0.0f, 1.0f, 0.0f);
	glTranslatef(-190.0f, 35.0f, 0.0f);
	glScalef(5.0f, 5.0f, 5.0f);
	glutSolidCube(5.0f);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(160, 100, 0, 1);
	glRotatef(rotation, 0.0f, 1.0f, 0.0f);
	glTranslatef(-190.0f, -35.0f, 0.0f);
	glScalef(5.0f, 5.0f, 5.0f);
	glutSolidCube(5.0f);
	glPopMatrix();
	switch (minute / 10)
	{
	case 0:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 1:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-350.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//glPushMatrix();
		//glColor4ub(160, 100, 0, 1);
		//glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		//glTranslatef(-350.0f, 40.0f, 0.0f);
		//glScalef(5.0f, 10.0f, 1.0f);
		//glutSolidCube(5.0f);
		//glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();
		break;
	case 2:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-300.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-350.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 3:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-270.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-270.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 4:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-270.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		//가로 3개
		break;
	case 5:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 6:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 7:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		//가로 3개
		break;
	case 8:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 9:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	}
	switch (minute % 10)
	{
	case 0:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-80.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-30.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-80.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-30.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 1:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-350.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-30.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//glPushMatrix();
		//glColor4ub(160, 100, 0, 1);
		//glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		//glTranslatef(-350.0f, 40.0f, 0.0f);
		//glScalef(5.0f, 10.0f, 1.0f);
		//glutSolidCube(5.0f);
		//glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-30.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();
		break;
	case 2:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-80.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-300.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-350.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-30.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 3:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-270.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-30.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-270.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-30.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 4:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-270.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-30.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-80.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-30.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		//가로 3개
		break;
	case 5:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-30.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-80.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 6:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-80.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-30.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-80.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 7:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-30.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-30.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		//가로 3개
		break;
	case 8:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-80.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-30.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-80.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-30.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 9:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-30.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-80.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-30.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-55.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	}
	glPushMatrix();
	glColor4ub(160, 100, 0, 1);
	glRotatef(rotation, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 35.0f, 0.0f);
	glScalef(5.0f, 5.0f, 5.0f);
	glutSolidCube(5.0f);
	glPopMatrix();

	glPushMatrix();
	glColor4ub(160, 100, 0, 1);
	glRotatef(rotation, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, -35.0f, 0.0f);
	glScalef(5.0f, 5.0f, 5.0f);
	glutSolidCube(5.0f);
	glPopMatrix();
	switch (second / 10)
	{
	case 0:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(30.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(80.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(30.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(80.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 1:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-350.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(80.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//glPushMatrix();
		//glColor4ub(160, 100, 0, 1);
		//glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		//glTranslatef(-350.0f, 40.0f, 0.0f);
		//glScalef(5.0f, 10.0f, 1.0f);
		//glutSolidCube(5.0f);
		//glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(80.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();
		break;
	case 2:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(30.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-300.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-350.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(80.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 3:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-270.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(80.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-270.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(80.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 4:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-270.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(80.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(30.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(80.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		//가로 3개
		break;
	case 5:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(80.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(30.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 6:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(30.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(80.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(30.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 7:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(80.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(80.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		//가로 3개
		break;
	case 8:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(30.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(80.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(30.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(80.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 9:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(80.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(30.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(80.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	}
	switch (second % 10)
	{
	case 0:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(110.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(160.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(55.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 1:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-350.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//glPushMatrix();
		//glColor4ub(160, 100, 0, 1);
		//glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		//glTranslatef(-350.0f, 40.0f, 0.0f);
		//glScalef(5.0f, 10.0f, 1.0f);
		//glutSolidCube(5.0f);
		//glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(160.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();
		break;
	case 2:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(110.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-300.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-350.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(160.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 3:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-270.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-270.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(160.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 4:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-270.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(160.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-245.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		//가로 3개
		break;
	case 5:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 6:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(110.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 7:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(160.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-135.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		//가로 3개
		break;
	case 8:
		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(110.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(160.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f,5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	case 9:
		/*glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(-160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 1.0f);
		glutSolidCube(5.0f);
		glPopMatrix();*/

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(160.0f, -40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(110.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(160.0f, 40.0f, 0.0f);
		glScalef(5.0f, 10.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//세로 4개

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, 0.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, 79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		glPushMatrix();
		glColor4ub(160, 100, 0, 1);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glTranslatef(135.0f, -79.0f, 0.0f);
		glScalef(10.0f, 5.0f, 5.0f);
		glutSolidCube(5.0f);
		glPopMatrix();

		//가로 3개
		break;
	}
	glutSwapBuffers();
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
	glutPostRedisplay();
	glutTimerFunc(100,Timer,1);
}

void keyBoard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'r':
		rotation += 10.0f;
		break;
	case 'R':
		rotation -= 10.0f;
		break;
	}
}