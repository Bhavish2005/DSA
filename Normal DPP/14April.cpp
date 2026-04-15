class Solution {
public:
    using ll=long long ;
    int n,m;
    vector<vector<ll>>dp;
    ll helper(int i, int j,vector<ll>& newFac, vector<int>&robots){
        if(i==n)
        return 0;
        if(j==m)
        return 1e15;
        if(dp[i][j]!=-1)
        return dp[i][j];
        ll take=helper(i+1, j+1, newFac, robots)+abs(newFac[j]-(1LL*robots[i]));
        ll skip=helper(i, j+1,newFac,robots);
        return dp[i][j]=min(take, skip);
    }
    ll minimumTotalDistance(vector<int>& robots, vector<vector<int>>& factory) {
        sort(robots.begin(), robots.end());
        sort(factory.begin(), factory.end());
        vector<ll>newFac;
        for(auto&it:factory){
            for(auto i=0;i<it[1];i++){
                newFac.push_back(1LL*it[0]);
            }
        }
        n=robots.size();
        m=newFac.size();
        dp.assign(n+1, vector<ll>(m+1,-1));
      return helper(0,0,newFac, robots);

    }
};
