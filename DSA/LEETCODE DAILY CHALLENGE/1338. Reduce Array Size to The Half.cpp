/*
You are given an integer array arr. You can choose a set of integers and remove
all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.



Example 1:

Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (
i.e equal to half of the size of the old array).

Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5]
which has a size greater than half of the size of the old array.

Example 2:

Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.


Constraints:

2 <= arr.length <= 105
arr.length is even.
1 <= arr[i] <= 105

*/

// https://leetcode.com/problems/reduce-array-size-to-the-half/discuss/1319416/C%2B%2BJavaPython-HashMap-and-Sort-then-Counting-Sort-O(N)-Clean-and-Concise

// https://leetcode.com/problems/reduce-array-size-to-the-half/discuss/1319437/Simple-Solution-w-Explanation-or-Delete-Elements-by-Max-Frequency-or-O(N)-Beats-100

// HASHMAP + GREEDY

class Solution
{

public:
    struct valueCompare
    {

        char operator()(const pair<int, int> &x, const pair<int, int> &y)
        {
            return y.second > x.second;
        }
    };

    int minSetSize(vector<int> &arr)
    {

        unordered_map<int, int> mpp;

        for (auto i : arr)
        {
            mpp[i]++;
        }

        // u can write comparator here

        priority_queue<pair<int, int>, vector<pair<int, int>>, valueCompare> maxHeap;

        for (auto x : mpp)
        {
            maxHeap.push(x);
        }

        int n = arr.size() / 2;
        int size = 0;

        while (n > 0)
        {
            n -= maxHeap.top().second;
            maxHeap.pop();
            size++;
        }

        return size;
    }
};
