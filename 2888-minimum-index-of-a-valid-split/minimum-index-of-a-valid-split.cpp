class Solution {
    private:
    int dominantElem(vector<int>&nums){
        int n = nums.size();
        int cnt = 0;
        int elem = -1;

        for(auto it:nums){
            if(cnt==0){
                elem = it;
                cnt = 1;
            }
            else if(elem==it){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        return elem;
    }

    vector<int>prefCnt(vector<int>&nums,int elem){
            int n = nums.size();
            vector<int>prefCnt(n+1,0);

            if(nums[0]==elem){
                prefCnt[0]=1;
            }

            for(int i=1;i<n;i++){
                prefCnt[i]=prefCnt[i-1];
                if(nums[i]==elem){
                    prefCnt[i]+=1;
                }
            }
            return prefCnt;
    }

public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int domiElem = dominantElem(nums);
        // cout<<"DomiElem : "<<domiElem<<endl;
        vector<int>pref = prefCnt(nums,domiElem);

        int ans = -1;

        for(int i=0;i<n-1;i++){
            int exLefCnt = ((i+1)/2) + 1;
            // cout<<"i : "<<i<<" exLefCnt : "<<exLefCnt<<endl;

            if(pref[i]>=exLefCnt){
                int rigExCnt = ((n-i-1)/2) +1;

                // cout<<"i : "<<i<<" rigExCnt : "<<rigExCnt<<endl;


                if(pref[n-1]-pref[i]>=rigExCnt){
                    return i;
                }
            }
        }
        return ans;
    }
};