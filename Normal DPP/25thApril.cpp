#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> arr(n);
        long long perimeter = 4LL * side;

        // Step 1: Flatten 2D points to 1D perimeter distances
        for (int i = 0; i < n; ++i) {
            long long x = points[i][0];
            long long y = points[i][1];
            
            if (y == 0) {
                arr[i] = x;                       // Bottom edge
            } else if (x == side) {
                arr[i] = side + y;                // Right edge
            } else if (y == side) {
                arr[i] = 3LL * side - x;          // Top edge
            } else { 
                arr[i] = 4LL * side - y;          // Left edge
            }
        }

        // Step 2: Sort the 1D points
        sort(arr.begin(), arr.end());

        // Step 3: Validation function to check if distance 'd' is possible
        auto isValid = [&](long long d) {
            for (int i = 0; i < n; i++) {
                int current_idx = i;
                int count = 1;

                while (count < k) {
                    // Look for the next point >= current distance + d
                    long long target = arr[current_idx] + d;
                    
                    // O(log N) lookup instead of O(N) linear scan
                    auto it = lower_bound(arr.begin(), arr.end(), target);
                    
                    if (it == arr.end()) {
                        break; // Reached the end of the array, not enough points
                    }
                    
                    current_idx = distance(arr.begin(), it);
                    count++;
                    
                    // The Crucial Check: 
                    // If placing the NEXT point (or closing the loop back to arr[i]) 
                    // exceeds the total allowable perimeter distance, it's invalid.
                    if (arr[current_idx] + d > arr[i] + perimeter) {
                        count = 0; 
                        break;
                    }
                }

                if (count == k) return true; // Successfully placed all k points
            }
            return false;
        };

        // Step 4: Binary Search on the answer
        long long low = 0;
        
        // CRUCIAL FIX: Bounding 'high' by 'side' guarantees that the perimeter 
        // distance perfectly equals the 2D Manhattan distance for all checks.
        long long high = side; 
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (isValid(mid)) {
                ans = mid;         // Valid, save it
                low = mid + 1;     // Try to maximize further
            } else {
                high = mid - 1;    // Invalid, decrease the distance
            }
        }

        return (int)ans;
    }
};
