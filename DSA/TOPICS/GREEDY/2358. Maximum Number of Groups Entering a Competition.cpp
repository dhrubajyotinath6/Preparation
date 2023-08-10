//https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/

You are given a positive integer array grades which represents the grades of students in a university. 
You would like to enter all these students into a competition in ordered non-empty groups, 
such that the ordering meets the following conditions:

The sum of the grades of students in the ith group is less than the sum of the grades of students in the 
(i + 1)th group, for all groups (except the last).

The total number of students in the ith group is less than the total number of students in the 
(i + 1)th group, for all groups (except the last).

Return the maximum number of groups that can be formed.

 

Example 1:

Input: grades = [10,6,12,7,3,5]
Output: 3
Explanation: The following is a possible way to form 3 groups of students:
- 1st group has the students with grades = [12]. Sum of grades: 12. Student count: 1
- 2nd group has the students with grades = [6,7]. Sum of grades: 6 + 7 = 13. Student count: 2
- 3rd group has the students with grades = [10,3,5]. Sum of grades: 10 + 3 + 5 = 18. Student count: 3
It can be shown that it is not possible to form more than 3 groups.
Example 2:

Input: grades = [8,8]
Output: 1
Explanation: We can only form 1 group, since forming 2 groups would lead to an equal number of students in both groups.



To arrange numbers in the way the question describes is to essentially create a triangle of numbers. 
For example, consider the input nums = [5,4,7,4,8,9,1,2,7,4,10]. One possible triangle could be:

1
2, 4
4, 4, 5
7, 7, 8, 9, 10
The cool trick here is that we're guaranteed that a triangle can be made out of any array of 
positive integers (where the last level of the triangle can have any number of elements).

Imagine an arbitrary integer array of positive values sorted in non-decreasing order: 
nums = [a0, a1, a2, ..., an], ai <= a(i+1).

Regardless of what those numbers are, we can say with absolute certainty that a1 + a2 > a0. 
Additionally, a3 + a4 + a5 > a1 + a2 and so on...

Therefore, as long as these numbers are positive, we can definitely create some triangle out of them. 
Heck, we don't even need to sort the array since we don't care where these numbers are nor what 
these numbers are. All we care about is that they exist.

Now all we need to figure is how tall we can make the triangle. Once we find that, we'll have our answer. 
This is the logic that Lee details above in the O(1) mathematical solution.
Hope this helps!


//https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/discuss/2357789/JavaC%2B%2BPython-One-line-O(1)


class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        
        int n = grades.size();
        int k = 0, total = 0;
        
        while((total + k + 1) <= n){
            
            k++;
            total += k;
        }
        
        return k;
    }
};




Solution : Math
1 + 2 + ... + k <= n
k(k + 1) / 2 <= n
(k + 0.5)(k + 0.5) <= n * 2 + 0.25
k + 0.5 <= sqrt(n * 2 + 0.25)
k <= sqrt(n * 2 + 0.25) - 0.5

Time O(1)
Space O(1)

int maximumGroups(vector<int>& A) {
        return (int)(sqrt(A.size() * 2 + 0.25) - 0.5);
    }