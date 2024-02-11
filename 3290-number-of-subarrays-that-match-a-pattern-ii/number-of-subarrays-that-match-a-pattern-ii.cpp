class Solution {
    private:
    vector<int> kmpAlgo(string str){
        int n = str.length();

        vector<int>lps(n,0);


        for(int i=1;i<n;i++){
            int prevInd = lps[i-1];

            while(prevInd>0 && str[i]!=str[prevInd]){
                prevInd = lps[prevInd-1];
            }

            lps[i]=prevInd + (str[i]==str[prevInd]?1:0);
        }
        return lps;
    }
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        string patt="";
        string str = "";

        for(auto it:pattern){
            if(it==1){
                patt.push_back('a'); // Ascending 
            }
            else if(it==0){
                patt.push_back('s'); // Same
            }
            else{
                patt.push_back('d'); // descending
            }
        }

        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                str.push_back('a'); // Ascending 
            }
            else if(nums[i]==nums[i-1]){
                 str.push_back('s'); // Same 
            }
            else{
                str.push_back('d'); // descending
            }
        }

        string res = patt+"#"+str;

        vector<int>lps = kmpAlgo(res);

        int ans = 0;

        for(int i=patt.length();i<lps.size();i++){
            if(lps[i]==patt.length()){
                ans++;
            }
        }
        return ans;
    }
};