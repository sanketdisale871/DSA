class DataStream {
public:
typedef long long int ll;

    int val,lst;
    ll consCnt = 0;

    DataStream(int value, int k) {
        this->val = value;
        this->lst = k;
    }
    
    bool consec(int num) {
 
        if(num == val){
            consCnt++;
        }
        else{
            consCnt=0;
        }

        if(consCnt>=lst){
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