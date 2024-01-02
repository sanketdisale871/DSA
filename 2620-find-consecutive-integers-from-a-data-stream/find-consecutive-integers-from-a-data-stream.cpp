class DataStream {
public:
    int val;
    int cnt = 0;
    int streak;
    DataStream(int value, int k) {
        val = value;
        streak = k;
    }
    
    bool consec(int num) {
        if(num== val){
            cnt++;
        }
        else{
            cnt=0;
        }

        if(cnt>=streak){
            return true;
        }

        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */