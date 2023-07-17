//https://leetcode.com/problems/largest-palindromic-number/discuss/2456626/CPP-JAVA-or-Greedy-or-O(1)-SPACE-or-O(N)-TIME

class Solution {
public:
    string largestPalindromic(string num) {
        
        vector<int> mpp(10);
        
        for(auto i : num){
            mpp[i - '0']++;
        }
        
        string ans = "";
        int single = -1;
        
        for(int i = 9; i >= 0; i--){
            
            if(ans.empty() && i == 0) continue;
            
            while(mpp[i] > 1){
                ans.push_back(i + '0');
                mpp[i] -= 2;
            }
            
            if(mpp[i] == 1 && single == -1){
                single = i;
            }
        }
        
        string secondPart = string(ans.rbegin(), ans.rend());
        
        if(ans.empty() && single == -1) return "0";
        
        // if(ans.empty() && single != -1) return to_string(single);
        
        if(single != -1){
            ans.push_back(single + '0');
        }
        
        ans += secondPart;
        
        return ans;               
    }
};

/*
Input
"00009"

Output
"00900"

Expected
"9"
*/

/*
Input
"00001105"

Output
"151"

Expected
"1005001"
*/