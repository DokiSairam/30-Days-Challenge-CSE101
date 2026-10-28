# Challenge 07 – Campus Event Ticket Audit

## Problem Statement

A campus event uses ticket IDs from 1 to N. The scanner records N entries, but one ticket ID is missing and another ticket ID has been scanned twice. The task is to audit the scan log, identify the missing and duplicated ticket IDs, count the out-of-order pairs, and find a personalised audit ticket based on the last two digits of the registration number.

## Objective

To develop a C program using one-dimensional arrays, loops, nested loops, and conditional statements to identify missing and duplicated ticket IDs, count out-of-order pairs, validate input, and locate a personalised target ticket without sorting the sequence or using a second array.

## Algorithm

1. Start.
2. Read the number of ticket IDs, N, ensuring that 5 < N < 15. If N is invalid, ask for it again.
3. Read N ticket IDs, ensuring that each ID is between 1 and N. If an ID is invalid, ask for it again.
4. Display the original scan sequence.
5. Check the frequency of each ticket ID from 1 to N using nested loops.
6. Identify the missing ticket ID, which appears zero times, and the duplicated ticket ID, which appears twice.
7. If the scan log does not contain exactly one missing ID and one duplicated ID, display an invalid scan log message.
8. Count the out-of-order pairs by comparing each ticket ID with every ticket ID to its right. Count a pair when the earlier ID is greater than the later ID.
9. Read the last two numeric digits of the registration number, R, ensuring that R is between 0 and 99.
10. Calculate the target ticket ID using the formula: Target = (R % N) + 1.
11. Display the target ticket ID, all its positions in the original sequence using one-based indexing, and its occurrence count.
12. Stop.

## C Concepts Used

- One-dimensional arrays
- `for` loops and nested loops
- Conditional statements (`if`, `else if`, `else`)
- Input validation using `while` loops
- Frequency counting
- Identifying missing and duplicated values
- Counting out-of-order pairs
- Modulus operator (`%`)
- Array traversal and one-based position display

## Conclusion

This challenge demonstrates how to audit a campus event ticket scan log using a single one-dimensional array. The program uses nested loops and conditional statements to identify missing and duplicated ticket IDs, count out-of-order pairs, validate input, and locate a personalised target ticket without sorting the sequence or using a second array.
