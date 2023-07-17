class Solution {
public:
    vector<int> sumZero(int n) {
       vector<int> nums(n);
        
        for(int i = 0; i < n; i++){
            nums[i] =   (- n + 1) + i*2;  
        }
    return nums; 
    }
};

/*
https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/discuss/465585/JavaC%2B%2BPython-Find-the-Rule
Naive idea
n = 1, [0]
n = 2, [-1, 1]

Now write more based on this
n = 3, [-2, 0, 2]
n = 4, [-3, -1, 1, 3]
n = 5, [-4, -2, 0, 2, 4]

It spreads like the wave.
    
we know, 
    Tth term in an AP = a + (t - 1)*d
    
    here n will be given, d = 2
    so, 1st term, a = (- n + 1)
        
    a + (t - 1)*d = (- n + 1) + (t - 1)*d = (- n + 1) + i*d
    
    
*/