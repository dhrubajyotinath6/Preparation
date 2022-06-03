Design a class to calculate the median of a number stream. The class should have the following two methods:

insertNum(int num): stores the number in the class
findMedian(): returns the median of all numbers inserted in the class
If the count of numbers inserted in the class is even, the median will be the average of the middle two numbers.

Example 1:

1. insertNum(3)
2. insertNum(1)
3. findMedian() -> output: 2
4. insertNum(5)
5. findMedian() -> output: 3
6. insertNum(4)
7. findMedian() -> output: 3.5



using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class MedianOfAStream {
 public:
  priority_queue<int> maxHeap; // containing first half of numbers
  priority_queue<int, vector<int>, greater<int>> minHeap;// containing second half

  virtual void insertNum(int num) {
    if (maxHeap.empty() || maxHeap.top() >= num) {
      maxHeap.push(num);
    } else {
      minHeap.push(num);
    }

    // either both the heaps will have equal number of elements or max-heap will have one
    // more element than the min-heap
    if (maxHeap.size() > minHeap.size() + 1) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    } else if (maxHeap.size() < minHeap.size()) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }

  virtual double findMedian() {
    if (maxHeap.size() == minHeap.size()) {
      // we have even number of elements, take the average of middle two elements
      return maxHeap.top() / 2.0 + minHeap.top() / 2.0;
    }
    // because max-heap will have one more element than the min-heap
    return maxHeap.top();
  }
};

int main(int argc, char *argv[]) {
  MedianOfAStream medianOfAStream;
  medianOfAStream.insertNum(3);
  medianOfAStream.insertNum(1);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(5);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(4);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
}