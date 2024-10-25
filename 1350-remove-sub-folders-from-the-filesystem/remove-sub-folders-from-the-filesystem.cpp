class Solution {
public:
    typedef long long int ll;
    vector<string> removeSubfolders(vector<string>& fold) {
        unordered_map<string,int>um;

        sort(fold.begin(),fold.end());

        vector<string>ans;
        
        for(auto it:fold){
            string str = "";
            bool isFind = true;
            for(ll i=0;i<it.length();i++){
           
                str.push_back(it[i]);
                

                if(um.find(str)!=um.end()){
                    if(i!=it.length()-1 && it[i+1]!='/'){
                        continue;
                    }
                    isFind = false;
                    //  cout<<" I : "<<it<<" str : "<<str<<endl;
                    break;
                }
            }

            if(isFind){
                um[str]++;
                // cout<<"it : "<<it<<" Stro : "<<str<<endl;
            }
        }

        // cout<<um.size()<<endl;

        for(auto it:um){
            string str = it.first;
           
            ans.push_back(str);
        }

        return ans;
    }
};