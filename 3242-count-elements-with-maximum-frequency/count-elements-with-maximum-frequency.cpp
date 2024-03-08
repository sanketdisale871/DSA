class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // 
        unordered_map<int,int>freqMap; // Freqency of each element 
        int maxiFreq = 0;

        for(auto number:nums){
            freqMap[number]++;
            maxiFreq = max(maxiFreq,freqMap[number]);
        }

        int totalFreq = 0;

        for(auto it:freqMap){
            if(it.second == maxiFreq){
                totalFreq+=maxiFreq;
            }
        }   

        return totalFreq;
    }
};