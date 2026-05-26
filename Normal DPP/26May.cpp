class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char>s(word.begin(), word.end());
        int count =0;
        int n=word.size();
        for(auto x:s){
            if(s.count(x-'a'+'A'))
            count++;
        }
    return count ;        
    }
};
