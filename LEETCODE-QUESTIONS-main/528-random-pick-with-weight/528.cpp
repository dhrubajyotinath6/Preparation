You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).
 

Example 1:

Input
["Solution","pickIndex"]
[[[1]],[]]
Output
[null,0]

Explanation
Solution solution = new Solution([1]);
solution.pickIndex(); // return 0. The only option is to return 0 since there is only one element in w.
Example 2:

Input
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output
[null,1,1,1,1,0]

Explanation
Solution solution = new Solution([1, 3]);
solution.pickIndex(); // return 1. It is returning the second element (index = 1) that has a probability of 3/4.
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 0. It is returning the first element (index = 0) that has a probability of 1/4.

Since this is a randomization problem, multiple answers are allowed.
All of the following outputs can be considered correct:
[null,1,1,1,1,0]
[null,1,1,1,1,1]
[null,1,1,1,0,0]
[null,1,1,1,0,1]
[null,1,0,1,0,0]
......
and so on.
 

Constraints:

1 <= w.length <= 104
1 <= w[i] <= 105
pickIndex will be called at most 104 times.



ANS:

//https://leetcode.com/problems/random-pick-with-weight/solution/
//https://leetcode.com/problems/random-pick-with-weight/solution/848087

/*
Explanation of why prefixSum works:

Think that if we had an array [1,2,3,4,3].
Normal random pickIndex would pick any index from 0 to 4 with equal probability.
But we want that index=1 is picked by 2/13 probability, index=0 with 1/13 probability 
and so on. (13 is sum of weights). 
To ensure that one way to think of it if we make a larger array (of size 13) 
where the values are the indices such that index i is repeated w[i] times 
then if we do a normal rand on this array
then index 0 to 12 will be picked randomly with equal probability. 
13 index array -> [0, 1,1, 2,2,2, 3,3,3,3, 4,4,4]. 
So there is a 3/13 chance of picking 2 as 2 is repeated thrice in the new array.

Now instead of actually constructing this 13 index array,
we just know the range of the index of the 13 index array 
where value = i. Eg:

for index=0, range is {0,0}
index =1, range of indices of the new array is {1,2}
index=2, range={3,5}
index=3, range ={6,9}
index = 4, range = {10,12}
In other words,

index=0, range is <1
index=1, range is <3
index=2, range is <6
index = 3, range is < 10
index = 4, range is < 13

If you notice the above numbers 1,3,6,10,13 - they are cumulative sum.
The reason this happens is because for every range: 
right = left + (w[i] - 1) and left is (prev right+1). 
So if we substitute 2nd equation into 1st. right = (prev right)+w[i]; 
i.e. keep adding prev sum to current weight.

Thus the prefixSum is able to implement this
*/

/*
upper_bound() is a standard library function in C++ defined in the header . 
It returns an iterator pointing to the first element in the range [first, last)
that is greater than value, or last if no such element is found

Input : 10 20 30 '30' 40 50
Output : upper_bound for element 30 is at index 4

Input : 10 20 30 40 '50'
Output : upper_bound for element 45 is at index 4

Input : 10 20 30 40 50 ''
Output : upper_bound for element 60 is at index 5
*/

/*
[1, 2, 3,  4,  3]  -> [0,1,1,2,2,2,3,3,3,3,4,4,4]
[1, 3, 6, 10, 13]  -> PREFIX SUM

*/

class Solution {
    
    vector<int> prefixSums;
public:
    Solution(vector<int>& w) {
        
        for(auto value : w){
            prefixSums.push_back( value + (prefixSums.empty() ? 0 : prefixSums.back()));
        }
    }
    
    int pickIndex() {
        
        float randNum = (float)rand()/RAND_MAX;
        float target = randNum * prefixSums.back();
        
        return upper_bound(begin(prefixSums), end(prefixSums), target) - begin(prefixSums);
    }
};

/*
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
*/
