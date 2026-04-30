class Solution {
public:
int m,n;
vector<vector<vector<int>>> t;
    int MIN=-1e9;
    int dfs(int k , vector<vector<int>>&grid, int i, int j ,int current_cost){
        if(i>=n || j>=m)
        return MIN;
        current_cost+=grid[i][j]==0?0:1;
        int score=grid[i][j];
        if(current_cost>k)
        return MIN;
        if(t[i][j][current_cost]!=-1)
        return t[i][j][current_cost];
        if(i==n-1 && j==m-1)
        return grid[i][j];
        int right_score=dfs(k,grid,i,j+1,current_cost);
        int down_score=dfs(k,grid,i+1,j,current_cost);
        int best=max(right_score, down_score);
        if(best==MIN)
        return t[i][j][current_cost]=MIN;
        else
        return t[i][j][current_cost]=score+best;
        
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m=grid[0].size();
        n=grid.size();
        t.assign(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int ans=0;
        ans =dfs(k,grid,0,0,0);
        return ans!=(MIN)?ans:-1;
    }
};
