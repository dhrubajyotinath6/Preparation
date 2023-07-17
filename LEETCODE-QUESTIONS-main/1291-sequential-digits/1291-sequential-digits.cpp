//https://leetcode.com/problems/sequential-digits/solution/  --VERY VERY IMP
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
           
        string digits = "123456789"; 
        
        vector<int> res; 
        
        int lowNoLength = to_string(low).length(); 
        int highNoLength = to_string(high).length();
        
         for(int rightPointer = lowNoLength; rightPointer <= highNoLength; rightPointer++){
             
              for(int leftPointer = 0; leftPointer < 10 - rightPointer; leftPointer++){  
                  
                // we took the substring and convert it to variable[starting point, length]
                int num = stoi(digits.substr(leftPointer, rightPointer));
                  
                if(num >= low && num <= high) res.push_back(num); 
            }
         }
        return res;
    }
};