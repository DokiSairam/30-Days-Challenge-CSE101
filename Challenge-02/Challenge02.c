/*
Calculate and display the amount of fuel required for the trip and the total fuel cost.
*/
#include<stdio.h>
int main()
{
    int distance,mileage,fuelprice;
    float fuelrequired,totalfuelcost;
    printf("Enter the total distance:");
    scanf("%d",&distance);
    printf("Enter the total Mileage:");
    scanf("%d",&mileage);
    printf("Enter the total Fuel Price:");
    scanf("%d",&fuelprice);
    printf("The total distance covered in (km) is =%d\n",distance);
    printf("The total mileage in (km/litre) is =%d\n",mileage);
    printf("The fuel price in (rupees/litre) is =%d\n",fuelprice);
    fuelrequired = distance/mileage;
    totalfuelcost = fuelrequired*fuelprice;
    printf(".......................................................\n");
    printf("The fuel required is =%f\n",fuelrequired);
    printf("The total fuel cost is =%f\n",totalfuelcost);
    return 0;
}
