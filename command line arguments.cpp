#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Date {
	int day;
	int month;
	int year;
};

struct Time {

	int min;
	int hour;

};

struct worktime
{
	int employeeID;
	struct Date date;
	struct Time startTime;
	struct Time endTime;
};

void main(int argc, char *argv[])
{
	FILE * fptr;
	struct worktime worker[3];
	char delim[] = "/:";
	char del[] = ",";
	char del2[] = " ':";
	int i;
	int j = 3;
	char *id[3];
	char *start[3];
	char *end[3];
	char *date[3];
	char *token;
	char day1[3];
	char day2[3];
	char day3[3];
	char month1[50];
	char month2[50];
	char month3[50];
	char year1[50];
	char year2[5];
	char year3[5];
	char hour1[6];
	char hour2[6];
	char hour3[6];
	char min1[6];
	char min2[6];
	char min3[6];
	char ehour1[6];
	char ehour2[6];
	char ehour3[6];
	char emin1[6];
	char emin2[6];
	char emin3[6];
	int Day[3];
	int Month[3];
	int Year[3];
	int ID[3];
	int Min[3];
	int Hour[3];
	int Emin[3];
	int Ehour[3];
	char line[200];



	
	
	
	if (!strcmp(argv[2], "/a"))
	{
		for (i = 0; i < 3; i++)
		{
			id[i] = argv[j];
			j++;
			date[i] = argv[j];
			j++;
			start[i] = argv[j];
			j++;
			end[i] = argv[j];
			j++;


		}




		token = strtok(date[0], delim);
		strcpy(day1, token);
		token = strtok(NULL, delim);
		strcpy(month1, token);
		token = strtok(NULL, delim);
		strcpy(year1, token);

		token = strtok(date[1], delim);
		strcpy(day2, token);
		token = strtok(NULL, delim);
		strcpy(month2, token);
		token = strtok(NULL, delim);
		strcpy(year2, token);

		token = strtok(date[2], delim);
		strcpy(day3, token);
		token = strtok(NULL, delim);
		strcpy(month3, token);
		token = strtok(NULL, delim);
		strcpy(year3, token);

		token = strtok(start[0], delim);
		strcpy(hour1, token);
		token = strtok(NULL, delim);
		strcpy(min1, token);

		token = strtok(start[1], delim);
		strcpy(hour2, token);
		token = strtok(NULL, delim);
		strcpy(min2, token);

		token = strtok(end[0], delim);
		strcpy(ehour1, token);
		token = strtok(NULL, delim);
		strcpy(emin1, token);

		token = strtok(end[1], delim);
		strcpy(ehour2, token);
		token = strtok(NULL, delim);
		strcpy(min2, token);


		ID[0] = atoi(id[0]);
		ID[1] = atoi(id[1]);
		ID[2] = atoi(id[2]);

		Day[0] = atoi(day1);
		Day[1] = atoi(day2);
		Day[2] = atoi(day3);

		Month[0] = atoi(month1);
		Month[1] = atoi(month2);
		Month[2] = atoi(month3);

		Year[0] = atoi(year1);
		Year[1] = atoi(year2);
		Year[2] = atoi(year3);

		Hour[0] = atoi(hour1);
		Min[0] = atoi(min1);

		Hour[1] = atoi(hour2);
		Min[1] = atoi(min2);

		Hour[2] = atoi(hour3);
		Min[2] = atoi(min3);

		Ehour[0] = atoi(ehour1);
		Emin[0] = atoi(emin1);

		Ehour[1] = atoi(ehour2);
		Emin[1] = atoi(emin2);

		Ehour[2] = atoi(hour2);
		Emin[2] = atoi(min2);

		for (i = 0; i < 3; i++)
		{
			worker[i].date.day = Day[i];
			worker[i].date.month = Month[i];
			worker[i].date.year = Year[i];

			worker[i].employeeID = ID[i];

			worker[i].startTime.hour = Hour[i];
			worker[i].startTime.min = Min[i];

			worker[i].endTime.hour = Ehour[i];
			worker[i].endTime.min = Emin[i];


		}
		fptr = fopen("C:\\Users\\samuel ojo\\Desktop\\programmin\\workers", "a+");

		for (i = 0; i < 3; i++)
		{
			fprintf(fptr, "'march %d %d','%d','%d:%d','%d:%d'\n ", worker[i].date.day, worker[i].date.year, worker[i].employeeID, worker[i].startTime.hour, worker[i].startTime.min, worker[i].endTime.hour, worker[i].endTime.min);
		}

		fclose(fptr);
	}

	if (!strcmp(argv[2], "/p"))
	{
		fptr = fopen("C:\\Users\\samuel ojo\\Desktop\\programmin\\workers", "r");

		for (i = 0; i < 3; i++)
		{
			fgets(line, 100, fptr);
			

			printf("%s", line);

		}
		fclose(fptr);
	}

	if (!strcmp(argv[2], "/s"))
	{
		fptr = fopen("C:\\Users\\samuel ojo\\Desktop\\programmin\\workers", "r");
		for (i = 0; i < 3; i++)
		{
			fgets(line, 100, fptr);
			token = strtok(line, del2);

			strcpy(month1, token);

			token = strtok(NULL, del2);
			worker[i].date.day = atoi(token);

			token = strtok(NULL, del2);
			worker[i].date.year = atoi(token);

			token = strtok(NULL, del2);
			token = strtok(NULL, del2);
			worker[i].employeeID = atoi(token);
			token = strtok(NULL, del2);
			token = strtok(NULL, del2);
			worker[i].startTime.hour = atoi(token);
			token = strtok(NULL, del2);
			worker[i].startTime.min = atoi(token);
			token = strtok(NULL, del2);
			token = strtok(NULL, del2);
			worker[i].endTime.hour = atoi(token);
			token = strtok(NULL, del2);
			worker[i].endTime.min = atoi(token);
		}
			if (!strcmp(argv[3], "1001"))
			{
				printf("The data belonging to this ID are Date: March %d %d Start time: %d:%d End time: %d:%d\n", worker[0].date.day, worker[0].date.year, worker[0].startTime.hour, worker[0].startTime.min, worker[0].endTime.hour, worker[0].endTime.min);
			}

			if (!strcmp(argv[3], "1010"))
			{
				printf("The data belonging to this ID are Date: March %d %d Start time: %d:%d End time: %d:%d\n", worker[1].date.day, worker[1].date.year, worker[1].startTime.hour, worker[1].startTime.min, worker[1].endTime.hour, worker[1].endTime.min);
			}

			if (!strcmp(argv[3], "2987"))
			{
				printf("The data belonging to this ID are Date: March %d %d Start time: %d:%d End time: %d:%d\n", worker[2].date.day, worker[2].date.year, worker[2].startTime.hour, worker[2].startTime.min, worker[2].endTime.hour, worker[2].endTime.min);
			}
		}






			

			





			


		}
	


	















