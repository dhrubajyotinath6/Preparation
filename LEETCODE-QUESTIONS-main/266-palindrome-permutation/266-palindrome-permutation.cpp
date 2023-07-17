/*
TC -> O(N) {but we r iterating 2 times}
SC -> O(1)

every number twice
    or
every number twice and one number odd times

So, we are finding whether we hv more than one odds or not

*/
/*
class Solution {
public:
    bool canPermutePalindrome(string s) {
        
        vector<int> mpp(26,0);
        
        for(int i = 0; i < s.size(); i++){
            mpp[s[i] - 'a']++;
        }
        
        bool flag = false;
        
        for(auto i : mpp){
            
            if(i % 2 != 0 && flag == true) return false;
            else if (i % 2 != 0) flag = true;
        }
        
        return true;
    }
};
*/



/*
We can solve in one loop also

https://leetcode.com/problems/palindrome-permutation/solution/ 
REFER APPROACH 4
*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        
        vector<int> mpp(26,0);
        int count = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            int val = (s[i] - 'a');
            
            mpp[val]++;
            
            if(mpp[val] % 2 == 0){
                count--;
            }
            else
                count++;
        }
        
       //if all characters are occuring even times, count = 0
       // if one character occuring odd time, count = 1;
       // if more than one character occuring odd times, count > 1
       return count <= 1; 
    }
};