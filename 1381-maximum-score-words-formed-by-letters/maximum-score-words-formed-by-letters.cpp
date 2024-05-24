class Solution {
    private:
    typedef long long int ll;

    bool isPossibleToTake(vector<string>&wrds,ll ind,unordered_map<char,ll>um,ll &cr,vector<int>&score){

        for(auto it:wrds[ind]){
            if(um[it]==0){
                return false;
            }
            um[it]--;
            cr+=score[it-'a'];
        }

        return true;
    }
    ll findMaxiScore(ll ind,vector<string>&wrds,unordered_map<char,ll>um,vector<int>&score){
        // base case
        if(ind>=wrds.size()){
            return 0;
        }

        ll take = 0,nt=0;
        ll t = 0;
        if(isPossibleToTake(wrds,ind,um,t,score)){
            for(auto it:wrds[ind]){
                um[it]--;
            }

            take = t + findMaxiScore(ind+1,wrds,um,score);

            for(auto it:wrds[ind]){
                um[it]++;
            }
        }

        nt = findMaxiScore(ind+1,wrds,um,score);

        return max(take,nt);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,ll>um;

        for(auto it:letters){
            um[it]++;
        }

        return findMaxiScore(0,words,um,score);
    }
};