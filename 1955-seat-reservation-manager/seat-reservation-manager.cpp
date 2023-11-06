class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>>minHeap;
    int cnt = 1;
    SeatManager(int n) {
        minHeap.push(cnt);
    }
    
    int reserve() {
        int resSeat = minHeap.top();minHeap.pop();
        cnt++;

        minHeap.push(cnt);

        return resSeat;
    }
    
    void unreserve(int seatNumber) {
        minHeap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */