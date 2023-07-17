//https://leetcode.com/problems/flip-string-to-monotone-increasing/discuss/189751/C%2B%2B-one-pass-DP-solution-0ms-O(n)-or-O(1)-one-line-with-explaination.

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int one = 0;
        int flip =0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] =='1')
                one++;
            else
                flip++;
            flip = min(one,flip);
        }
    return flip;
    }
};