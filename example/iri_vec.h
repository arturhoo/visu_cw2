#ifndef IRI_VEC_H
#define IRI_VEC_H

#include <stdio.h>
#include <math.h>
 
#include <GL/glut.h>

/*
 * Library of basic 3D vector functions written by Roy Ruddle for use with the
 * Advanced Graphics Modules in the School of Computing at Leeds University.
 *
 * 4 October 2001
 *
 */
 
#ifdef __cplusplus
extern "C" {                         /* Assume C declarations for C++ */
#endif

void iri_v3copy( GLfloat vin[], GLfloat vout[] );
/*
 * Copy a quaternion (vout = vin).
 *
 * vin  IN      3D vector
 * vout OUT     3D vector
 *
 */                                                                            
 
void iri_v3norm( GLfloat vec[] );
/*
 * Normalise supplied 3D vector.
 *
 * vec          INOUT   3D vector (unit vector exit)
 *
 */                                                                            
 
void iri_v3sub( GLfloat v1[], GLfloat v2[], GLfloat vres[] );
/*
 * Calculate vres = v1 - v2
 *
 * v1   IN      3D vector
 * v2   IN      3D vector
 * vres OUT     3D vector
 *
 */                                                                            
 
void iri_v3cross( GLfloat v1[], GLfloat v2[], GLfloat vres[] );
/*
 * Calculate cross product of two vectors
 *
 * v1   IN      3D vector
 * v2   IN      3D vector
 * vres OUT     Cross product 3D vector. vres = v1 x v2
 *
 */  
                                                                           
GLfloat iri_v3dot( GLfloat v1[], GLfloat v2[] );
/*
 * Return dot (scalar) product of two vectors (returned value = v1.v2)
 *
 * v1   IN      3D vector
 * v2   IN      3D vector
 *
 */                                                                            

#ifdef __cplusplus
}
#endif
 
#endif

