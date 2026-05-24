class Solution {
private:
 
    int dfs(int i, int d, const vector<int>& arr, vector<int>& dp) {
       
        if (dp[i] != 0) {
            return dp[i];
        }
        
        int n = arr.size();
        int max_jumps = 1;

        for (int j = i + 1; j <= min(i + d, n - 1); ++j) {
            if (arr[j] >= arr[i]) break;
            max_jumps = max(max_jumps, 1 + dfs(j, d, arr, dp));
        }

        for (int j = i - 1; j >= max(0, i - d); --j) {
            if (arr[j] >= arr[i]) break;
            max_jumps = max(max_jumps, 1 + dfs(j, d, arr, dp));
        }

        return dp[i] = max_jumps;
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, 0); 
        int global_max = 0;
        for (int i = 0; i < n; ++i) {
            global_max = max(global_max, dfs(i, d, arr, dp));
        }
        
        return global_max;
    }
};
