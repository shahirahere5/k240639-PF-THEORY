There are 10 floors in a building 0 to 9. The building lift/elevator has a 1 digit, 7 segment LCD Panel display to tell which floor the lift is on, as shown. The input into the LCD Panel is a 7-digit long number with only 1s and 0s. Each digit of the 7-digit long number tells which panel to light or not to light from A to G respectively, where 1 means to light the panel and 0 means to keep it off.  

E.g., 0110000 means only panel ‘B’ and ‘C’ are lit thus telling that this is the first floor. Similarly, the number 1111110 tells that all panels are lit except panel ‘G’ displaying the number 0.

You need to design a program for a computer surveillance system to tell which floor the lift is on. The input for the program is the 7-digit number comprising only 1s and 0s. The output should be a single digit number  0 to 9 telling which floor the lift is on. 
Hint: You can get the last digit by using %10 and the remaining digits by using number division /10.  Also, you only need branching to do it.


IPO CHART: 

input: number

process: check which floor by 0's and 1's

output: floor

PSEUDOCODE:
1. INPUT number
2. IF number = 1111110
3. print "0"
4. IF number = 0110000
5. print "1"
6. IF number = 1101101
7. print "2"
8. IF number = 1111001
9. print "3"
10. IF number = 0110011
11. print "4"
12. IF number = 1011011
13. print "5"
14. IF number = 1011111
15. print "6"
16. IF number = 1110000
17. print "7"
18. IF number = 1111111
19. print "8"
20. IF number = 1110011
21. print "9"
