class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {

        if(right.size()==0){
            return *max_element(left.begin(),left.end());
        }
        
        if(left.size()==0){
            return n-*min_element(right.begin(),right.end());
        }



        int rightMax = *max_element(right.begin(),right.end());
        int rightMin = *min_element(right.begin(),right.end());

        int leftMax = *max_element(left.begin(),left.end());
        int leftMin =  *min_element(left.begin(),left.end());

       


        return max((n-rightMin),leftMax);
    }
};