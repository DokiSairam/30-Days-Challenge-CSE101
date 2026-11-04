/*
Your university is organising a technical event in an auditorium with 5 rows and 8 seats in each row. 
Develop a menu-driven C program called SEATSMART to manage seat reservations. 
The program must allow users to view seats, book or cancel an individual seat, reserve consecutive seats for a group, and view an occupancy report. 
You must use a two-dimensional array and separate user-defined functions for the major operations.
Use one 5 × 8 integer array. A value of 0 means Available and a value of 1 means Booked. 
At the beginning, all 40 seats are available. Individual row numbers must be 1–5 and seat numbers 1–8. 
A group size must be from 2–8. Validate each value before using it. 
For individual booking/cancellation, pass the user-entered 1-based row and seat values to the functions; 
validate and convert them to 0-based indices inside the function.
*/

#include <stdio.h>

int totalauditoriumseats[5][8];

void makeseatavailable(void);
void showSeatingChart(void);
int booksingleseat(int , int );
int cancelsingleseat(int , int );
int bookmultipleseats(int , int );
void showleftseat(void);

int main(void)
{
    int selectoption;
    int rownumber;
    int seatNumber;
    int numberOfSeats;

    makeseatavailable();

    do {
        printf("\n--------------------------------------------------------------\n");
        printf("Seat Allocation and Available Menu Bar : \n");
        printf("1. Display all the seats available \n");
        printf("2. Book one seat from the available seat \n");
        printf("3. Cancel a booking seat\n");
        printf("4. Reserve a group of seats \n");
        printf("5. Show the availability of seats \n");
        printf("6. Ended now you can exit \n");

        printf("Enter your choice from the options given above: ");
        scanf("%d", &selectoption);

        if (selectoption == 1) 
        {
            showSeatingChart();
        }
        else if (selectoption == 2) 
        {
            printf("Enter the row and seat number: ");
            scanf("%d %d", &rownumber, &seatNumber);

            if (booksingleseat(rownumber, seatNumber)) 
            {
                printf("Seat booked successfully.\n");
            } else {
                printf("That seat is invalid or already booked.\n");
            }
        }
        else if (selectoption == 3) 
        {
            printf("Enter the row and seat number to cancel: ");
            scanf("%d %d", &rownumber, &seatNumber);

            if (cancelsingleseat(rownumber, seatNumber)) 
            {
                printf("Booking cancelled successfully.\n");
            } else {
                printf("That seat is invalid or was not booked.\n");
            }
        }
        else if (selectoption == 4) 
        {
            printf("Enter the row and number of seats needed: ");
            scanf("%d %d", &rownumber, &numberOfSeats);

            if (!bookmultipleseats(rownumber, numberOfSeats)) 
            {
                printf("No suitable consecutive seats are available.\n");
            }               
        }
        else if (selectoption == 5) 
        {
            showleftseat();
        }
        else if (selectoption == 6) 
        {
            printf("Program ended.\n");
        }
        else 
        {
            printf("Please enter a number from 1 to 6.\n");
        }

    } while (selectoption != 6);

    return 0;
}

void makeseatavailable(void)
{
    int rowIndex;
    int seatIndex;

    for (rowIndex = 0; rowIndex < 5; rowIndex++) 
    {
        for (seatIndex = 0; seatIndex < 8; seatIndex++) 
        {
            totalauditoriumseats[rowIndex][seatIndex] = 0;
        }
    }
}

void showSeatingChart(void)
{
    int rowIndex;
    int seatIndex;

    printf("\n0 = Available, 1 = Booked\n");

    for (rowIndex = 0; rowIndex < 5; rowIndex++) 
    {
        printf("Row %d: ", rowIndex + 1);

        for (seatIndex = 0; seatIndex < 8; seatIndex++) 
        {
            printf("%d ", totalauditoriumseats[rowIndex][seatIndex]);
        }

        printf("\n");
    }
}

int booksingleseat(int rownumber, int seatNumber)
{
    if (rownumber < 1 || rownumber > 5 || seatNumber < 1 || seatNumber > 8) 
        {
        return 0;
    }

    if (totalauditoriumseats[rownumber - 1][seatNumber - 1] == 1) 
    {
        return 0;
    }

    totalauditoriumseats[rownumber - 1][seatNumber - 1] = 1;
    return 1;
}

int cancelsingleseat(int rownumber, int seatNumber)
{
    if (rownumber < 1 || rownumber > 5 || seatNumber < 1 || seatNumber > 8) 
    {
        return 0;
    }

    if (totalauditoriumseats[rownumber - 1][seatNumber - 1] == 0) 
    {
        return 0;
    }

    totalauditoriumseats[rownumber - 1][seatNumber - 1] = 0;
    return 1;
}

int bookmultipleseats(int rownumber, int numberOfSeats)
{
    int firstSeatIndex;
    int seatOffset;
    int blockIsAvailable;

    if (rownumber < 1 || rownumber > 5 || numberOfSeats < 1 || numberOfSeats > 8) 
    {
        return 0;
    }

    for (firstSeatIndex = 0; firstSeatIndex <= 8 - numberOfSeats; firstSeatIndex++) 
        {
        blockIsAvailable = 1;

        for (seatOffset = 0; seatOffset < numberOfSeats; seatOffset++) 
        {
            if (totalauditoriumseats[rownumber - 1] [firstSeatIndex + seatOffset] == 1) 
            {
                blockIsAvailable = 0;
            }
        }

        if (blockIsAvailable == 1) 
        {
            for (seatOffset = 0; seatOffset < numberOfSeats; seatOffset++)
            {
                totalauditoriumseats[rownumber - 1] [firstSeatIndex + seatOffset] = 1;
            }

            printf("Reserved seats %d to %d in row %d.\n",firstSeatIndex + 1,firstSeatIndex + numberOfSeats,rownumber);

            return 1;
        }
    }

    return 0;
}

void showleftseat(void)
{
    int rowIndex;
    int seatIndex;
    int totalBookedSeats = 0;
    int bookedSeatsInRow;
    int highestRowBookingCount = 0;

    for (rowIndex = 0; rowIndex < 5; rowIndex++) 
    {
        bookedSeatsInRow = 0;

        for (seatIndex = 0; seatIndex < 8; seatIndex++) 
        {
            if (totalauditoriumseats[rowIndex][seatIndex] == 1) 
            {
                totalBookedSeats++;
                bookedSeatsInRow++;
            }
        }

        if (bookedSeatsInRow > highestRowBookingCount) 
        {
            highestRowBookingCount = bookedSeatsInRow;
        }
    }

    printf("\n--- Occupancy Report ---\n");
    printf("Total seats: 40\n");
    printf("Booked seats: %d\n", totalBookedSeats);
    printf("Available seats: %d\n", 40 - totalBookedSeats);
    printf("Occupancy: %.1f%%\n", totalBookedSeats * 100.0 / 40);
    printf("Row(s) with the most booked seats: ");

    for (rowIndex = 0; rowIndex < 5; rowIndex++) 
    {
        bookedSeatsInRow = 0;

        for (seatIndex = 0; seatIndex < 8; seatIndex++) 
        {
            if (totalauditoriumseats[rowIndex][seatIndex] == 1) 
            {
                bookedSeatsInRow++;
            }
        }

        if (bookedSeatsInRow == highestRowBookingCount) 
        {
            printf("%d ", rowIndex + 1);
        }
    }

    printf("\n");
}
