class Solution {
public:
class DSU {
    vector<int>size;
    vector<int>parent;
    public:
     DSU(int n ){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
     }
     int findParent(int node){
        if(parent[node]==node)
        return node;
        return parent[node]=findParent(parent[node]);
     }
     void Union(int u,int v){
        int up=findParent(u);
        int vp=findParent(v);
        if(up==vp)
        return;
        if(size[up]>=size[vp])
        {
            parent[vp]=up;
            size[up]+=size[vp];
        }
        else{
            parent[up]=vp;
            size[vp]+=size[up];
        }
     }
};
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        DSU d(n);
        unordered_map<int,unordered_map<int,int>>freq;
        for(auto s:allowedSwaps){
            d.Union(s[0],s[1]);
        }
        for(int i=0;i<n;i++){
            int parent=d.findParent(i);
            freq[parent][source[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int root=d.findParent(i);
            if(freq[root][target[i]]>0)
            freq[root][target[i]]--;
            else
            ans++;
        }
        return ans;

    }
};
