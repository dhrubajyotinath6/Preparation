//https://leetcode.com/problems/moving-average-from-data-stream/discuss/81557/What-if-the-size-is-too-big-to-hold-in-memory-How-to-handle

//https://leetcode.com/problems/moving-average-from-data-stream/discuss/81587/C++-easy-solution-using-queue/239392

class MovingAverage {
    
private:
    queue<int> queue;
    int size, sum = 0;
public:
    MovingAverage(int size) {
        this -> size = size;
     }
    
    double next(int val) {
        
        sum += val;
        queue.push(val);
        
        if(queue.size() > size){
            sum -= queue.front();
            queue.pop();
        }
        
        return (1.0*sum)/queue.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */