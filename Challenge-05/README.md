# Challenge 05 – Menu-Driven Mathematical Operations in C

## 📌 Challenge Objective

Create an interactive, menu-driven C program that allows users to perform different mathematical operations, including solving linear equations, calculating factorials, and solving quadratic equations. The menu must reappear after every operation, and the program must continue running until the user selects the Exit option.

## 🎯 Objectives

* Understand menu-driven programming in C.
* Implement loops for repeated execution.
* Use conditional statements to process user selections.
* Solve linear equations and handle special cases.
* Calculate factorials using loops.
* Solve quadratic equations using the discriminant.
* Apply mathematical formulas and the `sqrt()` function.
* Handle invalid choices and boundary conditions safely.

## 📝 Problem Statement

Develop a C program that presents the user with four menu options:

1. Solve a linear equation of the form `ax + b = 0`.
2. Calculate the factorial of an integer from 0 to 12.
3. Solve a quadratic equation of the form `ax² + bx + c = 0`.
4. Exit the program.

The program should validate inputs, display appropriate results or error messages, and repeatedly show the menu until the user chooses to exit.

## ⚙️ Algorithm

1. Start the program.
2. Initialize the required variables.
3. Display the mathematical operations menu.
4. Read the user's choice.
5. Perform the selected operation:

   * **Option 1 – Linear Equation:** Read `a` and `b`. If `a = 0` and `b = 0`, report infinitely many solutions. If `a = 0` and `b ≠ 0`, report no solution. Otherwise, calculate `x = -b/a`.
   * **Option 2 – Factorial:** Read an integer `n`. If `n` is outside the range 0–12, display an error. Otherwise, calculate the factorial using a loop, starting with `1`.
   * **Option 3 – Quadratic Equation:** Read `a`, `b`, and `c`. If `a = 0`, report that the equation is not quadratic. Otherwise, calculate the discriminant d` = b² − 4ac`. If d` > 0`, calculate two distinct real roots. If d` = 0`, calculate one repeated real root. If d` < 0`, report that there are no real roots.
   * **Option 4 – Exit:** Display a closing message and terminate the program.
   * **Invalid choice:** Display an error message and show the menu again.
6. Repeat the menu after every operation unless the user selects Exit means option 4.
7. Stop.

## 💻 C Programming Concepts Used

* Header files: `stdio.h` and `math.h`
* Variables and data types
* Standard input and output using `scanf()` and `printf()`
* `while` loop for repeated menu execution
* `if-else` statements for decision-making
* Arithmetic and relational operators
* Factorial calculation using iteration
* Discriminant-based classification of quadratic roots
* Mathematical functions such as `sqrt()`
* Input validation and boundary-case handling

## 🧮 Mathematical Formulas

**1. Linear equation**

For the equation:

`ax + b = 0`

When `a ≠ 0`:

`x = -b/a`

Special cases:

* `a = 0` and `b = 0`: Infinitely many solutions.
* `a = 0` and `b ≠ 0`: No solution.

**2. Factorial**

The factorial of a non-negative integer is:

`n! = 1 × 2 × 3 × ... × n`

For example:

`5! = 5 × 4 × 3 × 2 × 1 = 120`

Special case: `0! = 1`.

**3. Quadratic equation**

For the equation:

`ax² + bx + c = 0`

Calculate the discriminant:

`D = b² − 4ac`

The roots are determined as follows:

* `d > 0`: Two distinct real roots.
* `d = 0`: One repeated real root.
* `d < 0`: No real roots.

When real roots exist:

`x₁ = (-b + √d) / (2a)`

`x₂ = (-b - √d) / (2a)`

The coefficient `a` must not be zero for the equation to be quadratic.

## 🧪 Test Cases

| Test Case | Input / Condition                | Expected Result                        |
| --------- | -------------------------------- | -------------------------------------- |
| TC01      | Linear equation: `2x - 8 = 0`    | `x = 04`                               |
| TC02      | Linear equation: `0x + 5 = 0`    | No solution                            |
| TC03      | Factorial: `n = 0`               | `0! = 1`                               |
| TC04      | Factorial: `n = 5`               | `5! = 120`                             |
| TC05      | Quadratic: `x² − 2x + 6 = 0`     | Repeated roots: '1'                    |
| TC06      | Quadratic: `x² − 3x + 2 = 0`     | Two real roots: `2` and `1`            |
| TC07      | Quadratic: `x² + 0x + 1 = 0`     | No real roots                          |
| TC08      | Invalid menu choice, such as `5` | Wrong Option and menu displayed again  |
| TC09      | Menu choice `4`                  | Closing message and program terminates |

## 🛡️ Important Considerations

* Check for division by zero when solving linear equations.
* Distinguish between infinitely many solutions and no solution.
* Accept factorial inputs only from 0 through 12.
* Initialize the factorial result to `1` to handle `0!` correctly.
* Verify that `a ≠ 0` before solving a quadratic equation.
* Calculate the discriminant before determining the nature of the roots.
* Use `sqrt()` only when the discriminant is non-negative.
* Ensure that the menu repeats after every operation and invalid choice.
* Terminate the program only when the user selects Exit.

## ✅ Expected Outcome

A functional menu-driven C program that performs linear equation solving, factorial calculation, and quadratic equation analysis. The program should correctly handle mathematical special cases, validate factorial inputs, classify real roots, display errors for invalid menu choices, and continue until the user selects Exit.

## 📚 Conclusion

Challenge 05 demonstrates how loops, conditional statements, arithmetic operations, and mathematical formulas can be combined to create an interactive C application. It strengthens logical reasoning, structured programming, and the ability to handle boundary conditions while solving mathematical problems.
