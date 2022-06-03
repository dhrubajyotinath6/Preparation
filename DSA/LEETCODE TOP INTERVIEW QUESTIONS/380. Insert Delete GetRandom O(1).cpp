Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.

 

Example 1:

Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.





//https://leetcode.com/problems/insert-delete-getrandom-o1/discuss/85422/AC-C%2B%2B-Solution.-Unordered_map-%2B-Vector

/* 
https://www.cplusplus.com/reference/vector/vector/emplace_back/
emplace_back -> Construct and insert element at the end
Inserts a new element at the end of the vector, right after its current last element. This new element is constructed in        place using args as the arguments for its constructor.

This effectively increases the container size by one, which causes an automatic reallocation of the allocated storage space     if -and only if- the new vector size surpasses the current vector capacity.
    
*/

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    
    
    bool insert(int val) {        
        if (m.find(val) != m.end()) return false;        
        nums.emplace_back(val);
        m[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {           // val = 3
        if (m.find(val) == m.end()) return false; 
        int last = nums.back();      // 1 2 3 4 5 6 we want to delete 3 , so last = 6;
        m[last] = m[val];            // prev : 3 -> 2 , 6 -> 5 ; now : 6 -> 2 . in other words m[6] = m[3] = 2;
        nums[m[val]] = last;         // 1 2 6 4 5 6 , nums[2] = 6;
        nums.pop_back();             // 1 2 6 4 5
        m.erase(val);                // from the map delete 3 -> 2
        return true;
    }
    
    
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, int> m;
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */