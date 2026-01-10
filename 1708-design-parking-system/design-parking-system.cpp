class ParkingSystem {
public:
   
    vector<int>stCnt;

    ParkingSystem(int big, int medium, int small) {
        stCnt.resize(4);
        stCnt[1]=big;
        stCnt[2]=medium;
        stCnt[3]=small;
    }
    
    bool addCar(int carType) {
        if(stCnt[carType]==0){
            return false;
        }
        stCnt[carType]--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */