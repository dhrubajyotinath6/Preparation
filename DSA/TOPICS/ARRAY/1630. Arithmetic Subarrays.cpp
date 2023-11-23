A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference between every two consecutive elements is the same. More formally, a sequence s is arithmetic if and only if s[i+1] - s[i] == s[1] - s[0] for all valid i.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic:

1, 1, 2, 5, 7
You are given an array of n integers, nums, and two arrays of m integers each, l and r, representing the m range queries, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.

Return a list of boolean elements answer, where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be rearranged to form an arithmetic sequence, and false otherwise.

 

Example 1:

Input: nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
Output: [true,false,true]
Explanation:
In the 0th query, the subarray is [4,6,5]. This can be rearranged as [6,5,4], which is an arithmetic sequence.
In the 1st query, the subarray is [4,6,5,9]. This cannot be rearranged as an arithmetic sequence.
In the 2nd query, the subarray is [5,9,3,7]. This can be rearranged as [3,5,7,9], which is an arithmetic sequence.
Example 2:

Input: nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
Output: [false,true,false,false,true,true]


/*
class Solution {
public:
    bool check(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != diff) {
                return false;
            }
        }
        
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for (int i = 0; i < l.size(); i++) {
            vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
            ans.push_back(check(arr));
        }
        
        return ans;
    }
};

tc - O(m.n.logn)
sc - O(n)

*/

class Solution {
    
public:
    bool check(vector<int> &arr){
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        unordered_set<int> st;
        
        for(auto& num : arr){
            mini = min(mini, num);
            maxi = max(maxi, num);
            
            st.insert(num);
        }
        
        /*
        2  4  6  8  10
        10 - 2 = 8
        8/4 = 2
        */
        int n = arr.size();
        if((maxi - mini) %  (n-1) != 0) return false;
        
        int diff = (maxi - mini) / (arr.size() - 1);
        int curr = mini + diff;
        
        while(curr < maxi){
            if(st.find(curr) == st.end()) return false;
            
            curr += diff;
        }
        
        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool> ans;
        
        for(int i = 0; i < l.size(); i++){
            vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
            ans.push_back(check(arr));
        }
        
        return ans;
    }
};

/*
tc - O(m*n)
sc - O(n)


n -> nums.length
m -> length of l and r
*/