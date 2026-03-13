class Solution {
public:
    bool can(long long T, vector<int>& workerTimes, int mountainHeight) {
        long long total = 0;

        for (int t : workerTimes) {
            long long val = (2LL * T) / t;
            long long x = (sqrt(1 + 4 * val) - 1) / 2;
            total += x;

            if (total >= mountainHeight) return true;
        }

        return total >= mountainHeight;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 0, r = 1e18;
        long long ans = r;

        while (l <= r) {
            long long mid = (l + r) / 2;

            if (can(mid, workerTimes, mountainHeight)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
