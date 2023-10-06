Given a string s, check if it can be constructed by taking a substring of it 
and appending multiple copies of the substring together.

 

Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
Example 2:

Input: s = "aba"
Output: false
Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.



class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        if(t.substr(1, t.size() - 2).find(s) != -1) return true;
        
        return false;
    }
};


/*
Algorithm
1. Create a string variable t and set it to s + s.

2. If the substring formed by removing the first and last character of t contains s, we return true. Otherwise, return false. 

Note in our implementation, the substr function in C++ and the substring method in Java both take two parameters. In both languages, the first parameter is the initial index from which our substring begins, while the second parameter works differently. It is the length of the substring in C++ and the index of the last character in Java.


*/


//coordinates[i] = [x, y]
/*
2/3      2/3        4/6   --> same slope 

[ ]       [ ]    [ ]    [ ]     [ ] 

*/
class Solution {
    
public:
    int getDiffY(vector<int> &a, vector<int> &b){
        return  b[1] - a[1];
    }
    
    int getDiffX(vector<int> &a, vector<int> &b){
        return b[0] - a[0];
    }
    
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int deltaY = getDiffY(coordinates[1], coordinates[0]);
        int deltaX = getDiffX(coordinates[1], coordinates[0]);
        
        for(int i = 2; i < coordinates.size(); i++){
            
            if(deltaY * getDiffX(coordinates[i], coordinates[0]) !=  deltaX*getDiffY(coordinates[i], coordinates[0])){ 
                return false;
            }
               
        }   
        
        return true;
    }
};