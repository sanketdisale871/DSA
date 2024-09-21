class Solution {
public:
    vector<int> lexicalOrder(int n) {
         if(n==0) return {};
        vector<int> result;
        int current=1;
        for(int i=0;i<n;i++){
            result.push_back(current);
            current*=10; 
            while(current>n){ 
                current/=10; 
                current++;
                while(current%10==0) current/=10;
            }
        }
        return result;
    }
};