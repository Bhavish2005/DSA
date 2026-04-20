class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxi1=0;
        int n=colors.size();
         for(int i=0;i<n;i++){
            if(colors[n-1]!=colors[i]){
                maxi1=n-1-i;
                break;
            }
         }
         int maxi2=0;
         for(int i=n-1;i>=0;i--){
            if(colors[0]!=colors[i]){
                maxi2=i;
                break;
            }

         }
         return max(maxi1, maxi2);
  
  }
};
