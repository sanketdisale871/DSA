class Solution {
    /*
    
    understanding : 
    // What is the size of array? Which will contain negative nums
    // What is the range of elements in the array 
    // 
    // Approch: 
    - Two loops: 
     First loop => First Element 
     Second loop => Second element 
     // maxi Diff 

     T.C : O(n2), S.C: O(1)


     2nd Approach:
     mini =    
     diff = arr[i]-mini;
     maxiDiff = max(maxiDiff,diff);
    T.C : O(sizeOfArray)
    S.C : O(1)
    */
public:
    int maximumDifference(vector<int>& nums) {
        int sizeOfArray = nums.size();
        int maxiDiff = -1;
        int miniNum = nums[0];

        for(int itr=1;itr<sizeOfArray;itr++){
            if(nums[itr]!=miniNum){
            int currDiff = nums[itr]-miniNum;

            maxiDiff = max(maxiDiff,currDiff);
            }

            miniNum = min(miniNum,nums[itr]);
        }
        return maxiDiff;
    }
};