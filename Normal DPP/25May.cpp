class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
         if(s[n-1]=='1')
         return false;
         int alreadySeen=0;
       queue<int>q;
       q.push(0);
       while(!q.empty()){
        int top=q.front();
        q.pop();
        if(top==n-1)
        return true;
        int start =max(top+minJump, alreadySeen+1);
        int end =min(top+maxJump, n-1);
        for(int i=start;i<=end;i++){
            if(s[i]=='0')
            q.push(i);
        }
        alreadySeen=max(alreadySeen , end);
       } 
       return false;
    }
};
