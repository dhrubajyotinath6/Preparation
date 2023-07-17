//You must include the ith obstacle in the course.
/*
      1   2   6   7   5
LIS : 1   2   6   7

BUT must include the ith obstacle in the course
therefore, 1  2  5


*/

//https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/discuss/1390159/C%2B%2BPython-Same-with-Longest-Increasing-Subsequence-problem-Clean-and-Concise

class Solution {    

public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        vector<int> sub;
        
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            
            if(sub.empty() || sub[sub.size() - 1] <= num){
                sub.push_back(num);
                nums[i] = sub.size();
            }else{
                int idx = upper_bound(sub.begin(), sub.end(), num) - sub.begin(); //// Find the index of the smallest number > x
                sub[idx] = num;
                nums[i] = idx + 1;
            }
        }
        
        return nums;
    }
};




/*

stack doesnot work
        stack<int> st;
        vector<int> ans;
        
        for(auto& ob : obstacles){
            if(st.empty() || st.top() <= ob){
                st.push(ob);
                ans.push_back(st.size());
            }else{
                while(!st.empty() && st.top() > ob){
                    st.pop();
                }
                st.push(ob);
                ans.push_back(st.size());   
                
            }
        }
        
        return ans;
        
        
        
        Input
[5,1,5,5,1,3,4,5,1,4]
Output
[1,1,2,3,2,3,4,5,3,4]
Expected
[1,1,2,3,2,3,4,5,3,5]



stack   :        1    1    1     4   -> output 4
actual output:   1    1    3     4    4    ->output 5

*/
