using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // Sort arr2 to enable binary search
        sort(arr2.begin(), arr2.end());
        int distanceValue = 0;

        for (int x : arr1) {
            // Find the first element in arr2 that is >= (x - d)
            auto it = lower_bound(arr2.begin(), arr2.end(), x - d);

            // If no such element exists, or the smallest one is > (x + d),
            // then no element in arr2 has distance <= d from x.
            if (it == arr2.end() || *it > x + d) {
                distanceValue++;
            }
        }

        return distanceValue;
    }
};