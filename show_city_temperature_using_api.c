// progamtoshow temperature of a city by using api

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30
#define LENGTH 400
#define WEATHER_FILE "weather.json"

void main()
{
	char city_name[SIZE];
	char command[LENGTH];
	char *ptr_temperature;
	char buffer[LENGTH];
	float temperature;
 
	printf("Enter the city name to show temperature: ");
	scanf("%29[^\n]", city_name);

	FILE* fp_weather = fopen(WEATHER_FILE, "w");
	fclose(fp_weather);

	sprintf(command, "wget -q -O weather.json \"https://api.openweathermap.org/data/2.5/weather?q=%s&units=metric&appid=f1bbfa2e14bd200cb37f84449b442047\"", city_name);

	system(command);

	fp_weather = fopen(WEATHER_FILE, "r");

	while (fgets(buffer, LENGTH, fp_weather))
	{
		ptr_temperature = strstr(buffer, "\"temp\":");

		if (ptr_temperature != NULL) 
		{    
            sscanf(ptr_temperature, "\"temp\":%f", &temperature);
            printf("The temperature in %s is  %.2f Degree\n", city_name, temperature);
            break;
        }		
	}
	fclose(fp_weather);
}