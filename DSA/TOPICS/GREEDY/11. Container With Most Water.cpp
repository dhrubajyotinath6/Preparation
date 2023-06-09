//https://leetcode.com/problems/container-with-most-water/

You are given an integer array height of length n. There are n vertical lines drawn such that the 
two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains 
the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1



/*
public class Solution {
    public int maxArea(int[] height) {
        int maxarea = 0;
        for (int left = 0; left < height.length; left++) {
            for (int right = left + 1; right < height.length; right++) {
                int width = right - left;
                maxarea = Math.max(maxarea, Math.min(height[left], height[right]) * width);
            }
        }
        return maxarea;
    }
}

tc - O(n^2)
sc - O(1)
*/
//https://leetcode.com/problems/container-with-most-water/solution/


I found a lot of the discussion and proof about this quite opaque, 
but one thing helped it finally clicked for me (which is sort of proof by contradiction i guess)

You have two heights H_left and H_right, and H_right < H_left, then we know we have two choices, 
we want to move one of them. If we move the larger one, we cannot increase the height 
for the simple reason that we are always limited by the shortest, and we would be decreasing j-i, 
the width as well.

To clarify: let's say we kept the shortest forever, what would happen? Well, j-i would decrease, 
and either we come across a taller block, which doesn't matter because our shorter one we kept only mattered, or we find a shorter one, in which case that one matters.

Either way we end up with a smaller area, so we must move the shorter one because moving the 
larger one cannot give an increase in area.

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxArea = 0, area = 0;
        int left = 0, right = height.size()-1, width = 0;
        
        while(left < right){
           
            width = right - left;
            
            area = min(height[left], height[right])*width;
            maxArea = max(area, maxArea);
            
            if(height[left] < height[right]) left++;
            else right--;           
            
        }
        
     return maxArea;
    }
};



/*
tc - O(n)
sc - O(1)

*/


















