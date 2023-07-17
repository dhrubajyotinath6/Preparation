// https://leetcode.com/problems/minimum-cost-to-set-cooking-time/discuss/1746988/Python3-Java-C%2B%2B-Combinations-of-Minutes-and-Seconds-O(1)

class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
    
        int mins = targetSeconds / 60, secs = targetSeconds % 60;
        
        return min(cost(mins, secs, startAt, moveCost, pushCost), cost(mins - 1, secs + 60, startAt, moveCost, pushCost));
}
int cost(int mins, int secs, int startAt, int moveCost, int pushCost) {
    
    if (mins > 99 || secs > 99 || mins < 0 || secs < 0) return INT_MAX;
    
    string s = to_string(mins * 100 + secs); char curr = (char)(startAt + '0');
    
    int res = 0;
    
    for(char ch: s) {
        
        if (ch == curr){
            res += pushCost;
        } 
        else {
            res += pushCost + moveCost;
            curr = ch;
        }
    }
    return res;
    }
};