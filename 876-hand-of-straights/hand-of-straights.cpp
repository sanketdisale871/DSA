class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n%groupSize != 0){
            return false;
        }


        // Now there is possibilty, that i can arrange in Concecative order 

       map<int,int>um;
       priority_queue<int,vector<int>,greater<int>>minHeap;

       for(auto it:hand){
            um[it]++;
            minHeap.push(it);
       }


        while(!minHeap.empty()){
            int numm = minHeap.top();  minHeap.pop();
            if(um[numm]<=0){
                continue;
            }
            vector<int>temp;
            temp.push_back(numm);
            um[numm]--;
          

            while(temp.size()<groupSize && um[numm+1]>0){
                numm++;
                um[numm]--;
              
                temp.push_back(numm);
            }

            if(temp.size()<groupSize){
                return false;
            }
        }
      
       
               
        return true;
    }
};