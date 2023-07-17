//https://leetcode.com/problems/design-parking-system/discuss/876953/JavaC%2B%2BPython-3-Lines  

//https://leetcode.com/problems/design-parking-system/discuss/876915/Self-Explanatory-Code   -- imp

class ParkingSystem {

    int big, medium, small;
    
    public:
        ParkingSystem(int big, int medium, int small) {
        
            this->big = big;
            this->medium = medium;
            this->small = small;
        }
    
    public:
        bool addCar(int carType) {
        
            if(carType == 1 && big == 0 || carType == 2 && medium == 0 || carType == 3 && small == 0)
                return false;

            if(carType == 1) big--;
            if(carType == 2) medium--;
            if(carType == 3) small--;
        
        return true;
       }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */;

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */