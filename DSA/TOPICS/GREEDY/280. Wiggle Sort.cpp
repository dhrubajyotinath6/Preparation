//https://leetcode.com/problems/wiggle-sort/

Given an integer array nums, reorder it such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

You may assume the input array always has a valid answer.

 

Example 1:

Input: nums = [3,5,2,1,6,4]
Output: [3,5,1,6,2,4]
Explanation: [1,6,2,5,3,4] is also accepted.
Example 2:

Input: nums = [6,6,5,6,3,8]
Output: [6,6,5,6,3,8]
 

Constraints:

1 <= nums.length <= 5 * 104
0 <= nums[i] <= 104
It is guaranteed that there will be an answer for the given input nums.


//brute force approch
/*
class Solution {
public:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size() - 1; i += 2) {
            swap(nums[i], nums[i + 1]);
        }
    }
};


*/

/*
https://leetcode.com/problems/wiggle-sort/solution/
*/
class Solution {
    
public:
    void swap(vector<int> &nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
public:
    void wiggleSort(vector<int>& nums) {
        
        for(int i = 0; i < nums.size() - 1; i++){
            if( ((i%2 == 0) && nums[i] > nums[i+1]) ||  ((i % 2 == 1) && nums[i] < nums[i + 1])){
                swap(nums, i, i+1);
            }
        }
    }
};



As we know, the idea is ensure that every odd position is greater than or equal to its two adjacent 
even positions. For any odd index i, we need to ensure the nums[i-1] <= nums[i] and nums[i+1] <= nums[i].

Let's take an example. Suppose, we have the nums array that has five elements. If nums[0] <= nums[1], 
the first two elements are already wiggly sorted. We don't do anything here and move to the next element. 
Otherwise, if nums[0] > nums[1], we swap nums[0] and nums[1].

Let us now proceed to the next element, nums[2]. So far, we have nums[0] <= nums[1]. If nums[1] >= nums[2], 
the first three elements of nums are already sorted wiggly. Otherwise, if nums[1] < nums[2], 
it implies nums[0] < nums[2] (because nums[0] <= nums[1]). We swap nums[1] and nums[2] 
which reorders nums to follow nums[0] <= nums[1] >= nums[2], which is a wiggly sorted order. 
Notice how the second swap has no effect on nums[0].

Now, we've got the following: nums[0] <= nums[1] >= nums[2] after all the required swaps, 
and nums[3] is our next element. If nums[2] <= nums[3], the elements are already wiggly sorted. 
Otherwise, if nums[2] > nums[3], it implies nums[1] > nums[3] (because nums[1] >= nums[2]). 
We swap nums[2] and nums[3] so that the array follows nums[0] <= nums[1] >= nums[2] <= nums[3], 
which is a wiggly sorted array. Again, notice that in this third swap, the array until the second element, 
nums[1] is unaffected. It preserves the wiggly sorted property until nums[1].

Similarly, we can add nums[4] and observe that the array is unaffected until the third element, 
preserving the wiggly property.

The pattern that we can observe in the above example is that elements at indices 0 and 2 
(i.e., elements at even indices) are swapped with the next adjacent element if they are greater 
than the next adjacent element. Similarly, we see in the above example that elements at index 1 and 3 
(i.e., elements at oodd indices) are swapped with the next adjacent element if they are smaller 
than the next adjacent element. The example also shows that, given any array, we can always arrange them 
in wiggly sort order.

This leads to our solution. We greedily check for each index i. 
If i is even, nums[i] should be smaller than or equal to nums[i + 1]. 
If it is larger, i.e., nums[i] > nums[i + 1], we swap nums[i] and nums[i + 1].

Similarly, if i is odd, nums[i] should be greater than or equal to nums[i + 1]. 
If it is smaller, i.e., nums[i] < nums[i + 1], we swap nums[i] and nums[i + 1].

Here is a visual example with the steps:



















