#include "GL\freeglut.h"
#include <time.h>
#include <string>

using namespace std;

float min = -10, max = 10;
float alp = 0;
float y = max;
size_t prevTime;

void onDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1, 0, 0);

	glLineWidth(5);

	glBegin(GL_LINES);
	glVertex2f(min, y);
	glVertex2f(max, y);
	glEnd();

	glutSwapBuffers();
}

void onResize(int w, int h)
{
	glViewport(0, 0, w, h);
}

void onIdle()
{
	static float d = 0.1;
	if (clock() - prevTime>20) {
		prevTime = clock();

		if (y <= min - 1 || y >= max + 1)
			d = -d;
		
		y -= d;

		glutPostRedisplay();
	}
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("Test");

	gluOrtho2D(-10, 10, -10, 10);

	glutDisplayFunc(onDisplay);
	glutReshapeFunc(onResize);
	glutIdleFunc(onIdle);

	prevTime = clock();

	glutMainLoop();
}