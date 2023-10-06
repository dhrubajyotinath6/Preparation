A sequence of numbers is called an arithmetic progression if the difference between 
any two consecutive elements is the same.

Given an array of numbers arr, return true if the array can be rearranged to form an 
arithmetic progression. Otherwise, return false.

 

Example 1:

Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, 
between each consecutive elements.
Example 2:

Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.
 

Constraints:

2 <= arr.length <= 1000
-106 <= arr[i] <= 106




class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        int minValue = *min_element(arr.begin(), arr.end());
        int maxValue = *max_element(arr.begin(), arr.end());
        
        int n = arr.size();
        
        //If we have diff = 0, it means that all the numbers in arr are equal, and we can return true directly.
        if(maxValue - minValue == 0) return true;
        
        //If max_value - min_value is not divisible by n - 1, it means arr can't form an arithmetic sequence, return false.
        if((maxValue - minValue) % (n-1) != 0) return false;
        
        int diff = (maxValue - minValue)/(n-1);
        unordered_set<int> st;
        
        for(int i = 0; i < n; i++){
            //the difference between each number arr[i] and min_value must be divisible by diff
            if((arr[i] - minValue) % diff != 0) return false;
            
            // might not work if there are duplicate elements. For example, let arr = [1, 2, 3, 2, 5]. that's why set is used
            st.insert(arr[i]);
        }
        
        return st.size() == n;
    }
};


/*
Approach 3: In-place Modification

class Solution {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        int minValue = *std::min_element(arr.begin(), arr.end());
        int maxValue = *std::max_element(arr.begin(), arr.end());
        int n = arr.size();
        
        if ((maxValue - minValue) % (n - 1) != 0) {
            return false;
        }
        
        int diff = (maxValue - minValue) / (n - 1);
        int i = 0;
        
        while (i < n) {
            // If arr[i] is at the correct index, move on.
            if (arr[i] == minValue + i * diff) {
                i += 1;
                
            // If arr[i] doesn't belong to this arithmetic sequence, return false.
            } else if ((arr[i] - minValue) % diff != 0) {
                return false;
                
            // Otherwise, find the index j to which arr[i] belongs, swap arr[j] with arr[i].
            } else {
                int j = (arr[i] - minValue) / diff;
                
                // If we find duplicated elements, return False.
                if (arr[i] == arr[j]) {
                    return false;
                }
                
                // Swap arr[i] with arr[j].
                swap(arr[i], arr[j]);
            }
        }
        
        return true;
    }
};

['3', 9, '7', 1, '5']   =>   [1, '3', '5', '7', 9]


Now we have the common difference diff and the first term min_value. Given a number arr[i], we can calculate its position j in the arithmetic sequence as j = (arr[i] - min_value) / diff.

If j is already equal to i, then this number arr[i] is already in the correct position and we can move on to the next i. Otherwise, we swap arr[i] with arr[j]. We can put one number (arr[i]) in its correct position with each step.

In reference to the following image, for i = 0, arr[i] = 3 is not in the correct position, so we compute the correct index j it belongs to using j = (arr[i] - 1) / diff = 1, then we swap arr[0] with arr[1]. Note that we don't need to create the sorted arr, it is just for reference in the image.
*/