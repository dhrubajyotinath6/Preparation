//https://leetcode.com/problems/add-to-array-form-of-integer/discuss/3187080/Simplest-SolutionororFull-ExplanationororC%2B%2Boror-Python3-oror-Java

/*
Approach

Example: `num` = [2,1,5], `k` = 806
At index 2 num = [2, 1, 811] 
So, `k` = 81 and `num` = [2, 1, 1]

At index 1 num = [2, 82, 1]
So, `k` = 8 and `num` = [2, 2, 1]

At index 0 num = [10, 2, 1]
So, `k` = 1 and `num` = [0, 2, 1]

Now `k` > 0
So, we add at the beginning of num
`num` = [1, 0, 2, 1]


*/
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        for(int i = num.size()-1; i >= 0; i--){
            num[i] += k;
            k = num[i]/10;
            num[i] %= 10;
        }
        
        while(k > 0){
            num.insert(num.begin(), k % 10);
            k /= 10;
        }
        
        return num;
    }
};



