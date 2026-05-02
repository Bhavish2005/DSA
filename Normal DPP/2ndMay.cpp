class Solution {
public:
vector<int>possible={0,1,2,5,6,8,9};
int helper(long long num, bool has_rotator,int n){
    if(num>n)
    return 0;
    int count =0;
    if(num>0 && has_rotator)
    count++;
    for(auto d:possible){
        if(num ==0 && d==0)
        continue;
        long long next_num =num*10+d;
        bool next_has_rotator=has_rotator || d==2 || d==5 ||d==6 ||d==9;
        count+=helper(next_num ,next_has_rotator, n);
    }
    return count ;
}
    int rotatedDigits(int n) {
       return helper(0, false, n); 
    }
};
