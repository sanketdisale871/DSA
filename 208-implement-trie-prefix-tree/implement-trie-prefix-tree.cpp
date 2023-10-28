class Node{
    public:
    Node* childrens[26];
    bool endOfWord = false;

    // Check if the reference trie is present or not
    bool containsKey(char ch){
        return (childrens[ch-'a']!=NULL);
    }

    // Creating regerence trie
    void put(char ch,Node* node){
        childrens[ch-'a']=node;
    }

    // To get the next node for traversal
    Node* get(char ch){
        return childrens[ch-'a'];
    }

    // Setting flag true at the end of the word
    void setEnd(){
       endOfWord = true;
    }

    // Checking if the word is completed or not
    bool isEnd(){
        return endOfWord;
    }

};

class Trie {
private: Node* root;

public:
    Trie() {
        // Creating new Object
        root = new Node();
    }

    /// T.C : O(length of word)
    void insert(string word) {
        // Intializing dummy node poiting to root intially
        Node* node = root;

        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }

            // Moves to the referance trie !
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    /// T.C : O(length of word)
    bool search(string word) {
        Node* node = root;

        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }

        return node->isEnd();        
    }

    /// T.C : O(length of word)
    bool startsWith(string prefix) {
        Node* node = root;

        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
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