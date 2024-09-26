class MyCalendar {
public:
    vector<pair<int,int>>intervals;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
       
       for(auto it:intervals){
            if(start<it.second && end>it.first){
                return false;
            }
       }
       intervals.push_back({start,end});
       return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */