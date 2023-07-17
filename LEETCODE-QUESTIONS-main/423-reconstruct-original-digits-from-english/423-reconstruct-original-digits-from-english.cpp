//https://leetcode.com/problems/reconstruct-original-digits-from-english/solution/

class Solution {
  public:
    string originalDigits(string s) {
      
    // building hashmap letter -> its frequency      
    int count[26] = {0};
    
    for(auto &c : s){
        count[c-'a']++;
    }

    // building hashmap digit -> its frequency
    int numberOfDigits[10];
        
    // letter "z" is present only in "zero"
    numberOfDigits[0] = count['z'-'a'];
        
    // letter "w" is present only in "two"
    numberOfDigits[2] = count['w'-'a'];
        
    // letter "u" is present only in "four"
    numberOfDigits[4] = count['u'-'a'];
        
    // letter "x" is present only in "six"
    numberOfDigits[6] = count['x'-'a'];
        
    // letter "g" is present only in "eight"
    numberOfDigits[8] = count['g'-'a'];
        
    // letter "h" is present only in "three" and "eight"
    numberOfDigits[3] = count['h'-'a'] - numberOfDigits[8];
        
    // letter "f" is present only in "five" and "four"
    numberOfDigits[5] = count['f'-'a'] - numberOfDigits[4];
        
    // letter "s" is present only in "seven" and "six"
    numberOfDigits[7] = count['s'-'a'] - numberOfDigits[6];
        
    // letter "i" is present in "nine", "five", "six", and "eight"
    numberOfDigits[9] = count['i'-'a'] - numberOfDigits[5] - numberOfDigits[6] - numberOfDigits[8];
        
    // letter "n" is present in "one", "nine", and "seven"
    numberOfDigits[1] = count['n'-'a'] - numberOfDigits[7] - 2 * numberOfDigits[9];

    // building output string
    string ans = "";
        
    for(int i = 0; i < 10; i++)
      for (int j = 0; j < numberOfDigits[i]; j++)
        ans += to_string(i);
    return ans;
  }
};