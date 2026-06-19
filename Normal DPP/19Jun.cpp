class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prev=0;
        int high=0;
        for(int i=0;i<gain.size();i++){
            prev+=gain[i];
            high=max(prev, high);
        }
        return high;
    }
};
