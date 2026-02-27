class Solution {
public:
    int minOperations(string s, int k) {
        queue<int>q;
        int zeroes=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            zeroes+=(s[i]-'0'==0?1:0);
        }
        if(zeroes==0)
        return 0;
        vector<int>operation(n+1,-1);
        set<int> even;
         set<int>odd;
         for(int i=0;i<=n;i++){
            if(i%2)
            odd.insert(i);
            else
            even.insert(i);
         }
        q.push(zeroes);
        operation[zeroes]=0;
        if(zeroes%2)
        odd.erase(zeroes);
        else
        even.erase(zeroes);
        while(!q.empty()){
            auto z= q.front();
            q.pop();
            int min_z=z+k-2*min(k,z);
            int max_z=z+k-2*max(0,k-n+z);
            set<int>&curr=(min_z%2==0)?even:odd;
            auto it =curr.lower_bound(min_z);
            while(it!=curr.end() && *it <=max_z){
                int newZ=*it;
                if(operation[newZ]==-1){
                operation[newZ]=operation[z]+1;
                if(newZ==0)
                return operation[newZ];
                q.push(newZ);
            }
            it=curr.erase(it);
        }
    }
     return -1;
    }
};
