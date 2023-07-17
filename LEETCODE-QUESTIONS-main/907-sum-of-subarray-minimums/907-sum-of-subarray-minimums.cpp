//https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step


class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        
        int n=nums.size();
        long long sum=0;
        
        int mod = 1e9 +7;
        
        stack<int>st;
        
        vector<int> minPrev(n,-1),minNext(n,n);
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            
            if(!st.empty()) { minPrev[i]=st.top();}
            
            st.push(i);
        }
        
        while(!st.empty()){st.pop();}
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            
            if(!st.empty()){minNext[i]=st.top();}
            st.push(i);
        }
        
        
        for(int i=0;i<n;i++)
        {
            long long leftMin=i-minPrev[i],rightMin=minNext[i]-i;

            sum += (leftMin*rightMin)*nums[i];
            
        }
        
        return sum % mod;
    }
};