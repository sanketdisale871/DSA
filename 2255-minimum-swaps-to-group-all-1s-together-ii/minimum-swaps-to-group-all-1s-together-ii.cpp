class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int comp = 0;
        int prev = -1;
        int i=0;
        for(;i<n;i++){
            // 
            if(nums[i]==1){
                comp++;
            }
            nums.push_back(nums[i]);
        }               

        cout<<"Com : "<<comp<<endl;
         n = nums.size();

        vector<int>prefZeroes(n,0);
        int ans  =INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                prefZeroes[i]=1;
                if(i>0){
                    prefZeroes[i]+=prefZeroes[i-1];
                }
            }
            else if(i>0){
                prefZeroes[i]=prefZeroes[i-1];
            }
            // cout<<"Zeros : "<<prefZeroes[i]<<endl;
            int t = i-comp+1;
            // cout<<"t : "<<t<<" i : "<<i<<" "<<endl;
            if(t>=0){
                int z = prefZeroes[i];
                if(t>0){
                    z-=prefZeroes[t-1];
                }
                // cout<<"z : "<<z<<endl;


                ans = min(ans,z);
            }
           
        }

        return ans;

        return 0;

    }
};