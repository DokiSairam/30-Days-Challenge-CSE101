# Challenge 04 – LOOPLAB: Daily Expense Analysis

## Problem Statement

Create a C program called LOOPLAB to analyze daily expenses. The program repeatedly accepts expense amounts until the user enters `0`. For each positive amount, it classifies the expense into Small, Medium, or Large categories, updates the corresponding counts and totals, and finally displays a summary of all valid expenses. Negative amounts are considered invalid and must not affect any count or total.

## Objective

To practice loops, conditional statements, arithmetic operators, and variables in C by developing a program that classifies daily expenses, calculates totals and averages, and displays a summary. The program must not use arrays, functions, or strings.

## Algorithm

1. Start.
2. Initialize all expense counts and totals to zero.
3. Read an expense amount from the user.
4. If the amount is `0`, stop accepting input and proceed to the summary.
5. If the amount is negative, display an error message and do not update any count or total.
6. If the amount is positive and below ₹100, classify it as Small, increment the Small expense count, and add the amount to the Small total.
7. If the amount is ₹100 or more but below ₹500, classify it as Medium, increment the Medium expense count, and add the amount to the Medium total.
8. If the amount is ₹500 or more, classify it as Large, increment the Large expense count, and add the amount to the Large total.
9. Repeat steps 3–8 until the user enters `0`.
10. Calculate the total number of valid expenses and the total amount of valid expenses.
11. If at least one valid expense was entered, calculate the average valid expense. Otherwise, display a suitable message indicating that no valid expenses were entered.
12. Display the total number of valid expenses, total expense amount, count and total for each category, and average valid expense when applicable.
13. Stop.
