//https://leetcode.com/problems/stock-price-fluctuation/discuss/1513413/JavaC%2B%2BPython-Strightforward-Solutions
/*
Do you know what the difference is between *begin(prices) and *prices.begin()? 
They both work but as far as I know with C++ 
there's always some intricate goofy shit going on under the hood

begin(prices) is recommended as it works for both vector and C-style arrays.
*/

class StockPrice {
    
    map<int,int> rec;
    multiset<int> count;
    
public:
    StockPrice() {
        
        
    }
    
    void update(int timestamp, int price) {
        
        if(rec.find(timestamp) != rec.end()){
            count.erase(count.find(rec[timestamp]));
        }
        
        rec[timestamp] = price;
        count.insert(price);
    }
    
    int current() {
        
        return rec.rbegin()->second;
    }
    
    int maximum() {
        return *count.rbegin();
    }
    
    int minimum() {
        return *count.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */