class Solution {
    private:
    void hepify(vector<int>&nums,int n,int i){
        int larg = i;
        int lef = 2*i+1;
        int righ = 2*i+2;

        if(lef<n && nums[lef]>nums[larg]){
            larg = lef;
        }

        if(righ<n && nums[righ]>nums[larg]){
            larg = righ;
        }

        if(larg!=i){
            swap(nums[i],nums[larg]);
            hepify(nums,n,larg);
        }
    }

    void buildHeap(vector<int>&nums){
        int n = nums.size();

        for(int i=n/2;i>=0;i--){
            hepify(nums,n,i);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        buildHeap(nums);

        int t = nums.size()-1;

        // for(auto it:nums){
        //     cout<<it<<" ";
        // }

        while(t>=0){
            // cout<<"Nums : at /first and end"<<nums[0]<<" "<<nums[t]<<endl;

            swap(nums[0],nums[t]);
            t--;
            hepify(nums,t+1,0);
        }
        return nums;
    }
};