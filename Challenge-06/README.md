# Challenge 06 – Smart Campus Activity Monitor

## Problem Statement

A smart-campus activity monitor records the number of visits over several time slots. Write a C program that stores the readings in a one-dimensional array, analyses the sequence to find meaningful patterns, and rotates the data according to a user-provided integer.

The program must validate all inputs and handle unusual cases correctly.

## Objective

To practice one-dimensional arrays, loops, conditional statements, input validation, pattern detection, and in-place array rotation in C.

## Algorithm

1. **Start.**

2. Ask for the number of readings (`N`).
   - If `N` is less than 5 or greater than 12, ask again.

3. Ask for the last two digits of the registration number.
   - If the number is less than 0 or greater than 99, ask again.

4. Read the activity readings.
   - Ask for each reading one at a time.
   - If a reading is less than 0 or greater than 1000, ask for that reading again.
   - Store each valid reading in the array.

5. Display the original readings in the order entered.

6. Find the sum, minimum, and maximum.
   - Start the sum at 0.
   - Use the first reading as the starting minimum and maximum.
   - Go through the array, adding each value to the sum.
   - Update the minimum or maximum whenever a smaller or larger value is found.

7. Find the average.
   - Divide the sum by `N`, keeping the decimal part.

8. Find the second-largest distinct reading.
   - Ignore readings equal to the maximum.
   - Among the remaining readings, find the largest.
   - If there are none, report that no second-largest distinct value exists.

9. Count local peaks.
   - Check each reading except the first and last.
   - Count it if it is greater than both of its immediate neighbours.

10. Find the longest increasing run.
    - Compare each reading with the one immediately before it.
    - If it is greater, increase the current run length.
    - If it is not greater, start a new run at length 1.
    - Keep track of the largest run length.

11. Ask for the rotation amount (`K`).
    - Positive `K` means rotate right.
    - Negative `K` means rotate left.
    - Reduce `K` to an equivalent number of positions using the remainder after dividing by `N`.

12. Rotate the array in place.
    - Reverse the whole array.
    - Reverse the first part.
    - Reverse the remaining part.

13. Display the rotated readings.

14. Calculate `D`.
    - Use `D = (registration digits % 9) + 1`.

15. Count divisible readings.
    - Check the rotated array.
    - Count readings that are exactly divisible by `D`.

16. Display `D` and the count.

17. **Stop.**

## Concepts Used

- One-dimensional arrays
- Loops and conditional statements
- Input validation
- Sum, average, minimum, and maximum calculations
- Second-largest distinct value
- Local peak detection
- Longest strictly increasing contiguous run
- In-place array rotation using reversal
- Modulo operator (`%`)

## Testing Evidence

Test the program with at least six cases, including normal inputs and edge cases.

| Test Case | Purpose |
|---|---|
| TC01 | Ordinary sequence: verify sum, average, minimum, and maximum. |
| TC02 | Repeated maximum: verify the second-largest distinct value. |
| TC03 | All values equal: verify that no second-largest distinct value exists. |
| TC04 | Strictly decreasing sequence: verify that the longest increasing-run length is 1. |
| TC05 | Local peaks: verify the peak count. |
| TC06 | Array rotation with `K = 0`, positive `K`, and negative `K`. |
| TC07 | Personalised divisor: verify the divisibility count after rotation. |
| TC08 | Invalid input: test `N` below 5 or above 12, registration digits outside 0–99, and readings outside 0–1000. |

Record the observed results or attach screenshots of the program execution.

## Conclusion

This challenge demonstrates how one-dimensional arrays can be used to analyse sequences, identify patterns, validate input, and rotate data in place using loops and conditional statements in C.
