class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int>st;


        for(auto num:arr){
            if(st.count(2*num) || (num%2==0 && st.count(num/2))){
                return true;
            }
            st.insert(num);
        }



        return false;
    }
};