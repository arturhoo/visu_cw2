//
// GI31 OpenGL visualization practical answer.
//
#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <GL/glut.h>
#include <GL/glu.h>

#define ROYS_SOLUTION

#define CALC_NORMALS_FROM_CROSS_PRODUCT
#ifdef CALC_NORMALS_FROM_CROSS_PRODUCT
#include "iri_vec.h"
#endif

/* Window size */
static int winWidth = 500, winHeight = 500;

/* Function headers */
void init(void); 
void keyboard(unsigned char key, int x, int y);
void display(void);
void initSettings(void);
void myReshape(int w, int h);
int main(int argc, char **argv);

void init(void) 
/*
* Initialise state
*/
{
	GLfloat vfov = 45.0f; /* Vertical field of view in degrees */
	GLfloat near = 1.0;    	/* near clipping plane in eye coords */
	GLfloat far = 1000.0;    	/* far clipping plane in eye coords */

#ifdef ROYS_SOLUTION
	GLfloat light_ambient[4] = {0.1, 0.1, 0.1, 1.0};
	GLfloat light_diffuse[4] = {0.7, 0.7, 0.7, 1.0};
	GLfloat light_specular[4] = {0.0, 0.0, 0.0, 1.0};
	GLfloat mat_amb_diff[4] = {1.0, 1.0, 1.0, 1.0};
	GLfloat mat_specular[4] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_shininess[4] = {0.0, 0.0, 0.0, 0.0};

	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
#endif

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective( vfov, (GLfloat) winWidth / (GLfloat) winHeight, near, far);
}

void keyboard(unsigned char key, int x, int y)
/*
* Keyboard callback function
*/
{
	switch(key) {
		case 27:
			exit(0);
		default:
			break;
	}
}

void display(void)
/*
* Display callback function.
*/
{
	int l1, l2;
	//
	// Initialise for drawing
	//
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/* Set view transform */
	GLfloat eye[3] = {0.0f, -2.0f, 2.0f}; /* Viewpoint position */
	GLfloat at[3] = {0.0f, 0.0f, 0.0f}; /* Point we are looking at */
	GLfloat upDir[3] = {0.0f, 0.0f, 1.0f}; /* View up vector */
	gluLookAt( eye[0], eye[1], eye[2],  at[0], at[1], at[2], upDir[0], upDir[1], upDir[2] );
	//
	// Draw terrain
	//terrain-answer
	const int NUM_VERTICES = 10;
	float xyz[3], angle, squashingFactor = 0.3f;

#ifdef ROYS_SOLUTION
    float vertexA[3], vertexB[3];

#ifdef CALC_NORMALS_FROM_CROSS_PRODUCT
    float vertexC[3], vectorAB[3], vectorAC[3], normal[3];
#endif
    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

	for( l1=1; l1<=NUM_VERTICES; l1++ ) { // Loop over Y coordinates
		glBegin(GL_TRIANGLE_STRIP);

		for( l2=0; l2<=NUM_VERTICES; l2++ ) { // Loop over X coordinatesnormalAngle
			vertexA[0] = vertexB[0] = float( l2 ) / float( NUM_VERTICES ) - 0.5f;
			angle = 2.0f * 3.142f * float( l2 ) / float( NUM_VERTICES );
			float gradient = squashingFactor * cos( angle ) * 2.0 * 3.142;
			float gradientAngle = atan( gradient );
			float normalAngle = gradientAngle + 0.5f * 3.142f;
			vertexA[2] = vertexB[2] = squashingFactor * sin( angle );
			vertexA[1] = float( l1 ) / float( NUM_VERTICES ) - 0.5f;

			vertexB[1] = float( l1 - 1 ) / float( NUM_VERTICES ) - 0.5f;
			
#ifdef CALC_NORMALS_FROM_CROSS_PRODUCT
			//
			// The usual way of calculating normals in 3D graphics
			//
			vertexC[0] = float( l2 + 1 ) / float( NUM_VERTICES ) - 0.5f;
			vertexC[1] = vertexA[1];
			angle = 2.0f * 3.142f * float( l2 + 1 ) / float( NUM_VERTICES );
			vertexC[2] = squashingFactor * sin( angle );

			iri_v3sub( vertexB, vertexA, vectorAB );
			iri_v3norm( vectorAB );
			iri_v3sub( vertexC, vertexA, vectorAC );
			iri_v3norm( vectorAC );
			
			iri_v3cross( vectorAB, vectorAC, normal );
			
			glNormal3f( normal[0], normal[1], normal[2] );
#else
			glNormal3f( cos( normalAngle ), 0.0f, sin( normalAngle ) ); // Calculate normals from trigonometry
#endif
			glVertex3f( vertexA[0], vertexA[1], vertexA[2] );
			glVertex3f( vertexB[0], vertexB[1], vertexB[2] );
		}
		glEnd();

	}
	GLfloat light0_pos[4] = { 0.0F, 0.0F, 1.0F, 0.00F };

	glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
#else
	//
	// Draw terrain as a grid of points, equally spaced in X and Y (in range -0.5 to 0.5), and with the Z coordinate defined by a squashed sinewave.
	glBegin(GL_POINTS);
	glColor3f( 1.0f, 1.0f, 1.0f ); // White

	for( l1=0; l1<=NUM_VERTICES; l1++ ) { // Loop over Y coordinates
		xyz[1] = float( l1 ) / float( NUM_VERTICES ) - 0.5f;

		for( l2=0; l2<=NUM_VERTICES; l2++ ) { // Loop over X coordinates
			xyz[0] = float( l2 ) / float( NUM_VERTICES ) - 0.5f;
			angle = 2.0f * 3.142f * float( l2 ) / float( NUM_VERTICES );
			xyz[2] = squashingFactor * sin( angle );
			glVertex3f( xyz[0], xyz[1], xyz[2] );
		}
	}
	glEnd();
#endif

	glFlush();
	glutSwapBuffers();
}

void myReshape(int w, int h)
/*
* Window reshape callback function
*/
{
	glViewport(0, 0, w, h);
	winWidth = w;
	winHeight = h;
}

int main(int argc, char **argv)
/*
* Main program
*/
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Terrain-answer");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
	return 1;
}
