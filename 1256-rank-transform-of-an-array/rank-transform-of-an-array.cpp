class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        // [40,10,20,30] ==> [10,20,30,40] this are the elements we have
        // We have to sort it. 
        vector<int>ranks;

        unordered_map<int,int>um;
        vector<int>cpy(arr.begin(),arr.end());

        sort(cpy.begin(),cpy.end());


        for(auto it:cpy){
            if(um.find(it)==um.end()){
                um[it]=um.size()+1;
            }
        }

        for(auto it:arr){
            ranks.push_back(um[it]);
        }
        return ranks;
    }
};