class Solution {
public:
    int countOdds(int low, int high) {
        // count of odd numbers 
        // 1 - 5 ,, 1,3,5    ceil(bich/2)
        // 5/2 (st and ed) ,, 
        // 1-3
        // 3/2 ==> 2 
        // 1 - 8 

// 1e8>= ==> ,,,
// 8-10 ==> 
// 3/2 ==> 2, when st & ed ==> even = floor(bich/2)


// 3 - 8
// 6/2 ==> 
// 1-6
// 7/2 ==> floor(3
// 5 - 10
// 6/2 ==> 3


// 2-7
// 6/2
// 2-9
// 7/2 ==> ceil(3)

    int oddCnt = 0;

    int diff = high-low+1;
    if(low%2!=0 && high%2!=0){
        oddCnt= (int) ceil(diff*1.0/2);
    }
    else if(low%2==0 && high%2==0){
         oddCnt= diff/2;
    }
    else if(low%2==0 && high%2!=0){
        oddCnt= (int) ceil(diff*1.0/2);
    }
    else{
        oddCnt= diff/2;
    }

    return oddCnt;


      
    }
};