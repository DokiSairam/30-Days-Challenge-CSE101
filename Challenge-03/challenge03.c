/*
To determine the discount and delivery charge using conditional statements 
purchase amount, discount amount, amount after discount, delivery charge, and final payable amount
*/
#include<stdio.h>
int main()
{
    float purchaseamount,deliverycharge,finalpayment,amountafterdiscount,distance,discount;
    int customertype;
    
    printf("Enter the amount purchased : ");
    scanf("%f",&purchaseamount);

    printf("Enter The Custormer Type : ");
    scanf("%d",&customertype);

    printf("Enter distance for delivery (in km) : ");
    scanf("%f",&distance);

    if(purchaseamount < 0 || distance < 0)
    {
        printf("Invalid input\n");
    }

    if(customertype == 1)
    {
        if(purchaseamount >= 2000)
        {
            discount = purchaseamount*0.15;
        }else
        {
            discount = purchaseamount*0.10;
        }
    }    
    else if(customertype == 2)
    {
        if(purchaseamount >=3000)
        {
            discount = purchaseamount*0.08;
        }else   
        {
            discount = 0.00;
        }       
    }else
    {
        printf("Customer type is invlaid please enter the corrent id (1 or 2) \n");
    }
    
    amountafterdiscount = purchaseamount-discount;
    
    if(distance <= 5)
    {
        deliverycharge = 40;
    }else if(distance <= 15)
    {
        deliverycharge = 70;
    }else
    {
        deliverycharge = 100;
    }
    finalpayment = amountafterdiscount+deliverycharge;

    printf("............................................................................\n");
    printf("Purchase amount is = Rs %f\n",purchaseamount);
    printf("Discount amount is = Rs %f\n",discount);
    printf("The amount after the discount is = Rs %f\n",amountafterdiscount);
    printf("Delivery charges taken is = Rs %f\n",deliverycharge);
    printf("The final paymment done by the customer is = Rs %f\n",finalpayment);
}
