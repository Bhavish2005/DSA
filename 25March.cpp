class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
         int m =grid[0].size();
        vector<long long>col(m,0);
        vector<long long> row(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row[i]+=(long long)grid[i][j];
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                col[j]+=(long long)grid[i][j];
            }
        }
        long long total=accumulate(row.begin(), row.end(), 0LL);
        long long running =0;
         for(int i=0;i<n-1;i++){
            running+=row[i];
            if(running==total-running)
            return true;
         }
         running =0;
         for(int i=0;i<m-1;i++){
            running+=col[i];
            if(running==total - running)
            return true;
         }
         return false;
    }
};
