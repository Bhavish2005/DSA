class Solution {
public:
    int minimumDistance(vector<int>& nums) {

        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < nums.size(); ++i) {
            indices[nums[i]].push_back(i);
        }

        int min_dist = -1;

        for (const auto& [val, idx_list] : indices) {
            int n = idx_list.size();
            if (n >= 3) {
              
                for (int m = 0; m <= n - 3; ++m) {
                    int current_dist = 2 * (idx_list[m + 2] - idx_list[m]);
                    
                    if (min_dist == -1 || current_dist < min_dist) {
                        min_dist = current_dist;
                    }
                }
            }
        }

        return min_dist;
    }
};
