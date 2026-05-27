class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>firstUpper(26,-1);
        vector<int>lastLower(26,-1);
        int count =0;
         int n=word.size();
        for(int i=0;i<n;i++){
            if(word[i]>='a' && word[i]<='z')
            lastLower[word[i]-'a']=i;
            else if (word[i]>='A' && word[i]<='Z')
            {
                if(firstUpper[word[i]-'A']==-1){
                    firstUpper[word[i]-'A']=i;
                }
            }
        }
        for(int i=0;i<26;i++){
            if(firstUpper[i]!=-1 && lastLower[i] !=-1 && firstUpper[i] > lastLower[i])
            count ++;
        }
        return count ;
    }
};
