class Twitter {
    // unordered_map<userId,vector<{time,tweetId};
    unordered_map<int,vector<pair<int,int>>>t;
    // map<followerId,set<followesId>>
    unordered_map<int,set<int>>fo;
    long long time;

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        t[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // getting latest tweets
        priority_queue<pair<int,int>>maxHeap;
        // getting tweet post of userId
        for(auto it=t[userId].begin();it!=t[userId].end();it++){
            maxHeap.push(*it);
        }
        // Getting tweet post of it's followers
        for(auto  it1=fo[userId].begin();it1!=fo[userId].end();it1++){
            int user = *it1;

            for(auto it2=t[user].begin();it2!=t[user].end();it2++){
                maxHeap.push(*it2);
            }
        }

        vector<int>res;

        while(!maxHeap.empty()){
            res.push_back(maxHeap.top().second);

            if(res.size()==10){
                break;
            }
            maxHeap.pop();
        }
        return res;        
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            fo[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        fo[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
