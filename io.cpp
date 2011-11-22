#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

char * readLine(FILE * pFile) {
  int numChar = 0;
  fpos_t tempPosition;
  char c;

  fgetpos(pFile, &tempPosition);
  c = fgetc(pFile);
  while(c != '\n') {
    numChar++;
    c = fgetc(pFile);
  }

  char * line = (char*) malloc(numChar*sizeof(char));
  int counter = 0;
  fsetpos(pFile, &tempPosition);
  c = fgetc(pFile);
  while(c != '\n') {
    line[counter] = c;
    counter++;
    c = fgetc(pFile);
  }

  return line;
}

void skipLines(FILE * pFile) {
  char * line = readLine(pFile);
  line = readLine(pFile);
  fpos_t position;
  while(line[0] == '#') {
    fgetpos(pFile, &position);
    line = readLine(pFile);
  }
  fsetpos(pFile, &position);
}

int ** allocateMatrix(int nrows, int ncolumns) {
  int counter;
  int ** matrix = (int**) malloc(nrows*sizeof(int*));
  for(counter = 0; counter<nrows; counter++) {
    matrix[counter] = (int*) malloc(ncolumns*sizeof(int));
  }

  return matrix;
}

void getMatrix(int ** matrix, FILE * pFile, int ncolumns, int nrows) {
  skipLines(pFile);
  char * line;
  int counter = 0;
  for(; counter<3; counter++) line = readLine(pFile);

  int ccounter, rcounter, tcounter;
  char * token = strtok(line, " ");
  for(rcounter = 0; rcounter<nrows; rcounter++) {
    tcounter = 0;
    for(ccounter = 0; ccounter<ncolumns; ccounter++) {
      if(token == NULL){
        line = readLine(pFile);
        token = strtok(line, " ");
      }
      if(!(tcounter<ncolumns)) {
        break;
      }
      matrix[rcounter][ccounter] = atoi(token);
      token = strtok(NULL, " ");
      tcounter++;
    }
  }
}

int * getDimension(FILE * pFile) {
  int * dimension = (int*) malloc(2*sizeof(int));
  skipLines(pFile);
  char * line = readLine(pFile);
  sscanf(line, "%d %d", &dimension[0], &dimension[1]);

  return dimension;
}

int getMaxHeight(FILE * pFile) {
  skipLines(pFile);
  char * line = readLine(pFile);
  line = readLine(pFile);
  int maxHeight = atoi(line);

  return maxHeight;
}
