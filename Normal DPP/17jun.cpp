class Solution {
public:
    char processStr(string s, long long k) {
        long long n=0;
     for( auto c:s){
        if(c=='#')
        n*=2;
        else if (c=='*')
        n=max(0LL,n-1);
        else if( c=='%')
        continue;
        else
        n++;
     }   
     if(n<=k)
     return '.';
     reverse(s.begin(), s.end());
     for(auto c:s){
        if(c=='*')
        n++;
        else if(c=='#')
        {
            n/=2;
            if(n<=k)
            k-=n;
        }
        else if (c=='%')
        k=n-k-1;
        else{
            n--;
            if(n==k)
            return c;
        }

     }
     return '.';
    }
};
