//https://leetcode.com/problems/removing-minimum-number-of-magic-beans/discuss/1766764/C%2B%2BJavaPython3-Sorting-4-lines   -- very very imp

//https://leetcode.com/problems/removing-minimum-number-of-magic-beans/discuss/1767034/Count-Remaining-Beans


//https://leetcode.com/problems/removing-minimum-number-of-magic-beans/discuss/1766795/JavaPython-3-Sort-then-1-pass-find-max-rectangle-w-graph-explanation-and-analysis.



class Solution {
public:
    long long minimumRemoval(vector<int>& A) {
        
        long N = A.size(), ans = LLONG_MAX, sum = accumulate(begin(A), end(A), 0L);
        
        sort(begin(A), end(A));
        
        for (int i = 0; i < N; ++i) ans = min(ans, sum - (N - i) * A[i]);
        
        return ans;
    }
};
