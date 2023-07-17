//https://www.youtube.com/watch?v=DIJQ8zLeVEk
//https://github.com/LeadCoding/FrazArmy/blob/main/Recursion/Lecture%2017/LeetCode/Max%20Length%20of%20a%20Concatenated%20String%20with%20Unique%20Characters.cpp

class Solution { 
    
public:
    bool cmp(vector<int> &selected, string &currString){
        
        vector<int> selfCheck(26,0);
        
        for(int i = 0; i < currString.size(); i++){
            if(selfCheck[currString[i] - 'a'] == 1) return false;
            selfCheck[currString[i] - 'a'] = 1;
        }
        
        for(int i = 0; i < currString.size(); i++){
            if(selected[currString[i] - 'a'] == 1) return false;
        }
        
        return true;
    }
    
public:
    int help(int i, vector<string>& arr, vector<int> &selected, int len){
        
        if(i == arr.size()){
            return len;
        }
        
        string currString = arr[i];
        
        if(cmp(selected, currString) == false){
            return help(i+1, arr, selected,len);
        }        
        else{
            
            for(int j = 0; j < currString.size(); j++){
                selected[currString[j] - 'a'] = 1;
            }
            len += currString.size();
            
            int op1 = help(i+1, arr, selected, len);
            
            for(int j = 0; j < currString.size(); j++){
                selected[currString[j] - 'a'] = 0;
            }
            len -= currString.size();
            
            int op2 = help(i+1, arr, selected, len);
            
            return max(op1,op2);            
            
        }
        return 0;
    }
    
public:
    int maxLength(vector<string>& arr) {

        vector<int> selected(26,0);
        
        int ans = help(0, arr, selected, 0);
        
        return ans;
    }
};
