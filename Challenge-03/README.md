# Challenge 03 – SmartCart

## Problem Statement

A student is purchasing items from an online store. Write a C program to read the purchase amount, customer type (1 = Student, 2 = Regular Customer), and delivery distance in kilometres. Determine the discount and delivery charge using the given rules. Display the purchase amount, discount amount, amount after discount, delivery charge, and final payable amount.

## Objective

To apply `if`, `else if`, `else`, relational operators, logical operators, and arithmetic expressions to solve a multi-condition decision-making problem in C.

## Discount Rules

| Condition                                    | Discount |
| -------------------------------------------- | -------: |
| Student and purchase amount ≥ ₹2000          |      15% |
| Student and purchase amount < ₹2000          |      10% |
| Regular Customer and purchase amount ≥ ₹3000 |       8% |
| Regular Customer and purchase amount < ₹3000 |       0% |

## Delivery Rules

| Delivery Distance           | Delivery Charge |
| --------------------------- | --------------: |
| Distance ≤ 5 km             |             ₹40 |
| Distance > 5 km and ≤ 15 km |             ₹70 |
| Distance > 15 km            |            ₹100 |

## Algorithm

1. Start.
2. Read the purchase amount.
3. Read the customer type (1 for Student, 2 for Regular Customer).
4. Read the delivery distance in kilometres.
5. Check the customer type and purchase amount to determine the applicable discount percentage.
6. Calculate the discount amount.
7. Calculate the amount after discount.
8. Determine the delivery charge based on the delivery distance.
9. Calculate the final payable amount by adding the delivery charge to the amount after discount.
10. Display the purchase amount, discount amount, amount after discount, delivery charge, and final payable amount.
11. Stop.

## Formulae

* **Discount Amount** = Purchase Amount × Discount Percentage / 100
* **Amount After Discount** = Purchase Amount − Discount Amount
* **Final Payable Amount** = Amount After Discount + Delivery Charge

## Test Cases

Complete at least six test cases, including the boundary values ₹2000, ₹3000, 5 km, and 15 km.

| Test Case | Purchase Amount | Customer Type    | Distance | 
| --------- | --------------: | ---------------- | -------: | 
| TC01      |           ₹2000 | Student          |     5 km |            
| TC02      |           ₹3000 | Regular Customer |    15 km |           
| TC03      |           ₹1500 | Student          |     3 km |             
| TC04      |           ₹2500 | Regular Customer |    20 km |             
| TC05      |           ₹3500 | Regular Customer |     5 km |           
| TC06      |           ₹4000 | Student          |    10 km |            

## Concepts Used

* Variables and data types
* `printf()` and `scanf()`
* `if`, `else if`, and `else`
* Relational and logical operators
* Arithmetic expressions
* Conditional decision-making
* Basic input validation

## Files Included

* `README.md` – Problem statement, objective, algorithm, rules, and test cases.
* `challenge03.c` – C source code for the SmartCart problem.
* `output/` – Screenshots showing program execution and test results.

## Conclusion

The SmartCart program demonstrates the use of conditional statements and arithmetic operations to calculate customer discounts, delivery charges, and the final payable amount based on purchase amount, customer type, and delivery distance.

