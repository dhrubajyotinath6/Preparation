//https://leetcode.com/problems/dot-product-of-two-sparse-vectors/solution/
/*
CHECK OTHER APPROACHES TOO VERY VERY IMP

*/
class SparseVector {
    
    vector<int> arr;
public:
    
    SparseVector(vector<int> &nums) {
        this -> arr = nums;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        
        
        int res = 0;
        
        for(int i = 0; i < arr.size(); i++){
            res += arr[i] * vec.arr[i];
            // cout << arr[i] << " * " << vec.arr[i] <<  " = "<< arr[i] * vec.arr[i] << endl;
        }
        
        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);

/*
Your input
[1,0,0,2,3]
[0,3,0,4,0]

stdout
1 * 0 = 0
0 * 3 = 0
0 * 0 = 0
2 * 4 = 8
3 * 0 = 0

Output
8

Expected
8


*/