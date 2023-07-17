/*
The problem is not really interesting, but the solution is insightful - 
When something is too simple :

recognize is too simple, with the library implementation or something straightforward

see what the person asking the question is looking. Failing to ask for clarifications will be a negative hit in an interview setup

in real life interviews, the information about ASCII is not offered upfront, but you need to extracted from the interviewer


*/

class Solution {
    
public:
    string toLowerCase(string s) {
    
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = (char)(s[i] - 'A' + 'a');
            }
        }
        
        return s;
    }
};