/*
https://leetcode.com/problems/top-k-frequent-words/solution/
Approach 4: Bucket Sorting + Trie  -> CHECK THIS ALSO

*/

/*
C++ has in-built compare() function in order to compare two strings efficiently.

The compare() function compares two strings 
and returns the following values according to the matching cases:

Returns 0, if both the strings are the same.

Returns <0, if the value of the character of the first string is smaller 
as compared to the second string input.

Results out to be >0, when the second string is greater in comparison.

*/

class Solution {
    
public:
    
  struct valueCompare {
      
    bool operator()(const pair<string, int> &x, const pair<string, int> &y) {        
      if(x.second == y.second){
          
          string s1 = x.first, s2 = y.first;
          int n = s1.compare(s2);
          
          if(n <= 0) return false;
          else return true;
          
      }
      return y.second > x.second;
    }
      
  };
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
         unordered_map<string, int> characterFrequencyMap;
        
         for (auto word : words) {
             characterFrequencyMap[word]++;
         }

        priority_queue<pair<string, int>, vector<pair<string, int>>, valueCompare> maxHeap;

        // add all characters to the max heap
        for (auto entry : characterFrequencyMap) {
          maxHeap.push(entry);
        }
        
        vector<string> ans;
        
        for(int i = 0; i < k; i++){
            auto entry = maxHeap.top();
            maxHeap.pop();
            ans.push_back(entry.first);
        }
        
        return ans;
    }
};