//https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/discuss/1064548/JavaC%2B%2BPython-Binary-Search

// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/discuss/1064793/Binary-Search-or-with-Intuition-and-explanation

class Solution {
public:
	int minimumSize(vector<int>& nums, int maxOperations) {
        
		int start = 1, end = *max_element(nums.begin(), nums.end());
        
		int minPenalty = end;
        
		// binary search on possible range
		while (start <= end) {
            
			int mid = start + (end-start)/2;
            
			if (isPossible(nums, maxOperations, mid))
				minPenalty = mid, end = mid-1;
			else
				start = mid+1;
		}

		return minPenalty;
	}

    /*
	bool isPossible(vector<int>& nums, int maxOperations, int penalty) {
		int requiredOps = 0;
		for (int n : nums) {
			// no. of operations required to bring n less than or eq to curr assumed penalty
			int x = n / penalty;
			// if n is divisible by penalty, need to subtract 1
			if (n % penalty == 0) x--;
			requiredOps += x;
		}
		// getting current penalty is possible only if required ops is <= maxOps
		return requiredOps <= maxOperations;
	}
    
    9/3 = 2
    9 -> 6,3 -> 3,3,3
    
    10/3 = 3
    10 -> 3,7 -> 3,3,4 -> 3,3,3,1
    */
    bool isPossible(vector<int>& nums, int maxOperations, int penalty) {
        
        int requiredOps = 0;
        
        for (int a : nums)
                requiredOps += (a - 1) / penalty;
        
        return requiredOps <= maxOperations;
    }
    
};