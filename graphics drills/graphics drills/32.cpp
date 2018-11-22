#include "pch.h"
#include <stdlib.h>
#include <gl/freeglut.h>
#include <gl/glut.h>

#define WIDTH 800
#define HEIGHT 600

GLUquadricObj *py1;
GLUquadricObj *py2;
GLUquadricObj *py3;
GLUquadricObj *py4;
GLUquadricObj *py5;

GLUquadricObj *light1;
GLUquadricObj *light2;

float Amb_value = 1.0f;
float Diff_value = 1.0f;
float Spec_value = 1.0f;

GLfloat AmbientLight_01[] = { Amb_value,Amb_value,Amb_value,1.0f };
GLfloat DiffuseLight_01[] = { Diff_value,Diff_value,Diff_value, 1.0f };
GLfloat SpecularLight_01[] = { Spec_value,Spec_value,Spec_value,1.0f };
GLfloat LightPos_01[] = { 200.0,200.0,0.0,1.0 };
GLfloat AmbientLight_02[] = { 0.0f,0.0f,1.0f,1.0f };
GLfloat DiffuseLight_02[] = { 0.0f,0.0f,1.0f,1.0f };
GLfloat SpecularLight_02[] = { 0.0f,0.0f,1.0f,1.0f };
GLfloat LightPos_02[] = { -200.0,200.0,0.0,1.0 };

int Light_switch_01 = 0;
int Light_switch_02 = 0;

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
	glutCreateWindow("32");

	SetupRC();

	glutDisplayFunc(DrawScene);
	glutReshapeFunc(Reshape);
	/*glutKeyboardFunc(Keyboard);
	glutTimerFunc(100, TimerFunction, 1);*/

	glutMainLoop();
}

void SetupRC()
{
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);


	glEnable(GL_LIGHTING);

	glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight_01);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight_01);
	glLightfv(GL_LIGHT0, GL_SPECULAR, SpecularLight_01);

	glLightfv(GL_LIGHT1, GL_AMBIENT, AmbientLight_02);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, DiffuseLight_02);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SpecularLight_02);

	glEnable(GL_DEPTH_TEST);  // 은면 제거
	glFrontFace(GL_CCW);   // 앞면 설정  

	py1 = gluNewQuadric();
	py2 = gluNewQuadric();
	py3 = gluNewQuadric();
	py4 = gluNewQuadric();
	py5 = gluNewQuadric();
	light1 = gluNewQuadric();
	light2 = gluNewQuadric();
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
	case '1':
		if (Light_switch_01)
		{
			glDisable(GL_LIGHT0);
			Light_switch_01 = 0;
		}
		else
		{
			glEnable(GL_LIGHT0);
			Light_switch_01 = 1;
		}
		break;
	case '2':
		if (Light_switch_02)
		{
			glDisable(GL_LIGHT1);
			Light_switch_02 = 0;
		}
		else
		{
			glEnable(GL_LIGHT1);
			Light_switch_02 = 1;
		}
		break;
	case 'a':
		if (Amb_value > 0.0f)
		{
			Amb_value -= 0.05f;
			AmbientLight_01[0] = Amb_value;
			AmbientLight_01[1] = Amb_value;
			AmbientLight_01[2] = Amb_value;
		}
		break;
	case 'A':
		if (Amb_value < 1.0f)
		{
			Amb_value += 0.05f;
			AmbientLight_01[0] = Amb_value;
			AmbientLight_01[1] = Amb_value;
			AmbientLight_01[2] = Amb_value;
		}
		break;
	case 'd':
		if (Diff_value > 0.0f)
		{
			Diff_value -= 0.05f;
			DiffuseLight_01[0] = Diff_value;
			DiffuseLight_01[1] = Diff_value;
			DiffuseLight_01[2] = Diff_value;
		}
		break;
	case 'D':
		if (Diff_value < 1.0f)
		{
			Diff_value += 0.05f;
			DiffuseLight_01[0] = Diff_value;
			DiffuseLight_01[1] = Diff_value;
			DiffuseLight_01[2] = Diff_value;
		}
		break;
	case 's':
		if (Spec_value > 0.0f)
		{
			Spec_value -= 0.05f;
			SpecularLight_01[0] = Spec_value;
			SpecularLight_01[1] = Spec_value;
			SpecularLight_01[2] = Spec_value;
		}
		break;
	case 'S':
		if (Spec_value < 1.0f)
		{
			Spec_value += 0.05f;
			SpecularLight_01[0] = Spec_value;
			SpecularLight_01[1] = Spec_value;
			SpecularLight_01[2] = Spec_value;
		}
		break;
	}

	glutPostRedisplay();
}