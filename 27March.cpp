class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        
        vector<vector<int>>helper=mat;

        int n=mat.size();
        int m=mat[0].size();
         k = k % m; 
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i&1)
                helper[i][j]=mat[i][(j+k)%m];
                
                else
                helper[i][j]=mat[i][(j-k+m)%m];
                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(helper[i][j]!=mat[i][j])
                return false;
            }
        }
        return true;
    }
};
