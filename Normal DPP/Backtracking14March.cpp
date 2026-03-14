class Solution {
public:
    void helper(string & help,vector<string>& ans,int n){
        if(help.size()==n){
        ans.push_back(help);
        return;
        }
        for(auto chars:{'a','b','c'}){
            if(help.empty()|| help.back()!=chars){
                help.push_back(chars);
                helper(help,ans,n);
                help.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string>ans;
        string help="";
        helper(help,ans,n);
        if(k<=ans.size())
        return ans[k-1];
        else
        return "";
    }
};
