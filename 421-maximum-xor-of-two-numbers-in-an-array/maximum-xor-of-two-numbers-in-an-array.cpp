class Node{
    public:
    Node* links[2];

    Node(){
        for(int i=0;i<2;i++){
            links[i]=nullptr;
        }
    }

    bool containsKey(int bit){
        return links[bit]!=nullptr;
    }

    void putKey(int bit){
        links[bit]=new Node();
    }

    Node* getKey(int bit){
        return links[bit];
    }
};

class Trie{
    public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insertNum(int num){
        Node* trav = root;

        for(int i=31;i>=0;i--){
            int isBitSet = (num >> i) & 1;

            if(!(trav->containsKey(isBitSet))){
                trav->putKey(isBitSet);
            }
            trav = trav->getKey(isBitSet);
        }
    }

    int maxXorFind(int num){
        int ans = 0;

        Node* trav = root;

        for(int i=31;i>=0;i--){
          int isBitSet = (num >> i) & 1;

            if(trav->containsKey(1-isBitSet)){
               ans = ans | (1<<i);
               trav = trav->getKey(1-isBitSet);
            }
            else{
                trav = trav->getKey(isBitSet);
            }            
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* tb = new Trie();

        for(auto it:nums){
            tb->insertNum(it);
        }

        int maxXor = 0;

        for(auto it:nums){
            int res = tb->maxXorFind(it);

            maxXor = max(maxXor,res);
        }
        return maxXor;
    }
};