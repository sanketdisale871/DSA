class Node{
    public:
    Node* links[26];
    int cp,ew;

    Node(){
        cp=0;
        ew =0;

        for(int i=0;i<26;i++){
            links[i]=NULL;
        } 
    }

    bool contains(char ch){
        return (links[ch-'a']!=NULL);
    }

    void putChar(char ch){
        links[ch-'a']= new Node();
    }

    Node* getChar(char ch){
        return links[ch-'a'];
    }

    void incPref(){
        cp++;
    }

    void setWrdEnd(){
        ew++;
    }
};

class Trie{
    public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* trav = root;

        for(int i=0;i<word.length();i++){
            if(!trav->contains(word[i])){
                trav->putChar(word[i]);
            }
            trav = trav->getChar(word[i]);
            trav->incPref();
        }
        trav->setWrdEnd();
    }

    int countWordStartWith(string pref){
        Node* trav = root;

        for(int i=0;i<pref.length();i++){
            if(!trav->contains(pref[i])){
                return 0; 
            }
            trav = trav->getChar(pref[i]);
        }
        return trav->cp;
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie* tb = new Trie();

        for(auto it:words){
            tb->insert(it);
        }

        return tb->countWordStartWith(pref);
    }
};