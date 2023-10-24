Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.

 

Example 1:

Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].
Example 2:

Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The subsequence must be non-empty, so we choose the largest number.
Example 3:

Input: nums = [10,-2,-10,-5,20], k = 2
Output: 23
Explanation: The subsequence is [10, -2, -5, 20].
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        deque<int> queue;
        vector<int> dp(nums.size());
        
        for(int i = 0; i < nums.size(); i++){
            
            if(!queue.empty() && i - queue.front() > k) queue.pop_front();
            
            dp[i] = (!queue.empty() ? dp[queue.front()] : 0) + nums[i];
            
            while(!queue.empty() && dp[queue.back()] < dp[i]){
                queue.pop_back();
            }
            
            if(dp[i] > 0){
                queue.push_back(i);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};

Explanation:

Before we start developing a strategy, we must carefully understand what the problem is asking for.

We need to maximize the sum of a subsequence. We can take as many integers as we want, but the primary constraint is that we cannot have a gap of k or more in our subsequence.

You may immediately notice that in an array of positive integers, we should always take the entire array. The tricky part comes in when we have negative integers. Of course, we would prefer to avoid negative integers since they will decrease our sum. However, it may be worth taking a negative integer as a sort of "bridge". Take a look at the following example:

16   -13    -5      -10     4       3       9

k = 2;

In this example, we have a group of negative numbers separating a 16 and a group of positive numbers that sum to 16. We would like to take all the positive numbers while avoiding the negative numbers, but we aren't allowed to as that would result in a gap of three numbers. As k = 2, the biggest gap we can have is one number. The optimal solution here is to take the -5.


As you can see, the -5 acts as a bridge for the positive numbers. The question now is, how do we know when it is worth it to take negative numbers? In this case, taking the -5 allowed us to take the first element of 16. This results in a net gain of 11. Anytime we have a positive net gain, we should consider taking this element because it can contribute to a positive sum and potentially increase the sum of subsequent subsequences.

We will iterate over the input from left to right. At each index i, we will consider the maximum possible sum of a subsequence that includes and ends at nums[i]. Let's call this value curr. How do we calculate curr for a given index i? We want the maximum possible sum of a subsequence that ends within the last k indices. We will then add nums[i] to this sum.

We could solve this using dynamic programming - let dp[i] represent the maximum possible sum of a subsequence that includes and ends at nums[i]. We can calculate dp[i] by taking the maximum dp[j] for all j in the range [i - k, i - 1] (the last k indices), then adding nums[i] to it.

However, we would be iterating up to k times to calculate each state. As k can be large, this approach is too slow. We need a faster way to find the maximum dp[j] for all indices j in the range [i - k, i - 1].

Because we are only concerned with the maximum sum, we could use a max heap. The max heap would store dp[j] for all j in the last k indices. We can easily calculate curr by simply checking the top of this heap.

We need to make sure we donot use elements of the heap that are more than k away from the current index. Before we calculate curr, we pop from the top of the heap if it is outside our range. This means each entry in the heap will also need its associated index, so we can tell when an element is out of range.

Note that if the top of the heap is negative, it is better to not take it. This is a process very similar to Kadane's Algorithm, which solves the Maximum Subarray problem. When the top of the heap is negative, it indicates that selecting this subsequence would result in a sum less than 0. Every element in the array to the left of the current index should be abandoned - any "bridge" would not be worth taking. It is better to discard these subsequences altogether and reset the sum to 0.


tc - nlogn
sc - n

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        heap.push({nums[0], 0});
        int ans = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            while (i - heap.top().second > k) {
                heap.pop();
            }

            int curr = max(0, heap.top().first) + nums[i];
            ans = max(ans, curr);
            heap.push({curr, i});
        }
        
        return ans;
    }
};



//optim ised one

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> queue;
        vector<int> dp(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            if (!queue.empty() && i - queue.front() > k) {
                queue.pop_front();
            }
            
            dp[i] = (!queue.empty() ? dp[queue.front()] : 0) + nums[i];
            while (!queue.empty() && dp[queue.back()] < dp[i]) {
                queue.pop_back();
            }
            
            if (dp[i] > 0) {
                queue.push_back(i);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};

