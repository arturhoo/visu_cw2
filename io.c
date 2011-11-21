#include <stdio.h>
#include <stdlib.h>

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

  char * line = malloc(numChar*sizeof(char));
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

int ** getMatrix(FILE * pFile){
  int counter = 0;
  char * line;
  for(counter; counter<3; counter++) {
    line = readLine(pFile);
  }
  int width, height;
  sscanf(line, "%d %d", &width, &height);
  printf("Width: %d, Height: %d\n", width, height);

  int ** matrix = malloc(width*sizeof(int*));
  for(counter = 0; counter<width; counter++) {
    matrix[counter] = malloc(height*sizeof(int));
  }

  return matrix;
}


int main() {
  FILE * pFile;
  pFile = fopen("example1.pgm", "r");
  int ** matrix = getMatrix(pFile);
  return 1;
}
