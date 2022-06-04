Given a set of investment projects with their respective profits, we need to find the most profitable projects. We are given an initial capital and are allowed to invest only in a fixed number of projects. Our goal is to choose projects that give us the maximum profit. Write a function that returns the maximum total capital after selecting the most profitable projects.

We can start an investment project only when we have the required capital. Once a project is selected, we can assume that its profit has become our capital.

Example 1:

Input: Project Capitals=[0,1,2], Project Profits=[1,2,3], Initial Capital=1, Number of Projects=2
Output: 6
Explanation:

With initial capital of ‘1’, we will start the second project which will give us profit of ‘2’. Once we selected our first project, our total capital will become 3 (profit + initial capital).
With ‘3’ capital, we will select the third project, which will give us ‘3’ profit.
After the completion of the two projects, our total capital will be 6 (1+2+3).

Example 2:

Input: Project Capitals=[0,1,2,3], Project Profits=[1,2,3,5], Initial Capital=0, Number of Projects=3
Output: 8
Explanation:

With ‘0’ capital, we can only select the first project, bringing out capital to 1.
Next, we will select the second project, which will bring our capital to 3.
Next, we will select the fourth project, giving us a profit of 5.
After selecting the three projects, our total capital will be 8 (1+2+5).






using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class MaximizeCapital {
 public:
  struct capitalCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) { 
      return x.first > y.first; }
  };

  struct profitCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) { 
       return y.first > x.first; }
  };

  static int findMaximumCapital(const vector<int> &capital, const vector<int> &profits,
                                int numberOfProjects, int initialCapital) {
    int n = profits.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, capitalCompare> 
          minCapitalHeap;
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

int main(int argc, char *argv[]) {
  int result =
      MaximizeCapital::findMaximumCapital(vector<int>{0, 1, 2}, 
                                          vector<int>{1, 2, 3}, 2, 1);
  cout << "Maximum capital: " << result << endl;
  result =
      MaximizeCapital::findMaximumCapital(vector<int>{0, 1, 2, 3}, 
                                          vector<int>{1, 2, 3, 5}, 3, 0);
  cout << "Maximum capital: " << result << endl;
}