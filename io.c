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


int main() {
  FILE * pFile;
  pFile = fopen("example1.pgm", "r");
  char * line = readLine(pFile);
  printf("%s\n", line);

  return 1;
}
