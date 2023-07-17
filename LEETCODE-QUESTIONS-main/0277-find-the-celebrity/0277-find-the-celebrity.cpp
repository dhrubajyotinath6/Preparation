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