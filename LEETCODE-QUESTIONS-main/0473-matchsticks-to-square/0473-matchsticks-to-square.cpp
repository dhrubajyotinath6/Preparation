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