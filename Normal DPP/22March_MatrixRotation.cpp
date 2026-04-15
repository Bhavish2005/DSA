class Solution {
public:
    bool findRotation(vector<vector<int>>& matrix, vector<vector<int>>& target) {
        int n=matrix.size();
       vector<int>valid(4, true);
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(target[i][j]!=matrix[i][j])
            valid[0]=false;
            if(target[i][j]!=matrix[n-1-j][i])
            valid[1]=false;
            if(target[i][j]!=matrix[n-1-i][n-1-j])
            valid[2]=false;
            if(target[i][j]!=matrix[j][n-1-i])
            valid[3]=false;
        }

       }
       return valid[0]||valid[1]||valid[2]||valid[3];
    }
};
