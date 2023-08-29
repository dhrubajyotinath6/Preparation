/*
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its 
direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, 
the smaller one will explode. If both are the same size, both will explode. 
Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.


Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.


Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

*/

/*
overall, there are totally 4 scenarios will happen: 1)+ +   2)- -  3)+ -    4)- +
when collision happens: only 3 which is + -

use a stack to keep track of the previous and compare current value with previous ones

      ___
 -  -   |
 -  +   |   These 2 conditions will never collide
     ___|

So we need to worry when the prev(ie st.top() ) is  +

  +   -
  +   +    => again here if the coming asteroid is + ve, then also no collision

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


