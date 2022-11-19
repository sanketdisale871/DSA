class BrowserHistory {
public:
    // making doubly ll
    list<string>history;
    // making iteration 
   list<string> :: iterator it;
    
    
    BrowserHistory(string homepage) {
        
        history.push_back(homepage);
        it = history.begin(); // iterator pointing start page of history
        
    }
    
    void visit(string url) {
        
        // iterator ke aage ke pages delete kar do
        auto del = it;
        del++;
        
        history.erase(del,history.end());
        
        history.push_back(url);
        it++;
        
    }
    
    string back(int steps) {
        
        while(it!=history.begin() && steps--){
            it--;
        }
        return *it;
        
    }
    
    string forward(int steps) {
        
        while((it!=--history.end()) && steps--){
            it++;
        }
        
        return *it;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
