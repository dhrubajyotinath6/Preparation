class ReverseLinkedList {
 public:
  static ListNode *reverse(ListNode *head) {
    ListNode *current = head;      // current node that we will be processing
    ListNode *previous = nullptr;  // previous node that we have processed
    ListNode *next = nullptr;      // will be used to temporarily store the next node

    while (current != nullptr) {
      next = current->next;      // temporarily store the next node
      current->next = previous;  // reverse the current node
      // before we move to the next node, point previous to the current node
      previous = current; 
      current = next;      // move on the next node
    }
    // after the loop current will be pointing to 'null' and 'previous' will be the 
    // new head
    return previous;
  }
};