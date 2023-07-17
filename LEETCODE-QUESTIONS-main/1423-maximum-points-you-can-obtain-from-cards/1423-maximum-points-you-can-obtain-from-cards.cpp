//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/solution/   ---VERY VERY IMP
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        int totalScore = 0;
        int minSubarrayScore;
       
        // Total score obtained on selecting all the cards.
        for(int card : cardPoints){
            totalScore += card;
        }
        
        minSubarrayScore = totalScore;
        
        if(k == n){
            return totalScore;
        }
        
        int presentSubarrayScore = 0;
        int requiredSubarrayLength = n - k;
        int windowStart = 0;
        
        for(int windowEnd = 0; windowEnd < n; windowEnd++){
            
            presentSubarrayScore += cardPoints[windowEnd];
            int presentSubarrayLength = windowEnd - windowStart + 1;
            
            if(presentSubarrayLength == requiredSubarrayLength){
                minSubarrayScore = min(minSubarrayScore, presentSubarrayScore);
                presentSubarrayScore -= cardPoints[windowStart++];
            }
        }
        
        return totalScore - minSubarrayScore;
    }
};


/*
MAYBE CORRECT
If you think about it, there is a tradeoff between O(k) and O(n) solutions. If k < (n / 2), 
then O(k) solution is better, because we will do k iterations to compute the initial sum, and k iterations 
to move backwards while we do do n - k iterations to compute initial sum 
and k iteration forward for the O(n) solution. 
However, if k > (n / 2), then it's worse, because we will still do the same number of iterations but this time, 2k > n.

*/