class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans ="";
        
        for(auto a:words){
            int sum=0;
            for(int i=0;i<a.size();i++){
                sum+=weights[a[i]-'a'];
            }
            ans+=25-sum%26+'a';
        }
        return ans;
    }
};

