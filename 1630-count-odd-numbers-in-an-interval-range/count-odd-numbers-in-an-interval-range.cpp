class Solution {
public:
    int countOdds(int low, int high) {
        // count of odd numbers 
        // 1 - 5 ,, 1,3,5
        // 5/2 (st and ed)
        // 1-3
        // 3/2 ==> 2 
        // 1 - 8 

// 1e8>= ==> ,,,


        int oddCnt = 0;

        for(int i=low;i<=high;i++){
            if(i%2!=0){
                oddCnt++;
            }
        }
        return oddCnt;

    }
};