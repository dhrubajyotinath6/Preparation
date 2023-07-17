//https://leetcode.com/problems/strobogrammatic-number/discuss/67207/C%2B%2B-unordered_map
//https://leetcode.com/problems/strobogrammatic-number/solution/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        
        unordered_map<char,char> mpp{
                                    {'0', '0'},
                                    {'1', '1'},
                                    {'6', '9'},
                                    {'8', '8'},
                                    {'9', '6'}            
                                    };
        
        int left = 0;
        int right = num.size() - 1;
        
        while(left <= right){
            
            if(mpp.find(num[left]) == mpp.end() || mpp[num[left]] != num[right]){
                return false; // 8 9 '9' 6 8 -> when left and right points to 9, we get 6 from the map but we need 9 since                                   //right pointer is pointing towards 9
            }
            left++;
            right--;
        }
        return true;
    }
};

/*
Be careful of that middle value in an odd-lengthed number. While the number 8 9 0 6 8 is strobogrammatic, the number 8 9 4 6 8 is not. And nor is 8 9 9 6 8 (this last example is one that is particularly likely to catch some people out, as the middle digit is rotatable, but it doesn't become itself).


*/