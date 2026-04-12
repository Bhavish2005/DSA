class Solution {
public:
vector<vector<int>>t;
    int manhattanDistance(int a, int b){
        if (a==26 || b==26)
        return 0;
        int a_x= (a)/6;
        int a_y=(a)%6;
        int b_x=(b)/6;
        int b_y=(b)%6;
        return abs(a_x-b_x)+abs(a_y-b_y);

    }
     int solve(int ind, int otherFinger,string&word){
        if(ind==word.length())
        return 0;
        if(t[ind][otherFinger]!=-1)
        return t[ind][otherFinger];
        int prevFinger=(ind==0)?26 : word[ind-1]-'A';
        int targetChar=word[ind]-'A';
        int movprev=manhattanDistance(prevFinger,targetChar)+solve(ind+1, otherFinger, word);
        int moveOther=manhattanDistance(otherFinger,targetChar)+solve(ind+1,prevFinger,word);
        return t[ind][otherFinger]=min(movprev,moveOther);
     }
    int minimumDistance(string word) {
        int n=word.size();
        t.assign(n,vector<int>(27,-1));
        return solve(0,26,word);
        //starting is the 1 word in word and other finger is at the free state...
        
    }
};
