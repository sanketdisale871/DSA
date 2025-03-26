class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
     /*
     2
     5
     6
     8

     This will be never ,, Ye to sahi hai, ki If remainder is NOT zero, then difficult to make all equal

    // This also I want bhai, ki aise aise hona chahiye,,, 
     x = 2

     I can Add/Remove the X in the List,, 

     */   
        int m = grid.size();
        int n = grid[0].size();

        vector<int>nums;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(),nums.end()); 
        // 2 4 6 8 9 => 5/2 -1, 2

        n = nums.size();
        int middElem = -1;

        if(n%2==0){
             middElem = nums[(n/2) -1];
            
        }
        else{
            middElem = nums[n/2];
        }

        int oper = 0;

        for(int i=0;i<nums.size();i++){
            int diff = abs(nums[i]-middElem);

            if(diff%x!=0){
                return -1;
            }
            oper+=(diff/x);
        }
        return oper;


    }
};