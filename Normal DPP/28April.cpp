class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v.push_back(grid[i][j]);
            }
        }
        int z=v.size();
        int rem=v[0]%x;
        for(int i=1;i<z;i++){
            if(v[i]%x!=rem)
            return -1;
        }
        sort(v.begin(), v.end());
        int median =v[z/2];
        int ans=0;
        for(int i=0;i<z;i++){
            ans+=abs(v[i]-median)/x;
        }
        return ans;
    }
};
