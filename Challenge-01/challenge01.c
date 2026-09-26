/*
To get the Students percentage and average marks; 
*/
#include<stdio.h>
int main()
{
    char sub;
    float marks,mark1,mark2,mark3,mark4,mark5;
    float total,average,percentage;

    printf("Enter the marks scored on 1st subject:");
    scanf("%f",&mark1);
    printf("The marks scored on 1st subject is =%f\n",mark1);

    printf("Enter the marks scored on 2nd subject:");
    scanf("%f",&mark2);
    printf("The marks scored on 2nd subject is =%f\n",mark2);

    printf("Enter the marks scored on 3rd subject:");
    scanf("%f",&mark3);
    printf("The marks scored on 3rd subject is =%f\n",mark3);

    printf("Enter the marks scored on 4th subject:");
    scanf("%f",&mark4);
    printf("The marks scored on 4th subject is =%f\n",mark4);

    printf("Enter the marks scored on 5th subject:");
    scanf("%f",&mark5);
    printf("The marks scored on 5th subject is =%f\n",mark5);
    
    marks = mark1+mark2+mark3+mark4+mark5;
    
    total = marks;
    printf("Total Marks is =%f\n",total);
    average = total/5;
    printf("The Average Marks is =%f\n",average);
    percentage = (marks/500)*100;
    printf("The Percentage is =%f\n",percentage);

}
