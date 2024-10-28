<img> ![image](https://github.com/user-attachments/assets/1622a8f4-759b-4ac1-9d19-c76458d1726a) <\img>


Input Collection: We ask the user to enter five numbers, which are stored in an integer array num. 

Initial Comparison Setup: Since we need two smallest numbers, we start by comparing the first two elements of the array and assigning the smaller one to smallest and the larger one to second_small. 

Single-Pass Comparison Loop: Starting from the third element, we iterate through the remaining numbers:

If the current element is smaller than smallest, it becomes the new smallest, and the previous smallest value is assigned to second_small.
If the current element is not smaller than smallest but is smaller than second_small, it becomes the new second_small.
This ensures that after one pass, we’ll have both the smallest and the second smallest values.

Edge Case Handling: After the loop, we check if second_small is equal to smallest. If they are the same, it means all elements were identical, so there’s no valid second smallest number.



By solving this problem, I learned how to efficiently find the smallest and second smallest elements in an array. I also strengthened my understanding of edge case handling, especially when elements may be identical.
