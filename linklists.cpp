#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct result
{
	char last[40];
	char first[40];
	int age;
	char email[40];
	struct result *next;
};

void initialise();
struct result *first, *current, *last;

void main()
{

	
	int i;
	int j;
	char extra[100];
	char line[2000];
	FILE *fptr;
	char *token;
	char delim[] = ",";
	int currAge = 0;
	

	fptr = fopen("C:\\Users\\samuel ojo\\Desktop\\programmin\\details.txt", "r");
	fgets(extra, 100, fptr);
	
	
	
	
	while (!feof(fptr))
	{
		initialise();

		fgets(line, 1000, fptr);

		token = strtok(line, delim);
		strcpy(current->last, token);
	
		token = strtok(NULL, delim);
		strcpy(current->first, token);

		token = strtok(NULL, delim);
		current->age = atoi(token);

		token = strtok(NULL, delim);
		strcpy(current->email, token);
		

		


	}

	
	fclose(fptr);
	
	do

	{
		printf("Enter The Age You want to search for:");
		scanf("%d", &currAge);

		current = first;
		while (currAge != current->age)
		{

			current = current->next;

		}

		printf("%s " "%s\n", current->first, current->last);
	} while (currAge = current->age);


	
	





    
}

void initialise()
{
	if (first == NULL) {


		first = (struct result *)malloc(sizeof(struct result));
		first->next = NULL;
		current = first;
	}

	else
	{
		last = (struct result *)malloc(sizeof(struct result));
		current->next = last;
		current = last;
		last->next = NULL;
	}

	
}





