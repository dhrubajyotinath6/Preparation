//https://leetcode.com/problems/find-the-celebrity/

Suppose you are at a party with n people labeled from 0 to n - 1 and among them, 
there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people 
know the celebrity, but the celebrity does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. 
You are only allowed to ask questions like: "Hi, A. Do you know B?" to get information about whether A knows B. 
You need to find out the celebrity (or verify there is not one) by asking as few questions as possible 
(in the asymptotic sense).

You are given a helper function bool knows(a, b) that tells you whether a knows b. 
Implement a function int findCelebrity(n). There will be exactly one celebrity if they are at the party.

Return the celebrity's label if there is a celebrity at the party. If there is no celebrity, return -1.

 

Example 1:


Input: graph = [[1,1,0],[0,1,0],[1,1,1]]
Output: 1
Explanation: There are three persons labeled with 0, 1 and 2. graph[i][j] = 1 means person i knows person j, otherwise graph[i][j] = 0 means person i does not know person j. The celebrity is the person labeled as 1 because both 0 and 2 know him but 1 does not know anybody.
Example 2:


Input: graph = [[1,0,1],[1,1,0],[0,1,1]]
Output: -1
Explanation: There is no celebrity.



/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
    
public:
    bool isCeleb(int i, int n){
        for(int j = 0; j < n; j++){
            
            if (i == j) continue; // Don't ask if they know themselves.
            
            if (knows(i, j) || !knows(j, i)) {
                return false;
            }
        }
        return true;
    }
    
public:
    int findCelebrity(int n) {
        
        int possibleCandidate = 0;
        
        for(int i = 0; i < n; i++){
            if(knows(possibleCandidate, i)){
                possibleCandidate = i;
            }
        }
        
        if(isCeleb(possibleCandidate, n)) return possibleCandidate;
        return -1;
    }
};