class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>um(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});

        if(um.count(beginWord)){
            um.erase(beginWord);
        }


        while(!q.empty()){
            auto it = q.front();q.pop();
            string wrd = it.first;int t = it.second;

            if(wrd == endWord){
                return t;
            }

            for(int i=0;i<wrd.length();i++){
                char ch = wrd[i];

                for(char chh = 'a';chh<='z';chh++){
                    wrd[i] = chh;

                    if(um.count(wrd)){
                        q.push({wrd,t+1});
                        um.erase(wrd);
                    }
                }
                wrd[i]=ch;
            }
        }

        return 0;
    }
};