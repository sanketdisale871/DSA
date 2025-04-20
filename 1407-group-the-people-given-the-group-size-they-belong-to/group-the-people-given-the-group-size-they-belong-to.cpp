class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // How Can i re
        unordered_map<int,vector<int>>um;

        
        for(int i=0;i<groupSizes.size();i++){
            um[groupSizes[i]].push_back(i);
        }
        cout<<um.size()<<endl;
        vector<vector<int>>ans;

        for(auto it:um){
            vector<int>temp;
           
                for(auto itt:it.second){
                    if(temp.size()<it.first){
                        temp.push_back(itt);
                    }
                    else{
                        ans.push_back(temp);
                        temp.clear();
                        temp.push_back(itt);
                    }
                }

                if(temp.size()){
                    ans.push_back(temp);
                }

            
        }


        return ans;       
    }
};