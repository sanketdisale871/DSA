class Solution {
    private:
    bool isPossible(int canBeoptimalQueries,vector<int>& nums, vector<vector<int>>& queries){
         int numsSize = nums.size();
        int querySize = queries.size();


        vector<int>maxiRedu(numsSize+1,0);

        for(int queryItr=0;queryItr<canBeoptimalQueries;queryItr++){
            int l = queries[queryItr][0];
            int r = queries[queryItr][1];
            int val = queries[queryItr][2];

            maxiRedu[l]+=val;
            maxiRedu[r+1]-=val;
        }

        for(int itr=1;itr<=numsSize;itr++){
            maxiRedu[itr]+=maxiRedu[itr-1];
        }

        for(int travNumsArr = 0;travNumsArr<numsSize;travNumsArr++){
            if(nums[travNumsArr]>maxiRedu[travNumsArr]){
                return false;
            }
        }
        return true;
    }
public:
/*
Understanding:
a) 


Brute Force:
a) 
Trav Queries * Travesing Nums* Nums zero or the not => O(n3)

b) (queriesSize * k queries (maxi Minimize)) + nums => O(n2)

 k =   = FFFFFFTTTTTTTTTTTTTTTTTTTT

  queries = [[0,2,1],[0,2,1],[1,1,3]]

   maxred: 1  1  1
  index :  0  1  2



c) log(queriesSize)*k + O(size(nums)) => 


*/
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int numsSize = nums.size();
        int querySize = queries.size();

        int lowQueriesICanSelect = 0;
        int highQueriesICanSelect =querySize ;

        int miniQueriesToSelect = -1;

        while(lowQueriesICanSelect<=highQueriesICanSelect){
            int canBeoptimalQueries = lowQueriesICanSelect + (highQueriesICanSelect-lowQueriesICanSelect)/2;

            if(isPossible(canBeoptimalQueries,nums,queries)){
                miniQueriesToSelect = canBeoptimalQueries;
                highQueriesICanSelect = canBeoptimalQueries-1;
            }
            else{
                lowQueriesICanSelect = canBeoptimalQueries+1;
            }
        }
        return miniQueriesToSelect;
    }
};