/*
At the beginning, I got confusions about what is the nth sequence.  
The following are sequence from n=1 to n=10:

 1.     1
 2.     11
 3.     21
 4.     1211
 5.     111221 
 6.     312211
 7.     13112221
 8.     1113213211
 9.     31131211131221
 10.   13211311123113112211
 
From the examples you can see, 
the (i+1)th sequence is the "count and say" of the ith sequence!

*/

class Solution {
public:
    string countAndSay(int n) {
        
        string currString = "1";
        
        for(int i = 2; i <= n; i++){
            
        /*
            111221
            312211
        */    
            string nextString;
            int j = 0;
            
            while(j < currString.size()){
                char currChar = currString[j];
                
                // cout << currChar << endl;
                
                int k = 0;
                while(currChar == currString[j]){
                    k++;
                    j++;
                }
                // cout << k << " " << j << endl << endl;
                nextString += to_string(k) + currString[j-1];
            }
            
            // cout << nextString << endl;
            
            currString = nextString;
            
            
        }
        
        return currString;
    }
};