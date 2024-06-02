class Solution {
public:
    typedef long long int ll;
    void reverseString(vector<char>& s) {
        ll low = 0;
        ll high = s.size()-1;

        while(low<high){
            swap(s[low],s[high]);
            low++;
            high--;
        }
        
    }
};