class Solution {
public:
    int c,mx;
    unordered_set<int>vis;

    Solution(int m, int n) {
        c = n;
        mx = m*n;
    }
    
    vector<int> flip() {
        if(vis.size()==mx){ // all cells are visited
            return {};
        }

        int rNum = rand()%mx;

        while(vis.count(rNum)){
            rNum = (++rNum)%mx;
        }

        vis.insert(rNum);

        return {rNum/c,rNum%c};        
    }
    
    void reset() {
        vis = {};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */