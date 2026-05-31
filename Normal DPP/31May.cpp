class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long curr=1LL*mass;
        sort(asteroids.begin(), asteroids.end());
        for(int i=0;i<asteroids.size();i++){
            if(curr>=asteroids[i])
            curr+=asteroids[i];
            else
            return false;
        }
        return true;
    }
};
