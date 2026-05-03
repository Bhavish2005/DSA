class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
        return false;
       string newString =s+s;
       return !(newString.find(goal)==string::npos);
    }
};
