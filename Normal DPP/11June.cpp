class Solution {
public:
const int MOD=1e9+7;
long long helper(long long base, long long exp){
    long long ans=1;
    if(exp<0)
    return 0;
    while(exp>0){
        if(exp%2==1){
            ans=(ans*base)%MOD;
        }
        base=(base*base)%MOD;
        exp/=2;
    }
    return ans;
}
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
      vector<vector<int>>adj(n);
      vector<bool>visited(n, false);
       for(auto e:edges){
        int node1=e[0]-1;
        int node2=e[1]-1;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
       }  
       long long count=0;
       queue<int>q;
       q.push(0);
       visited[0]=true;
       while(!q.empty()){
        int sz=q.size();
        bool flag=false;
        for(int i=0;i<sz;i++){
            int curr=q.front();
            q.pop();
            for(auto a:adj[curr]){
                if(!visited[a])
                {
                    flag=true;
                    q.push(a);
                    visited[a]=true;
                }
                
            }
        }
        if(flag)
        count++;
       }
       return helper(2, count-1);
    }
};
