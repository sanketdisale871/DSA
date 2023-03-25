class Solution {
    // DSA Student : Sanket Disale
public:
/*Approach : Heap Approach
-1 is multiplied here because we have to get least frequency element first, so declared maxHeap will behave as minHeap and we get least frequency element first.

Now, the question is, i should have just used minHeap ?

The answer to this question is : if the frequency is same, then i need elements in decreasing order, that's where maxHeap come into play, so a maxHeap is declared.
Long answer short : -1 is multiplied to convert maxHeap to minHeap.
*/
    // vector<int> frequencySort(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int>ans;
    //     unordered_map<int,int>um;
    //     priority_queue<pair<int,int>>maxHeap;

    //     for(int i=0;i<n;i++){
    //         um[nums[i]]++;
    //     }

    //     for(auto it : um){
    //         int num = it.first;
    //         int freq = it.second;

    //         maxHeap.push({-(freq),num});
    //     }

    //     while(!maxHeap.empty()){
    //         int freq = -(maxHeap.top().first);
    //         int elem = maxHeap.top().second;

    //         while(freq--){
    //             ans.push_back(elem);
    //         }
    //         maxHeap.pop();
    //     }

    //     return ans;
    // }

    // Approach : Comparator Function
    vector<int> frequencySort(vector<int>& nums){
            unordered_map<int,int>um;

            for(auto num : nums){
                um[num]++;
            }

            sort(nums.begin(),nums.end(),[&](int a,int b){
                if(um[a]!=um[b]){
                    return um[a]<um[b];
                }
                else{
                    return a>b;
                }
            });
            return nums;
    }
};
