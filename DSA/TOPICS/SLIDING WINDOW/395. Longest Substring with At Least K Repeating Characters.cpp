Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

if no such substring exists, return 0.

 

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 

Constraints:

1 <= s.length <= 104
s consists of only lowercase English letters.
1 <= k <= 105


class Solution {
    
public:
    int getMaxUniqueLetters(string s){
        bool map[26] = {0};
        int maxUnique = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(map[s[i] - 'a'] == 0){
                maxUnique++;
                map[s[i] - 'a'] = true;
            }
        }
        
        return maxUnique;
    }
    
public:
    int longestSubstring(string s, int k) {
  
        int countMap[26];
        int maxUnique = getMaxUniqueLetters(s);
        
        int result = 0;
        
        for(int currUnique = 1; currUnique <= maxUnique; currUnique++){
            
            //////////////////
            
            memset(countMap, 0, sizeof(countMap));
            int windowStart = 0, unique = 0;
            int i = 0;
            int countAtLeastK = 0;
            
            for(int windowEnd = 0; windowEnd < s.size();){
                
                if(unique <= currUnique){
                    i = s[windowEnd] - 'a';
                    
                    if(countMap[i] == 0) unique++;
                    countMap[i]++;
                    
                    if(countMap[i] == k) countAtLeastK++;
                    windowEnd++;
                }
                else{
                    i = s[windowStart] - 'a';
                    if(countMap[i] == k) countAtLeastK--;
                    countMap[i]--;
                    
                    if(countMap[i] == 0) unique--;
                    windowStart++;
                }
                
                if(unique == currUnique && unique == countAtLeastK){
                    result = max(result, windowEnd - windowStart);
                }
            }
            
            ///////////////////
        }
        
        return result;
    }
};


/*
s = "a b a b a b b d a b c a b c",  k = 2;

maxUnique = 3

currUnique = 1
s = a b a b a [b b] d a b c a b c  -> 2

currUnique = 2
s = [a b a b a b b] d a b c a b c  -> 7

currUnique = 3
s = a b a b a b b d [a b c a b c]  -> 6


res = max(2,7,6) = 7



Algorithm

Find the number of unique characters in the string s and store the count in variable maxUnique. For s = aabcbacad, the unique characters are a,b,c,d and maxUnique = 4.

Iterate over the string s with the value of currUnique ranging from 1 to maxUnique. In each iteration, currUnique is the maximum number of unique characters that must be present in the sliding window.

The sliding window starts at index windowStart and ends at index windowEnd and slides over string s until windowEnd reaches the end of string s. At any given point, we shrink or expand the window to ensure that the number of unique characters is not greater than currUnique.

If the number of unique character in the sliding window is less than or equal to currUnique, expand the window from the right by adding a character to the end of the window given by windowEnd

Otherwise, shrink the window from the left by removing a character from the start of the window given by windowStart.

Keep track of the number of unique characters in the current sliding window having at least k frequency given by countAtLeastK. Update the result if all the characters in the window have at least k frequency.
*/




















