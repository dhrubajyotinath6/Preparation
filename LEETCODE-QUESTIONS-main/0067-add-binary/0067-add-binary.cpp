//https://leetcode.com/problems/add-binary/discuss/1680021/Very-simple-O(n)-C%2B%2B-solution

/*
 carry
  
  0   + 0 + 0 = 0
      + 1 + 0 = 1
      
  1   + 1 + 0  = 2
      + 1 + 1  = 3
*/

class Solution {
public:
    string addBinary(string a, string b) {
        
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        
        string ans;
        
        while(i >= 0 || j >= 0 ||carry){
            
            int sum = 0;
            
            if(i >= 0){
                sum += a[i] - '0';
                i--;
            }
            
            if(j >= 0){
                sum += b[j] - '0';
                j--;
            }
            
            sum += carry;
            
            ans += (sum % 2 + '0');
            carry = sum/2;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};