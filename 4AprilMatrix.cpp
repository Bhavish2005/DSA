class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int col=encodedText.length()/rows;
        int n=encodedText.length();
        string ans="";
        int step=col+1;
         for(int i=0;i<col;i++){
            for(int j=i;j<n ;j+=step){
                ans+=encodedText[j];
                if(j%col==col-1)
                    break;
            }
         }
       while(!ans.empty() && ans.back()==' ')
       ans.pop_back();
         return ans;
    }
};
