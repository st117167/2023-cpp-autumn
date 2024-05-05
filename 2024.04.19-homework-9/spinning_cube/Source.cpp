#include <Header.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cmath>

using namespace std;


class wcPt3D		// class to represent a 2D point
{
public:
	GLfloat x, y, z;
};

GLfloat xRotated, yRotated, zRotated;
GLfloat xScale = 1, yScale = 1, zScale = 1;
GLfloat xTranslate = 0, yTranslate = 0, zTranslate = 02;

string mode = "none";

wcPt3D top[3];
wcPt3D bottom[3];
wcPt3D left[3];
wcPt3D right[3];
wcPt3D front[3];
wcPt3D back[3];


void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

}

void DrawCube(void)
{

	glMatrixMode(GL_MODELVIEW);
	// clear the drawing buffer.
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -10.5);

	glPushMatrix();

	glRotatef(xRotated, 1.0, 0.0, 0.0); // rotation about Y axis
	glRotatef(yRotated, 0.0, 1.0, 0.0); // rotation about Z axis

	glTranslatef(xTranslate, yTranslate, zTranslate);

	glScalef(xScale, yScale, zScale);

	glRotatef(zRotated, 0.0, 0.0, 1.0);
	glBegin(GL_QUADS);        // Draw The Cube Using quads
	glColor3f(0.0f, 1.0f, 0.0f);    // Color Blue
	glVertex3f(1.0f, 1.0f, -1.0f);    // Top Right Of The Quad (Top)
	glVertex3f(-1.0f, 1.0f, -1.0f);    // Top Left Of The Quad (Top)
	glVertex3f(-1, 1, 1);    // Bottom Left Of The Quad (Top)
	glVertex3f(1.0f, 1.0f, 1.0f);    // Bottom Right Of The Quad (Top)
	glColor3f(1.0f, 0.5f, 0.0f);    // Color Orange
	glVertex3f(1.0f, -1.0f, 1.0f);    // Top Right Of The Quad (Bottom)
	glVertex3f(-1.0f, -1.0f, 1.0f);    // Top Left Of The Quad (Bottom)
	glVertex3f(-1.0f, -1.0f, -1.0f);    // Bottom Left Of The Quad (Bottom)
	glVertex3f(1.0f, -1.0f, -1.0f);    // Bottom Right Of The Quad (Bottom)
	glColor3f(1.0f, 0.0f, 0.0f);    // Color Red
	glVertex3f(1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Front)
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Front)
	glVertex3f(-1.0f, -1.0f, 1.0f);    // Bottom Left Of The Quad (Front)
	glVertex3f(1.0f, -1.0f, 1.0f);    // Bottom Right Of The Quad (Front)
	glColor3f(1.0f, 1.0f, 0.0f);    // Color Yellow
	glVertex3f(1.0f, -1.0f, -1.0f);    // Top Right Of The Quad (Back)
	glVertex3f(-1.0f, -1.0f, -1.0f);    // Top Left Of The Quad (Back)
	glVertex3f(-1.0f, 1.0f, -1.0f);    // Bottom Left Of The Quad (Back)
	glVertex3f(1.0f, 1.0f, -1.0f);    // Bottom Right Of The Quad (Back)
	glColor3f(0.0f, 0.0f, 1.0f);    // Color Blue
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Left)
	glVertex3f(-1.0f, 1.0f, -1.0f);    // Top Left Of The Quad (Left)
	glVertex3f(-1.0f, -1.0f, -1.0f);    // Bottom Left Of The Quad (Left)
	glVertex3f(-1.0f, -1.0f, 1.0f);    // Bottom Right Of The Quad (Left)
	glColor3f(1.0f, 0.0f, 1.0f);    // Color Violet
	glVertex3f(1.0f, 1.0f, -1.0f);    // Top Right Of The Quad (Right)
	glVertex3f(1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Right)
	glVertex3f(1.0f, -1.0f, 1.0f);    // Bottom Left Of The Quad (Right)
	glVertex3f(1.0f, -1.0f, -1.0f);    // Bottom Right Of The Quad (Right)
	glEnd();            // End Drawing The Cube

	//glPopMatrix();
	//glutSwapBuffers();

	glFlush();
}


void animation(void)
{

	if (mode == "spin") {
		yRotated += 0.5;
		xRotated += 0.6;
	}

	DrawCube();
}

void reshape(int x, int y)
{
	if (y == 0 || x == 0) return;  //Nothing is visible then, so return
	//Set a new projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Angle of view:40 degrees
	//Near clipping plane distance: 0.5
	//Far clipping plane distance: 20.0

	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);  //Use the whole window for rendering


}

void key(unsigned char key, int x, int y) {
	switch (key) {
	case 115:
		if (mode == "spin") {
			mode = "none";
		}
		else {
			mode = "spin";
		}
		glutPostRedisplay();
		break;
	case 103: //g
		xScale = xScale + .1;
		yScale = yScale + .1;
		zScale = zScale + .1;

		glutPostRedisplay();
		break;
	case 'h':
		xScale = xScale - .1;
		yScale = yScale - .1;
		zScale = zScale - .1;

		glutPostRedisplay();
		break;
	case 'd':
		xTranslate = xTranslate + .1;
		glutPostRedisplay();
		break;
	case 'f':
		xTranslate = xTranslate - .1;
		glutPostRedisplay();
		break;
	case 'j':
		xRotated = xRotated + 1;
		//yRotated = yRotated + 1;
		glutPostRedisplay();
		break;
	case 'k':
		xRotated = xRotated - 1;
		//yRotated = yRotated - 1;
		glutPostRedisplay();
		break;
	}

}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	//we initizlilze the glut. functions
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(DrawCube);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(key);
	//Set the function for the animation.
	glutIdleFunc(animation);
	glutMainLoop();
	return 0;
}