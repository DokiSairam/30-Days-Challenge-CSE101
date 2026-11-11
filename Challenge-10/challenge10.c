#include <stdio.h>

#define ZONES 5
#define DAYS 7

const char *zoneNames[ZONES] = 
{
    "Academic Block", "Hostel", "Library", "Cafeteria", "Sports Area"
};

void inputData(float temperature[ZONES][DAYS], float humidity[ZONES][DAYS], int airQuality[ZONES][DAYS]);
void displayData(float temperature[ZONES][DAYS], float humidity[ZONES][DAYS], int airQuality[ZONES][DAYS]);
void calculateAverages(float temperature[ZONES][DAYS], float humidity[ZONES][DAYS], int airQuality[ZONES][DAYS],
                       float averageTemperature[ZONES], float averageHumidity[ZONES], float averageAirQuality[ZONES]);
void detectRiskZones(float temperature[ZONES][DAYS], float humidity[ZONES][DAYS], int airQuality[ZONES][DAYS], int riskDays[ZONES]);
void computeGreenIndex(float averageTemperature[ZONES], float averageHumidity[ZONES], float averageAirQuality[ZONES], float greenIndex[ZONES]);
void displayRanking(float greenIndex[ZONES]);
void displayRecommendations(float averageTemperature[ZONES], float averageHumidity[ZONES], float averageAirQuality[ZONES], int riskDays[ZONES]);

float readValue(const char *prompt, float minimum, float maximum)
{
    float value;
    int result;

    do {
        printf("%s", prompt);
        result = scanf("%f", &value);

        if (result != 1) 
        {
            while (getchar() != '\n');
            printf("Please enter a number.\n");
        } else if (value < minimum || value > maximum) 
        {
            printf("Enter a value from %.0f to %.0f.\n", minimum, maximum);
        }
    } while (result != 1 || value < minimum || value > maximum);

    return value;
}

int main(void)
{
    float temperature[ZONES][DAYS] = {0};
    float humidity[ZONES][DAYS] = {0};
    int airQuality[ZONES][DAYS] = {0};
    float averageTemperature[ZONES], averageHumidity[ZONES];
    float averageAirQuality[ZONES], greenIndex[ZONES];
    int riskDays[ZONES], dataEntered = 0, option;

    do {
        printf("\n1. Enter readings\n");
        printf("2. Display readings\n");
        printf("3. Averages \n");
        printf("4. Risk days\n");
        printf("5. Green Index and ranking\n");
        printf("6. Recommendations\n");  
        printf("7. Exit\n");

        option = (int)readValue("Choose: ", 1, 7);

        if (option == 1) 
        {
            inputData(temperature, humidity, airQuality);
            dataEntered = 1;
        } else if (option == 7) 
        {
            printf("Goodbye!\n");
        } else if (!dataEntered) 
        {
            printf("Enter readings first using option 1.\n");
        } else if (option == 2) 
        {
            displayData(temperature, humidity, airQuality);
        } else 
        {
            calculateAverages(temperature, humidity, airQuality, averageTemperature, averageHumidity, averageAirQuality);

            if (option == 3) 
            {
                for (int zone = 0; zone < ZONES; zone++)
                printf("%s: %.1f C, %.1f%% humidity, AQI %.1f\n", zoneNames[zone], averageTemperature[zone], averageHumidity[zone], averageAirQuality[zone]);
            } else if (option == 4 || option == 6) 
            {
                detectRiskZones(temperature, humidity, airQuality, riskDays);

                if (option == 4)
                    for (int zone = 0; zone < ZONES; zone++)
                    printf("%s: %d risk day(s)\n", zoneNames[zone], riskDays[zone]);
                else
                    displayRecommendations(averageTemperature, averageHumidity, averageAirQuality, riskDays);
            } else 
            {
                computeGreenIndex(averageTemperature, averageHumidity, averageAirQuality, greenIndex);
                displayRanking(greenIndex);
            }
        }
    } while (option != 7);

    return 0;
}

void inputData(float temperature[ZONES][DAYS], float humidity[ZONES][DAYS], int airQuality[ZONES][DAYS])
{
    char prompt[60];

    for (int zone = 0; zone < ZONES; zone++) 
    {
        printf("\nEnter readings for %s:\n", zoneNames[zone]);

        for (int day = 0; day < DAYS; day++) 
        {
            sprintf(prompt, "Day %d temperature (10-50 C): ", day + 1);
            temperature[zone][day] = readValue(prompt, 10, 50);

            sprintf(prompt, "Day %d humidity (0-100%%): ", day + 1);
            humidity[zone][day] = readValue(prompt, 0, 100);

            sprintf(prompt, "Day %d AQI (0-500): ", day + 1);
            airQuality[zone][day] = (int)readValue(prompt, 0, 500);
        }
    }
}

void displayData(float temperature[ZONES][DAYS], float humidity[ZONES][DAYS], int airQuality[ZONES][DAYS])
{
    for (int zone = 0; zone < ZONES; zone++) 
    {
        printf("\n%s\nDay  Temperature  Humidity  AQI\n", zoneNames[zone]);
        for (int day = 0; day < DAYS; day++)
        printf("%d    %.1f C       %.1f%%      %d\n", day + 1, temperature[zone][day], humidity[zone][day], airQuality[zone][day]);
    }
}

void calculateAverages(float temperature[ZONES][DAYS],float humidity[ZONES][DAYS], int airQuality[ZONES][DAYS],
                       float averageTemperature[ZONES],float averageHumidity[ZONES],float averageAirQuality[ZONES])
{
    for (int zone = 0; zone < ZONES; zone++) 
    {
        averageTemperature[zone] = averageHumidity[zone] = averageAirQuality[zone] = 0;

        for (int day = 0; day < DAYS; day++) 
        {
            averageTemperature[zone] += temperature[zone][day];
            averageHumidity[zone] += humidity[zone][day];
            averageAirQuality[zone] += airQuality[zone][day];
        }

        averageTemperature[zone] /= DAYS;
        averageHumidity[zone] /= DAYS;
        averageAirQuality[zone] /= DAYS;
    }
}

void detectRiskZones(float temperature[ZONES][DAYS], float humidity[ZONES][DAYS], int airQuality[ZONES][DAYS], int riskDays[ZONES])
{
    for (int zone = 0; zone < ZONES; zone++) 
    {
        riskDays[zone] = 0;
        for (int day = 0; day < DAYS; day++)
        if (airQuality[zone][day] > 150 || temperature[zone][day] > 35 || humidity[zone][day] > 80)
        riskDays[zone]++;
    }
}

void computeGreenIndex(float averageTemperature[ZONES], float averageHumidity[ZONES], float averageAirQuality[ZONES], float greenIndex[ZONES])
{
    for (int zone = 0; zone < ZONES; zone++) 
    {
        float temperatureDifference = averageTemperature[zone] - 25;
        float humidityDifference = averageHumidity[zone] - 50;
        if (temperatureDifference < 0) temperatureDifference = -temperatureDifference;
        if (humidityDifference < 0) humidityDifference = -humidityDifference;

        float aqiScore = 100 - averageAirQuality[zone] / 5;
        float temperatureScore = 100 - 4 * temperatureDifference;
        float humidityScore = 100 - humidityDifference;

        if (aqiScore < 0) aqiScore = 0;
        if (temperatureScore < 0) temperatureScore = 0;
        if (humidityScore < 0) humidityScore = 0;

        greenIndex[zone] = 0.4f * aqiScore + 0.3f * temperatureScore + 0.3f * humidityScore;
    }
}

void displayRanking(float greenIndex[ZONES])
{
    int rank[ZONES];

    for (int zone = 0; zone < ZONES; zone++) 
    {
        rank[zone] = 1;
        for (int other = 0; other < ZONES; other++)
        if (greenIndex[other] > greenIndex[zone])
        rank[zone]++;
    }

    printf("\nGreen Index ranking (higher is better):\n");
    for (int place = 1; place <= ZONES; place++)
        for (int zone = 0; zone < ZONES; zone++)
        if (rank[zone] == place)
        printf("Rank %d: %s - %.2f\n", rank[zone], zoneNames[zone], greenIndex[zone]);
}

void displayRecommendations(float averageTemperature[ZONES], float averageHumidity[ZONES], float averageAirQuality[ZONES], int riskDays[ZONES])
{
    for (int zone = 0; zone < ZONES; zone++) 
    {
        printf("\n%s:\n", zoneNames[zone]);
        if (averageAirQuality[zone] > 150)
            printf("- Reduce vehicle idling and improve ventilation.\n");
        if (averageTemperature[zone] > 35)
            printf("- Add shade or greenery to reduce heat.\n");
        if (averageHumidity[zone] > 80)
            printf("- Improve ventilation and check drainage.\n");
        if (riskDays[zone] > 0)
            printf("- Monitor the %d risk day(s).\n", riskDays[zone]);
        if (riskDays[zone] == 0)
            printf("- No risk days found; continue monitoring.\n");
    }
}
