class Solution {
public:

    vector<vector<int>> helper(string word){
        int n=word.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
         for(int i=0;i<n;i++){
            if(word[n-1]==word[i]){
                  dp[i][n-1]=1;
                  dp[n-1][i]=1;
            }
         }
         for(int i=n-2;i>=0;i--){
             for(int j=n-2;j>=0;j--){
                if(word[i]==word[j])
                dp[i][j]=1+dp[i+1][j+1];
             }
         }
         return dp;
         
    }
    string findTheString(vector<vector<int>>& lcp) {
        int  n=lcp.size();
         string word(n,'*');
          for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(lcp[j][i]!=0){
                    word[i]=word[j];
                    break;
                }
            }
             if(word[i]=='*'){
                vector<int>notAllowed(26, false);
                for(int j=0;j<i;j++){
                    if(lcp[j][i]==0)
                    notAllowed[word[j]-'a']=true;
                }
                    for(int k=0;k<26;k++){
                        if(notAllowed[k]==false){
                        word[i]=k+'a';
                        break;
                        }
                    }
                if(word[i]=='*')
                return "";               
             }
          }
          return helper(word)==lcp?word:"";
    }
};
