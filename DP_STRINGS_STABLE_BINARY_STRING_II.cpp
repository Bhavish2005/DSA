class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {

        // MOD for large answers
        const int M = 1e9+7;

        /*
        APPROACH (Key Idea):

        We build arrays using DP.

        State:
        t[i][j][0] -> number of valid arrays using i zeros and j ones ending with 0
        t[i][j][1] -> number of valid arrays using i zeros and j ones ending with 1

        Why 3D?
        Because the last element matters due to the LIMIT constraint.

        Transition Idea:
        If we place 1 -> previous state could end with 0 or 1
        If we place 0 -> previous state could end with 0 or 1

        BUT we must ensure we never create more than 'limit' consecutive elements.
        To enforce this efficiently we subtract the invalid cases.
        */

        vector<vector<vector<int>>> t(
            zero+1, vector<vector<int>>(one+1, vector<int>(2,0))
        );

        // Base cases:
        // Arrays consisting of only zeros (valid only if <= limit)
        for(int i=0;i<=min(zero, limit);i++){
            t[i][0][0] = 1;
        }

        // Arrays consisting of only ones (valid only if <= limit)
        for(int i=0;i<=min(one, limit);i++){
            t[0][i][1] = 1;
        }

        for(int i=0;i<=zero;i++){
            for(int j=0;j<=one;j++){

                // Already handled base cases
                if(i == 0 || j == 0)
                    continue;

                /*
                Ending with 1:
                We add a '1' to arrays that previously used j-1 ones.
                */
                t[i][j][1] = (t[i][j-1][1] + t[i][j-1][0]) % M;

                // Remove cases where more than 'limit' consecutive 1s occur
                if(j-1 >= limit){
                    t[i][j][1] = (t[i][j][1] - t[i][j-1-limit][0] + M) % M;
                }

                /*
                Ending with 0:
                We add a '0' to arrays that previously used i-1 zeros.
                */
                t[i][j][0] = (t[i-1][j][1] + t[i-1][j][0]) % M;

                // Remove cases where more than 'limit' consecutive 0s occur
                if(i-1 >= limit){
                    t[i][j][0] = (t[i][j][0] - t[i-1-limit][j][1] + M) % M;
                }
            }
        }

        // Final answer can end with either 0 or 1
        return (t[zero][one][1] + t[zero][one][0]) % M;
    }
};
