class Solution {
public:
    int minOperations(string s) {
        int pattern1=0;
        int pattern2=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=(i%2 ?'1' :'0')) 
            pattern1++;
            else if(s[i]!=(i%2?'0':'1'))pattern2 ++;
            }
         return min(pattern1, pattern2 );
    }
};
