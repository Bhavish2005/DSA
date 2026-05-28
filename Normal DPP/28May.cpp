class Solution {
public:
struct TrieNode{
    int idx;
    TrieNode* children[26];
    ~TrieNode(){
        for(int i=0;i<26;i++){
            delete children[i];
        }
    }
};
    TrieNode* getNode(int i){
        TrieNode* temp=new TrieNode();
        temp->idx=i;
        for(int i=0;i<26;i++){
            temp->children[i]=NULL;
        }
        return temp;
    }
    void insertTrie(TrieNode* pcrawl, int i,vector<string>&wordContainer){
        string word=wordContainer[i];
        int n=word.size();
        for(int j=n-1;j>=0;j--){
            int idx=word[j]-'a';
            if(pcrawl->children[idx]==NULL)
            pcrawl->children[idx]=getNode(i);
            pcrawl=pcrawl->children[idx];
            if(wordContainer[pcrawl->idx].size()>n)
            pcrawl->idx=i;
        }

    }
    int search(TrieNode *pcrawl, string & word){
        int idx=pcrawl->idx;
        int n=word.size();
        for(int i=n-1;i>=0;i--){
            int ch_idx=word[i]-'a';
            pcrawl=pcrawl->children[ch_idx];
            if(pcrawl==NULL)
            return idx;
            idx=pcrawl->idx;
        }
        return idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m=wordsContainer.size();
        int n=wordsQuery.size();
        vector<int>result(n);
        TrieNode* root=getNode(0);
        for(int i=0;i<m;i++){
            if(wordsContainer[root->idx].size()>wordsContainer[i].size())
            root->idx=i;
            insertTrie(root,i,wordsContainer);
        }
        for(int i=0;i<n;i++){
            result[i]=search(root,wordsQuery[i]);
        }
        delete root;
        return result;
        
    }
};
