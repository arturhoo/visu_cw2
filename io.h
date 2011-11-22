// 
// io.h
// Header for io.cpp
// Artur Rodrigues - 2011
// 

char * readLine(FILE * pFile);
void skipLines(FILE * pFile);
int ** allocateMatrix(int nrows, int ncolumns);
void getMatrix(int ** matrix, FILE * pFile, int ncolumns, int nrows);
int * getDimension(FILE * pFile);
int getMaxHeight(FILE * pFile);
