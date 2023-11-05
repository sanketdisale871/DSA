class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();

        if(k>=n){
            return *max_element(arr.begin(),arr.end());
        }

        int currWin = arr[0];
        int conse = 0;

        for(int i=1;i<n;i++){
            if(arr[i]>currWin){
                currWin = arr[i];
                conse = 1;
            }
            else{
                conse++;
            }

            if(conse==k){
                return currWin;
            }
        }

        return currWin;
    }
};