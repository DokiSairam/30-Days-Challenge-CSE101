#include<stdio.h>
#include<math.h>
int main()
{
    int option,num,step,answer;
    float a,b,c,d,x,root1,root2;

    while(option != 4)
    {
    printf("\n1st one is Linear Equation \n");
    printf("2nd one is Factorial \n");
    printf("3rd one is Quadratic Equation \n");
    printf("4th one is Now you are allowed to exit or go out \n");
    printf("\nPlease select any one option from (1-4) to proceed further \n");

    printf("\n_________________________________________________________________________________\n");
    
    printf("Select or choose one option from all these option = ");
    scanf("%d",&option);

    printf("_________________________________________________________________________________\n");

    if(option == 1)
    {
        printf("Please enter the values of a and b for the Linear Equation (ax+b=0) = ");
        scanf("%f %f",&a ,&b);
        
        printf("_________________________________________________________________________________\n");
            
            if(a==0)
        {
            if(b==0)
            {
                printf("THERE ARE INFINITELY MANY SOLUTIONS \n");
            }else
                printf("THERE IS NO SOLUTION \n");
        } else 
            {
                x = -b / a;
                printf("THERE IS ONE SOLUTION \n");
                printf("The value of x = %f\n",x);
            }
        }else if(option == 2)
    {
        printf("Enter one integer value (1 to 12) to calculate factorial = ");
        scanf("%d",&num);
        
        printf("_________________________________________________________________________________\n");
        
        if(num > 12 || num < 0)
        {
            printf("Enter a number between 1 to 12 ");
        } else
        {
            answer = 1;

            for(step = 1;step <=num ;step++)
            {
                answer = answer*step;
            }
            printf("%d! = %d\n",num,answer);
        }
    }else if (option == 3)
        {
        printf("Enter the values of a,b and c for the quadratic equation (ax^2 + bx + c = 0) = ");
        scanf("%f %f %f",&a, &b, &c);

        printf("_________________________________________________________________________________\n");
        
        if (a == 0)
        {
            printf("THIS EQUATION DOES NOT BELONGS TO QUADRATIC EQUATION \n");
        }else
        {
        d= b * b - 4 * a * c;
        
        if(d > 0)
        {
            root1 = (-b + sqrt(d))/(2*a);
            root2 = (-b - sqrt(d))/(2*a);
            printf("The two real roots are = %f and %f \n", root1, root2);
        }else if (d == 0)
        {
            root1 = -b/(2 * a);
            printf("One root is repeated = %f\n",root1);
        }else
        {
            printf("NO REAL ROOTS \n");
        }
        }
    }else if(option == 4)
        {
        printf("THANK YOU GOOD BYE !\n");
        }else
        {
        printf("THE OPTION YOU HAVE SELECTED IS INCORRECT\n PLEASE CHOOSE THE CORRECT OPTION AGAIN \n");
        }
    }
}
