class MedianFinder {
public:
    priority_queue<int>maxHeap; // leftPart elements 
    priority_queue<int,vector<int>,greater<int>>minHeap; // rightPart elements
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top()>num){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }

        if(maxHeap.size()>minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size()>maxHeap.size()+1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size()){
            double avg = (maxHeap.top()+minHeap.top())/2.00;
            return avg;
        }
        else{
            return maxHeap.size()>minHeap.size()?maxHeap.top():minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */