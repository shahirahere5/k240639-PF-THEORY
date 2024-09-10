Problem 11: No not optimus prime its Coprime..

IPO CHART:

input: num1,num2

process: find out their gcd, if its 1 then they're coprime

output: if they're coprime or not

PSEUDOCODE:
1. input num1,num2
2. WHILE B!= 0
3.   temp = num2
4.   num2 = num1 % num2
5.   num1 = temp
6. ENDWHILE
7. IF num1 = 0
8.   print("the numbers are coprime")
9. ELSE
10.  print("the numbers are not coprime")    
