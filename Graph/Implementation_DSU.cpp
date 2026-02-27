#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class disjoint_set{
	vector<int> rank,parent,size;
	public:
		disjoint_set(int n){
			rank.resize(n+1,0);
			parent.resize(n+1);
			size.resize(n+1,1);
			// settnig the node as its own parent...
			for(int i=0;i<=n;i++){
				parent[i]=i;
			}
		}
		int findParent(int node){
			// if the ultimate parent of node is itself then return it
			if(parent[node]==node){
				return node;
			}
			// go to the ultimate parent of parent of node..
			return parent[node]=findParent(parent[node]);
		}
		void UnionByRank(int u, int v){
			int pu=findParent(u);
			int pv=findParent(v);
			if(pu==pv)
			return ;
			if(rank[pu]>rank[pv])
			parent[pv]=pu;
			else if(rank[pu]<rank[pv])
			parent[pu]=pv;
			else
			{
				parent[pv]=pu;
				rank[pu]++;
			}
		}
		void UnionBySize(int u, int v){
			int pu=findParent(u);
			int pv=findParent(v);
			if(pu==pv)
			return;
			if(size[pu]>size[pv]){
				parent[pv]=pu;
				size[pu]+=size[pv];
			}
			else
			parent[pu]=pv;
			size[pv]+=size[pu];
		}
};
int main(){
	disjoint_set ds(7);
	disjoint_set ds2(7);
	ds.UnionByRank(1,2);
	ds.UnionByRank(2,3);
	ds.UnionByRank(4,5);
	ds.UnionByRank(6,7);
	ds.UnionByRank(5,6);
	if(ds.findParent(3)==ds.findParent(7))
	cout<<"Same"<<endl;
	else
	cout<<"Not Same"<<endl;
	ds.UnionByRank(3,7);
	if(ds.findParent(3)==ds.findParent(7))
	cout<<"Same"<<endl;
	else
	cout<<"Not Same"<<endl;
	return 0;
}
