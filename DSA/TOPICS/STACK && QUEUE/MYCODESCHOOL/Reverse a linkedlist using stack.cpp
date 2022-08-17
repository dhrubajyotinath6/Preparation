/*
THERE ARE 2 OTHER WAYS ALSO TO REVERSE A LINKED LIST IF WE NOT USE STACK

    (A) ITERATIVE WAY
        TC -> O(N)
        SC -> O(1)

    (B) RECURSIVE WAY
        TC -> O(N)
        SC -> O(N)
*/

// (C) USING STACK

void Reverse(){

    if (head == NULL) return;      //  here TC -> O(2N) = O(N)APPROX [SINCE WE ARE TRANSVERSING THE LINKED TWO TIMES
                                   //                                  ONE TIME FOR PUTTING THEM INTO STACK
    stack<struct Node*> S;         //                                  ANOTHER TIME WHILE POPPING THEM OUT FROM THE STACK]
    Node* temp = head;             //       SC -> O(N)  [FOR STACK]

    while(temp != NULL){
        S.push(temp);
        temp = temp->next;
    }

    temp = S.top();
    head = temp;

    while(!S.empty()){
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}