class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> prefXY(n, vector<int>(m, 0));
        vector<vector<int>> prefX(n, vector<int>(m, 0));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefXY[i][j] = (grid[i][j] == 'X' ? 1 : (grid[i][j] == 'Y' ? -1 : 0));
                prefX[i][j]  = (grid[i][j] == 'X' ? 1 : 0);

                if (i > 0) { prefXY[i][j] += prefXY[i-1][j]; prefX[i][j] += prefX[i-1][j]; }
                if (j > 0) { prefXY[i][j] += prefXY[i][j-1]; prefX[i][j] += prefX[i][j-1]; }
                if (i > 0 && j > 0) { prefXY[i][j] -= prefXY[i-1][j-1]; prefX[i][j] -= prefX[i-1][j-1]; }

                if (prefXY[i][j] == 0 && prefX[i][j] > 0) count++;
            }
        }
        return count;
    }
};
