//program to show temperature usiing api with strtok

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30
#define LENGTH 1000
#define DELIMITER "{},:"
#define NEXT_TOKEN() strtok(NULL, DELIMITER)
#define WEATHER_FILE "weather.json"

int main()
{
    char city_name[SIZE];
    char command[LENGTH];
    char buffer[LENGTH];
    float temperature = 0.0;
    FILE* fp_weather;

    printf("Enter the city name to show temperature: ");
    scanf("%29[^\n]", city_name);

    sprintf(command, "wget -q -O weather.json \"https://api.openweathermap.org/data/2.5/weather?q=%s&units=metric&appid=f1bbfa2e14bd200cb37f84449b442047\"", city_name);

    system(command);

    fp_weather = fopen(WEATHER_FILE, "r");

    while (fgets(buffer, LENGTH, fp_weather))
    {
        char *token = strtok(buffer, DELIMITER);

        while (token != NULL)
        {
            if (strcmp(token, "\"temp\"") == 0)
            {
                token = NEXT_TOKEN;
                temperature = atof(token);
                printf("The temperature of %s is %.2f degrees\n", city_name, temperature);
                break;
            }
            token = NEXT_TOKEN();
        }
    }

    fclose(fp_weather);
    return 0;
}
