// progamtoshow temperature of a city by using api

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30
#define LENGTH 400

typedef enum
{
	REPLACE_SPACE,
	REPLACE_PLUS
} replace_type;

void replace(char*, replace_type);

void main()
{
	char city_name[SIZE];
	char command[LENGTH];
	char *ptr_temperature;
	char buffer[LENGTH];
	float temperature;

	printf("Enter the city name to show temperature: ");
	scanf("%29[^\n]", city_name);

	replace(city_name, REPLACE_SPACE);

	sprintf(command, "curl -s \"https://api.openweathermap.org/data/2.5/weather?q=%s&units=metric&appid=f1bbfa2e14bd200cb37f84449b442047\"", city_name);

	FILE* fp_weather = popen(command, "r");

	while (fgets(buffer, LENGTH, fp_weather))
	{
		ptr_temperature = strstr(buffer, "\"temp\":");

		if (ptr_temperature != NULL) 
		{    
            sscanf(ptr_temperature, "\"temp\":%f", &temperature);
            replace(city_name, REPLACE_PLUS);
            printf("The temperature in %s is  %.2f degrees\n", city_name, temperature);
            break;
        }		
	}
	
}

void replace(char *city_name, replace_type replace_type)
{
	int counter = 0;

	while (city_name[counter] != '\0')
	{
		if (replace_type == REPLACE_SPACE && city_name[counter] == ' ')
		{
			city_name[counter] = '+';
		}
		else if (replace_type == REPLACE_PLUS && city_name[counter] == '+')
		{
			city_name[counter] = ' ';
		}
		counter++;
	}
}