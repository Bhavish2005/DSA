class Solution {
public: vector<vector<vector<int>>>dp;
int n,m;
    int solve(int i, int j, int robbed, vector<vector<int>>&coins){
        if(i>=n || j>=m)
        return -1e9;
        if(i==n-1 && j==m-1 ){
        if(coins[i][j]<0 && robbed>0){
            return 0;
        }
        return coins[i][j];
    }
    if(dp[i][j][robbed]!=-1e9)
    return dp[i][j][robbed];
        int right=solve(i,j+1,robbed, coins);
        int down=solve(i+1,j,robbed, coins);
        int ans=coins[i][j]+max(right,down);

        if(coins[i][j]<0 && robbed>0){
            int right=solve(i,j+1,robbed-1, coins);
            int down=solve(i+1,j, robbed-1,coins);
            ans=max(ans,max(right,down));
        }
        return dp[i][j][robbed]=ans;
    }
    // int bottomUp(vector<vector<int>>&coins){
        
    // }
    int maximumAmount(vector<vector<int>>& coins) {
        n=coins.size();
        m=coins[0].size();
       dp.assign(n, vector<vector<int>>(m,vector<int>(3,-1e9)));
       return solve(0,0,2, coins);

    }
};
