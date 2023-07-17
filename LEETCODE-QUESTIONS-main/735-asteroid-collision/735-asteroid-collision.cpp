/*
overall, there are totally 4 scenarios will happen: 1.+ + 2.- - 3.+ - 4.- +
when collision happens: only 3 which is + -

use a stack to keep track of the previous and compare current value with previous ones

*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        
        for(int ast : asteroids){
            
            bool insert = true;
            
            while(st.empty() == false && ast < 0 && st.top() > 0){
                
                if(st.top() < -ast){  //  o->  <-0
                    st.pop();
                    insert = true;
                    
                }else if(st.top() == -ast){ // o->  <-o
                    st.pop();
                    insert = false;
                    break;
                }
                else if(st.top() > -ast){
                    insert = false;
                    break;
                }
                
             }
            
            if(insert) st.push(ast);
            // cout << st.top() << endl;
                       
        }
        
        vector<int> ans(st.size());
        
        for(int i = ans.size() - 1; i >= 0 ; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};