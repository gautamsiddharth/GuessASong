/*

Siddharth Gautam
Program that guess a songs from given phrases. 

*/
#include "GameLib.h"
#include "FileLib.h"

int main(int argc, char *argv[])
{
	music Song[Max_Entries]={};
	char Phrase[Max_Input] = {};
	char DashPhrase[Max_Input] = {};
	char UpperPhrase[Max_Input] = {};
	FILE *FileOpen;

	FileOpen = OpenFile(argc, argv, "r+");
	
	int Strike = 0;
	int index = StartGame(Phrase, FileOpen, Song);
	DashIt(Phrase, DashPhrase);
	int i;
	for(i=0; i< strlen(Phrase); i++)
	{
		UpperPhrase[i]= toupper(Phrase[i]);
	}
	
	
	do
	{
		if(GuessALetter(Phrase, DashPhrase, UpperPhrase) == 0)
		{
			Strike ++;
			printf("\nStrike  %d\n", Strike);
		}
	}
	while(strchr(DashPhrase, '-') != NULL && Strike < Strikes);
	if(Strike < Strikes)
	{
		printf("\n\nYou figured is out!!\n\nThe phrase was\n");
		printf("\n%s", DashPhrase);
		printf("\n\nYOU WIN!!!!\n");
	
	}
	else
	{
		printf("\n%d STRIKES - YOU'RE OUT!!\n\n", Strikes);
		printf("Game over");
	}
	return 0;
}
