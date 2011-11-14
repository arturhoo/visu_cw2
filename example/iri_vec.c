#include <stdio.h>

#include <GL/glut.h>

#include "iri_vec.h"

/*
 * Library of basic 3D vector functions written by Roy Ruddle for use with the
 * Advanced Graphics Modules in the School of Computing at Leeds University.
 *
 * 4 October 2001
 *
 */

void iri_v3copy( GLfloat vin[], GLfloat vout[] )
/*
 * Copy a quaternion (vout = vin).
 *
 * vin  IN      3D vector
 * vout OUT     3D vector
 *
 */
{
  GLint l1;

  for( l1=0; l1<3; l1++ ) {
    vout[l1] = vin[l1];
  }
}

void iri_v3norm( GLfloat vec[] )
/*
 * Normalise supplied 3D vector.
 *
 * vec		INOUT	3D vector (unit vector exit)
 *
 */
{
  GLfloat length;

  length = vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2];

  if( length > 1.0e-8 ) {
    length = (GLfloat) sqrt( (double) length );
    vec[0] /= length;
    vec[1] /= length;
    vec[2] /= length;
  }
}

void iri_v3sub( GLfloat v1[], GLfloat v2[], GLfloat vres[] )
/*
 * Calculate vres = v1 - v2
 *
 * v1   IN      3D vector
 * v2   IN      3D vector
 * vres OUT     3D vector
 *
 */
{
  GLint l1;
 
  for( l1=0; l1<3; l1++ ) {
    vres[l1] = v1[l1] - v2[l1];
  }
}

void iri_v3cross( GLfloat v1[], GLfloat v2[], GLfloat vres[] )
/*
 * Calculate cross product of two vectors
 *
 * v1   IN      3D vector
 * v2	IN	3D vector
 * vres OUT	Cross product 3D vector
 *
 */
{
  vres[0] = v1[1]*v2[2]-v1[2]*v2[1];
  vres[1] = v1[2]*v2[0]-v1[0]*v2[2];
  vres[2] = v1[0]*v2[1]-v1[1]*v2[0];
}

GLfloat iri_v3dot( GLfloat v1[], GLfloat v2[] )
/*
 * Return dot (scalar) product of two vectors
 *
 * v1   IN      3D vector
 * v2   IN      3D vector
 *
 */
{
  return ((v1[0]*v2[0])+(v1[1]*v2[1])+(v1[2]*v2[2]));
}
