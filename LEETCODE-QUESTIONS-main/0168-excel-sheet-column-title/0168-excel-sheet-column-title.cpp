/*
52 ->  AZ
26 + 26

52 remainder 26 = 26 but 26 is not Z , 25 is Z
so do 52-- = 51
      51 rem 26 = 25
      
51/26 = 1;
*/
class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string ans;
        
        while(columnNumber > 0){
            
            columnNumber--;
            
            int curr = columnNumber % 26;
            columnNumber = columnNumber/26;
            
            ans += (curr + 'A');
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};