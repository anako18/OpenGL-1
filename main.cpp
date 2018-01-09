#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <ctime>

using namespace std;

static int w = 0, h = 0;

double rotate_x = 0;
double rotate_y = 0;
double rotate_z = 0;

void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
}

void Reshape(int width, int height) {
	w = width;
	h = height;
}

void sphere() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glutSolidSphere(50.0f, 50, 50);
	glFlush();
	glutSwapBuffers();
}

void render_triangle() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	glVertex3d(0, 0, 0);
	glVertex3d(.5f, .5f, .5f);
	glVertex3d(-.5f, 0, 0);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void render_rectangle() {
	glBegin(GL_QUADS);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
	glVertex2f(0, -0.5f);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(0, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void render_color_triangle() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3d(-.3, 0, 0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3d(.9f, .9f, .9f);
	glColor3f(0.7, 0.0, 0.7);
	glVertex3d(.9f, 0, 0);
	glEnd();

	glFlush();
	glutSwapBuffers();
}


//render_teapot() - 0
//render_sphere() - 1
//render_cube() - 2
//render_cone()  - 3
//render_torus() - 4
//render_dodecahedron() -5 
//render_octahedron() - 6
//render_tetrahedron() -7
//render_icosahedron() -8

int i = 0;

void render_figure() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);

	switch (i) {
	case 0: 
		glutWireTeapot(.6); break;
	case 1:
		glutWireSphere(.6, 40, 40); break;
	case 2:
		//glRotatef(80, 0.0, 1.0, 1.0);
		glutWireCube(1); break;
	case 3:
		//glRotatef(80, 0.0, 1.0, 1.0);
		glutWireCone(.6, .6, 30, 30); break;
	case 4:
		//glRotatef(80, 0.0, 1.0, 1.0);
		glutWireTorus(.2, .5, 50, 50); break;
	case 5:
		//glRotatef(80, 0.0, 1.0, 1.0);
		glScaled(.5, .5, .5);
		glutWireDodecahedron(); break;
	case 6:
		//glRotatef(80, 0.0, 1.0, 1.0);
		glutWireOctahedron(); break;
	case 7:
		//glRotatef(80, 1.0, 1.0, 1.0);
		glutWireTetrahedron(); break;
	case 8:
		//glRotatef(80, 0.0, 1.0, 1.0);
		glutWireIcosahedron(); break;
	default:
		glRotatef(80, 0.0, 1.0, 1.0);
		glutWireSphere(.5, 50, 50); //break;
		glutWireCube(1); //break;
		glutWireCone(.5, .6, 50, 50); //break;
		glutWireTorus(.5, .5, 50, 50); //break;
		glutWireDodecahedron(); //break;
		glutWireOctahedron();// break;
		glutWireTetrahedron(); //break;
		glutWireIcosahedron();// break;
	}
	glFlush();
	glutSwapBuffers();
}

void render_teapot() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glutWireTeapot(.6);

	glFlush();
	glutSwapBuffers();
}

void Mouse(int button, int state, int x, int y) {
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
		rotate_x = 0;
		rotate_y = 0;
		rotate_z = 0;
		glColor3ub(rand() % 255, rand() % 255, rand() % 255);
		i < 7 ? i++ : i = 0;
		glutPostRedisplay();
	}

	if (state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON) {
		rotate_x = 0;
		rotate_y = 0;
		rotate_z = 0;
		glColor3ub(rand() % 255, rand() % 255, rand() % 255);
		i > 0 ? i-- : i = 8;
		glutPostRedisplay();
	}
}

void turn(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP: rotate_x += 5; break;
	case GLUT_KEY_DOWN: rotate_x -= 5; break;

	case GLUT_KEY_RIGHT: rotate_y += 5; break;
	case GLUT_KEY_LEFT: rotate_y -= 5; break;

	case GLUT_KEY_F1: rotate_z += 5; break;
	case GLUT_KEY_F2: rotate_z -= 5; break;
	}
	glutPostRedisplay();
}


int main(int argc, char* argv[]) {
	glutInit(&argc, argv);

	glutInitWindowPosition(400, 0);
	glutInitWindowSize(800, 800);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutCreateWindow("OpenGL");

	//Task1
	glutReshapeFunc(changeViewPort);
	i = 0;
	//glutDisplayFunc(render_figure);

	//Task2
	//glutDisplayFunc(render_triangle);
	//glutDisplayFunc(render_rectangle);
	//glutDisplayFunc(render_color_triangle);


	//Task3
	//i = 0;
	glutDisplayFunc(render_figure);
	glutMouseFunc(Mouse);
	glutSpecialFunc(turn);

	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}

	glutMainLoop();
	return 0;


}