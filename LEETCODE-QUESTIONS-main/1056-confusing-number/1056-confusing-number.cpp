/*
https://leetcode.com/problems/confusing-number/solution/1720903

https://leetcode.com/problems/confusing-number/solution/
*/
class Solution {
public:
    bool confusingNumber(int n) {
        
        unordered_map<char, char> map = {
                                            {'0', '0'},
                                            {'1', '1'},
                                            {'6', '9'},
                                            {'8', '8'},
                                            {'9', '6'}            
                                        };
       string rotatedNumber;
        
        for(auto &ch : to_string(n)){
            if(map.find(ch) == map.end()) return false;
            
            rotatedNumber += map[ch];
        }
        
        cout << rotatedNumber << endl;
        
        reverse(begin(rotatedNumber), end(rotatedNumber));
        
        return stoi(rotatedNumber) != n;
    }
};