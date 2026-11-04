# Challenge 09 – SmartSeat: Auditorium Seat Reservation System

## Problem Statement

A university is organising a technical event in an auditorium with 5 rows and 8 seats in each row. Develop a menu-driven C program called SMARTSEAT to manage seat reservations. The program allows users to view seats, book or cancel individual seats, reserve consecutive seats for a group, and view an occupancy report. The program uses a two-dimensional array and separate user-defined functions for each operation.

## Objective

To develop a menu-driven C program using two-dimensional arrays, loops, conditional statements, and user-defined functions to manage auditorium seat reservations, perform individual and group bookings, cancel reservations, and generate occupancy reports.

## Algorithm

1. Start.
2. Define the number of rows as 5 and columns as 8.
3. Declare a two-dimensional array to represent the auditorium seats.
4. Initialize all 40 seats to 0, indicating that all seats are available.
5. Display the menu with the following options:
   - Display seats
   - Book one seat
   - Cancel booking
   - Group reservation
   - Occupancy report
   - Exit
6. Read the user's menu choice.
7. Perform the selected operation using the respective user-defined function.
8. For individual booking, accept the row and seat numbers, validate the inputs, and book the seat if it is available.
9. For cancellation, accept the row and seat numbers, validate the inputs, and cancel the booking if the seat is already booked.
10. For group reservation, accept the group size and search each row from left to right for the first available block of consecutive seats. Book the seats if a suitable block is found.
11. Display the updated seating arrangement after every successful booking or cancellation.
12. For the occupancy report, calculate the total booked seats, available seats, occupancy percentage, and the rows having the highest number of booked seats.
13. Repeat the menu until the user selects Exit.
14. Display a closing message and stop.

## C Concepts Used

- Two-dimensional arrays
- User-defined functions
- Function prototypes and function calls
- Menu-driven programming using `switch` statements
- `for` and `while` loops
- Conditional statements (`if-else`)
- Array initialization and traversal
- Input validation
- Seat booking and cancellation
- Consecutive seat allocation
- Occupancy calculation and percentage
- Return values from functions

## Conclusion

This challenge demonstrates the implementation of a smart auditorium seat reservation system using C programming. It provides practical experience with two-dimensional arrays, user-defined functions, menu-driven programming, and conditional statements. The program efficiently manages individual bookings, cancellations, consecutive group reservations, and auditorium occupancy reports.
