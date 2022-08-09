
There are two approaches for this problem: 

a)We have taken two stacks(s1 && s2)    

       |        |           |       |            TC -> O(N);      
       |        |           |       |            SC -> O(2N);
       |        |           |       |
       |________|           |_______|
            s1                  s2

push(x)
    s1 -> s2 (element by element)
    x -> s1 (Add x to s1)
    s2 -> s1 (element by element)

pop(x)
   s1.pop();

  FOR DRY RUN:
        push(4);
        push(3);
        push(2);
        push(5);
        top();
        pop();
        top();


b)In the 2nd approach too we have taken two stacks(Input && Output)

       |        |           |       |           TC -> O(1) (FOR PUSH OPERATIONS)      
       |        |           |       |                 O(1)  (AMORTISED TC) BCOZ BOTH POP AND TOP OPEARTIONS 
       |        |           |       |                       ARE TAKING O(1) COMPLEXITY BUT IN SOME INSTANCES THEY ARE
       |________|           |_______|                       TAKING O(N) COMPLEXITY
       Input                 Output
                                                SC -> O(2N)
        push(x)                                     
        Add x -> Input

        pop()
        if(Output not empty)
            Output.pop();
        else
            Input -> Output (element by element)
            Output.pop();

        top()
        if(Output not empty)
            Output.top();
        else
            Input -> Output (element by element)
            Output.top();

FOR DRY RUN:
    push(2);   ---> O(1)
    push(5);   ---> O(1)
    push(3);   ---> O(1)
    top();     ---> O(N)    // 2
    pop();     ---> O(1)    
    push(6);   ---> O(1)
    pop();     ---> O(1)
    pop();     ---> O(1)
    top();     ---> O(N)    // 6

PSEUDOCODE:
    push(x){
        Input.push(x);
    }

    pop(){
        if(Output.empty() == false) Output.pop();
        else{
            while(Input.empty() == false){
                Output.push(Input.top());
                Input.pop();
            }
            Output.pop();
        }
    }
        
    top(){
        if(Output.empty() == false) Output.top();
        else{
            while(Input.empty() == false){
                Output.push(Input.top());
                Input.pop();
            }
            Output.top();
        }
    }  
 
CODE: 
class MyQueue {
public:
    stack<int> input, output;

    // Initialize your data structure here. 
    MyQueue() {
        
    }
    
    // Push element x to the back of queue.
    void push(int x) {
        input.push(x);
    }
    
    // Removes the element from in front of queue and returns that element. 
    int pop() {

        // shift input to output 
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();

        int x = output.top();
        output.pop(); 
        return x; 
    }
    
    // Get the front element. 
    int top() {
        // shift input to output 
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();

        return output.top(); 
    }
    
    // Returns whether the queue is empty. 
    bool empty() {
        return input.empty() && output.empty();  // if both are empty then only we can say it is empty
    }

};