class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int lastMoment = 0;

        for(auto l : left){
            lastMoment=max(lastMoment,l);
        }

        for(auto r : right){
            lastMoment = max(lastMoment,n-r);
        }

        return lastMoment;
    }
};