class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        stack<int> st;
        
        for(auto &op : operations){
            
            // 5  10  -> 5  10  15
            if(op == "+"){
                int t1 = st.top();
                st.pop();
                
                int newTop = t1 + st.top();
                
                st.push(t1);
                st.push(newTop);
            }else if(op == "C"){
                st.pop();
            }else if(op == "D"){
                st.push(2*st.top());
            }else{
                st.push(stoi(op));
            }
        }
        
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};