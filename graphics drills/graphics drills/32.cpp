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
float Spec_valuse = 1.0f;