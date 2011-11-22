#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
using namespace std;

#include "io.h"

int main() {
  FILE * pFile;
  pFile = fopen("example1.pgm", "r");
  int * dimension = getDimension(pFile);
  rewind(pFile);
  int maxHeight = getMaxHeight(pFile);
  printf("NRows: %d - NColumns: %d - MaxHeight %d\n", dimension[0], dimension[1], maxHeight);
  rewind(pFile);
  int ** matrix = allocateMatrix(dimension[1], dimension[0]);
  getMatrix(matrix, pFile, dimension[0], dimension[1]);


  int i, j;
  for(i=0; i<7; i++) {
    for (j=0; j<24; j++) {
      printf("%d ",matrix[i][j]);
    }
    printf("\n");
  }
  return 0;
}