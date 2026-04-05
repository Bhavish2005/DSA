class Solution {
public:
    bool judgeCircle(string moves) {
        int vertical=0;
        int horizontal=0;
        int n=moves.size();
         for(int i=0;i<n;i++){
            if(moves[i]=='U')
            vertical+=1;
            else if(moves[i]=='L')
            horizontal-=1;
            else if(moves[i]=='R')
            horizontal+=1;
            else
            vertical-=1;
         }
         return horizontal==0 && vertical==0;
    }
};
