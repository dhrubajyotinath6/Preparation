class Solution {
public:
    int totalFruit(vector<int>& arr) {
        
        int windowStart = 0, maxLength = 0;
        //<char, int>
        unordered_map<int, int> fruitFrequencyMap;
        // try to extend the range [windowStart, windowEnd]
        for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
        {
            fruitFrequencyMap[arr[windowEnd]]++;
            // shrink the sliding window, until we're left with '2' fruits in the frequency map
            while ((int)fruitFrequencyMap.size() > 2)
            {
                fruitFrequencyMap[arr[windowStart]]--;
                if (fruitFrequencyMap[arr[windowStart]] == 0)
                {
                    fruitFrequencyMap.erase(arr[windowStart]);
                }
                windowStart++; // shrink the window
            }
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }

        return maxLength;
    }
};