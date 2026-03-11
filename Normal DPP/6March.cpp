class Solution {
public:
    bool checkOnesSegment(string s) {
        int maxi=0;
        int curr=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
            curr++;
            count++;
        }
            else
            curr=0;
            maxi=max(curr, maxi);
        }
        return maxi==count;
    }
};


// this approach worked because everytime the in string there are no Leading Zeros...
class Solution{
    public:
bool checkOnesSegment(string s){
    for(int i=0;i<s.size()-1;i++){
        if(s[i]=='0' && s[i+1]=='1')
        return false;
    }
    return true;
}
};
