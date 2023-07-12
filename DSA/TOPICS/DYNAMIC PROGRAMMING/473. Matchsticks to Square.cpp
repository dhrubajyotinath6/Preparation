//https://leetcode.com/problems/matchsticks-to-square/solution

You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. 
You want to use all the matchsticks to make one square. You should not break any stick, 
but you can link them up, 
and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.

 

Example 1:


Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:

Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
 

Constraints:

1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 108

 -----------------------------------------------------------------------------------

class Solution {

public:
    bool dfs(vector<int> &matchsticks, int possibleSquareSide, vector<int> &sums, int index){
        
        if(index == matchsticks.size()){
            return sums[0] == sums[1] && sums[1] == sums[2] && sums[2] == sums[3];
        }
        
        int element = matchsticks[index];
        
        for(int i = 0; i < 4; i++){
            
            if(sums[i] + element <= possibleSquareSide){
                sums[i] += element;
                
                if(dfs(matchsticks, possibleSquareSide, sums, index+1)) return true;
                
                sums[i] -= element;
            }
        }
        
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        
        if(matchsticks.size() == 0) return false;
        
        int L = matchsticks.size();
        int peri = 0;
        
        for(int i = 0; i < L; i++){
            peri += matchsticks[i];
        }
        
        int possibleSquareSide = peri/4;
        
        if(possibleSquareSide * 4 != peri) return false; 
        
        sort(matchsticks.begin(), matchsticks.end(), greater <>());
        
        vector<int> sums(4);
        
        bool ans = dfs(matchsticks, possibleSquareSide, sums, 0);
        
        return ans;
    }
};

/*
Tc : O(4^N)
SC : O(N)

*/

/*
This solution should mention that this problem is an instance of the well-known 
Bin Packing Problem, which has been proven to be NP-complete, 
so it is not possible to implement a solution that takes less than exponential time. 
This would be a very important fact for the candidate to identify, because they 
otherwise will likely spin their wheels trying to identify a polynomial-time solution.

Once you've identified that the problem is NP-complete, 
you know that you'll just have to implement a "brute force" solution, 
and the only task remaining is to look for opportunities to reduce the amount of work 
you need to do via pruning, memoization, etc.

*/

// Approach 2: Dynamic Programming  -> one more approach
//https://leetcode.com/problems/matchsticks-to-square/solution/
