#include<stdio.h>
int main()
{
    float expense,total=0,smalltotal=0,mediumtotal=0,largetotal=0,average;
    int count=0,smallcount=0,mediumcount=0,largecount=0;

    do{
        printf("The amount is used =");
        scanf("%f",&expense);

        if(expense > 0)
        {
            count++;
            total = total+expense;
        }else if(expense < 0)
        {
            printf("The entered amount is invalid and it will not be counted in your expense  \n");
        }

        if(expense < 100)
        {
            smallcount++;
            smalltotal = smalltotal+expense;
        }else if(expense < 500)
        {
            mediumcount++;
            mediumtotal = mediumtotal+expense;
        }else
        {
            largecount++;
            largetotal =  largetotal+expense;
        }

    } while (expense != 0);
    
    printf("...........................................................................\n");
    printf("The Number of valid expenses are = %d\n",count);
    printf("Total number of valid expenses are = %f\n",total);
    printf("Small expenses and The Total =%f, Count = %d\n",smalltotal,smallcount);
    printf("Medium expenses and The Total =%f, Count =%d\n",mediumtotal,mediumcount);
    printf("Large exppenses and the Total =%f, Count =%d\n",largetotal,largecount);

    if (count>0)
    {
        average = total/count;
        printf("The average valid expenses are = %f\n",average);
    }else{
        printf("The entered expenses are not valid\n so there is no average\n");
    }
}
