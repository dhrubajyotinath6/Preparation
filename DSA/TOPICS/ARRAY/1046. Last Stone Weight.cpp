You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

 

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that the value of the last stone.
Example 2:

Input: stones = [1]
Output: 1


class Solution {
public:
    int lastStoneWeight(vector<int>& weights) {
        
    int n = weights.size();
    
    priority_queue<int> pq;
    
    for(int i = 0; i < n; i++){
        
        int x = weights[i];
        
        pq.push(x);
    }
    
    
    while(pq.size() > 1){
        
        int top1 = pq.top();
        pq.pop();
        
        int top2  = pq.top();
        pq.pop();
        
        if(top1 > top2){
            top1 -= top2;
            pq.push(top1);
        }else if(top2 > top1){
            top2 -= top1;
            pq.push(top2);
        }
    }
    
    int ans;
    
    if(pq.empty()){
        ans = 0;
    }else{
        ans = pq.top();
    }
    // cout << pq.size() << endl;
    
    return ans;
    }
};