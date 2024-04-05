class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& o) {
        vector<vector<string>> ans;

        map<int,map<string,int>>um;
        set<string>foods;


        for(auto it:o){
           string tb = it[1];
           string fd = it[2];

           um[stoi(tb)][fd]+=1;
           if(foods.count(fd)==0){
                foods.insert(fd);
           }           
        }

        vector<string>str;
        str.push_back("Table");
        for(auto it:foods){
            str.push_back(it);
        }

        ans.push_back(str);

        for(auto it:um){
            vector<string>t;
            t.push_back(to_string(it.first));
            for(auto itt:foods){
                t.push_back(to_string(um[it.first][itt]));
            }
            ans.push_back(t);
        }
        return ans;
    }
};