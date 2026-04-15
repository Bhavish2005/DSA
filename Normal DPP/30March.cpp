class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int countodd1[26]={0};
        int counteven1[26]={0};
        int countodd2[26]={0};
        int counteven2[26]={0};
         for(int i=0;i<s1.size();i++){
            if(i&1){
            countodd1[s1[i]-'a']++;
            countodd2[s2[i]-'a']++;
         }
         else{
            counteven1[s1[i]-'a']++;
            counteven2[s2[i]-'a']++;
         }
         }
         for(int i=0;i<26;i++){
            if(countodd1[i]!=countodd2[i] || counteven1[i]!=counteven2[i])
            return false;
         }
         return true;
    }
};
