class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>avlWrds(wordList.begin(),wordList.end());

        queue<pair<int,string>>q;
        q.push({1,beginWord});

        while(!q.empty()){
            auto it = q.front();q.pop();
            int wrdsCnt = it.first;
            string currWrd  = it.second;


            if(currWrd==endWord){
                return wrdsCnt;
            }

            for(int i=0;i<currWrd.length();i++){
                char runChar = currWrd[i];

                for(char ch='a';ch<='z';ch++){
                    if(ch!=runChar){
                        currWrd[i]=ch;

                        if(avlWrds.count(currWrd)){
                            q.push({wrdsCnt+1,currWrd});
                            avlWrds.erase(currWrd);
                        }
                    }
                }
                currWrd[i]=runChar;
            }
        }

        // no sequence
        return 0;
    }
};