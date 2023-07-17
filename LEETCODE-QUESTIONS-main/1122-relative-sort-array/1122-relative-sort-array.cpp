/* 
Runtime: 4 ms, faster than 62.49% of C++ online submissions for Relative Sort Array.
Memory Usage: 7.6 MB, less than 93.45% of C++ online submissions for Relative Sort Array.

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        vector<int> cnt(1001,0);
        
        //Count each number in arr1.
        for(int n : arr1) cnt[n]++;
        
        //Sort the common numbers in both arrays by the order of arr2.
        int i = 0;
        for(int n : arr2) {
            while(cnt[n]-- > 0) {
                arr1[i++] = n;
            }
        }
        
        
        // Sort the remaining numbers(which are present only in arr1) in arr1.
        for(int n = 0; n < cnt.size(); n++) {
            while(cnt[n]-- > 0) {
                arr1[i++] = n;
            }
        }
        return arr1;
    }
};
*/
//what if the constraints are not there?
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        map<int, int> m;        
        for (auto i : arr1) m[i]++;
        
        int pos = 0;
        for (auto j : arr2) {
            while(m[j]-- > 0) arr1[pos++] = j;
        }
        
        
        for (auto it : m) {
            while(it.second-- > 0) arr1[pos++] = it.first;
        }
        
        return arr1;
    }
};