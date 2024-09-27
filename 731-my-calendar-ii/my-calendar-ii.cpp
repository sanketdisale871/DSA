class MyCalendarTwo {
public:
    // vector<pair<int,int>>inter;
    map<int,int>um;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        int cnt = 0;
        um[start]++;
        um[end]--;

        for(auto it:um){
            cnt+=it.second;

            if(cnt==3){
                um[start]--;
                um[end]++;
                return false;
            }
        }

        // inter.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */