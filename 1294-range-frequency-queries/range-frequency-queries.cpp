class RangeFreqQuery {
public:
    unordered_map<int,vector<int>>um;
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            um[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if(um.find(value)==um.end()){
            return 0;
        }

        vector<int>&curr = um[value];

        int rMInd = upper_bound(curr.begin(),curr.end(),right) - curr.begin();
        int lMInd = lower_bound(curr.begin(),curr.end(),left)-curr.begin();

        return rMInd-lMInd;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */