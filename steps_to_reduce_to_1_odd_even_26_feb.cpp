class Solution {
public:

    void add1(string& s){
        int carry = 0;
        int i = s.size() - 1;

        while(i >= 0 && s[i] == '1'){  
            s[i] = '0';
            carry = 1;
            i--;                   
        }

        if(i >= 0){                   
            s[i] = '1';
        }
        else if(carry == 1){           
            s = "1" + s;
        }
    }

    int numSteps(string s) {
        int count = 0;

        for(int i = s.size()-1; s != "1"; i = s.size()-1){ 
            if(s[i] == '1')
                add1(s);
            else
                s.pop_back();

            count++;
        }

        return count;
    }
};

//style 2 of approach ....
class Solution {
public:

    void add1(string &s) {
        int i = s.size() - 1;

        while (i >= 0 && s[i] == '1') {
            s[i] = '0';
            i--;
        }

        if (i >= 0) {
            s[i] = '1';
        } else {
            s = "1" + s;   // overflow case
        }
    }

    int numSteps(string s) {
        int count = 0;

        while (s != "1") {
            if (s.back() == '0') {
                s.pop_back(); 
            } else {
                add1(s);    
            }
            count++;
        }

        return count;
    }
};
