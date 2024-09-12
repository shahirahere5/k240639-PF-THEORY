Problem 9 : Exact Age in days, months, and years from DOB  


IPO CHART:

input: current date, date_of_birth

process: calculate age

output: age

PSEUDOCODE:
1. INPUT dob, current_date
2. IF (dob(month) AND current(month))<=1 && (dob(month) AND current(month)) >=12
3.  IF (day valid for given month)
4.   IF dob(date) < current(date)
5.    year = current(year)-dob(year)
6.    month = current(month)-dob(month)
7.    IF month <0
8.    year = year -1
9.    month = month + 12
10.   day = current(day) - dob(day)
11.   ELSE
12.    day = current(day) - dob(day)
13. print year
14. print month
15. print day

FLOWCHART:

<img> ![WhatsApp Image 2024-09-12 at 10 14 47 PM (3)](https://github.com/user-attachments/assets/a89c1f32-339f-47d9-ae6e-f3df710e1322) <\img>

17. print
