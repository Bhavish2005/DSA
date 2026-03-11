class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
         int n=grid.size();
        vector<int>endZero(n,0);
         for(int i=0;i<n;i++){
            int j=n-1;
            int count =0;
            while(j>=0 && grid[i][j]==0){
                count++;
                j--;
            }
            endZero[i]=count;
         }
         int ans=0;
         for(int i=0;i<n;i++){
            int need=n-i-1;
             int j=i;
              while(j<n && endZero[j]<need)
              j++;

              if(j==n)
              return -1;
              ans+=(j-i);
              while(j>i)
              {
                swap(endZero[j], endZero[j-1]);
                j--;
              }

         }
         return ans;
    }
};
