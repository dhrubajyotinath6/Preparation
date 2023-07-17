//https://leetcode.com/problems/camelcase-matching/discuss/270029/JavaC%2B%2BPython-Check-Subsequence-and-Regax
/*
ASCII value

A - 65

a - 97

*/

class Solution {
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern) {
        
        vector<bool> res;
        
        for (string &query : queries) res.push_back(isMatch(query, pattern));
        return res;

    }

    bool isMatch(string query, string pattern) {
        
        int i = 0;
        
        for (char & c : query)
            if (i < pattern.length() && c == pattern[i]) i++;
            else if (c < 'a') return false;
        return i == pattern.length();
    }
};