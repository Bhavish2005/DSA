class Solution {
public:vector<vector<pair<long long,long long >>>t;
const int MOD=1e9+7;
int n,m;
    pair<long long,long long> solve(int i, int j, vector<vector<int >>& grid){
        if(i>=n || j>=m)
        return {LLONG_MIN, LLONG_MAX};
        if(i==n-1 && j==m-1)
        return {grid[i][j], grid[i][j]};
        if(t[i][j].first!=LLONG_MIN)
        return t[i][j];
        auto right=solve(i,j+1, grid);
        auto down=solve(i+1, j, grid);
        long long maxVal=max(right.first, down.first);
        long long minVal=min(right.second, down.second);
        int curr=(long long)grid[i][j];
        long long newMax,newMin;
        if(curr<=0){
            newMax=minVal*curr;
            newMin=maxVal*curr;
        }
        else
        {
            newMax=maxVal*curr;
            newMin=minVal*curr;

        }
        return t[i][j]={newMax, newMin};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        t.assign(n,vector<pair<long long ,long long>>(m,{LLONG_MIN, LLONG_MAX}));
        auto ans=solve(0,0,grid);
        if(ans.first<0)
        return -1;
        else
        return ans.first%MOD;
    }
};
