#include <stdio.h>
int main()
{
    int reading[12];
    int readingcount, registrationdigits, index, inputvalue, minimumreading, maximumreading;
    int total = 0, secondhighest = 0, foundSecondHighest = 0, peakcount = 0, divisibleReadingCount = 0;
    int increasingRunLength = 1, longestIncreasingLength = 1;
    int rotationamount, rightshift, leftindex, rightindex, divisor;
    float average;

    printf("Enter number of readings (5 to 12): ");
    scanf("%d", &readingcount);

    while (readingcount < 5 || readingcount > 12) 
    {
        printf("Invalid number. Enter a value from 5 to 12: ");
        scanf("%d", &readingcount);
    }
    printf("Enter the last two digits of your registration number (0 to 99): ");
    scanf("%d", &registrationdigits);

    while (registrationdigits < 0 || registrationdigits > 99) 
    {
        printf("Invalid value. Enter a number from 0 to 99: ");
        scanf("%d", &registrationdigits);
    }
    for (index = 0; index < readingcount; index++) 
    {
        printf("Enter reading %d (0 to 1000): ", index + 1);
        scanf("%d", &inputvalue);
        while (inputvalue < 0 || inputvalue > 1000) 
        {
            printf("Invalid reading. Enter a value from 0 to 1000: ");
            scanf("%d", &inputvalue);
        }

        reading[index] = inputvalue;
    }

    printf("\nOriginal readings: ");
    for (index = 0; index < readingcount; index++) 
    {
        printf("%d ", reading[index]);
    }
    printf("\n");

    minimumreading = reading[0];
    maximumreading = reading[0];

    for (index = 0; index < readingcount; index++) 
    {
        total = total + reading[index];

        if (reading[index] < minimumreading) 
        {
            minimumreading = reading[index];
        }

        if (reading[index] > maximumreading) 
        {
            maximumreading = reading[index];
        }
    }

    average = (float)total / readingcount;

    printf("Sum: %d\n", total);
    printf("Average: %.2f\n", average);
    printf("Minimum reading: %d\n", minimumreading);
    printf("Maximum reading: %d\n", maximumreading);

    for (index = 0; index < readingcount; index++) 
    {
        if (reading[index] < maximumreading) 
        {
            if (foundSecondHighest == 0) 
            {
                secondhighest = reading[index];
                foundSecondHighest = 1;
            } else if (reading[index] > secondhighest) 
            {
                secondhighest = reading[index];
            }
        }
    }

    if (foundSecondHighest == 1) 
    {
        printf("Second-largest distinct value: %d\n", secondhighest);
    } else {
        printf("There is no second-largest distinct value.\n");
    }

    for (index = 1; index < readingcount - 1; index++) 
    {
        if (reading[index] > reading[index - 1] && reading[index] > reading[index + 1]) 
        {
            peakcount++;
        }
    }

    printf("Number of local peaks: %d\n", peakcount);

    for (index = 1; index < readingcount; index++) 
    {
        if (reading[index] > reading[index - 1]) 
        {
            increasingRunLength++;

            if (increasingRunLength > longestIncreasingLength) 
            {
                longestIncreasingLength = increasingRunLength;
            }
        } else 
        {
            increasingRunLength = 1;
        }
    }

    printf("Longest increasing run length: %d\n", longestIncreasingLength);

    printf("Enter rotation amount K (positive = right, negative = left): ");
    scanf("%d", &rotationamount);

    rightshift = rotationamount % readingcount;

    if (rightshift < 0) 
    {
        rightshift = rightshift + readingcount;
    }

    if (rightshift > 0) 
    {
        leftindex = 0;
        rightindex = readingcount - 1;

        while (leftindex < rightindex) 
        {
            inputvalue = reading[leftindex];
            reading[leftindex] = reading[rightindex];
            reading[rightindex] = inputvalue;
            leftindex++;
            rightindex--;
        }
        leftindex = 0;
        rightindex = rightshift - 1;

        while (leftindex < rightindex) 
        {
            inputvalue = reading[leftindex];
            reading[leftindex] = reading[rightindex];
            reading[rightindex] = inputvalue;
            leftindex++;
            rightindex--;
        }
        leftindex = rightshift;
        rightindex = readingcount - 1;

        while (leftindex < rightindex) 
        {
            inputvalue = reading[leftindex];
            reading[leftindex] = reading[rightindex];
            reading[rightindex] = inputvalue;
            leftindex++;
            rightindex--;
        }
    }
    printf("Readings after rotation: ");
    for (index = 0; index < readingcount; index++) 
    {
        printf("%d ", reading[index]);
    }
    printf("\n");

    divisor = (registrationdigits % 9) + 1;
    for (index = 0; index < readingcount; index++) 
    {
        if (reading[index] % divisor == 0) 
        {
            divisibleReadingCount++;
        }
    }
    printf("D = %d\n", divisor);
    printf("Readings divisible by D: %d\n", divisibleReadingCount);
}
