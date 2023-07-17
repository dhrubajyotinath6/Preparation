//https://leetcode.com/problems/student-attendance-record-i/solution/


/*
//approach 2

public class Solution {
    public boolean checkRecord(String s) {
        int count=0;
        for(int i=0;i<s.length() && count<2 ;i++)
            if(s.charAt(i)=='A')
                count++;
        return count<2 && s.indexOf("LLL")<0;
    }
}

*/
//approach 3
class Solution {
public:
    bool checkRecord(string s) {
        
        int countA = 0;
        
        for(int i = 0; i < s.size() && countA < 2; i++){
            if(s[i] == 'A') countA++;
            
            if(i <= s.size()-3 && s[i] == 'L' && s[i+1] == 'L' &&  s[i+2] == 'L') return false;
        }
        
        return countA < 2;
    }
};


//check approach 4 : regex solution