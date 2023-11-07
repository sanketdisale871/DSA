class Solution {
public:
typedef long long int ll;

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(),nums.end());

        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                
                int l = j+1,h = n-1;

                while(l<h){
                    ll sum = nums[i]*1ll+nums[j]*1ll+nums[l]*1ll+nums[h]*1ll;

                    if(sum == target){
                        ans.push_back({nums[i],nums[j],nums[l],nums[h]});

                        while(l<h && nums[l]==nums[l+1]){
                            l++;
                        }
                        while(l<h && nums[h]==nums[h-1]){
                            h--;
                        }
                        l++;
                        h--;
                    }
                    else if(sum<target){
                        l++;
                    }
                    else{
                        h--;
                    }
                }
                while(j<n-2 && nums[j]==nums[j+1]){
                    j++;
                }
            }
              while(i<n-3 && nums[i]==nums[i+1]){
                    i++;
            }
        }
        return ans;
    }
};