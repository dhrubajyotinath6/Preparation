/*

https://leetcode.com/problems/decode-xored-array/discuss/1009844/JavaC%2B%2BPython-Easy-and-Concise

For each element we have

A[i] = res[i] ^ res[i+1]
A[i] ^ A[i] ^ res[i+1] = res[i] ^ res[i+1] ^ A[i] ^ res[i+1]
res[i+1] = res[i] ^ A[i]

So we use the conslusion above,
iterate the input encoded array A,
update res[i + 1] = res[i] ^ A[i].


Complexity
Time O(n)
Space O(n)

*/

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        
      vector <int> res;
        
      res.push_back(first);
        
      for (int i = 0; i < encoded.size(); i++) {

        res.push_back(encoded[i] ^ res[i]);

      }
        
      return res;
    }
};