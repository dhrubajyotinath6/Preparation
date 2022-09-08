vector<int> Solution::nextPermutation(vector<int> &A) {
    
    int n = A.size(), k, l;
    vector<int> ans;
    
    for(k = n-2; k >= 0; k--){
        if(A[k+1] > A[k]) break;
    }
    
    if(k < 0){
        reverse(A.begin(), A.end());
        return ans = A;
    }
    
    for(l = n-1; l > k; l--){
        if(A[l] > A[k]) break;
    }
    
    swap(A[l], A[k]);
    
    reverse(A.begin() + k + 1, A.end());  
    return ans = A; 
    
}

/*


*/
