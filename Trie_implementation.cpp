struct TrieNode{
TrieNode* children[26];
bool isEndofWord;
TrieNode(){
    isEndofWord=false;
    for(int i=0;i<26;i++){
        children[i]=nullptr;
    }
}
};
class Trie{
    TrieNode* root;
     
    public:
    Trie(){
        root=new TrieNode();
    }
    void insert(string word){
        TrieNode* curr=root;
        for(char c:word){
            int doorNumber=c-'a';
            if(curr->children[doorNumber]==nullptr)
            curr->children[doorNumber]=new TrieNode();
            curr=curr->children[doorNumber];
        }
        curr->isEndofWord=true;
    }
    // find the Word..
    bool search (string word){  
        int count=2;
        TrieNode* curr=root;
        for(auto c:word){
            int doorNumber=c-'a';
            if(curr->children[doorNumber]==nullptr && count ==0)
            return false;
            curr=curr->children[doorNumber];
            
        }
        return curr->isEndofWord;
    }

    // if want to search for the prefix
    bool SearchPrefix(string prefix){
        TrieNode* curr = root;
        
        for (char c : prefix) {
            int doorNumber = c - 'a';
            
            if (curr->children[doorNumber] == nullptr) {
                return false;
            }
            curr = curr->children[doorNumber];
        }
        return true;
    }

};
