class Solution {
    // DSA Student : Sanket Disale !
public:
/* Approach : T.C. : O(n*log(n) + n * k) */
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(),hand.end()); // it's necessary for -> hand = [2,1] groupSize = 2
        // O/p : True

        unordered_map<int,int>um;
        for(auto hd : hand){
            um[hd]++;
        }

        for(int i=0;i<hand.size();i++){
            int num = hand[i];

            if(um.find(num)==um.end()){
                continue;
            }

            int limit = 0;
            // vector<int>temp; // of we want to print the group then we will use it

            while((um.find(num)!=um.end()) and (limit<groupSize)){
                um[num]--;
                if(um[num]==0){
                    um.erase(num);
                }
                // temp.push_back(num);
                limit++;
                num++; // we want a cosecative number
            }

            if(limit != groupSize){
                return false;
            }
        }
        return true;
    }
};
