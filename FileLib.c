

#include "FileLib.h"
#include "GameLib.h"

void get_command(char *argv[], char PName[], char PValue[])
{
	int i= 1;
	while(argv[i] != NULL)
	{
		if(!strncmp(argv[i], PName, strlen(PName)))
		{
			strcpy(PValue, strchr(argv[i], '=')+ 1);
		}
		i++;
	}
}	

FILE *OpenFile (int argc, char *argv[], char mode[2])
{
	FILE *FileOpen= NULL;
	char FileName[100]= {};
	get_command(argv, "FILENAME=", FileName);
	
	
	if(argc==1)
	{
		printf("Must run with an input filename\n");
	}
	else
	{
	
		FileOpen= fopen(FileName, mode);
	}
		
	while(FileOpen == NULL)
	{
		printf("Enter a file name at the prompt ");
		fgets(FileName, sizeof(FileName)-1, stdin);
		FileName[strlen(FileName)-1] = '\0';
		FileOpen= fopen(FileName, mode);
		if(FileOpen==NULL)
		{
			printf("Could not open a file named %s \n", FileName);
		}

	}
	return FileOpen;
}


int ReadFileIntoArray(FILE *FileRead, music Song[])
{
	int count =0;
	char phrase[800]= {};
	char *Token = NULL;
	while(fgets(phrase, sizeof(phrase)-1, FileRead))
	{
		phrase[strlen(phrase)-1]='\0';
		if (count < Max_Entries)
		{
			if(phrase ==" ")
			{
				continue;
			}
			Token = strtok(phrase, "|");
			Song[count].Artist = malloc(strlen(Token)*sizeof(char)+1);
			strcpy(Song[count].Artist, Token);
			
			Token = strtok(NULL, "|");
			Song[count].Title = malloc(strlen(Token)*sizeof(char)+1);
			strcpy(Song[count].Title, Token);
			
			Token = strtok(NULL, "|");
			strcpy(Song[count].Rel_Date, Token);
			
			Token = strtok(phrase, "|");
			Song[count].ALB_Name = malloc(strlen(Token)*sizeof(char)+1);
			strcpy(Song[count].ALB_Name, Token);
			
			count++;
		}
	}
	return count;
}

void WriteFile(music Song[], int value,FILE *FileWrite)
{
	int i=0;
	while(i!= sizeof(Song))
	{
		if(i!=value)
		{
			fprintf(FileWrite, "%s|%s|%s|%s", Song[i].Artist, Song[i].Title, Song[i].Rel_Date, Song[i].ALB_Name);
		}
		else if(i==value)
		{
			i++;
			fprintf(FileWrite, "%s|%s|%s|%s", Song[i].Artist, Song[i].Title, Song[i].Rel_Date, Song[i].ALB_Name);
		}
		i++;
	}
	long position1 = ftell(FileWrite);
	printf("%1d", position1);
	fseek(FileWrite, 0, SEEK_END);
	long position2 = ftell(FileWrite);
	printf("%1d", position2);
	long difference = (position2- position1);
	
	for(i=0; i<sizeof(Song); i++)
	{
		free(Song[i].Artist);
		free(Song[i].Title);
		free(Song[i].ALB_Name);
	}
    for(i=0; i<difference; i++)
	{
		fprintf(FileWrite, "%c",' ');
	}	
	fclose(FileWrite);
}
