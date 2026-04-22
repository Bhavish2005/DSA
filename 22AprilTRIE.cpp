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
     bool dfs(TrieNode * node ,const string & word ,int index, int edits){
        //if it reaches last index of word..
        if(index==word.length())
        return true;
        int expectedDoor=word[index]-'a';
        if(node->children[expectedDoor]!=nullptr){
            if(dfs(node->children[expectedDoor], word, index+1, edits))
            return true;
        }
        if(edits>0){
            for(int i=0;i<26;i++){
                if(i!=expectedDoor && node->children[i]!=nullptr)
                if(dfs(node->children[i], word, index+1, edits-1))
                return true;
            }
        }
        return false;
    }
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
    // only for this question :
    bool searchwithEdits(string word){
        return dfs(root, word, 0,2);
    }

};
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        Trie t;
       for(auto s:dictionary)
       t.insert(s);
       vector<string>ans;
       for(auto s:queries){
        if(t.searchwithEdits(s))
        ans.push_back(s);
       }
       return ans;
    }
};
