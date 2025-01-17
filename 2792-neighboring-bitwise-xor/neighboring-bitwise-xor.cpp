class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans = 0;

        for(auto it:derived){
            ans^=it;
        }

        return ans<=0;
    }
};