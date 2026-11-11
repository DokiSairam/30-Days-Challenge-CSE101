# Challenge 10 – Campus Green Environment Monitoring

## Problem Statement

Develop a menu-based C program to monitor and evaluate environmental conditions in five university campus locations: Academic Block, Hostel, Library, Cafeteria, and Sports Area. The application stores temperature, humidity, and AQI values for seven days. It processes the collected information to calculate environmental averages, identify unsafe conditions, generate Green Index scores, compare the performance of different zones, and provide suggestions for maintaining a healthier campus environment.

## Objective

To implement a practical environmental data analysis system using C programming concepts such as two-dimensional arrays, functions, loops, and decision-making statements. The program aims to improve understanding of data storage, validation, environmental calculations, risk identification, and menu-driven operations.

## Algorithm

1. Start
2. define the necessary arrays for storing environmental readings of all five zones.
3. Initialize a menu-driven system that allows the user to select different environmental analysis operations.
4. Accept temperature, humidity, and AQI values for each zone for seven days, ensuring that all readings satisfy the given validation rules.
5. Store the accepted readings and provide an option to update previously entered environmental data.
6. Retrieve and present the stored readings in a structured format whenever the display option is selected.
7. Find the average temperature, humidity, and AQI values separately for every zone.
8. Check each day's readings against the environmental risk conditions and calculate the total number of risk days for each zone.
9. Use the calculated averages to determine the Green Index score of every zone.
10. Arrange the zones according to their Green Index scores and display their respective ranks, including equal ranks for identical scores.
11. Analyze the environmental results and display suitable improvement measures for each campus location.
12. Return to the main menu after completing an operation and continue until the exit option is selected.
13. Stop
