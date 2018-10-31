#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gl/freeglut.h>
#include <gl/glut.h>

#define WIDTH 800
#define HEIGHT 600

float sph_x = 0;
float sph_z = 0;
float sph_angle_x = 0;
float sph_angle_y = 0;
float sph_angle_z = 0;
float angle_x = 0;
float angle_y = 0;
float angle_z = 0;
float camera_x = 0.0f;
float camera_y = 200.0f;
float camera_z = -300.0f;
double camera_angle_x = 0.0;
double camera_angle_y = 0.0;
double camera_angle_z = 0.0;
float box_way = 5.0f;
float box1_x = 0.0f;
float arm1_x = 0.0f;
float arm1_y = 0.0f;
float arm2_x = 0.0f;
float arm2_z = 0.0f;
float tree_size = 1.0f;
float size = 0.05f;
float spin = 0.0f;
float run = 0.0f;
float leg1 = 0.0f;
float leg1_dir = 5.0f;
float leg2 = 0.0f;
float leg2_dir = -5.0f;
float babel1 = 0.0f;
float babel2 = 0.0f;
float m = 0.0f;
float turning = 0.0f;
GLUquadricObj *sph;

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
	glutTimerFunc(30, TimerFunction, 1);

	glutMainLoop();
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
	{
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
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(box1_x, -30.0f, 0.0f);
		glScalef(1.5f, 1.0f, 1.5f);
		glutSolidCube(20);
		glColor3ub(0, 0, 0);
		glutWireCube(20);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(box1_x, 0.0f, 0.0f);
		glTranslatef(0.0f, -15.0f, 0.0f);
		glRotatef(arm1_y, 0.0f, 1.0f, 0.0f);
		glRotatef(arm1_x, 1.0f, 0.0f, 0.0f);
		glPushMatrix();
		{
			glTranslatef(0.0f, 5.0f, 0.0f);

			glRotatef(arm2_z, 0.0f, 0.0f, 1.0f);
			glRotatef(arm2_x, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, 10.0f, 0.0f);
			glScalef(1.0f, 3.0f, 1.0f);
			glColor3ub(250, 100, 100);
			glutSolidCube(5);
			glColor3ub(0, 0, 0);
			glutWireCube(5);
		}
		glPopMatrix();
		glScalef(1.0f, 2.0f, 1.0f);
		glColor3ub(100, 250, 100);
		glutSolidCube(10);
		glColor3ub(0, 0, 0);
		glutWireCube(10);

	}
	glPopMatrix();


	/*glColor3ub(250, 250, 0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-50.0f, -50.0f, -100.0f);
	glVertex3f(-100.0f, -50.0f, -100.0f);
	glVertex3f(-100.0f, -50.0f, -50.0f);
	glEnd();
	*/

	glPushMatrix();
	{
		glColor3ub(250, 250, 0);
		glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(-30.0f, -49.0f, -100.0f);
		glVertex3f(-100.0f, -49.0f, -100.0f);
		glVertex3f(-100.0f, -49.0f, -30.0f);
		glEnd();
		glTranslatef(-80.0f, -25.0f, -80.0f);
		glPushMatrix();
		{
			glColor3ub(0, 200, 0);
			glTranslatef(0.0f, 40.0f, 0.0f);
			glScalef(tree_size, tree_size, tree_size);
			glutWireSphere(20,10,10);
		}
		glPopMatrix();
		glScalef(1.0f, 2.5f, 1.0f);
		glColor3ub(50, 50, 50);
		glutSolidCube(20);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(40.0f, -25.0f, 70.0f);
		glPushMatrix();
		{
			glColor3ub(200, 200, 200);
			glScalef(1.0f, 10.0f, 1.0f);
			glutSolidCube(5);
		}
		glPopMatrix();
		glTranslatef(40.0f, 0.0f, 0.0f);
		glPushMatrix();
		{
			glColor3ub(200, 200, 200);
			glScalef(1.0f, 10.0f, 1.0f);
			glutSolidCube(5);
		}
		glPopMatrix();
		glTranslatef(-20.0f, 20.0f, 0.0f);
		glPushMatrix();
		{
			glColor3ub(200, 200, 200);
			glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
			glScalef(1.0f, 10.0f, 1.0f);
			glutSolidCube(4);
		}
		glPopMatrix();
		glRotatef(spin, 1.0f, 0.0f, 0.0f);
		glTranslatef(0.0f, -20.0f, 0.0f);
		glPushMatrix();
		{
			glColor3ub(250, 200, 200);
			glScalef(2.0f, 2.0f, 1.0f);
			glutSolidCube(5);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glColor3ub(250, 200, 200);
			glTranslatef(7.5f, 10.0f, 0.0f);
			glScalef(1.0f, 3.0f, 1.0f);
			glutSolidCube(5);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glColor3ub(250, 200, 200);
			glTranslatef(-7.5f, 10.0f, 0.0f);
			glScalef(1.0f, 3.0f, 1.0f);
			glutSolidCube(5);
		}
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glColor3ub(200, 200, 200);
		glTranslatef(-70.0f, -40.0f, 70.0f);
		glPushMatrix();
		{
			glTranslatef(-10.0f, 0.0f, 0.0f);
			glScalef(1.0f, 1.0f, 10.0f);
			glutSolidCube(5);

		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(10.0f, 0.0f, 0.0f);
			glScalef(1.0f, 1.0f, 10.0f);
			glutSolidCube(5);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(10.0f, 10.0f, 20.0f);
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
			glScalef(1.0f, 1.0f, 10.0f);
			glutSolidCube(5);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(-10.0f, 10.0f, 20.0f);
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
			glScalef(1.0f, 1.0f, 10.0f);
			glutSolidCube(5);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(0.0f, 40.0f, 0.0f);
			glScalef(2.0f, 3.0f, 1.0f);
			glutSolidCube(5);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(-2.5f, 40.0f, 0.0f);
			glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
			glRotatef(leg1, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, 15.0f, 0.0f);
			glScalef(1.0f, 3.0f, 1.0f);
			glutSolidCube(5);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(2.5f, 40.0f, 0.0f);
			glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
			glRotatef(leg2, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, 15.0f, 0.0f);
			glScalef(1.0f, 3.0f, 1.0f);
			glutSolidCube(5);
		}
		glPopMatrix();

		glColor3ub(250, 250, 0);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(2.0f, 1.0f, 2.0f);
		glRotatef(-run, 0.0f, 0.0f, 1.0f);
		glutWireTorus(3.0f, 10.0f, 10, 10);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glColor3ub(200, 200, 200);
		glTranslatef(70.0f, -40.0f, -70.0f);

		glPushMatrix();
		{
			glScalef(3.0f, 1.0f, 6.0);
			glutSolidCube(5);
		}
		glPopMatrix();

		glTranslatef(0.0f, 5.0f, 5.0f);
		glColor3ub(250, 200, 200);
		glPushMatrix();
		{
			glScalef(1.5f, 1.0f, 2.0f);
			glutSolidCube(5);
		}
		glPopMatrix();
		glTranslatef(0.0f, 10.0f, 5.0f);
		glPushMatrix();
		{
			glColor3ub(200, 200, 200);
			glTranslatef(0.0f, babel1, 0.0f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			glScalef(1.0f, 1.0f, 10.0f);
			glutSolidCube(2);
		}
		glPopMatrix();
		glPushMatrix();
		{
			glTranslatef(-10.0f, babel1, 0.0f);
			glScalef(1.0f, 3.0f, 3.0f);
			glutSolidCube(5);
		}
		glPopMatrix();
		glPushMatrix();
		{
			glTranslatef(10.0f, babel2, 0.0f);
			glScalef(1.0f, 3.0f, 3.0f);
			glutSolidCube(5);
		}
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(0.0f, 80.0f, 0.0f);
		glRotatef(turning, 0.0f, 1.0f, 0.0f);
		glTranslatef(-50.0f, 0.0f, 0.0f);
		glPushMatrix();
		{
			glColor3ub(100, 100, 100);
			glScalef(2.0f, 3.0f, 8.0f);
			glutSolidCube(5);
		}
		glPopMatrix();
		glPushMatrix();
		{
			glColor3ub(160, 100, 230);
			glTranslatef(0.0f, 0.0f, -15.0f);
			glScalef(4.0f, 1.0f, 1.0f);
			glutSolidCube(5);
		}
		glPopMatrix();
		glPushMatrix();
		{
			glColor3ub(160, 160, 230);
			glTranslatef(10.0f, 0.0f, -15.0f);
			glScalef(0.4f, 2.0f, 4.0f);
			glutSolidCube(5);
		}
		glPopMatrix();
		glPushMatrix();
		{
			glColor3ub(160, 160, 230);
			glTranslatef(-10.0f, 0.0f, -15.0f);
			glScalef(0.4f, 2.0f, 4.0f);
			glutSolidCube(5);
		}
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(0.0f, 80.0f, 0.0f);


		glPushMatrix();
		{
			glRotatef(turning - 40.0f, 0.0f, 1.0f, 0.0f);
			glTranslatef(-50.0f, 0.0f, 0.0f);
			glColor3ub(150, 150, 150);
			glScalef(2.0f, 2.0f, 2.0f);
			glutSolidCube(10);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glRotatef(turning - 60.0f, 0.0f, 1.0f, 0.0f);
			glTranslatef(-50.0f, 0.0f, 0.0f);
			glColor3ub(150, 150, 150);
			glScalef(1.5f, 1.5f, 1.5f);
			glutSolidCube(10);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glRotatef(turning - 80.0f, 0.0f, 1.0f, 0.0f);
			glTranslatef(-50.0f, 0.0f, 0.0f);
			glColor3ub(150, 150, 150);
			glScalef(1.0f, 1.0f, 1.0f);
			glutSolidCube(10);
		}
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glColor4ub(200, 100, 50, 200);
		gluQuadricDrawStyle(sph, GLU_LINE);
		gluQuadricNormals(sph, GLU_SMOOTH);
		gluQuadricOrientation(sph, GLU_OUTSIDE);
		glTranslatef(sph_x, -30.0f, sph_z);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(sph_angle_x, 1.0f, 0.0f, 0.0f);
		glRotatef(sph_angle_y, 0.0f, 1.0f, 0.0f);
		glRotatef(sph_angle_z, 0.0f, 0.0f, 1.0f);
		gluSphere(sph, 20, 20, 20);
		glRotatef(angle_x, 1.0f, 0.0f, 0.0f);
		glRotatef(angle_y, 0.0f, 1.0f, 0.0f);
		glRotatef(angle_z, 0.0f, 0.0f, 1.0f);
	}
	glPopMatrix();

	glutSwapBuffers();
}

void SetupRC()
{
	glEnable(GL_DEPTH_TEST);  // 은면 제거
	glFrontFace(GL_CCW);   // 앞면 설정  
	//glEnable(GL_CULL_FACE);  // 내부는 잘라낸다  
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	sph = gluNewQuadric();

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
	case 't':
		if (arm1_x < 90.0f)
			arm1_x += 6.0f;
		break;
	case 'g':
		if (arm1_x > 0.0f)
			arm1_x -= 6.0f;
		break;
	case 'f':
		if (arm1_y < 90.0f)
			arm1_y += 7.0f;
		break;
	case 'h':
		if (arm1_y > 0.0f)
			arm1_y -= 7.0f;
		break;
	case 'o':
		if (arm2_x < 90.0f)
			arm2_x += 8.0f;
		break;
	case 'l':
		if (arm2_x > 0.0f)
			arm2_x -= 8.0f;
		break;
	case 'k':
		if (arm2_z > 0.0f)
			arm2_z -= 5.0f;
		break;
	case ';':
		if (arm2_z < 90.0f)
			arm2_z += 5.0f;
		break;
	case 'b':
		if (sph_x < 100.0f&&sph_z<50.0f&&sph_z>-50.0f)
		{
			sph_x += 10.0f;
		}
		else if (sph_x < 30.0f&&sph_z<-50.0f&&sph_z>-100.0f)
		{
			sph_x += 10.0f;
		}
		else if (sph_x < 30.0f&&sph_z<100.0f&&sph_z>50.0f)
		{
			sph_x += 10.0f;
		}
		sph_angle_x += 5.0f;
		break;
	case 'B':
		if (sph_x > -100.0f&&sph_z<50.0f&&sph_z>-50.0f)
		{
			sph_x -= 10.0f;
		}
		else if (sph_x > -30.0f&&sph_z<-50.0f&&sph_z>-100.0f)
		{
			sph_x -= 10.0f;
		}
		else if (sph_x > -30.0f&&sph_z<100.0f&&sph_z>-50.0f)
		{
			sph_x -= 10.0f;
		}
		sph_angle_x -= 5.0f;
		break;
	case 'm':
		sph_angle_y += 5.0f;
		break;
	case 'M':
		sph_angle_y -= 5.0f;
		break;
	case 'n':
		if (sph_z < 100.0f&&sph_x<50.0f&&sph_x>-50.0f)
		{
			sph_z += 10.0f;
		}
		else if (sph_z < 30.0f&&sph_x<-50.0f&&sph_x>-100.0f)
		{
			sph_z += 10.0f;
		}
		else if (sph_z < 30.0f&&sph_x<100.0f&&sph_x>50.0f)
		{
			sph_z += 10.0f;
		}
		sph_angle_z += 5.0f;
		break;
	case 'N':
		if (sph_z > -100.0f&&sph_x<50.0f&&sph_x>-50.0f)
		{
			sph_z -= 10.0f;
		}
		else if (sph_z > -30.0f&&sph_x<-50.0f&&sph_x>-100.0f)
		{
			sph_z -= 10.0f;
		}
		else if (sph_z > -30.0f&&sph_x<100.0f&&sph_x>50.0f)
		{
			sph_z -= 10.0f;
		}
		sph_angle_z -= 5.0f;
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
	if (box1_x - 30 <= sph_x && box1_x + 30 >= sph_x && (sph_z >= -10 && sph_z <= 10))
	{
		box_way *=-1;
	}
	else if (box1_x > 100.0f)
	{
		box_way = -5.0f;
	}
	else if (box1_x < -100.0f)
	{
		box_way = 5.0f;
	}

	if (tree_size > 2.0f)
	{
		size = -0.05f;
	}
	else if (tree_size < 1.0f)
	{
		size = 0.05f;
	}

	if (leg1 > 30.0f)
	{
		leg1_dir = -5.0f;
	}
	else if (leg1 < -30.0f)
	{
		leg1_dir = 5.0f;
	}

	if (leg2 > 30.0f)
	{
		leg2_dir = -5.0f;
	}
	else if (leg2 < -30.0f)
	{
		leg2_dir = 5.0f;
	}

	if (babel1 >= 20.0f&&babel2 >= 20.0f)
	{
		m = -5.0f;
	}
	else if (babel1 <= 0.0f&&babel2 <= 0.0f)
	{
		m = 5.0f;
	}

	tree_size += size;
	box1_x += box_way;
	spin += 10.0f;
	run += 10.0f;
	leg1 += leg1_dir;
	leg2 += leg2_dir;
	babel1 += m;
	babel2 += m;
	turning += 10.0f;
	glutTimerFunc(100, TimerFunction, 1);
}