
// first Approarch worked as Constrains were less
class Solution {
public:
    string invert(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0')
                s[i] = '1';
            else
                s[i] = '0';
        }
        return s;
    }
    string build(int n) {
        if(n == 1)
            return "0";
        string prev = build(n - 1);
        string temp = prev;
        reverse(temp.begin(), temp.end());
        temp = invert(temp);
        return prev + "1" + temp;
    }
    char findKthBit(int n, int k) {
        string ans = build(n);
        return ans[k - 1]; 
    }
};

// second Appraoch (OPtimized)
class Solution {
public:
    char solve(int n, int k) {
        if(n == 1)
            return '0';
        int length = (1 << n) - 1;
        int mid = length/2 + 1;
        if(k == mid)
            return '1';
        if(k < mid)
            return solve(n-1, k);
        char ch = solve(n-1, length - k + 1);
        return (ch == '0') ? '1' : '0';
    }

    char findKthBit(int n, int k) {
        return solve(n, k);
    }
};
