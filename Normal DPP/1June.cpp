class Solution {
public:
    int minimumCost(vector<int>& cost) {
      sort(cost.begin(), cost.end());
        int n=cost.size();
        int ans=0;
        int j=n-1;
         while(j>0){
            ans+=cost[j]+cost[j-1];
            j-=3;
         }
        if(n%3==1)
        ans+=cost[0];
        return ans;
    }
};
