/*
A campus event uses ticket IDs from 1 to N.
The scanner records N entries, but one ticket ID is missing and another ticket ID has been scanned twice. 
Your job is to audit the scan log, identify the missing and duplicate IDs, and measure how far the scan sequence is out of order.
*/
#include<stdio.h>
int main()
{
    int i,j,missing=0,duplicate=0,numberofid,targetid,ticket[15];

    printf("Enter the value of number of id thet much number you have to give and in between (5-15) = ");
    scanf("%d",&numberofid);

    while(numberofid < 5 || numberofid > 15 )
    {
        printf("The number you have chosen for id is invalid\nplease try again you have to choose from (5-15) ");
        scanf("%d",&numberofid);
    }
    for (i = 0; i < numberofid; i++) 
    {
        printf("Please enter ticket ID %d (1 to %d): ",   i + 1, numberofid);
        scanf("%d", &ticket[i]);

        while (ticket[i] < 1 || ticket[i] > numberofid) 
        {
            printf("Incorrect ID. Enter a value from 1 to %d: ",numberofid);
            scanf("%d", &ticket[i]);
        }
    }
    printf("\nThe ticket numbers you entered, Original scan: ");
    for (i = 0; i < numberofid; i++) 
    
    {
        printf("%d", ticket[i]);
        
        if (i < numberofid - 1) 
        {
            printf(", ");
        }
    }
    printf("\n");
    int isscanvalid = 1, currentid, numberoftimesfound = 0;

    for (currentid = 1; currentid <= numberofid; currentid++)
    {
        int numberoftimesfound = 0;
        
        for (i = 0; i < numberofid; i++)
        {
            if (ticket[i] == currentid)
            {
                numberoftimesfound++;
            }
        }
        
        if (numberoftimesfound == 0) 
        {
            missing = currentid;
        }else if (numberoftimesfound == 2) 
        {
            duplicate = currentid;
        }else if (numberoftimesfound != 1) 
        {
            isscanvalid = 0;
        }
    }
    if (missing == 0 || duplicate == 0) 
    {
        isscanvalid = 0;
    }
    if (isscanvalid == 0) 
    {
        printf("Invalid scan log.\n");
    }else
    {
        printf("Missing ticket ID: %d\n", missing);
        printf("Duplicated ticket ID: %d\n", duplicate);
    }
    int outoforderpair = 0;
    for (i = 0; i < numberofid; i++) 
    {
        for (j = i + 1; j < numberofid; j++)
        {
            if (ticket[i] > ticket[j]) 
            {
                outoforderpair++;
            }
        }
    }
    printf("Number of out-of-order pairs: %d\n",outoforderpair);

    int r = -1;

    printf("Enter the last two digits of your registration number: ");
    scanf("%d", &r);

    while (r < 0 || r > 99) 
    {
        printf("Enter a number from 0 to 99: ");
        scanf("%d", &r);
    }
    targetid = (r % numberofid) + 1;
    printf("The target ticket ID is: %d\n", targetid);
    printf("Target position(s): ");
    
    int targetidmatches = 0;
    
    for (i = 0; i < numberofid; i++) 
    {
        if (ticket[i] == targetid) 
        {
            printf("%d ", i + 1);
            targetidmatches++;
        }
    }
    if (targetidmatches == 0) 
    {
        printf("The target ticket ID was not found");
    }
    printf("\nTarget occurrence count is: %d\n", targetidmatches);
}
