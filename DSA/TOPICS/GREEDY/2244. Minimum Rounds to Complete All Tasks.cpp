// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. 
In each round, you can complete either 2 or 3 tasks of the same difficulty level.

Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete 
all the tasks.

 

Example 1:

Input: tasks = [2,2,3,3,2,4,4,4,4,4]
Output: 4
Explanation: To complete all the tasks, a possible plan is:
- In the first round, you complete 3 tasks of difficulty level 2. 
- In the second round, you complete 2 tasks of difficulty level 3. 
- In the third round, you complete 3 tasks of difficulty level 4. 
- In the fourth round, you complete 2 tasks of difficulty level 4.  
It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.
Example 2:

Input: tasks = [2,3,3]
Output: -1
Explanation: There is only 1 task of difficulty level 2, but in each round, you can only complete either
2 or 3 tasks of the same difficulty level. Hence, you cannot complete all the tasks, and the answer is -1.


/*
all numbers can be represented as sum of 2 and 3 except 1.

so when freq is 1 return -1;

now we need to find minimum no of rounds.

https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/solution/
*/
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int,int> freq;
        
        for(auto &task : tasks){
            freq[task]++;
        }
        
        int miniRounds = 0;
        
        for(auto [task, count] : freq){
            
            if(count == 1) return -1;
            
            if(count % 3 == 0){
                miniRounds += count/3;
            }else{
                /*if it is not divided by 3, then 2 possible remainders are there 1 and 2
                
                eg: 7, 8
                
                7 = 7 + 2 + 2
                7/3 = 2 and rem = 1 (3,3,1)->(3,2,2)
                
                8 = 3 + 3 + 2 
                8/3 = 2 and rem 2  (3,3,2)

                2
                2/3 + 1 = 0 + 1
                
                */
                
                miniRounds += count/3 + 1;
            }
        }
        
        return miniRounds;
    }
};



