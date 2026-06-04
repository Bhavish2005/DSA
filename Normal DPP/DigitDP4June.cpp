class Solution {
    struct Result {
        long long ways = -1;
        long long waviness = 0;
    };
    
    // Contiguous memory array, no heap allocation overhead per test case
    Result memo[20][11][11][2][2];

    void clearMemo() {
        for(int i = 0; i < 20; ++i)
            for(int j = 0; j < 11; ++j)
                for(int k = 0; k < 11; ++k)
                    for(int t = 0; t < 2; ++t)
                        for(int l = 0; l < 2; ++l)
                            memo[i][j][k][t][l] = {-1, 0};
    }

public:
    Result solve(string &s, int ind, bool is_tight, int prev, int prev_prev, bool is_lz) {
        if (ind == s.length()) {
            return {1, 0};
        }
        
        if (memo[ind][prev][prev_prev][is_tight][is_lz].ways != -1) {
            return memo[ind][prev][prev_prev][is_tight][is_lz];
        }
        
        int limit = is_tight ? (s[ind] - '0') : 9;
        long long total_ways = 0;
        long long total_waviness = 0;
        
        for (int curr = 0; curr <= limit; curr++) {
            bool new_tight = is_tight && (curr == limit);
            bool new_lz = is_lz && (curr == 0);
            bool is_wave = false;
            
            if (!new_lz && prev != 10 && prev_prev != 10) {
                if (prev > prev_prev && prev > curr) is_wave = true;
                if (prev < prev_prev && prev < curr) is_wave = true;
            }
            
            int next_p = prev;
            int next_pp = prev_prev;
            
            if (new_lz) {
                next_p = 10;
                next_pp = 10;
            } else {
                next_pp = prev;
                next_p = curr;
            }
            
            Result ans = solve(s, ind + 1, new_tight, next_p, next_pp, new_lz);
            
            total_ways += ans.ways;
            total_waviness += ans.waviness;
            
            if (is_wave) {
                total_waviness += ans.ways;
            }
        }
        
        return memo[ind][prev][prev_prev][is_tight][is_lz] = {total_ways, total_waviness};
    }
    
    long long solveHelper(string s) {
        // Just overwrite the existing array memory instead of re-allocating
        clearMemo();
        Result ans = solve(s, 0, true, 10, 10, true);
        return ans.waviness;
    }
    
    long long totalWaviness(long long num1, long long num2) {
        string s1 = to_string(num1 - 1);
        string s2 = to_string(num2);
        
        long long ans1 = solveHelper(s1);
        long long ans2 = solveHelper(s2);
        
        return ans2 - ans1;
    }
};
