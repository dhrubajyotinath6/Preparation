Painter’s Partition Problem
Problem Statement: Given an array/list of length ‘N’, where the array/list represents the boards 
and each element of the given array/list represents the length of each board. 

Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board 
takes 1 unit of time to paint. You are supposed to return the area of the minimum time to get 
this job done of painting all the ‘N’ boards under the constraint that any painter will only paint 
the continuous sections of boards.



ANS:
Upon close observation, we can understand that this problem is similar to the previous problem: 
BS-18. Allocate Books or Book Allocation | Hard Binary Search. 

There we had to allocate books to the students and here we need to allocate walls to the painters.


Assume the given array is {10, 20, 30, 40} and number of painters, k = 2. 
Now, we can allocate these boards in different ways. Some of them are the following:


10 | 20, 30, 40  → Minimum time required to paint all the boards  = 90
10, 20 | 30, 40  → Minimum time required to paint all the boards = 70
10, 20, 30 | 40  → Minimum time required to paint all the boards = 60

From the above allocations, we can clearly observe that in the last case, 
the first painter will paint the first 3 walls in 60 units of time and the second painter 
will take 40 units of time. So, the minimum time required to paint all the boards is 60.


