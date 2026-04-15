class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<tuple<int,int ,char ,int>>t;
         int n=positions.size();
         for(int i=0;i<n;i++){
            t.push_back({positions[i], healths[i],directions[i], i});
         }
         sort(t.begin(), t.end());
         stack<int>s;
         for(int i=0;i<n;i++){
             char currdir=get<2>(t[i]);
             int currid=get<3>(t[i]);
           if( currdir=='R'){
            s.push(currid);
           }
           else{
            while(!s.empty() && healths[currid]>0){
                int fir=s.top();
                 if (healths[currid]==healths[fir]){
                    healths[fir]=0;
                    healths[currid]=0;
                    s.pop();
                 }
                 else if (healths[currid]>healths[fir]){
                    healths[fir]=0;
                    healths[currid]-=1;
                    s.pop();
                 }
                 else{
                    healths[currid]=0;
                    healths[fir]-=1;
                 }
            }
           }
         }
         vector<int>ans;
         for(int i=0;i<n;i++){
            if(healths[i]>0)
            ans.push_back(healths[i]);
         }
         return ans;
        
    }
};
