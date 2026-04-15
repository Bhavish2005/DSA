class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();    
        int m = grid[0].size();
        
        vector<long long> col(m, 0);
        vector<long long> row(n, 0);
        
        // calculating the initial Sums...
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                row[i] += (long long)grid[i][j];
                col[j] += (long long)grid[i][j]; 
            }
        }
        long long total = accumulate(row.begin(), row.end(), 0LL);

        if (n > 1) {
            unordered_set<long long> top_elements;
            unordered_map<long long, int> bottom_counts;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    bottom_counts[grid[i][j]]++;
                }
            }
            
            long long running = 0;
            for(int i = 0; i < n - 1; i++){
                running += row[i];
                for(int j = 0; j < m; j++) {
                    long long val = grid[i][j];
                    top_elements.insert(val);
                    bottom_counts[val]--;
                    if(bottom_counts[val] == 0) bottom_counts.erase(val);
                }
                
                long long top_sum = running;
                long long bot_sum = total - running;
                
                if(top_sum == bot_sum) return true; 
                
                
                if (top_sum > bot_sum) {
                    long long diff = top_sum - bot_sum;
                    int R = i + 1, C = m; 
                    
                    if (R == 1 && C > 1) {
                        if (diff == grid[0][0] || diff == grid[0][m-1]) return true;
                    } else if (C == 1 && R > 1) {
                        if (diff == grid[0][0] || diff == grid[i][0]) return true;
                    } else if (R > 1 && C > 1) {
                        if (top_elements.count(diff)) return true;
                    }
                } 
              
                else {
                    long long diff = bot_sum - top_sum;
                    int R = n - 1 - i, C = m; 
                    
                    if (R == 1 && C > 1) {
                        if (diff == grid[i+1][0] || diff == grid[i+1][m-1]) return true;
                    } else if (C == 1 && R > 1) {
                        if (diff == grid[i+1][0] || diff == grid[n-1][0]) return true;
                    } else if (R > 1 && C > 1) {
                        if (bottom_counts.count(diff)) return true;
                    }
                }
            }
        }
        
        
        if (m > 1) {
            unordered_set<long long> left_elements;
            unordered_map<long long, int> right_counts;
            
            
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    right_counts[grid[i][j]]++;
                }
            }
            
            long long running = 0;
            for(int j = 0; j < m - 1; j++){
                running += col[j];
                
                
                for(int i = 0; i < n; i++) {
                    long long val = grid[i][j];
                    left_elements.insert(val);
                    right_counts[val]--;
                    if(right_counts[val] == 0) right_counts.erase(val);
                }
                
                long long left_sum = running;
                long long right_sum = total - running;
                
                if(left_sum == right_sum) return true; 
                
                if (left_sum > right_sum) {
                    long long diff = left_sum - right_sum;
                    int R = n, C = j + 1;
                    
                    if (C == 1 && R > 1) {
                        if (diff == grid[0][0] || diff == grid[n-1][0]) return true;
                    } else if (R == 1 && C > 1) {
                        if (diff == grid[0][0] || diff == grid[0][j]) return true;
                    } else if (R > 1 && C > 1) {
                        if (left_elements.count(diff)) return true;
                    }
                } else {
                    long long diff = right_sum - left_sum;
                    int R = n, C = m - 1 - j; 
                    
                    if (C == 1 && R > 1) {
                        if (diff == grid[0][j+1] || diff == grid[n-1][j+1]) return true;
                    } else if (R == 1 && C > 1) {
                        if (diff == grid[0][j+1] || diff == grid[0][m-1]) return true;
                    } else if (R > 1 && C > 1) {
                        if (right_counts.count(diff)) return true;
                    }
                }
            }
        }
        
        return false;
    }
};
