//https://leetcode.com/problems/max-number-of-k-sum-pairs/solution/            3rd and 4th approach



class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        int count = 0;
        
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            if (nums[left] + nums[right] < k) {
                left++;
            } else if (nums[left] + nums[right] > k) {
                right--;
            } else {
                left++;
                right--;
                count++;
            }
        }
        return count;
    }
};

/*

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
    
        unordered_map<int, int> map;
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
        
            int current = nums[i];
            int complement = k - current;
            
            if (map[complement] > 0) {
                // remove complement from the map
                map[complement] = map[complement] - 1;
                count++;
            } else {
                 // add current element in the map
                map[current] = map[current] + 1;
            }
        }
        return count;
    }
};

*/