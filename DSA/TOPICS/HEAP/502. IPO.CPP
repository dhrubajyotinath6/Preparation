Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.

 

Example 1:

Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
Explanation: Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
Example 2:

Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
Output: 6
 

Constraints:

1 <= k <= 105
0 <= w <= 109
n == profits.length
n == capital.length
1 <= n <= 105
0 <= profits[i] <= 104
0 <= capital[i] <= 109


class Solution {
    
public:
    
  struct capitalCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) { 
      return x.first > y.first; }
  };

  struct profitCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) { 
      return y.first > x.first; }
  };
    
    
public:
    int findMaximizedCapital(int numberOfProjects, int initialCapital, vector<int>& profits, vector<int>& capital) {
        
    int n = profits.size();
        
    priority_queue<pair<int, int>, vector<pair<int, int>>, capitalCompare> minCapitalHeap;
        
    priority_queue<pair<int, int>, vector<pair<int, int>>, profitCompare> maxProfitHeap;

    // insert all project capitals to a min-heap
    for (int i = 0; i < n; i++) {
      minCapitalHeap.push(make_pair(capital[i], i));
    }

    // let's try to find a total of 'numberOfProjects' best projects
    int availableCapital = initialCapital;
        
    for (int i = 0; i < numberOfProjects; i++) {
      // find all projects that can be selected within the available capital and insert 
      // them in a max-heap
      while (!minCapitalHeap.empty() && minCapitalHeap.top().first <= availableCapital) {
        auto capitalIndex = minCapitalHeap.top().second;
        minCapitalHeap.pop();
        maxProfitHeap.push(make_pair(profits[capitalIndex], capitalIndex));
      }

      // terminate if we are not able to find any project that can be completed within 
      // the available capital
      if (maxProfitHeap.empty()) {
        break;
      }

      // select the project with the maximum profit
      availableCapital += maxProfitHeap.top().first;
      maxProfitHeap.pop();
    }

    return availableCapital;
    }
};