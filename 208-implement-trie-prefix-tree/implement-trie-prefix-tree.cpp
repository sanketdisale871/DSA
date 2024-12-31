class Node{
    public:
    Node* links[26];
    bool isEndWrd;

    Node(){
        isEndWrd = false;
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr; 
        }
    }

    bool containsChar(char ch){
        return (links[ch-'a']!=NULL);
    }

    void putKey(char ch,Node* newNode){
        links[ch-'a']=newNode;
    }

    Node* getKey(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        isEndWrd = true;
    }

    bool isWordEnd(){
        return isEndWrd;
    }
};

class Trie {
    private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* travNode = root;

        for(int i=0;i<word.length();i++){
            char ch = word[i];

            if(!travNode->containsChar(ch)){
                travNode->putKey(ch,new Node());
            }
            travNode=travNode->getKey(ch);
        }
        travNode->setEnd();
    }
    
    bool search(string word) {
        Node* travNode = root;

        for(int i=0;i<word.length();i++){
            char ch = word[i];

            if(travNode->containsChar(ch)==false){
                return false;
            }
            travNode = travNode->getKey(ch);
        }
        if(travNode->isWordEnd()){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* travNode = root;

        for(int i=0;i<prefix.length();i++){
            char ch = prefix[i];

            if(travNode->containsChar(ch)==false){
                return false;
            }
            travNode = travNode->getKey(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */