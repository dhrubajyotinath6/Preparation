/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(!list1) return list2;
        if(!list2) return list1;
        
        if(list1->val > list2->val) swap(list1, list2);
        
        ListNode *res = list1;
        
        while(list1 != NULL && list2 != NULL){

            ListNode *tmp = NULL;

            while(list1 != NULL && list1->val <= list2->val){
                tmp = list1;
                list1 = list1->next;
            }

            tmp->next = list2;
            swap(list1,list2);
            
        }
        return res;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
     if(lists.empty()) return NULL;
        
    while(lists.size() > 1){
        lists.push_back(mergeTwoLists(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
        
    return lists.front();
    }
};


//2ND SOLUTION
class MergeKSortedLists {

 public:
  struct valueCompare {
    bool operator()(const ListNode *x, const ListNode *y) { return x->value > y->value; }
  };

  static ListNode *merge(const vector<ListNode *> &lists) {

    priority_queue<ListNode *, vector<ListNode *>, valueCompare> minHeap;

    // put the root of each list in the min heap
    for (auto root : lists) {
      if (root != nullptr) {
        minHeap.push(root);
      }
    }

    // take the smallest (top) element form the min-heap and add it to the result;
    // if the top element has a next element add it to the heap
    ListNode *resultHead = nullptr, *resultTail = nullptr;

    while (!minHeap.empty()) {

      ListNode *node = minHeap.top();
      minHeap.pop();

      if (resultHead == nullptr) {
        resultHead = resultTail = node;
      } else {
        resultTail->next = node;
        resultTail = resultTail->next;
      }

      if (node->next != nullptr) {
        minHeap.push(node->next);
      }

    }

    return resultHead;
  }
};