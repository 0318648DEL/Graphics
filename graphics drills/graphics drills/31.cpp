#include "pch.h"
#include <stdlib.h>
#include <gl/freeglut.h>
#include <gl/glut.h>

#define WIDTH 800
#define HEIGHT 600

GLUquadricObj *sph;
GLUquadricObj *light1;
GLUquadricObj *light2;

float Diffuse = 1.0f;
float Specular = 1.0f;

GLfloat AmbientLight_01[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat DiffuseLight_01[] = { Diffuse,Diffuse,Diffuse, 1.0f};
GLfloat SpecularLight_01[] = { Specular,Specular,Specular,1.0f };
GLfloat LightPos_01[] = { 200.0,200.0,0.0,1.0 };
GLfloat AmbientLight_02[] = { 0.0f,0.0f,1.0f,1.0f };
GLfloat DiffuseLight_02[] = { 0.0f,0.0f,1.0f,1.0f };
GLfloat SpecularLight_02[] = { 0.0f,0.0f,1.0f,1.0f };
GLfloat LightPos_02[] = { -200.0,200.0,0.0,1.0 };

GLfloat specref[] = { 1.0f,1.0f,1.0f,1.0f };

int Light_switch_01 = 0;
int Light_switch_02 = 0;
int LIght_switch_auto = 0;

float Light_angle_01 = 0.0f;
float Light_angle_02 = 0.0f;

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
	glutCreateWindow("31");

	SetupRC();

	glutDisplayFunc(DrawScene);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutTimerFunc(100, TimerFunction, 1);

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

	sph = gluNewQuadric();
	light1 = gluNewQuadric();
	light2 = gluNewQuadric();
}

void DrawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 400.0, 400.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight_01);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight_01);
	glLightfv(GL_LIGHT0, GL_SPECULAR, SpecularLight_01);

	glLightfv(GL_LIGHT1, GL_AMBIENT, AmbientLight_02);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, DiffuseLight_02);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SpecularLight_02);


	glPushMatrix();
	{
		glRotatef(Light_angle_01, 0.0f, 1.0f, 0.0f);
		glLightfv(GL_LIGHT0, GL_POSITION, LightPos_01);
		glTranslatef(200.0f, 200.0f, 0.0f);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
		glMateriali(GL_FRONT, GL_SHININESS, 10);
		glEnable(GL_AUTO_NORMAL);
		glColor3f(0.5f, 0.5f, 0.5f);
		gluCylinder(light1, 50.0, 0.0, 50.0, 20, 8);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glRotatef(Light_angle_02, 0.0f, 1.0f, 0.0f);
		glLightfv(GL_LIGHT1, GL_POSITION, LightPos_02);
		glTranslatef(-200.0f, 200.0f, 0.0f);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
		glMateriali(GL_FRONT, GL_SHININESS, 10);
		glEnable(GL_AUTO_NORMAL);
		glColor3f(0.5f, 0.5f, 0.5f);
		gluCylinder(light2, 50.0, 0.0, 50.0, 20, 8);
	}
	glPopMatrix();

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 24);
	glEnable(GL_AUTO_NORMAL);
	glColor3f(0.0f, 0.5f, 0.5f);
	gluSphere(sph, 50, 20, 20);

	glutSwapBuffers();
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
	case 'y':
		Light_angle_01 += 13.0f;
		Light_angle_02 += 13.0f;
		break;
	case 'Y':
		Light_angle_01 -= 13.0f;
		Light_angle_02 -= 13.0f;
		break;
	case 'a':
		LIght_switch_auto = 1;
		break;
	case 'A':
		LIght_switch_auto = 0;
		break;
	case 'd':
		if (Diffuse > 0.0f)
		{
			Diffuse -= 0.05f;
			DiffuseLight_01[0] = Diffuse;
			DiffuseLight_01[1] = Diffuse;
			DiffuseLight_01[2] = Diffuse;
		}
		break;
	case 'D':
		if (Diffuse < 1.0f)
		{
			Diffuse += 0.05f;
			DiffuseLight_01[0] = Diffuse;
			DiffuseLight_01[1] = Diffuse;
			DiffuseLight_01[2] = Diffuse;
		}
		break;
	case 's':
		if (Specular > 0.0f)
		{
			Specular-=0.05f;
			SpecularLight_01[0] = Specular;
			SpecularLight_01[1] = Specular;
			SpecularLight_01[2] = Specular;
		}
		break;
	case 'S':
		if (Specular < 1.0f)
		{
			Specular+=0.05f;
			SpecularLight_01[0] = Specular;
			SpecularLight_01[1] = Specular;
			SpecularLight_01[2] = Specular;
		}
		break;
	}

	glutPostRedisplay();
}

void TimerFunction(int value)
{
	if (LIght_switch_auto)
	{
		Light_angle_01 += 13.0f;
		Light_angle_02 += 13.0f;
	}

	glutPostRedisplay();
	glutTimerFunc(6, TimerFunction, 1);
}