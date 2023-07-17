// O(n) square
/*
class Solution {
    
public:
    int secondsToRemoveOccurrences(string binaryInput) {

        int n = binaryInput.size();
        int ans = 0;
        
        while(1){
            
            bool found = false;
            
            for(int i = 0; i < n-1; ){
            
                if(binaryInput[i] == '0' && binaryInput[i+1] == '1'){

                    binaryInput[i] == '1';
                    binaryInput[i+1] == '0';

                    found = true;
                    i+= 2;
                }
                else {
                    i++;
                }
            
            }
            
            if(!found) break;
            else ans++;
            
        }  
        
        return ans;
    }
    
};

*/
/*
https://github.com/LachezarTsK/Time-Needed-to-Rearrange-a-Binary-String/blob/main/Solution.cpp

https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/discuss/2454262/DP-vs.-Brute-Force

*/

class Solution {
    
public:
    int secondsToRemoveOccurrences(string binaryInput) {

        int numberOfZeros = 0;
        int seconds = 0;

        for (const auto& digit : binaryInput) {
            if (digit == '0') {
                ++numberOfZeros;
            } else if (numberOfZeros > 0) {
                seconds = max(seconds + 1, numberOfZeros);
            }
        }
        return seconds;
    }
};




