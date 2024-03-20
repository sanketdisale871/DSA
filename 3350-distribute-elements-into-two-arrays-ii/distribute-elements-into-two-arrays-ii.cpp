#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int,int>,null_type,greater<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> pbds;

class Solution {
    public:
    typedef long long int ll;

vector<int> resultArray(vector<int>& nums) {
    vector<ll> arr1;
    vector<ll> arr2;
    
    pbds st1;
    pbds st2;
    
    arr1.push_back(nums[0]);
    st1.insert({nums[0],0});
    arr2.push_back(nums[1]);
    st2.insert({nums[1],1});
    
    // Preprocess counts
    int cnt1=1;
    int cnt2=1;

    for (int i = 2; i < nums.size(); i++) {
        // cnt1 = greaterCount(st1, nums[i]);
        cnt1 = st1.order_of_key({nums[i],i});
        // cout<<"Nums[i] "<<nums[i]<<" cnt1 : "<<cnt1<<endl;
        // cnt2 = greaterCount(st2, nums[i]);
        cnt2 = st2.order_of_key({nums[i],i});
        // cout<<"Nums[i] "<<nums[i]<<" cnt2 : "<<cnt2<<endl;

        if (cnt1 > cnt2) {
            arr1.push_back(nums[i]);
            st1.insert({nums[i],i});
        } else if (cnt1 < cnt2) {
            arr2.push_back(nums[i]);
            st2.insert({nums[i],i});
        } else if (cnt1 == cnt2 && arr1.size() > arr2.size()) {
            arr2.push_back(nums[i]);
            st2.insert({nums[i],i});
        } else {
            arr1.push_back(nums[i]);
            st1.insert({nums[i],i});
        }
    }
    
    // concatenate arrays
    vector<int> ans;
    for (auto it : arr1){
        ans.push_back(static_cast<int>(it));
    }

    // cout<<"2nd Array : "<<endl;
    for (auto it : arr2){
        ans.push_back(static_cast<int>(it));
    }
    
    return ans;
}
};