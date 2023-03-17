class Solution {
    // DSA Student : Sanket Disale !
public:
    int atMost(vector<int>&arr,int goal){
        if(goal <0){
            return 0;
        }
        int i=0,j=0;
        int n = arr.size();
        int ans = 0,sum = 0;

        while(j<n){
            // Calculation wala part
            sum+=arr[j];

            if(sum<=goal){
                ans+=(j-i+1);
                j++;
            }
            else if(sum>goal){
                while(sum>goal){
                    sum-=arr[i];
                    i++;
                }
                ans+=(j-i+1);
                j++;
            }
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
      /* Hash Map Approach */
      
        //     int n = nums.size();
        //     unordered_map<int,int>um;
        //    um[0]=1;
        //     int ans = 0;
        //     int sum = 0;
        //     for(int i=0;i<n;i++){
        //         sum+=nums[i];
               
                
        //         if(um.find(sum-goal)!=um.end()){
        //             ans+=um[sum-goal];
        //         }

        //          um[sum]++;

        //     }
        //     return ans;

      
        /* Sliding Window Approach : 
          Approach : number of subaarays produce sum exactly 'goal' = 
            sum of subarrays window size which produce sum at most 'goal' - sum of subarrays window size which produce sum at most 'goal-1'
        */
        return atMost(nums,goal)-atMost(nums,goal-1);
    }
};
