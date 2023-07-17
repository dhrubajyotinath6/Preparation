class Solution {
public:
    int candy(vector<int>& A) {
    int n = A.size();
    vector<int> left(n, 1);  // 0  1     n
    
    for(int i = 1; i < n; i++){
        if(A[i] > A[i-1])  left[i] = left[i-1] + 1;
    }
    
    int right = 1;
    for(int j = n-2; j >= 0; j--){
        if(A[j] > A[j+1]){
            right++;
            left[j] = max(left[j], right);
        }else{
            right = 1;
        }
    }
    
    
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += left[i];
    }
    
    return sum;
    }
};