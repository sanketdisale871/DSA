class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chnk = 0;

        int exSum = 0,acSum=0;

        for(int i=0;i<n;i++){
            acSum+=arr[i];
            exSum+=i;

            if(acSum==exSum){
                chnk++;
            }
        }
        return chnk;
    }
};