Problem 13: The general N-M size die hard jug problem

IPO CHART:

input: size of M and L jugs

process: how many litres can be measured by using gcd(greatest common divisor)

output: number of litres

PSEUDOCODE:
1. INPUT M,L
2. WHILE r!= 0
3.    r = M % L
4.    M = L
5.    L = r
6. ENDWHILE
7. IF r==1
8.   PRINT "You can measure any amount from 1 to max(M, L) liters."
9.ELSE
10.  print("you can measure multiples from of M litres upto max(M,L)litres.")         

FLOWCHART:
