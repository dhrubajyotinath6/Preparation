class Solution {
public:
    vector<int> findAnagrams(string str, string pattern) {
        
        int windowStart = 0, matched = 0;
        unordered_map<char, int> charFrequencyMap;
        for (auto chr : pattern)
        {
            charFrequencyMap[chr]++;
        }

        vector<int> resultIndices;
        // our goal is to match all the characters from the map with the current window
        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++)
        {
            char rightChar = str[windowEnd];
            // decrement the frequency of the matched character
            if (charFrequencyMap.find(rightChar) != charFrequencyMap.end())
            {
                charFrequencyMap[rightChar]--;
                if (charFrequencyMap[rightChar] == 0)
                {
                    matched++;
                }
            }

            if (matched == (int)charFrequencyMap.size())
            { // have we found an anagram?
                resultIndices.push_back(windowStart);
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
                    // put the character back
                    charFrequencyMap[leftChar]++;
                }
            }
        }

        return resultIndices;
    }
};