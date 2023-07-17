//https://leetcode.com/problems/reduce-array-size-to-the-half/discuss/1319416/C%2B%2BJavaPython-HashMap-and-Sort-then-Counting-Sort-O(N)-Clean-and-Concise

//https://leetcode.com/problems/reduce-array-size-to-the-half/discuss/1319437/Simple-Solution-w-Explanation-or-Delete-Elements-by-Max-Frequency-or-O(N)-Beats-100



// HASHMAP + GREEDY


class Solution {
    
public:
    
    struct valueCompare {
        
        char operator()(const pair<int, int> &x, const pair<int, int> &y) {
          return y.second > x.second;
        }
        
    };
    
    
    int minSetSize(vector<int>& arr) {
        
       unordered_map<int,int> mpp;
        
       for(auto i : arr){
           mpp[i]++;
       }
        
       // u can write comparator here
        
       priority_queue<pair<int, int>, vector<pair<int, int>>, valueCompare> maxHeap;
        
       for(auto x : mpp){
           maxHeap.push(x);
       }
        
       int n = arr.size()/2;
       int size = 0;
        
        
        while(n > 0){
            n -= maxHeap.top().second;
            maxHeap.pop();
            size++;
        }
       
        return size;
        
    }
};




