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


















