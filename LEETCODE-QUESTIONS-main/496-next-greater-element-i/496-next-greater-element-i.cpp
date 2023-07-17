class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        unordered_map<int,int> mpp;
        
        for(int n : nums2){
            while(st.empty() == false && st.top() < n){
                mpp[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }
        
        vector<int> ans;
        for(int n : nums1){
            ans.push_back(mpp.count(n) ? mpp[n] : -1);
        }
        return ans;
    }
};