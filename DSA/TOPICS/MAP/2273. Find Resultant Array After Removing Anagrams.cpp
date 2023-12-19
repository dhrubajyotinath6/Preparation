You are given a 0-indexed string array words, where words[i] consists of lowercase English letters.

In one operation, select any index i such that 0 < i < words.length and words[i - 1] and words[i] are anagrams, and delete words[i] from words. Keep performing this operation as long as you can select an index that satisfies the conditions.

Return words after performing all operations. It can be shown that selecting the indices for each operation in any arbitrary order will lead to the same result.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase using all the original letters exactly once. For example, "dacb" is an anagram of "abdc".

 

Example 1:

Input: words = ["abba","baba","bbaa","cd","cd"]
Output: ["abba","cd"]
Explanation:
One of the ways we can obtain the resultant array is by using the following operations:
- Since words[2] = "bbaa" and words[1] = "baba" are anagrams, we choose index 2 and delete words[2].
  Now words = ["abba","baba","cd","cd"].
- Since words[1] = "baba" and words[0] = "abba" are anagrams, we choose index 1 and delete words[1].
  Now words = ["abba","cd","cd"].
- Since words[2] = "cd" and words[1] = "cd" are anagrams, we choose index 2 and delete words[2].
  Now words = ["abba","cd"].
We can no longer perform any operations, so ["abba","cd"] is the final answer.
Example 2:

Input: words = ["a","b","c","d","e"]
Output: ["a","b","c","d","e"]
Explanation:
No two adjacent strings in words are anagrams of each other, so no operations are performed.


class Solution {
    
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size()) return false;
        
        vector<int> freq(26,0);
        
        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        
        
        for(int i = 0; i < 26; i++){
            if(freq[i]) return false;
        }
        
        return true;
    }
    
public:
    vector<string> removeAnagrams(vector<string>& words) {
        
        vector<string> ans;
        
        int i = 0, j = 1;
        
        for(; j < words.size();){
            
            if(isAnagram(words[i], words[j])){
                j++;
            }
            else{
               ans.push_back(words[i]);
                i = j;
                j++;
            }
        }
        
        ans.push_back(words[i]);
        
        return ans;
    }
};