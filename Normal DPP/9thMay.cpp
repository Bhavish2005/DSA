class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (top < bottom && left < right) {
            vector<int> layer;
            for (int i = top; i < bottom; ++i) layer.push_back(grid[i][left]);
            for (int j = left; j < right; ++j) layer.push_back(grid[bottom][j]);
            for (int i = bottom; i > top; --i) layer.push_back(grid[i][right]);
            for (int j = right; j > left; --j) layer.push_back(grid[top][j]);
            int L = layer.size();
            int actual_k = k % L;
            rotate(layer.rbegin(), layer.rbegin() + actual_k, layer.rend());
            int idx = 0;
            for (int i = top; i < bottom; ++i) grid[i][left] = layer[idx++];
            for (int j = left; j < right; ++j) grid[bottom][j] = layer[idx++];
            for (int i = bottom; i > top; --i) grid[i][right] = layer[idx++];
            for (int j = right; j > left; --j) grid[top][j] = layer[idx++];
            top++;
            bottom--;
            left++;
            right--;
        }
        
        return grid;
    }
};
