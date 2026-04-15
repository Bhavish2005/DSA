class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=grid.size();
         int m=grid[0].size();
         int i=x, j=min(n-1,(x+k-1));
         while(i<j)
         {
            for(int l=y;l<min(m,y+k);l++){
                swap(grid[i][l], grid[j][l]);
            }
            i++;
            j--;
         }
         return grid;
    }
};
