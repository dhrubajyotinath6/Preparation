//https://leetcode.com/problems/split-array-into-consecutive-subsequences/solution/   --VERY VERY IMP
class Solution {
public:
    struct Compare {
        bool operator()(array<int, 2> subsequence1, array<int, 2> subsequence2) {
            if (subsequence1[1] == subsequence2[1]) {
                return (subsequence1[1] - subsequence1[0]) > (subsequence2[1] - subsequence2[0]);
            }
            return subsequence1[1] > subsequence2[1];
        }
    };

    bool isPossible(vector<int> &nums) {
        priority_queue<array<int, 2>, vector<array<int, 2>>, Compare> subsequences;

        for (int num : nums) {
            //Condition 1 - remove non qualifying subsequences
            while (!subsequences.empty() && subsequences.top()[1] + 1 < num) {
                array<int, 2> currentSubsequence = subsequences.top();
                subsequences.pop();
                int subsequenceLength = currentSubsequence[1] - currentSubsequence[0] + 1;
                if (subsequenceLength < 3) {
                    return false;
                }
            }
            //Condition 2 - create a new subsequence
            if (subsequences.empty() || subsequences.top()[1] == num) {
                subsequences.push({num, num});
            } else {
                //Condition 3 - add num to an existing subsequence
                array<int, 2> currentSubsequence = subsequences.top();
                subsequences.pop();
                subsequences.push({currentSubsequence[0], num});
            }
        }

        //If any subsequence is of length less than 3 return false
        while (!subsequences.empty()) {
            array<int, 2> currentSubsequence = subsequences.top();
            subsequences.pop();
            int subsequenceLength = currentSubsequence[1] - currentSubsequence[0] + 1;
            if (subsequenceLength < 3) {
                return false;
            }
        }
        return true;
    }
};