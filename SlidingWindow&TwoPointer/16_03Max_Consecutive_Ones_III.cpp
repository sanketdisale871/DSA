class Solution {
public:
    int longestOnes(vector<int>& arr, int k){
        int maxiOnes = 0;
        int i =0,j=0;
        int n = arr.size();

        int flippedZeroes = 0;

        while(j<n){
            // calculation wala part
            if(arr[j]==0){
                flippedZeroes++;
            }

            // case disscussing
            // if(flippedZeroes<k){
            //     j++;
            // }
            if(flippedZeroes<=k){
                maxiOnes = max(maxiOnes,j-i+1);
                j++;
            }
            else if(flippedZeroes>k){
                while(flippedZeroes>k){
                    if(arr[i]==0){
                        flippedZeroes--;
                    }
                    i++;
                }
                j++;
            }
        }
        return maxiOnes;
    }
};
