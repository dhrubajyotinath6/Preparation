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