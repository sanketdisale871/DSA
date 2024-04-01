class Solution {
    private:
    typedef long long int ll;
    
    ll globalInversions = 0;
    void merge(ll low,ll high,vector<int>&nums){
        ll mid = low+(high-low)/2;

        ll len1 = mid-low+1;
        ll len2 = high-mid;
        ll mainIndex = low;

        int *first = new int[len1];
        int *second = new int[len2];

        for(ll i=0;i<len1;i++){
            first[i]=nums[mainIndex++];
        }

        for(ll i=0;i<len2;i++){
            second[i]=nums[mainIndex++];
        }

        ll index1 = 0,index2=0;
        mainIndex = low;

        while(index1<len1 && index2<len2){
            if(first[index1]<=second[index2]){
                nums[mainIndex++]=first[index1++];
            }
            else{
                ll res = (len1-index1);
                globalInversions+=res;
                nums[mainIndex++]=second[index2++];
            }
        }

        while(index1<len1){
            nums[mainIndex++]=first[index1++];
        }

        while(index2<len2){
            nums[mainIndex++]=second[index2++];
        }
    }

    void mergeSort(ll low,ll high,vector<int>&nums){
        // base case
        if(low>=high){
            return ;
        }

        ll mid = low+(high-low)/2;

        mergeSort(low,mid,nums);
        mergeSort(mid+1,high,nums);


        merge(low,high,nums);
    }
public:
    /*Approach : 
    1) Find the Global Inversions
        - Merge Sort Technique to find Global Inversion
    2) Find the Local Inversion
    */

    bool isIdealPermutation(vector<int>& nums) {
        ll n = nums.size();

         ll lclInv = 0;

        for(ll i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                lclInv++;
            }
        }

        mergeSort(0,n-1,nums);

     

      cout<<" globalInversions"<<globalInversions<<" lclInv "<<lclInv<<endl;

        return globalInversions==lclInv;
    }
};