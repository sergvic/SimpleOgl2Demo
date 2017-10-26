#include "GL\freeglut.h"
#include <time.h>

float min = -10, max = 10;
float alp = 0;
size_t prevTime;

void onDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1, 0, 0);

	glLineWidth(5);

	glBegin(GL_LINES);
	glVertex2f(-5.0-alp, -5.0 + alp);
	glVertex2f(5 + alp, 5 - alp);
	glColor3f(1, 0.5, 0);
	glVertex2f(-5, 5);
	glVertex2f(2, 5);
	glEnd();

	glutSwapBuffers();
}

void onResize(int w, int h)
{

}

void onIdle()
{
	static float d = 0.5;
	if (clock() - prevTime>20) {
		prevTime = clock();
		alp += d;
		if (alp < min) {
			alp = min;
			d = -d;
		}

		if (alp > max) {
			alp = max;
			d = -d;
		}

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