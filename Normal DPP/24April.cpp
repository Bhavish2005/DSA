class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int diff=0;
        int count =0;
        int n=moves.size();
        for(int i=0;i<n;i++){
            if(moves[i]=='L')diff--;
            else if (moves[i]=='R')
            diff++;
            else
            count++;
        }
        return abs(diff)+count ;

    }
};
