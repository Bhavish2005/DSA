#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> KahnsAlgo(vector<vector<int>>&adj, int n){
 vector<int>indegree(n,0);
vector<int>ans;
	for(auto v:adj){
	for(int i=0;i<v.size();i++){
		indegree[v[i]]++;
}
}
	queue<int>q;	
	for(int i=0;i<n;i++){
	if(indegree[i]==0)
	q.push(i);
}
while(!q.empty()){
int t=q.front();
q.pop();
ans.push_back(t);
for(auto  v:adj[t]){
indegree[v]--;
if(indegree[v]==0)
q.push(v);
}
}
return ans;

}

int main(){
int n;
cin>>n;
vector<vector<int>>adj(n);
for(int i=0;i<n;i++){
int numberofEdges;
cin>>numberofEdges;
for(int j=0;j<numberofEdges;j++){
int ind ;
cin>> ind;
adj[i].push_back(ind);
}
}
vector<int>ans=KahnsAlgo(adj,n);
if(ans.size()!=n){
cout<<"cylce Detected "<<endl;
return 0;}
for(int i=0;i<n;i++){
cout<<ans[i]<<" ";
}
return 0;
}
