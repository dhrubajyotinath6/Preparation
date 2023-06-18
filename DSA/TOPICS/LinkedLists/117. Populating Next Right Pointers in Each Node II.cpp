/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
the solution which one in grooking doesnot hv SC - 0(1)
*/

class Solution {
    Node *prev, *leftmost;
    
public:
    void processChild(Node* childNode){
        
        if(childNode != NULL){
            
            if(this->prev != NULL){
                this->prev->next = childNode;
            }else{
                this->leftmost = childNode;
            }
            
         this->prev = childNode;
        }        
        
    }
public:
    Node* connect(Node* root) {
        
        if(!root) return NULL;
        
        this->leftmost = root;
        
        Node *curr = leftmost;
        
        while(this->leftmost != NULL){
            
            this->prev = NULL;
            curr = this->leftmost;
            this->leftmost = NULL;
            
            while(curr != NULL){
                processChild(curr->left);
                processChild(curr->right);
                
                curr = curr->next;
            }
        }
        return root;
    }
};