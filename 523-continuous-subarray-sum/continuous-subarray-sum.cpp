class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // map<pre,ind>um
        unordered_map<int,int>um;

        um[0]=-1; // nums =[23,2,4,6,6]  k = 7 ==> [23,2,4,6,6]
        //  pr[i] + k =>pr[j]
        // [ x ,x ,x ,x ,x ,x]
        // pr[j] = pr[i] + k ,, Take mod both side
        // pr[j]%k = pr[i]%k + k%k
        // pr[j]%k = pr[i]%k
        // pr[i]%k = pr[j]%k

        int preSum = 0;

        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];

            if(um.find(preSum%k)!=um.end()){
                if(i-um[preSum%k] > 1){
                    return true;
                }
            }
            else{
                um[preSum%k]=i;
            }
        }
        return false;
    }
};