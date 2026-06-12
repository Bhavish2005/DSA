class Solution {
public: using ll= long long ;
    const ll MOD=1e9+7;
    vector<int>depth;
    vector<vector<int>>up;
    int LOG=18;
    ll helper(ll base, ll exp){
        ll ans=1;
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
    auto get_LCA(int u, int v){
        if(depth[u]<depth[v])
        swap(u,v);
        int diff=depth[u]-depth[v];
        for(int j=0;j<LOG;j++){
            if((diff>>j) & 1)
            u=up[u][j];
        }
        if(u==v)
        return u;
        for(int j=LOG-1;j>=0;j--){
            if(up[u][j]!=up[v][j]){
            u=up[u][j];
            v=up[v][j];
        }
        }
        return up[u][0];//immeditate parent it means (i and j in dp table tells->2^J parent of node i)...
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size()+1;
        depth.assign(n+1,0);
        vector<vector<int>>adj(n+1);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        up.assign(n+1, vector<int>(LOG,0));
        vector<bool>visited(n+1,false);
        queue<int>q;
        q.push(1);
        visited[1]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto a:adj[curr]){
                if(!visited[a]){
                    visited[a]=true;
                    depth[a]=depth[curr]+1;
                    up[a][0]=curr;
                    q.push(a);
                }
            }
        }
        for(int j=1;j<LOG;j++){
            for(int i=1;i<=n;i++){
                if(up[i][j-1]!=0){
                    up[i][j]=up[up[i][j-1]][j-1];
                }
            }
        }
        vector<int>ans;
        for(auto &q:queries){
            int u=q[0];
            int v=q[1];
            if(u==v)
            ans.push_back(0);
            else{
                int lca=get_LCA(u,v);
                int L=depth[u]+depth[v] -2*depth[lca];
                ll ways=helper(2,L-1);
                ans.push_back(ways);
                
                }
        }
        return ans;

    }
};
