Problem 8: Digit Sum
You are required to design a solution  that takes as input a single number and prints out the sum of its digits.

IPO CHART:

input: number

process: take sum of all its gigits

output: sum

PSEUDOCODE:
1. INPUT num
2. sum := 0
3. WHILE num != 0
4.   digit = num % 10
5.   sum := sum + digit
6.   num = num / 10
7. ENDWHILE
8. print sum  
