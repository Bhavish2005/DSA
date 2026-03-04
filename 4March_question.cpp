// approach 1 bruteforce for me....
class Solution {
public:
    int numSpecial(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>rows(n,0);
        vector<int>cols(m,0);
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                rows[i]++;
                cols[j]++;
            }
            }
         }
         int ans=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1 && rows[i]==1 && cols[j]==1)
                ans++;
            }
         }
         return ans;
    }
};

// approach 2 OPtimized in terms of Storage ....
class Solution {
public:
    int numSpecial(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int count = 0;
            int colIndex = -1;
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 1) {
                    count++;
                    colIndex = j;
                }
            }
            if(count == 1) {
                int colCount = 0;
                for(int k = 0; k < n; k++) {
                    if(matrix[k][colIndex] == 1)
                        colCount++;
                }
                if(colCount == 1)
                    ans++;
            }
        }

        return ans;
    }
};
