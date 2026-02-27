class Solution {
public:
int timer=1;
    void DFS(int node,int parent,vector<bool>&visited,vector<vector<int>>&adj,vector<vector<int>>&connections,vector<int>&time,vector<int>&lowTime,vector<vector<int>>&ans){
        visited[node]=true;
        time[node]=timer;
        lowTime[node]=timer;
        timer++;
        for(auto newNode:adj[node]){
            if(newNode==parent)
            continue;
            if(!visited[newNode]){
                DFS(newNode,node,visited,adj,connections,time,lowTime,ans);
                lowTime[node]=min(lowTime[node],lowTime[newNode]);
                if(lowTime[newNode]>time[node])
                ans.push_back({node,newNode});
            }
            else{
                lowTime[node]=min(lowTime[node],lowTime[newNode]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        //making Adjencancy List...
        for(auto edge:connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>time(n);
        vector<int>lowTime(n);
        vector<bool>visited(n,false);
        vector<vector<int>> ans;
        DFS(0,-1,visited,adj,connections,time,lowTime,ans);
        return ans;


    }
};
