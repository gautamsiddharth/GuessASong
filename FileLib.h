/*
Siddharth Gautam
1001741324
CSE 1320_002
Coding Assignment #7

*/
#ifndef _FILELIB_H_
#define _FILELIB_H_
#include <errno.h>
#include "GameLib.h"


void get_command(char *argv[], char PName[], char PValue[]);
FILE *OpenFile (int args, char *arvs[], char mode[]);
int ReadFileIntoArray(FILE *fileRead, music Song[]);
void WriteFile(music Song[], int value, FILE *FileWrite);


#endif
