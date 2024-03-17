class Solution {

    /*
    Understanding:

    1) In query [index,k], i have to mark the index and k smallest unmarked numbers
        that i have to mark.
    2) I have to give the sum of unmarked numbers after the query.    
    */
public:
    typedef long long int ll;
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        ll n = nums.size();
        ll totSum = 0;
        
        for(auto it:nums){
            totSum=(totSum*1ll)+it;
        }
        
        vector<ll>ans;
        
        vector<ll>marked(n+1,0);
        
        // pair<elem,ind>
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>minHeap;
        
        for(ll i=0;i<nums.size();i++){
            minHeap.push({nums[i],i});
        }
            
        
        bool flagBreak = false;
        
        for(auto it:queries){
            ll mrkInd = it[0];
                        
            if(marked[mrkInd]==0){
                marked[mrkInd]=1;
                totSum=(totSum) - nums[mrkInd];
            }
            
            
            
            ll k = it[1];
            
            
            while(k>0 && !minHeap.empty()){
                auto itt = minHeap.top();minHeap.pop();
                ll id = itt.second;

                
                 if(marked[id]==0){
                    marked[id]=1;
                    totSum=(totSum) - nums[id];
                     k--;
                }   
            }            
            
            if(k>0){
                flagBreak = true;
                break;
            }            
            ans.push_back(totSum);
        }
        
        
        if(flagBreak){
            while(ans.size()<queries.size()){
                ll t= 0;
                ans.push_back(t);
            }
        }        

        return ans;        
    }
};