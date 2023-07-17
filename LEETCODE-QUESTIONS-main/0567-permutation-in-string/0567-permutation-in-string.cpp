class Solution {
public:
    bool checkInclusion(string pattern, string str) {
             int windowStart = 0, matched = 0;
        unordered_map<char, int> charFrequencyMap;
        for (auto chr : pattern)
        {
            charFrequencyMap[chr]++;
        }

        // our goal is to match all the characters from the 'charFrequencyMap' with the
        // current window try to extend the range [windowStart, windowEnd]
        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++)
        {
            char rightChar = str[windowEnd];
            if (charFrequencyMap.find(rightChar) != charFrequencyMap.end())
            {
                // decrement the frequency of the matched character
                charFrequencyMap[rightChar]--;
                if (charFrequencyMap[rightChar] == 0)
                { // character is completely matched
                    matched++;
                }
            }

            if (matched == (int)charFrequencyMap.size())
            {
                return true;
            }

            if (windowEnd >= pattern.length() - 1)
            { // shrink the window
                char leftChar = str[windowStart++];
                if (charFrequencyMap.find(leftChar) != charFrequencyMap.end())
                {
                    if (charFrequencyMap[leftChar] == 0)
                    {
                        matched--; // before putting the char back, decrement the matched count
                    }
                    // put the character back for matching
                    charFrequencyMap[leftChar]++;
                }
            }
        }

        return false;   
    }
};