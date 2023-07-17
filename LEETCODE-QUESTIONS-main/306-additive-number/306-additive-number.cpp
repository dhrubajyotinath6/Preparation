class Solution {
    bool f(long long n1, long long n2, string s, bool found){
        
        //784557  -> 784 && 557 -> n1 and n2 can be like this but this should be false 
        if(s.length() == 0 && found) return true;
        
        string n3 = to_string(n1 + n2);
        
        int ind = min(s.length() , n3.length());
        
        if(s.substr(0, ind) == n3)
            return f(n2, stol(n3), s.substr(ind), true);
        return false;
    }
public:
    bool isAdditiveNumber(string num) {
        
        int n = num.length();
        
        for(int i = 1; i < n-1; i++){
            
            long long n1 = stol(num.substr(0, i));
            if(to_string(n1) != num.substr(0, i)) break;
            
            for(int j = i + 1; j < n; j++){
                long long n2 = stol(num.substr(i, j-i));
                if(to_string(n2) != num.substr(i, j-i)) break;
                
                 bool found = f(n1, n2, num.substr(j), false);
                 if(found) return true;
            }           
        }
        // double for loop ends
        return false;
    }
};