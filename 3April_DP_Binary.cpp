class Solution {
public:
    using p = pair<int, int>;
    int n;
    vector<vector<int>> dp;
    int count(vector<int>& walls, int L, int R) {
        int low = lower_bound(walls.begin(), walls.end(), L) - walls.begin();
        int high = upper_bound(walls.begin(), walls.end(), R) - walls.begin();
        return high - low;
    }
    int solve(vector<p>& robodis, vector<int>& walls, vector<p>& ranges, int i,
              int dir) {
        if (i == n)
            return 0;
        if (dp[i][dir] != -1)
            return dp[i][dir];
        int leftStart = ranges[i].first;
        if (dir == 1) {
            if (i > 0)
                leftStart = max(leftStart, ranges[i - 1].second + 1);
        }
        int takeleft = count(walls, leftStart, robodis[i].first) +
                       solve(robodis, walls, ranges, i + 1, 0);
        int takeright = count(walls, robodis[i].first, ranges[i].second) +
                        solve(robodis, walls, ranges, i + 1, 1);
        return dp[i][dir] = max(takeleft, takeright);
    }
    int solveBottomUp(vector<p>& robodis, vector<int>& walls,
                      vector<p>& ranges) {
        vector<vector<int>> dpTab(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {

            for (int dir = 0; dir <= 1; dir++) {

                int leftStart = ranges[i].first;

                if (dir == 1) {
                    if (i > 0) {
                        leftStart = max(leftStart, ranges[i - 1].second + 1);
                    }
                }

                int takeleft =
                    count(walls, leftStart, robodis[i].first) + dpTab[i + 1][0];
                int takeright =
                    count(walls, robodis[i].first, ranges[i].second) +
                    dpTab[i + 1][1];

                dpTab[i][dir] = max(takeleft, takeright);
            }
        }

        return dpTab[0][0];
    }
    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {
        n = robots.size();
        vector<p> helper;
        // dp.assign(n,vector<int>(2,-1)); for recursive way..
        for (int i = 0; i < n; i++) {
            helper.push_back({robots[i], distance[i]});
        }
        sort(helper.begin(), helper.end());
        sort(walls.begin(), walls.end());
        vector<p> ranges;
        for (int i = 0; i < n; i++) {
            int pos = helper[i].first;
            int dis = helper[i].second;

            int leftlimit = i == 0 ? 1 : (helper[i - 1].first + 1);
            int rightlimit = i == n - 1 ? 1e9 : (helper[i + 1].first - 1);
            int L = max(leftlimit, pos - dis);
            int R = min(rightlimit, pos + dis);
            ranges.push_back({L, R});
        }
        // here dir is prev robo direction taken .....
        // return solve(helper, walls, ranges, 0, 0);
         return solveBottomUp(helper, walls, ranges);
    }
};
