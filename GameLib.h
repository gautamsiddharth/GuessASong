/*
Siddharth Gautam
1001741324
CSE 1320_002
Coding Assignment #7

*/
#ifndef _GAMELIB_H_
#define _GAMELIB_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max_Input 81
#define Strikes 3
#define Max_Entries 6

typedef struct
{
	char *Artist;
	char *Title;
	char *ALB_Name;
	char Rel_Date[5];
}
music;

int StartGame(char Phrase[Max_Input], FILE *myfile, music Song[]);
void CheckPhrase(char *PhraseBank);
int GuessALetter(char Phrase[Max_Input], char DashPhrase[], char UpperPhrase[]);
void DashIt( char *PhraseBank, char DashPhrase[Max_Input]);
#endif
