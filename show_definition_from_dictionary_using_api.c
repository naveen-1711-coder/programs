// program to show meaning of a word from dictionary using api

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 30
#define LINE_SIZE 2000
#define DELIMITER "{}[]\""
#define COMMAND_SIZE 150
#define DICTIONARY_FILE "dictionary.json"
#define NEXT_TOKEN() strtok(NULL, DELIMITER)

int main()
{
    char word[WORD_SIZE];
    char command[COMMAND_SIZE];
    char line[LINE_SIZE];
    char *token;
    char audio_url[COMMAND_SIZE];
    char play_command[COMMAND_SIZE];
    FILE *fp_definition;
    int found = 0;
    int choice, is_audio_played = 0;

    do
    {
    	printf("\n-------- Dictionary --------\n");
    	printf("\nEnter a word: ");
    	scanf("%29s", word);

    	sprintf(command, "curl -s \"https://api.dictionaryapi.dev/api/v2/entries/en/%s\" -o dictionary.json", word);

    	system(command);
		fp_definition = fopen(DICTIONARY_FILE, "r");

    	if (fp_definition == NULL)
    	{
        	printf("Unable to open dictionary file\n");
        	return 1;
    	}

    	choice = 0;

    	while (fgets(line, LINE_SIZE, fp_definition))
    	{
    		char *token = strtok(line, DELIMITER);
    		while (token != NULL)
    		{
    			if (strcmp(token, "audio") == 0)
    			{
    				NEXT_TOKEN();
    				token = NEXT_TOKEN();

    				if (token != NULL && strlen(token) > 0)
    				{
    					strcpy(audio_url, token);
    				}
    			}

    			if (strcmp(token, "definition") == 0)
    			{
    				NEXT_TOKEN();
    				token = NEXT_TOKEN();

    				found = 1;

    				if (is_audio_played == 0)
    				{
    					sprintf(play_command, "vlc --intf dummy --play-and-exit \"%s\"", audio_url);
    					system(play_command);
    					is_audio_played = 1;
    				}

    				printf("\nDefiniton of %s:\n%s", word, token);
    				while (token != NULL)
    				{
    					if (token == "\"")
    					{
    						
    					}
    				}

    				if (choice == 0)
    				{
    					printf("Do you want multiple definitions for the word?\nEnter (1 for yes, 0 for no): ");
    					scanf("%d", &choice);
    				}

    				if (choice == 0)
    				break;
    			}
    			token = NEXT_TOKEN();
    		}

    		if (found)
    		{
    			break;
    		}
    	}

    	fclose(fp_definition);

    	if (!found)
    	{
        	printf("\nMeaning not found.\n");
    	}

    	printf("\nDo you want to print another word definition?\n");
    	printf("Enter (1 for yes & 0 for no): ");
    	scanf("%d", &choice);

    	found = 0;
    	is_audio_played = 0;
    } while (choice);
    	
}