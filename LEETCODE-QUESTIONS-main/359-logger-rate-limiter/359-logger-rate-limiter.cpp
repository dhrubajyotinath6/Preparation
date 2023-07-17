class Logger {
    
    unordered_map<string, int> msg;
    
public:
    Logger() {
         
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        
        if(msg.find(message) == msg.end()){
            msg[message] = timestamp;
            return true;
        }
        
        int oldTimeStamp = msg[message];
        
        if(timestamp - oldTimeStamp >= 10){
            msg[message] = timestamp;
            return true;
        }else{
            return false;
        }
        
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */