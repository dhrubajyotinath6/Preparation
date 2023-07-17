class Solution {
    
public:
    bool f(vector<int>& arr, int index, vector<int> &vis){
        
        //base conditions
        if(index < 0 || index >= arr.size()) return false;      
        if(vis[index] == 1) return false;          
        if(arr[index] == 0) return true;
        
        /*
          this is wrong   
        if(vis[index] == 1) return false;    
        if(index < 0 || index >= arr.size()) return false; 
        if(arr[index] == 0) return true;
        */
        
        vis[index] = 1;
        
        bool ans = false;
        
        bool op1 = f(arr, index + arr[index], vis);
        bool op2 = f(arr, index - arr[index], vis);
        
        ans = ans || op1 || op2;
        
        return ans;
    }
    
public:
    bool canReach(vector<int>& arr, int start) {
        
        vector<int> vis(arr.size(), 0);
        
        bool ans = f(arr, start, vis);
        
        return ans;
    }
};