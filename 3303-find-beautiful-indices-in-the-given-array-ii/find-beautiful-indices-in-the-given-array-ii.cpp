class Solution {
    private:

    vector<int>kmpAlgo(string str){
        int n = str.length();

        vector<int>lps(n,0);

        for(int i=1;i<n;i++){
            int prevInd = lps[i-1];

            while(prevInd>0 && str[i]!=str[prevInd]){
                prevInd = lps[prevInd-1];
            }

            lps[i]=prevInd + (str[i]==str[prevInd] ?1 : 0);
        }
        return lps;
    }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        string str1 = a+"#"+s;
        string str2 = b+"#"+s;

        vector<int>lps1 = kmpAlgo(str1);
        vector<int>lps2 = kmpAlgo(str2);

        vector<int>aPos;
        vector<int>bPos;

        for(int i=a.length();i<lps1.size();i++){
            if(lps1[i]==a.length()){
                aPos.push_back(i-a.length()-a.length());
            }
        }

        for(int i=b.length();i<lps2.size();i++){
            if(lps2[i]==b.length()){
                bPos.push_back(i-b.length()-b.length());
            }
        }

        vector<int>ans;

        for(int itr1=0;itr1<aPos.size();itr1++){

            auto it = lower_bound(bPos.begin(),bPos.end(),aPos[itr1]);

            bool flag = true;
            if(it!=bPos.end()){

                int res = abs(aPos[itr1]-*it);

                if(res<=k){
                    ans.push_back(aPos[itr1]);
                    flag = false;
                }
            }

            if(it!=bPos.begin() && flag){
                it--;
                int res = abs(aPos[itr1]-*it);

                if(res<=k){
                    ans.push_back(aPos[itr1]);
                    flag = false;
                }
            }
        }
        return ans;
    }
};