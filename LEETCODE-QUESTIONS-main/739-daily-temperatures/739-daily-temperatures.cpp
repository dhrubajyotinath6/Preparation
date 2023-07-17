//https://leetcode.com/problems/daily-temperatures/solution/

/*
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<int> st;
        int n = temperatures.size();        
        vector<int> ans(n,0);
        
        for(int i = 0; i < n; i++){
            
            while(st.empty() == false && temperatures[i] > temperatures[st.top()] ){
                ans[st.top()] = i - st.top();
                st.pop();
            }
            
            st.push(i);
        }
        return ans;
    }
};
*/



class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        int hottest = 0;
        vector<int> ans(n,0);
        
        for(int currDay = n - 1; currDay >= 0; currDay--){
            
            if(temperatures[currDay] >= hottest){
                hottest = temperatures[currDay];
                continue;
            }
            
            int days = 1;
            
            while(temperatures[currDay + days] <= temperatures[currDay]){
                //days++;  --> TLE
                days += ans[currDay + days];
            }
            
            ans[currDay] = days;
        }
        return ans;
    }
};

















