//https://leetcode.com/problems/hamming-distance/solution/  - IMP
class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int i = x^y;
        int dis = 0;
        
        //count the no of 1
        while(i != 0){            
            dis++;
            i = i & (i-1);
        }
        return dis;
    }
};





