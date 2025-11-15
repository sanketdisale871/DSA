class Node{
    private:
    Node* links[26];
    bool endWrd;

    public:
    Node(){
        endWrd = false;
        for(int i=0;i<26;i++){
            links[i]=nullptr;
        }
    }

    bool containsChar(char ch){
        return links[ch-'a']!=nullptr;
    }

    void putKey(char ch,Node* newNode){
        links[ch-'a']=newNode;
    }

    void setEnd(){
        endWrd = true;
    }

    bool isEndWord(){
        return endWrd;
    }

    Node* getKey(char ch){
        return links[ch-'a'];
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
            travNode = travNode->getKey(ch);
        }
        travNode->setEnd();
    }
    
    bool search(string word) {
        Node* travNode = root;
        for(int i=0;i<word.length();i++){
                char ch = word[i];

                if(!travNode->containsChar(ch)){
                return false;
            }
        travNode = travNode->getKey(ch);

        }
        return travNode->isEndWord();
    }
    
    bool startsWith(string prefix) {
        Node* travNode = root;
        for(int i=0;i<prefix.length();i++){
                char ch = prefix[i];

                if(!travNode->containsChar(ch)){
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