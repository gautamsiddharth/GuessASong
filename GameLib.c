
#include <stdio.h>
#include "GameLib.h"
#include "FileLib.h"

int StartGame(char Phrase[Max_Input], FILE *myfile, music Song[])
{
	
	int index =	 ReadFileIntoArray(myfile, Song);
	if(index ==0)
	{
		printf("All the games have been played - please reload file");
		exit(0);
	}
	
	printf("\nWelcome to %d STRIKES - YOU'RE OUT - the CSE version\n\n", Strikes);
	printf("Please pick a phrase from the following menu\n\n");
	char DashPhrase[Max_Input]= {};
	int i =0;
	int choice =0;
	for(i=0; i<index; i++)
	{
		CheckPhrase(Song[i].Title);
		printf("%d.%s's song that was relesed in %s on album %s", i+1, Song[i].Artist, Song[i].Rel_Date, Song[i].ALB_Name);
		printf("\n");
	}
	printf("\nEnter choice: ");
	scanf("%d", &choice);
	
	if(choice<=index && choice> 0)
	{
		printf("Here ia the phrase you need to guess\n");
	    strcpy(Phrase, Song[choice-1].Title);
	}
	else
	{
		printf("\nEnter choice: ");
	    scanf("%d", &choice);
		printf("Here ia the phrase you need to guess\n");
	    strcpy(Phrase, Song[choice-1].Title);
	}
	return choice -1;
   
}


void CheckPhrase(char *PhraseBank)
{
	char *Dash= strchr(PhraseBank, '-');
	if (Dash != NULL)
	{
		int distance = abs(PhraseBank - Dash)+1;
		printf("\n%s contains a dash in postion %d!!", PhraseBank, distance);
		printf("\nyou broke the rules. We can't play.  BYE!!\n");
		exit(0);
	}
	
}
	

int GuessALetter(char Phrase[], char DashPhrase[], char UpperPhrase[])
{
	char Guess;
	char *FindGuess = NULL;
	char UpperPhraseCopy[Max_Input]= {};
	int FoundALetter = 0;

	strcpy(UpperPhraseCopy, UpperPhrase);
	printf("\n%s", DashPhrase);
	printf("\n\nGuess a letter : ");
	scanf(" %c", &Guess);
	Guess = toupper(Guess);
	FindGuess = strchr(UpperPhraseCopy, Guess);

	while(FindGuess != NULL)
	{
		FoundALetter = 1;
		DashPhrase[FindGuess- UpperPhraseCopy]= Phrase[FindGuess-UpperPhraseCopy];
		*FindGuess= '-';
		FindGuess = strchr(UpperPhraseCopy, Guess);
	}

	return FoundALetter;
}
void DashIt( char *PhraseBank, char DashPhrase[])
{
	int i=0;
	for( i=0; i<=strlen(PhraseBank); i++)
	{
		DashPhrase[i]= toupper(*(PhraseBank+i));
	}
	char *CHAR;
	char UPPERCASE[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	CHAR= strpbrk(DashPhrase, UPPERCASE);
	while( CHAR != NULL)
	{
		*CHAR = '-';
		CHAR= strpbrk(DashPhrase, UPPERCASE);
	}
}
