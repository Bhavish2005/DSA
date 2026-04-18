class Solution {
public:
int rev(int num){
    int res=0;
     while(num>0){
        int j=num%10;
        res=res*10+j;
        num/=10;
     }
     return res;
}
    int mirrorDistance(int n) {
        return abs(n-rev(n));
    }
};
