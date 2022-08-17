/*
https://leetcode.com/problems/implement-stack-using-queues/


There are two approaches 
     a)Using two queues
     b)Using one queue


    a)Using two queues
       |        |           |       |           
       |        |           |       |
       |        |           |       |
       |________|           |_______|
        Q1                     Q2

            push(3);                         
            push(4);
            push(2);
            push(1);
            top();
            pop();
            top();

            ---------------STEPS------------
            push(x)
                    1) Add x -> Q2
                    2) Q1 -> Q2  (Element by element)
                    3) swap(Q1, Q2)

            pop(x)
                    1) Remove the top of Q1

PSEUDOCODE:
        push(x){
            Q2.push(x);

            while(!Q1.empty()){
                Q2.push(Q1.front());
                Q1.pop();
            }
             swap(Q1, Q2);             
        }

        pop(x){
            Q1.pop();
        }
        
        top(){
            return Q1.front();
        }

*/

// b)Using one queue

class MyStack{

public:

    queue<int> queue;

    //Initialize  data structure here
    MyStack(){

    }

    //Push element x onto stack
    void push(int x){
        queue.push(x);

        for(int i = 0; i < queue.size(); i++){
            queue.push(queue.front());
            queue.pop();
        }
    }

    int pop(){

        int x = queue.front();
        queue.pop();
        return x;
    }

    int top(){
        return queue.front();
    }

    bool empty() {
        return que.size() == 0; 
    }
}